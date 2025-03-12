#ifndef CLIENTAPI_H
#define CLIENTAPI_H

#include <QObject>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>


class ClientAPI;

class SingletonDestroyer
{
private:
    ClientAPI * p_instance;
public:
    ~SingletonDestroyer();
    void initialize(ClientAPI * p);
};


class ClientAPI: public QObject
{
    Q_OBJECT

private:
    static ClientAPI * p_instance;
    static SingletonDestroyer destroyer;
     QTcpSocket * mTcpSocket;
protected:
    ClientAPI(QObject *parent = nullptr);
    ~ClientAPI();
    ClientAPI(const ClientAPI& ) = delete;
    ClientAPI& operator = (ClientAPI &) = delete;
    friend class SingletonDestroyer;
public:
    static ClientAPI* getInstance();
//private:
    QByteArray query_to_server(QString);
signals:
    void disconnected();
public slots:
    void slotServerDisConnection();
};

#endif // CLIENTAPI_H
