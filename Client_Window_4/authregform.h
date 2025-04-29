#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QDialog>
#include <QGraphicsScene>  // Добавлен include для QGraphicsScene
#include "functions_to_client.h"
#include "clientapi.h"
#include "passwordhasher.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QSsl>
#include <QUrl>
#include <QSslSocket>
#include <QCoreApplication>
#include <QDebug>
#include <QByteArray>

namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QDialog {
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();
    QString getLineEditText() const; // Метод для замены пароля
    static int randomValue;
    static void loadBackground(QGraphicsView* view, QGraphicsScene* scene, const QString& imagePath);  // Добавлен метод для загрузки фона

public slots:
    void slot_auth_reg_show(QString);

private slots:
    void on_pushButton_toReg_clicked();
    void on_pushButton_Auth_clicked();
    void on_pushButton_Reg_clicked();
    void on_pushButton_new_password_clicked();
    void on_pushButton_pass_new_clicked();

signals:
    void reg_ok(QString);
    void auth_ok(QString);
    void pass_no(QString);

private:
    Ui::AuthRegForm *ui;
    ClientAPI *clientApi; // Указатель на ClientAPI
    QGraphicsScene *scene;  // Добавлен указатель на сцену

    void change_type_to_reg(bool);
    void clear();
    bool isvalidEmail(QString email);

    int authAttempts; // Счетчик неудачных попыток авторизации
    int toRegAttempts; // Счетчик неудачных попыток авторизации
};

#endif // AUTHREGFORM_H
