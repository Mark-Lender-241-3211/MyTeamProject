#include "passwordhasher.h"
#include <QDebug>

QByteArray PasswordHasher::generateSalt(int length) {
    QByteArray salt;
    salt.resize(length);
    QRandomGenerator::global()->fillRange(reinterpret_cast<quint32*>(salt.data()), length / sizeof(quint32));
    return salt.toHex();
}

QByteArray PasswordHasher::hashPassword(const QString& password, const QByteArray& salt, int iterations) {
    QByteArray key(32, 0);
    PKCS5_PBKDF2_HMAC(
        password.toUtf8().constData(), password.length(),
        reinterpret_cast<const unsigned char*>(salt.constData()), salt.size(),
        iterations,
        EVP_sha256(),
        key.size(), reinterpret_cast<unsigned char*>(key.data())
        );
    return key.toHex();
}

bool PasswordHasher::verifyPassword(const QString& password, const QByteArray& storedHash, const QByteArray& salt, int iterations) {
    QByteArray newHash = hashPassword(password, salt, iterations);
    return newHash == storedHash;
}
