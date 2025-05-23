#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QVector>
#include "databasesingleton.h"
#include "carscalculator.h"

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    QString Parsing(QString);
    QString generateRandomCode(int);
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
private:
    QByteArray Data;
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    QMap<QTcpSocket*, QString> * Socket_Email;
    QVector <QTcpSocket*> Sockets;
    DataBaseSingleton *db;
    void sendEmail(const QString&, const QString&);
    //int server_status;
};
#endif // MYTCPSERVER_H
