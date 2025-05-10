#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include<QString>
#include <QRandomGenerator>
MyTcpServer::~MyTcpServer()
{
    delete[] Socket_Email;
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
    qDebug() << "Database address: " << this->db;
    Socket_Email = new QMap<QTcpSocket*, QString>;
}

void MyTcpServer::slotNewConnection(){
    mTcpSocket = mTcpServer->nextPendingConnection();
    connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
    connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);

    Sockets.push_back(mTcpSocket);
}

void MyTcpServer::slotServerRead(){

    QTcpSocket* senderSocket = qobject_cast<QTcpSocket*>(sender());
    if (!senderSocket) return; // проверка, dynamic cast сработал или нет
    QString res = "";
    while(senderSocket->bytesAvailable()>0)
    {
        QByteArray array =senderSocket->readAll();
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
void MyTcpServer::slotClientDisconnected() {
    QTcpSocket* disconnectedSocket = qobject_cast<QTcpSocket*>(sender());
    if (!disconnectedSocket){
        Sockets.remove(Sockets.indexOf(disconnectedSocket));
        return;
    }
    Sockets.remove(Sockets.indexOf(disconnectedSocket));
    disconnectedSocket->close();
}

QString MyTcpServer::Parsing(QString inputs)
{
    QString command_string = inputs;
    //строка inputs это строка с параметрами, по которым сервер определяет что отправить клиенту обратно
    //константы параметров для команд
    const int auth_params_const = 3;
    const int reg_params_const = 5;
    const int cars_params_const = 8;
    //Для среза "\r\n";
    if(inputs.indexOf("\r\n") > 0){
    int r_index = 0;
    for(int i = 0; i < inputs.length(); i++){if(inputs[i] == '\r'){r_index = i;}}
    command_string = inputs.replace(r_index, 2, "");
    }
    QTcpSocket * sendSock = qobject_cast<QTcpSocket*>(sender());
    qDebug() <<Sockets.indexOf(sendSock) <<":"<<inputs;
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
        // reg <login> <hache_password> <salt> <email>
            QString login = command_string.split(" ")[1];
            QString password = command_string.split(" ")[2];
            QString salt = command_string.split(" ")[3];
            QString email = command_string.split(" ")[4];
            return db->reg(login, password, salt, email);
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

            if(car == '1'){
                PassengerCar calc(brand, color, fuel_volume, fuel_power);
                return "cars " + calc.Distance_fuel() + " " +  calc.Price_for_full_tank(fuel_price) + " nan";
                //return cars <Distance> <PriceFullTank> <0>
            }
            else if(car == '0'){
                Truck calc(brand, color, fuel_volume, fuel_power, max_weight);
                return "cars " + calc.Distance_fuel() + " " +  calc.Price_for_full_tank(fuel_price)  + " " + calc.Price_km(fuel_price);
                //return cars <Distance> <PriceFullTank> <Price/km>
            }
            else{
                return "cars InvalidParams";
            }
        }
        else if(command == "repas")
        {
            //repas <login>
            if(count_of_params == 2)
            {
                QString login = command_string.split(" ")[1];
                QString email = this->db->checkUser(login);
                if(email == ""){return "UserNotExists";}
                QTcpSocket* senderSocket = qobject_cast<QTcpSocket*>(sender());
                Socket_Email->insert(senderSocket, email);

                QString code = generateRandomCode(6); // Генерация кода
                std::thread([this, email, code]() {// параллельный процесс
                    this->sendEmail(email, code); // высылается на почту
                }).detach();
                return "repas " + code;
            }

            //<repas> <cache> <salt>
            else if(count_of_params == 3)
            {
                QTcpSocket* senderSocket = qobject_cast<QTcpSocket*>(sender());
                QString SocketEmail = Socket_Email->take(senderSocket);
                QString pas = command_string.split(" ")[1];
                QString salt = command_string.split(" ")[2];
                Socket_Email->remove(senderSocket);
                return db->repas(SocketEmail, pas, salt);
            }
        }//checkUser <email>
        else if(command == "checkUser") // так чисто по приколу
        {
            return db->checkUser(command_string.split(" ")[1]);
        }
        else{
            return "invalid command";
        }
    }
    else
    {
        return "invalid request";
    }
    return "Critical Error";
}

void MyTcpServer::sendEmail(const QString &to, const QString &code) {
    QSslSocket socket;
    // Подключаемся с SSL
    socket.connectToHostEncrypted("smtp.mail.ru", 465);
    if (!socket.waitForEncrypted(3000)) {
        qDebug() << "SSL handshake failed:" << socket.errorString();
        return;
    }

    // Функция для отправки команд
    auto write = [&](const QString &data) {
        socket.write((data + "\r\n").toUtf8());
        if (!socket.waitForBytesWritten(3000)) {
            qDebug() << "Write failed:" << socket.errorString();
            return false;
        }
        if (!socket.waitForReadyRead(3000)) {
            qDebug() << "No response:" << socket.errorString();
            return false;
        }
        return true;
    };

    // Правильная SMTP-сессия с SSL
    write("EHLO example.com");
    write("AUTH LOGIN");
    write(QByteArray("car_specific@mail.ru").toBase64());
    write(QByteArray("j7p7JJWPwvPYZbkc01va").toBase64());
    write("MAIL FROM: <car_specific@mail.ru>");
    write("RCPT TO: <" + to + ">");
    write("DATA");
    write("From: Cars Specific <car_specific@mail.ru>");
    write("To: " + to);
    write("Subject: Verification Code");
    write("");
    write("Your verification code: " + code);
    write(".");
    write("QUIT");
}

QString MyTcpServer::generateRandomCode(int length) {
    const QString characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    QString randomString;
    for (int i = 0; i < length; ++i) {
        int index = QRandomGenerator::global()->bounded(characters.length());
        randomString.append(characters[index]);
    }
    return randomString;
}
