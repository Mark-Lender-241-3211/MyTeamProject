#include "clientapi.h"

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

bool ClientAPI::isLoginValid(const QString &login) {
    // Формируем запрос для проверки существования логина
    QString request = QString("auth %1 dummyPassword").arg(login);
    QByteArray response = query_to_server(request);

    // Проверяем ответ от сервера
    if (response.startsWith("auth+")) {
        return true; // Логин существует
    } else if (response.startsWith("auth-")) {
        return false; // Логин не существует
    }
    return false; // Ошибка запроса
}

bool ClientAPI::isPasswordValid(const QString &login, const QString &password) {
    // Формируем запрос для проверки логина и пароля
    QString request = QString("auth %1 %2").arg(login).arg(password);
    QByteArray response = query_to_server(request);

    // Проверяем ответ от сервера
    if (response.startsWith("auth+")) {
        return true; // Пароль верный
    } else if (response.startsWith("auth-")) {
        return false; // Пароль неверный
    }
    return false; // Ошибка запроса
}

void ClientAPI::slotServerDisConnection() {
    mTcpSocket->close();
    emit disconnected();
}

QByteArray ClientAPI::query_to_server(QString msg) {
    mTcpSocket->write(msg.toUtf8());
    if (mTcpSocket->waitForReadyRead(5000)) {
        return mTcpSocket->readAll();
    }
    return QByteArray();
}
