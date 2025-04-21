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
