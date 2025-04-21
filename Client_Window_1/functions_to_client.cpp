#include "functions_to_client.h"

bool auth(QString login, QString password)
{
    //querry to server_app
    if (login == "user" && password == "123") return true;
    else return false;
}

bool reg(QString login, QString password, QString mail)
{
    //querry to server_app to reg and auth
    if (login != "user" || password != "123") return true;
    else return false;
}
