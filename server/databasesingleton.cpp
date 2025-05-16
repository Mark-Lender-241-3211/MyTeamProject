#include "databasesingleton.h"
using namespace std;
#include <QRegularExpression>
#include <QCoreApplication>
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
    QCoreApplication::addLibraryPath("plugins");
    if (!QSqlDatabase::drivers().contains("QSQLITE")) {
        qDebug() << "Driver SQLite not avalible!";
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
            salt TEXT NOT NULL,
            email TEXT NOT NULL UNIQUE
        )
    )";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Create table error:" << query.lastError().text();
    }
    qDebug() << "Database is connected!";

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
        qDebug() << "Database do not open!";
        return "DataBaseIsNotOpen";
    }
    QSqlQuery query(this->db);

    query.prepare("select password, salt from users where login = :login");
    query.bindValue(":login", log);

    if (!query.exec()) {
        qDebug() << "Query exec error:" << query.lastError().text();
        return "QueryIsNotValid";
    }
    QByteArray hache;
    QByteArray salt;
    while (query.next()) {
        hache = query.value(0).toByteArray();
        salt = query.value(1).toByteArray();
    }
    if(PasswordHasher::verifyPassword(pas, hache, salt, 10000)){return "auth+";}
    else {return "auth-";}
    return "auth CriticalError";
}

QString DataBaseSingleton::reg(QString log,QString pas, QString salt, QString email)
{
    //if(!isvalidEmail(email)){return "Email is not valid";}
    QSqlQuery query(this->db);
    if(log!="\t" && log != "" && pas != "\t" && pas!= ""){
        query.prepare("INSERT INTO Users (login, password, salt, email) VALUES (:login, :password, :salt, :email);");
        query.bindValue(":password",pas);
        query.bindValue(":salt", salt);
        query.bindValue(":login",log);
        query.bindValue(":email",email);

        if(query.exec()){
            //int index = query.record().indexOf("Role");
            //return "auth+&"+log+"&"+query.value(index).toString();
            query.clear();
            qDebug() << "User has been created";
            return "reg+";
        }
        else{
            QString text = query.lastError().text();
            qDebug() << "Query error: " << text;
            if(text[text.indexOf("Users.") + 6] == 'l'){return "loginNotUNIQ";}
            else if(text[text.indexOf("Users.") + 6] == 'e'){return "emailNotUNIQ";}
            return "reg-";
        }
    }
    return "reg CriticalError";
}
QString DataBaseSingleton::repas(QString email, QString hache, QString salt)
{
    QSqlQuery query(this->db);
    query.prepare("update users set password = :hache, salt = :salt where email = :email");
    query.bindValue(":hache",hache);
    query.bindValue(":salt", salt);
    query.bindValue(":email",email);
    if (!query.exec()) {
        qDebug() << "Query exec error:" << query.lastError().text();
        return "QueryIsNotValid";
    }
    return "repas+";
}

QString DataBaseSingleton::checkUser(QString login)
{
    QSqlQuery query(this->db);
    query.prepare("select email from users where login = :login");
    query.bindValue(":login", login);
    if(!query.exec()){
        qDebug() << "Query exec error:" << query.lastError().text();
        return "QueryIsNotValid";
    }
    QString email;
    while (query.next()) {
        email = query.value(0).toByteArray();
    }
    // если возвращает пустую строку то такого пользователя с такой почтой нет
    return email;
}

bool isvalidEmail(QString email)
{
    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@(gmail\\.com|mail\\.ru|yandex\\.ru)$");
    QRegularExpressionMatch match = regex.match(email);
    return match.hasMatch();
}
