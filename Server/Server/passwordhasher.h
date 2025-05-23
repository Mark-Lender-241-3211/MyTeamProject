#ifndef PASSWORDHASHER_H
#define PASSWORDHASHER_H

#include <QByteArray>
#include <QString>
#include <QRandomGenerator>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <QDebug>
class PasswordHasher {
public:
    static QByteArray generateSalt(int length = 4);
    static QByteArray hashPassword(const QString& password, const QByteArray& salt, int iterations = 100000);
    static bool verifyPassword(const QString& password, const QByteArray& storedHash, const QByteArray& salt, int iterations = 100000);
};

#endif // PASSWORDHASHER_H
