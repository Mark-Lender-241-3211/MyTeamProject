#include <QCoreApplication>
#include "clientapi.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<ClientAPI::getInstance()->query_to_server("AAAAAAAAAAA");
    return a.exec();
}
