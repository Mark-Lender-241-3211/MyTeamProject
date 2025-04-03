#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QDialog>
#include "functions_to_client.h"
#include "clientapi.h"

namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QDialog {
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();

private slots:
    void on_pushButton_toReg_clicked();
    void on_pushButton_Auth_clicked();
    void on_pushButton_Reg_clicked();

signals:
    void reg_ok(QString);
    void auth_ok(QString);

private:
    Ui::AuthRegForm *ui;
    ClientAPI *clientApi;        // Указатель на ClientAPI
    void change_type_to_reg(bool);
    void clear();
    bool isvalidEmail(QString email);
    int authAttempts;            // Счетчик неудачных попыток авторизации
};

#endif // AUTHREGFORM_H
