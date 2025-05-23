#ifndef CLIENTAPI_H
#define CLIENTAPI_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include "passwordhasher.h"

class ClientAPI;

class SingletonDestroyer {
private:
    ClientAPI *p_instance;
public:
    ~SingletonDestroyer();
    void initialize(ClientAPI *p);
};

class ClientAPI : public QObject {
    Q_OBJECT

private:
    static ClientAPI *p_instance;
    static SingletonDestroyer destroyer;
    QTcpSocket *mTcpSocket;
    QTimer *reconnectTimer;
    void tryConnectToServer();

protected:
    ClientAPI(QObject *parent = nullptr);
    ~ClientAPI();
    ClientAPI(const ClientAPI&) = delete;
    ClientAPI& operator=(ClientAPI&) = delete;
    friend class SingletonDestroyer;

public:
    static ClientAPI* getInstance();
    QByteArray query_to_server(QString);
    QString COD;
    bool isAuthValid(const QString &login, const QString &password);
    QString isRegValid(const QString &login, const QString &password, const QString &mail);
    QString sendMail(const QString &mail);

signals:
    void disconnected();

public slots:
    void slotServerDisConnection();
};

#endif // CLIENTAPI_H
