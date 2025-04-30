#include "authregform.h"
#include "ui_authregform.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QCoreApplication>
#include <QSslSocket>
#include <QByteArray>

int AuthRegForm::randomValue = QRandomGenerator::global()->bounded(1, 3);

AuthRegForm::AuthRegForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthRegForm)
    , clientApi(ClientAPI::getInstance())
    , authAttempts(0)
    , toRegAttempts(0)
{
    ui->setupUi(this);
    // Инициализация сцены (правильный способ)
    scene = new QGraphicsScene(this);  // scene теперь член класса
    ui->graphicsView->setScene(scene);

    change_type_to_reg(false);
    ui->label_error->setVisible(false);
    ui->pushButton_new_password->setVisible(false);
    ui->pushButton_pass_new->setVisible(false);
    ui->lineEdit_login->setFocus();

    // Загрузка первого фона
    if (randomValue == 1) {
        loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/1.png"); }
    else {
        loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/2.png");
    }
}

// Добавляем новый метод для загрузки фона
void AuthRegForm::loadBackground(QGraphicsView* view, QGraphicsScene* scene, const QString& imagePath) {
    QPixmap background(imagePath);
    if(background.isNull()) return;

    scene->clear();
    scene->addPixmap(background);
    view->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

void AuthRegForm::on_pushButton_toReg_clicked() {
    toRegAttempts++;
    qDebug() << randomValue;

    ui->label_error->setText("");
    change_type_to_reg(!ui->label_mail->isVisible());
    ui->lineEdit_login->setText("");
    ui->lineEdit_password->setText("");
    ui->pushButton_new_password->setVisible(false);
    ui->lineEdit_login->setFocus();
    // Упрощенная смена фона
    if (toRegAttempts % 2 != 0) {
        if (randomValue  == 1) {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/7.png"); }
        else {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/8.png");
        }

        ui->label_login->setGeometry(60, 180, 131, 41);
        ui->label_password->setGeometry(70, 230, 111, 51);
        ui->label_passwordcheck->setGeometry(60, 290, 131, 41);
        ui->lineEdit_passwordcheck->setGeometry(210, 290, 391, 31);
        ui->lineEdit_password->setGeometry(210, 240, 381, 31);
        ui->lineEdit_login->setGeometry(210, 190, 391, 31);


        ui->pushButton_toReg->setGeometry(130, 610, 141, 51);
        ui->pushButton_Reg->setGeometry(470, 640, 291, 51);
        ui->label_mail->setVisible(true);
        ui->lineEdit_mail->setVisible(true);
    } else {
        if (randomValue  == 1) {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/1.png"); }
        else {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/2.png");
        }
        ui->pushButton_toReg->setGeometry(470, 640, 291, 51);
        ui->pushButton_Reg->setVisible(false);
        ui->label_login->setGeometry(70, 230, 111, 51);
        ui->label_password->setGeometry(60, 290, 131, 41);
        ui->lineEdit_login->setGeometry(210, 240, 381, 31);
        ui->lineEdit_password->setGeometry(210, 290, 391, 31);
    }
}


void AuthRegForm::change_type_to_reg(bool is_reg) {
    ui->label_passwordcheck->setVisible(is_reg);
    ui->label_mail->setVisible(is_reg);
    ui->lineEdit_passwordcheck->setVisible(is_reg);
    ui->lineEdit_mail->setVisible(is_reg);
    ui->pushButton_Reg->setVisible(is_reg);

    ui->pushButton_Auth->setVisible(!is_reg);
    //ui->pushButton_toReg->setText(is_reg ? "Назад" : "Регистрация");
}

AuthRegForm::~AuthRegForm() {
    delete ui;
}

void AuthRegForm::slot_auth_reg_show(QString login) {
    this->show();
}

void AuthRegForm::on_pushButton_Auth_clicked() {
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    // Проверяем, существует ли пользователь
    if (!clientApi->isAuthValid(login, password))    {
            ui->label_error->setVisible(true);
        if (randomValue  == 1) {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/3.png"); }
        else {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/4.png");
        }
            //ui->label_error->setText("Неверный логин или пароль!"); // Сообщение об ошибке для пароля
            ui->lineEdit_password->setText("");
            ui->lineEdit_login->setText("");
            authAttempts++;
            ui->lineEdit_login->setFocus(); // Устанавливаем фокус на поле пароля
        }
    else {
            // Если логин и пароль верные
            emit auth_ok(login);
            this->close();
        }

    if (authAttempts >= 2) {
            if (randomValue  == 1) {
                loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/5.png"); }
            else {
                loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/6.png");
            }
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
    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@(gmail\\.com|mail\\.ru|yandex\\.ru)$");
    QRegularExpressionMatch match = regex.match(email);
    return match.hasMatch();
}


void AuthRegForm::on_pushButton_Reg_clicked() {

    QByteArray testRequest = "test";
    clientApi->query_to_server(testRequest);

    if (clientApi->query_to_server(testRequest) == "Timeout error") {
        ui->label_error->setVisible(true);
        ui->label_error->setText("Сервер недоступен! Попробуйте позже.");
        return;
    }

    // Проверяем, заполнены ли все поля и совпадают ли пароли
    ui->lineEdit_login->setFocus();
    if (ui->lineEdit_password->text().isEmpty() ||
        ui->lineEdit_login->text().isEmpty() ||
        ui->lineEdit_mail->text().isEmpty()) {
        ui->label_error->setVisible(true);
        if (randomValue  == 1) {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/9.png"); }
        else {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/10.png");
        }
        //ui->label_error->setText("Пожалуйста, заполните все поля!"); // Устанавливаем сообщение об ошибке
    } else if (ui->lineEdit_password->text() != ui->lineEdit_passwordcheck->text()) {
        ui->label_error->setVisible(true);
        if (randomValue  == 1) {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/11.png"); }
        else {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/12.png");
        }
        //ui->label_error->setText("Пароли не совпадают!");  // Устанавливаем сообщение об ошибке
        ui->lineEdit_passwordcheck->setText("");
        ui->lineEdit_passwordcheck->setFocus();
    } else if (!isvalidEmail(ui->lineEdit_mail->text())) // Проверка email через функцию
    {
        ui->label_error->setVisible(true);
        if (randomValue  == 1) {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/13.png"); }
        else {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/14.png");
        }
        //ui->label_error->setText("Некорректный email!");
        ui->lineEdit_mail->setText("");
        ui->lineEdit_mail->setFocus();
    }
    else {
        QString login = ui->lineEdit_login->text();
        QString mail = ui->lineEdit_mail->text();
        QString password = ui->lineEdit_password->text();

        qDebug() << login << password;

        if ((clientApi->isRegValid(login, password, mail)) == "reg+") {
            ui->lineEdit_passwordcheck->setText("");
            ui->lineEdit_mail->setText("");
            ui->pushButton_toReg->click();
        } else if ((clientApi->isRegValid(login, password, mail)) == "loginNotUNIQ"){
            ui->lineEdit_login->setText("");
            if (randomValue == 1) {
                loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/15.png"); }
            else {
                loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/16.png");
            }
            //ui->label_error->setText("Пользователь уже зарегистрирован! \n Придумайте новый логин !");
        } else if ((clientApi->isRegValid(login, password, mail)) == "emailNotUNIQ"){
            ui->lineEdit_mail->setText("");
            if (randomValue  == 1) {
                loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/17.png"); }
            else {
                loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/18.png");
            }
            //ui->label_error->setText("Данный email уже занят!");
        }
        else { ui->label_error->setText("Ошибка регистрации! Попробуйте снова..."); }
    }
}

void AuthRegForm::on_pushButton_new_password_clicked() {
    // Обработка функции "Забыли пароль?"
    //emit pass_no(ui->lineEdit_password->text());
    ui->lineEdit_mail->setGeometry(210, 240, 381, 31);
    ui->label_login->setVisible(false);
    ui->label_passwordcheck->setVisible(false);
    ui->label_password->setVisible(false);
    ui->label_mail->setVisible(true);
    ui->lineEdit_login->setVisible(false);
    ui->lineEdit_password->setVisible(false);
    ui->lineEdit_passwordcheck->setVisible(false);
    ui->lineEdit_mail->setVisible(true);
    ui->lineEdit_mail->setText("");
    ui->lineEdit_mail->setFocus();
    ui->pushButton_Reg->setVisible(false);
    ui->pushButton_Auth->setVisible(false);
    ui->pushButton_toReg->setVisible(false);
    ui->label_error->setVisible(false);
    ui->pushButton_new_password->setVisible(false);

    //ui->label_one->setAlignment(Qt::AlignCenter);
    //ui->label_one->setText("Введите почту, чтобы получить \n    код для сброса пароля!");

    ui->pushButton_pass_new->setVisible(true);
    ui->label_mail->setGeometry(70, 230, 111, 51);
    if (randomValue  == 1) {
        loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/19.png"); }
    else {
        loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/20.png");
    }

    //QMessageBox::information(this, "Восстановление пароля", "Ссылка на восстановление пароля отправлена на ваш email.");
}

void AuthRegForm::on_pushButton_pass_new_clicked()
{
    if (!isvalidEmail(ui->lineEdit_mail->text())) // Проверка email через функцию
    {
        ui->label_error->setVisible(true);
        if (randomValue  == 1) {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/21.png"); }
        else {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/22.png");
        }
        //ui->label_error->setText("Некорректный email.");
        ui->lineEdit_mail->setText("");
        ui->label_mail->setFocus();
    }
    else {
        // Первая смена фона
        if (randomValue  == 1) {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/25.png"); }
        else {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/26.png");
        }

        // Ждем 2 секунды перед проверкой почты
        QEventLoop loop;
        QTimer::singleShot(2000, &loop, &QEventLoop::quit);
        loop.exec();

        QString mail = ui->lineEdit_mail->text();
        if ((clientApi->sendMail(mail)) == "cod-") {
            // Вторая смена фона после проверки
            if (randomValue  == 1) {
                loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/23.png"); }
            else {
                loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/24.png"); }
        }
            //ui->label_error->setText("Пользователя с такой почтой не найдено!"); }
        else {

        //ui->label_one->setText("    Добро пожаловать в наше приложение!\n       Чтобы продолжить, \n авторизируйтесь или пройдите регистрацию!");
        ui->label_error->setVisible(false);
        ui->label_login->setVisible(true);
        ui->label_password->setVisible(true);
        ui->label_passwordcheck->setVisible(false);
        ui->label_mail->setVisible(false);
        ui->lineEdit_login->setText("");


        ui->lineEdit_login->setVisible(true);
        ui->lineEdit_mail->setVisible(false);
        ui->lineEdit_password->setVisible(true);
        ui->lineEdit_passwordcheck->setVisible(false);
        ui->pushButton_pass_new->setVisible(false);

        ui->pushButton_Auth->setVisible(true);
        ui->pushButton_toReg->setVisible(true);
        //ui->pushButton_toReg->setText(true ? "Регистрация" : "Назад");
        ui->pushButton_Reg->setVisible(false);

        this->close();
        emit pass_no(ui->lineEdit_password->text());
        ui->lineEdit_mail->setText("");
        ui->lineEdit_mail->setGeometry(210, 350, 391, 21);
        if (randomValue  == 1) {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/1.png"); }
        else {
            loadBackground(ui->graphicsView, scene, "D:/TMP/Client_Window/image/2.png"); }
        }
        //QMessageBox::information(this, "Восстановление пароля", "Ссылка на восстановление пароля отправлена на ваш email.");
    }
}
