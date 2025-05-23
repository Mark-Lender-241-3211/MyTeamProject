#ifndef DATABASESINGLETON_H
#define DATABASESINGLETON_H

#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMutex>
#include <passwordhasher.h>
class DataBaseSingleton;

class DataBaseSingletonDestroyer
{
private:
    DataBaseSingleton * p_instance;
public:
    ~DataBaseSingletonDestroyer();
    void initialize(DataBaseSingleton * p);
};


class DataBaseSingleton
{
private:
    static DataBaseSingleton * p_instance;
    static DataBaseSingletonDestroyer destroyer;
    QSqlDatabase db;
protected:
    DataBaseSingleton();
    DataBaseSingleton(const DataBaseSingleton&) = delete;
    DataBaseSingleton& operator = (DataBaseSingleton&) = delete;
    ~DataBaseSingleton();
    friend class DataBaseSingletonDestroyer;
public:
    static DataBaseSingleton* getInstance();
    QString auth(QString, QString);
    QString reg(QString, QString,QString, QString);
    QString repas(QString, QString, QString);
    QString checkUser(QString);
};
bool isvalidEmail(QString);
#endif // DATABASESINGLETON_H
