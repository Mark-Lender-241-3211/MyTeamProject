#include "new_pass_form.h"
#include "ui_new_pass_form.h"
#include "authregform.h"
#include "authregform.cpp"
#include "clientapi.h"
#include "functions_to_client.h"

new_pass_form::new_pass_form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::new_pass_form), clientApi(ClientAPI::getInstance())
{
    ui->setupUi(this);

    // Инициализация сцен
    scene2 = new QGraphicsScene(this);
    ui->graphicsView2->setScene(scene2);

    //qDebug() << AuthRegForm::randomValue;
    scene2->clear();

}

new_pass_form::~new_pass_form()
{
    delete ui;
}

void new_pass_form::slot_pass_no_show(QString password) {

    if (AuthRegForm::randomValue == 1) {
        AuthRegForm::loadBackground(ui->graphicsView2, scene2, "D:/TMP/Client_Window/image/27.png");
    } else {
        AuthRegForm::loadBackground(ui->graphicsView2, scene2, "D:/TMP/Client_Window/image/28.png");
    }

    this->show();
    ui->lineEdit_cod->setFocus();
    ui->lineEdit_cod->setText("");
    ui->lineEdit_cod->setVisible(true);
    ui->label_error->setVisible(false);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->pushButton_exit->setVisible(false);
    ui->label_text2->setVisible(true);

    //ui->label_text->setText("Код для восстановления пароля \n отправлен на ваш email!");
    ui->pushButton_continue->setVisible(true);

    //QString generatedCode = generateRandomCode(6); // Генерация случайного кода
    //ui->label_text2->setText("Чтобы продолжить, введите код...");
    //QString mail = ui->lineEdit_mail->text();
    //isCodeGenerated = false;
    // Отправляем код на почту
    //sendEmail(mail, code);
    //ui->label_text2->setText(generatedCode);
    // Сохраняем код в переменной или отправляем его на сервер для дальнейшей проверки
}

void new_pass_form::on_pushButton_continue_clicked()
{
    scene2->clear();
    QString enteredCode = ui->lineEdit_cod->text();

    QString codes = clientApi->COD;

    qDebug () << codes;

    if (enteredCode.isEmpty()) {
        ui->label_error->setVisible(true);
        if (AuthRegForm::randomValue == 1) {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, "D:/TMP/Client_Window/image/31.png");
        } else {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, "D:/TMP/Client_Window/image/32.png");
        }
        //ui->label_error->setText("Введите код."); // Уведомление об ошибке
        return;
    }
    if (enteredCode != codes) {
        ui->label_error->setVisible(true);
        if (AuthRegForm::randomValue == 1) {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, "D:/TMP/Client_Window/image/33.png");
        } else {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, "D:/TMP/Client_Window/image/34.png");
        }
        //ui->label_error->setText("Некорректный код."); // Ошибка
    }
    else {
        // Код верен, продолжайте процесс сброса пароля
        if (AuthRegForm::randomValue == 1) {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, "D:/TMP/Client_Window/image/29.png");
        } else {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, "D:/TMP/Client_Window/image/30.png");
        }
       // ui->label_text->setText("Придумайте новый пароль!");
        ui->lineEdit_cod->setVisible(false);
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
        ui->lineEdit->setVisible(true);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_2->setVisible(true);
        //ui->label_text->setText("Придумайте новый пароль!");
        ui->lineEdit->setFocus();
        ui->label_text2->setVisible(false);
        ui->pushButton_continue->setVisible(false);
        ui->pushButton_exit->setGeometry(400, 480, 161, 61);
        ui->pushButton_exit->setVisible(true);
    }
}

void new_pass_form::on_pushButton_exit_clicked()
{
    scene2->clear();
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty()) {
        if (AuthRegForm::randomValue == 1) {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, "D:/TMP/Client_Window/image/51.png");
        } else {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, "D:/TMP/Client_Window/image/52.png");
        }
        return;
    }
    if (ui->lineEdit->text() != ui->lineEdit_2->text()) {
        ui->label_error->setVisible(true);
        if (AuthRegForm::randomValue == 1) {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, "D:/TMP/Client_Window/image/35.png");
        } else {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, "D:/TMP/Client_Window/image/36.png");
        }
        //ui->label_error->setText("Пароли не совпадают."); // Устанавливаем сообщение об ошибке
        ui->lineEdit_2->setText("");
        ui->lineEdit_2->setFocus(); }
    else {

        QString password = ui->lineEdit->text();

        // Генерируем соль и хешируем пароль
        QByteArray salt = PasswordHasher::generateSalt();
        QByteArray hashedPassword = PasswordHasher::hashPassword(password, salt, 10000); // 10000 итераций для защиты

        // Преобразуем QByteArray в QString перед использованием
        QString UserDataAuth = QString("repas %1 %2").arg(QString::fromUtf8(hashedPassword)).arg(QString::fromUtf8(salt));
        QByteArray repas  = clientApi->query_to_server(UserDataAuth);


        this->close();
        emit pass_ok(password);
    }
}
