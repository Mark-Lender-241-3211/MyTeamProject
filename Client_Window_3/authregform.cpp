#include "authregform.h"
#include "ui_authregform.h"

AuthRegForm::AuthRegForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthRegForm)
    , clientApi(ClientAPI::getInstance())
    , authAttempts(0) // Инициализация счетчика попыток
{
    ui->setupUi(this);
    change_type_to_reg(false);
    ui->label_error->setVisible(false); // Скрываем сообщение об ошибке
    ui->pushButton_new_password->setVisible(false); // Скрываем кнопку "Забыли пароль?"
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
    ui->label_error->setText("");
    change_type_to_reg(!ui->label_mail->isVisible());
    ui->lineEdit_login->setText("");
    ui->lineEdit_password->setText("");
}

void AuthRegForm::on_pushButton_Auth_clicked() {
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    // Проверяем, существует ли логин
    if (!auth_l(login)) {
    //if (!clientApi->isLoginValid(login)) { // Предполагается, что у вас есть метод для проверки логина
        ui->label_error->setVisible(true);
        ui->label_error->setText("Логин неверный."); // Сообщение об ошибке для логина
        ui->lineEdit_login->setText("");
        ui->lineEdit_password->setText("");
        authAttempts++;
        ui->lineEdit_login->setFocus(); // Устанавливаем фокус на поле логина
    } else {
        // Если логин верный, проверяем пароль
        if (!auth_p(password)) {
        //if (!clientApi->isPasswordValid(login, password))    {
            ui->label_error->setVisible(true);
            ui->label_error->setText("Пароль неверный."); // Сообщение об ошибке для пароля
            ui->lineEdit_password->setText("");
            authAttempts++;
            ui->lineEdit_password->setFocus(); // Устанавливаем фокус на поле пароля
        } else {
            // Если логин и пароль верные
            emit auth_ok(login);
            QString UserDataAuth = QString("auth %1 %2").arg(login).arg(password);
            QByteArray authorization = clientApi->query_to_server(UserDataAuth);
            this->close();
        }
    }

    if (authAttempts >= 3) {
        ui->pushButton_new_password->setVisible(true); // Показываем кнопку "Забыли пароль?"
    }
}


void AuthRegForm::clear() {
    ui->lineEdit_login->setText("");
    ui->lineEdit_password->setText("");
    ui->lineEdit_passwordcheck->setText("");
    ui->lineEdit_mail->setText("");
}

bool AuthRegForm::isvalidEmail(QString email) {
    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionMatch match = regex.match(email);
    return match.hasMatch();
}

void AuthRegForm::on_pushButton_Reg_clicked() {

    // Проверяем, заполнены ли все поля и совпадают ли пароли
    if (ui->lineEdit_password->text().isEmpty() ||
        ui->lineEdit_login->text().isEmpty() ||
        ui->lineEdit_mail->text().isEmpty()) {
        ui->label_error->setVisible(true);
        ui->label_error->setText("Пожалуйста, заполните все поля."); // Устанавливаем сообщение об ошибке
    } else if (ui->lineEdit_password->text() != ui->lineEdit_passwordcheck->text()) {
        ui->label_error->setVisible(true);
        ui->label_error->setText("Пароли не совпадают.");  // Устанавливаем сообщение об ошибке
        ui->lineEdit_passwordcheck->setText("");
    } else if (!isvalidEmail(ui->lineEdit_mail->text())) // Проверка email через функцию
    {
        ui->label_error->setVisible(true);
        ui->label_error->setText("Некорректный email.");
    }
    else {
        emit reg_ok(ui->lineEdit_login->text());

        QString login = ui->lineEdit_login->text();
        QString password = ui->lineEdit_password->text();
        QString passwordcheck = ui->lineEdit_passwordcheck->text();
        QString mail = ui->lineEdit_mail->text();
        QString UserDataReg = QString("reg %1 %2 %3 %4").arg(login).arg(password).arg(passwordcheck).arg(mail);
        QByteArray registration = clientApi->query_to_server(UserDataReg);
        this->close();
    }
}
