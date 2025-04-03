#include "functions_to_client.h"

bool auth(const QString& login, const QString& password) {
    // Заглушка для авторизации
    return (login == "user" && password == "123");
}
bool auth_p(const QString& password) {
    return (password == "123");
}

bool auth_l(const QString& login) {
    return (login == "user");
}

bool reg(const QString& login, const QString& password, const QString& mail) {
    // Заглушка для регистрации
    return (login != "user" || password != "123");
}
