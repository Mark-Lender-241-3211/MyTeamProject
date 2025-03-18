#include "authregform.h"
#include "ui_authregform.h"

AuthRegForm::AuthRegForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthRegForm)
{
    ui->setupUi(this);
    change_type_to_reg(false);
}

void AuthRegForm::change_type_to_reg(bool is_reg) {
    ui->label_passwordcheck->setVisible(is_reg);
    ui->label_mail->setVisible(is_reg);
    ui->lineEdit_passwordcheck->setVisible(is_reg);
    ui->lineEdit_mail->setVisible(is_reg);
    ui->pushButton_Reg->setVisible(is_reg);

    ui->pushButton_Auth->setVisible(!is_reg);
    ui->pushButton_toReg->setText(is_reg ? "Назад" : "Регистрация");
}

AuthRegForm::~AuthRegForm() {
    delete ui;
}

void AuthRegForm::on_pushButton_toReg_clicked() {
    change_type_to_reg(!ui->label_mail->isVisible());
}

void AuthRegForm::on_pushButton_Auth_clicked() {
    if (auth(ui->lineEdit_login->text(), ui->lineEdit_password->text())) {
        emit auth_ok(ui->lineEdit_login->text());
        this->close();
    } else {
        clear();
    }
}

void AuthRegForm::clear() {
    ui->lineEdit_login->setText("");
    ui->lineEdit_password->setText("");
    ui->lineEdit_passwordcheck->setText("");
    ui->lineEdit_mail->setText("");
}

void AuthRegForm::on_pushButton_Reg_clicked() {
    if (ui->lineEdit_password->text() != ui->lineEdit_passwordcheck->text() || ui->lineEdit_password->text() == "" || ui->lineEdit_login->text() == "" ||
        ui->lineEdit_mail->text() == "") {
        clear();
    } else {
        if (reg(ui->lineEdit_login->text(),
                ui->lineEdit_password->text(),
                ui->lineEdit_mail->text())) {
            emit reg_ok(ui->lineEdit_login->text());
            this->close();
        } else {
            clear();
        }
    }
}
