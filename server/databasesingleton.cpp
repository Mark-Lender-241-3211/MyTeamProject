#include "databasesingleton.h"
using namespace std;
#include <QRegularExpression>
DataBaseSingleton * DataBaseSingleton::p_instance;
DataBaseSingletonDestroyer DataBaseSingleton::destroyer;

DataBaseSingletonDestroyer::~DataBaseSingletonDestroyer()
{
    delete p_instance;
}

void DataBaseSingletonDestroyer::initialize(DataBaseSingleton * p)
{
    p_instance = p;
}

DataBaseSingleton::DataBaseSingleton()
{
    if (!QSqlDatabase::drivers().contains("QSQLITE")) {
        qDebug() << "Драйвер SQLite не доступен!";
        return;
    }

    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("DataBase.db");

    if(!db.open()){
        qDebug()<<db.lastError().text();
    }

    QSqlQuery query(this->db);
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS Users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            login TEXT NOT NULL UNIQUE,
            password TEXT NOT NULL,
            email TEXT NOT NULL UNIQUE
        )
    )";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Ошибка создания таблицы:" << query.lastError().text();
    }
    qDebug() << "База данных подключена";

}

DataBaseSingleton::~DataBaseSingleton()
{
    db.close();
}

DataBaseSingleton* DataBaseSingleton::getInstance(){
    if(!p_instance){
        p_instance = new DataBaseSingleton();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

QString DataBaseSingleton::auth(QString log, QString pas)
{
    if (!this->db.isOpen()) {
        qDebug() << "База данных не открыта!";
        return "DataBaseIsNotOpen";
    }
    QMutexLocker locker(&mutex);
    QSqlQuery query(this->db);

    query.prepare("select * from users where login = :login and password = :password");
    query.bindValue(":login", log);
    query.bindValue(":password", pas);

    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return "QueryIsNotValid";
    }

    if (query.next()) {
        qDebug() << "User " << log << " exists";
        return "auth+ ";
    } else {
        qDebug() << "User " << log << " is not exists";
        return "auth- ";
    }
    return "CriticalError";
}

QString DataBaseSingleton::reg(QString log, QString pas,QString conf_pas, QString email)
{
    if(!isvalidEmail(email)){return "Email is not valid";}
    QMutexLocker locker(&mutex);
    QSqlQuery query(this->db);
    if(log!="\t" && log != "" && pas != "\t" && pas!= "" && pas==conf_pas){
        query.prepare("INSERT INTO Users (login, password, email) VALUES (:login, :password, :email);");
        query.bindValue(":password",pas);
        query.bindValue(":login",log);
        query.bindValue(":email",email);

        if(query.exec()){
            //int index = query.record().indexOf("Role");
            //return "auth+&"+log+"&"+query.value(index).toString();
            query.clear();
            qDebug() << "User has been created";
            return "reg+ ";
        }
        else{
            QString text = query.lastError().text();
            qDebug() << "Query error: " << text;
            if(text[text.indexOf("Users.") + 6] == 'e'){return "emailNotUNIQ";}
            else if(text[text.indexOf("Users.") + 6] == 'l'){return "loginNotUNIQ";}
            return "Error ";
        }
    }
    return "CriticalError reg- ";
}

bool isvalidEmail(QString email)
{
    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionMatch match = regex.match(email);
    return match.hasMatch();
}
