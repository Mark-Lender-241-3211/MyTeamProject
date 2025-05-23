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
    reconnectTimer = new QTimer(this);
    reconnectTimer->setInterval(2000);
    reconnectTimer->setSingleShot(false);

    connect(mTcpSocket, &QTcpSocket::connected, reconnectTimer, &QTimer::stop);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &ClientAPI::slotServerDisConnection);
    connect(reconnectTimer, &QTimer::timeout, this, &ClientAPI::tryConnectToServer);

    tryConnectToServer();
}
void ClientAPI::tryConnectToServer() {
    if (mTcpSocket->state() == QAbstractSocket::UnconnectedState) {
        mTcpSocket->abort();
        mTcpSocket->connectToHost("127.0.0.1", 33333);
    }
    if (!reconnectTimer->isActive()) {
        reconnectTimer->start();
    }
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
    QString request = QString("auth %1 %2").arg(login).arg(password);
    QString response = query_to_server(request);
    if (response.startsWith("auth+")) {
        return true;
    } else if (response.startsWith("auth-")) {
        return false;
    }
    return false;
}

QString ClientAPI::isRegValid(const QString &login, const QString &password, const QString &mail) {

    QByteArray salt = PasswordHasher::generateSalt();
    QByteArray hashedPassword = PasswordHasher::hashPassword(password, salt, 10000);

    QString UserDataAuth = QString("reg %1 %2 %3 %4").arg(login).arg(QString::fromUtf8(hashedPassword)).arg(QString::fromUtf8(salt)).arg(mail);
    QString registration  = query_to_server(UserDataAuth);
    QString error = "";
    QString reg_flag = "";

    if (registration.startsWith("reg+")) {
        return (reg_flag = "reg+");
    } else if (registration.startsWith("reg-")) {
        return (reg_flag = "reg-");
    } else if (registration.startsWith("loginNotUNIQ")) {
        return ( error = "loginNotUNIQ");
    } else if (registration.startsWith("emailNotUNIQ")) {
        return ( error = "emailNotUNIQ");
    }
    return "что-то пошло не так...";
}

QString ClientAPI::sendMail(const QString &login) {

    QString mail_for_cod = QString("repas %1").arg(login);
    QString MailUser  = query_to_server(mail_for_cod);
    QString new_pass_flag = "";
    if (MailUser.startsWith("UserNotExists")) {
        return (new_pass_flag = "cod-");
    } else  {
        COD = MailUser.mid(6);
        return COD;
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
