#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include<QString>
MyTcpServer::~MyTcpServer()
{

    mTcpServer->close();
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
    DataBaseSingleton* database = DataBaseSingleton::getInstance();
    this->db = database;
    qDebug() << "Адрес базы данных в памяти: " << this->db;
}

void MyTcpServer::slotNewConnection(){
    mTcpSocket = mTcpServer->nextPendingConnection();
    connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
    connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);

    Sockets.push_back(mTcpSocket);
}

void MyTcpServer::slotServerRead(){

    QTcpSocket* senderSocket = qobject_cast<QTcpSocket*>(sender()); // Нужно для подключения нескольких клиентов к серверу
    if (!senderSocket) return; // проверка, dynamic cast сработал или нет
    QString res = "";
    while(senderSocket->bytesAvailable()>0)
    {
        QByteArray array =senderSocket->readAll();
        qDebug()<<QString::fromUtf8(array)<<"\n";
        if(array=="\x01")
        {
            senderSocket->write(Parsing(res).toUtf8());
            res = "";
        }
        else
            res.append(array);
    }
    senderSocket->write(Parsing(res).toUtf8());
}
void MyTcpServer::slotClientDisconnected(){
    mTcpSocket->close();
}

QString MyTcpServer::Parsing(QString inputs)
{
    QString command_string = inputs;
    //строка inputs это строка с параметрами, по которым сервер определяет что отправить клиенту обратно
    //константы параметров для команд
    const int auth_params_const = 3;
    const int reg_params_const = 5;
    const int cars_params_const = 8;
    qDebug() << inputs;
    //Для среза "\r\n";
    if(inputs.indexOf("\r\n") > 0){
    int r_index = 0;
    for(int i = 0; i < inputs.length(); i++){if(inputs[i] == '\r'){r_index = i;}}
    command_string = inputs.replace(r_index, 2, "");
    }
    //QString command_string = inputs;
    //команды из программы: auth, reg, cars
    if(command_string.count(" ") != 0) // проверка, что в строке вообще есть пробелы
    {
        QString command = command_string.split(" ")[0]; // команда
        int count_of_params = command_string.split(" ").length(); // количество параметров
        // Логин должен иметь 3 параметра
        // Регистрация должен иметь 5 параметра
        // калькулятор машин должен иметь 8 параметров
        // остальное неправильное и возвращается ошибка
        if(command == "auth" && count_of_params == auth_params_const)
        {
        // auth <login> <password>
            QString login = command_string.split(" ")[1];
            QString password = command_string.split(" ")[2];
            return db->auth(login, password);
        }
        else if(command == "reg" && count_of_params == reg_params_const)
        {
        // reg <login> <password> <check_password> <email>
            QString login = command_string.split(" ")[1];
            QString password = command_string.split(" ")[2];
            QString check_password = command_string.split(" ")[3];
            QString email = command_string.split(" ")[4];
            return db->reg(login, password, check_password, email);
        }
        else if(command == "cars" && count_of_params == cars_params_const)
        {
        // cars <0 or 1> <brand> <color> <fuel_volume> <fuel_power> <max_weight> <fuel_price>
            QString car = command_string.split(" ")[1];
            QString brand = command_string.split(" ")[2];
            QString color = command_string.split(" ")[3];
            QString fuel_volume = command_string.split(" ")[4];
            QString fuel_power = command_string.split(" ")[5];
            QString max_weight = command_string.split(" ")[6];
            QString fuel_price = command_string.split(" ")[7];

            if(car == '0'){
                PassengerCar calc(brand, color, fuel_volume, fuel_power);
                return "cars " + calc.Distance_fuel() + " 0";
                //return cars <Distance> <0>
            }
            else if(car == '1'){
                Truck calc(brand, color, fuel_volume, fuel_power, max_weight);
                return "cars " + calc.Distance_fuel() + " " + calc.Price_km(fuel_price);
                //return cars <Distance> <Price/km>
            }
            else{
                return "cars InvalidParams ";
            }
        }
        else{
            return "invalid command ";
        }
    }
    else
    {
        return "invalid request ";
    }
    return "Critical Error ";
}
