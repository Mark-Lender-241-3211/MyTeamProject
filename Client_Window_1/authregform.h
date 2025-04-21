#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QDialog>
#include "functions_to_client.h"

namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QDialog
{
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();

private slots:
    void on_pushButton_toReg_clicked();

    void on_pushButton_Auth_clicked();

    void on_pushButton_Reg_clicked();

signals:
    void auth_ok(QString);

private:
    Ui::AuthRegForm *ui;
    void change_type_to_reg(bool);
    void clear();
};

#endif // AUTHREGFORM_H
