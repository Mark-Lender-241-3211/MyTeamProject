#ifndef FUNCTIONS_TO_CLIENT_H
#define FUNCTIONS_TO_CLIENT_H

#include <QString>

bool auth(const QString& login, const QString& password);
bool reg(const QString& login, const QString& password, const QString& mail);

#endif // FUNCTIONS_TO_CLIENT_H
