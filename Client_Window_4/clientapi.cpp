#include "clientapi.h"

QString COD;

ClientAPI *ClientAPI::p_instance = nullptr;
SingletonDestroyer ClientAPI::destroyer;

SingletonDestroyer::~SingletonDestroyer() {
    delete p_instance;
}

void SingletonDestroyer::initialize(ClientAPI *p) {
    p_instance = p;
}

ClientAPI::ClientAPI(QObject *parent) : QObject(parent) {
    mTcpSocket = new QTcpSocket(this);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &ClientAPI::slotServerDisConnection);
    mTcpSocket->connectToHost("127.0.0.1", 33333);
}

ClientAPI::~ClientAPI() {
    mTcpSocket->close();
}

ClientAPI *ClientAPI::getInstance() {
    if (!p_instance) {
        p_instance = new ClientAPI();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}


bool ClientAPI::isAuthValid(const QString &login, const QString &password) {
    // Формируем запрос для проверки логина и пароля
    QString request = QString("auth %1 %2").arg(login).arg(password);
    QString response = query_to_server(request);
    qDebug() << response;
    // Проверяем ответ от сервера
    if (response.startsWith("auth+")) {
        return true; // Пароль верный
    } else if (response.startsWith("auth-")) {
        return false; // Пароль неверный
    }
    return false; // Ошибка запроса
}

QString ClientAPI::isRegValid(const QString &login, const QString &password, const QString &mail) {

    QByteArray salt = PasswordHasher::generateSalt();
    QByteArray hashedPassword = PasswordHasher::hashPassword(password, salt, 10000); // 10000 итераций для защиты

    QString UserDataAuth = QString("reg %1 %2 %3 %4").arg(login).arg(QString::fromUtf8(hashedPassword)).arg(QString::fromUtf8(salt)).arg(mail);
    QString registration  = query_to_server(UserDataAuth);
    QString error = "";
    QString reg_flag = "";

    qDebug() << registration;
    qDebug() << QString::fromUtf8(hashedPassword);
    qDebug() << QString::fromUtf8(salt);

    if (registration.startsWith("reg+")) {
        return (reg_flag = "reg+"); // Пароль верный
    } else if (registration.startsWith("reg-")) {
        return (reg_flag = "reg-"); // Пароль неверный
    } else if (registration.startsWith("loginNotUNIQ")) {
        return ( error = "loginNotUNIQ"); // Логин неверный
    } else if (registration.startsWith("emailNotUNIQ")) {
        return ( error = "emailNotUNIQ"); // Почтовый адрес неверный
    }
    return "что-то пошло не так...";
}

QString ClientAPI::sendMail(const QString &mail) {

    QString mail_for_cod = QString("repas %1").arg(mail);
    qDebug () << mail_for_cod;
    QString MailUser  = query_to_server(mail_for_cod);
    qDebug () << MailUser;

    QString new_pass_flag = "";

    if (MailUser.startsWith("UserNotExists")) {
        return (new_pass_flag = "cod-");
    } else  {
        COD = MailUser.mid(6);
        return COD; // Пароль неверный
    }
}

void ClientAPI::slotServerDisConnection() {
    mTcpSocket->close();
    emit disconnected();
}

QByteArray ClientAPI::query_to_server(QString msg) {
    if(!mTcpSocket->isOpen()) {
        mTcpSocket->connectToHost("127.0.0.1", 33333);
        if(!mTcpSocket->waitForConnected(3000)) {
            return QByteArray("Connection error");
        }
    }

    mTcpSocket->write(msg.toUtf8());
    mTcpSocket->waitForBytesWritten();

    if (mTcpSocket->waitForReadyRead(30000)) {
        QByteArray response = mTcpSocket->readAll();
        while(mTcpSocket->waitForReadyRead(100)) {
            response += mTcpSocket->readAll();
        }
        return response;
    }
    return QByteArray("Timeout error");
}
