#include "new_pass_form.h"
#include "ui_new_pass_form.h"
#include "authregform.h"
#include "authregform.cpp"
#include "clientapi.h"

new_pass_form::new_pass_form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::new_pass_form), clientApi(ClientAPI::getInstance())
{
    ui->setupUi(this);
    scene2 = new QGraphicsScene(this);
    setWindowTitle("CarSpecific");
    ui->graphicsView2->setScene(scene2);
    scene2->clear();
    ui->lineEdit->setMaxLength(10);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setMaxLength(10);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->pushButton_showPassword->setVisible(false);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->graphicsView2->viewport()->installEventFilter(this);

    closeButton = new QPushButton("✕", this);
    closeButton->setStyleSheet(
        "QPushButton {"
        "   color: white;"
        "   background-color: rgba(173, 216, 230, 150);"
        "   border-radius: 12px;"
        "   font-size: 18px;"
        "   font-weight: bold;"
        "   min-width: 24px;"
        "   min-height: 24px;"
        "}"
        "QPushButton:hover {"
        "   background-color: rgba(255, 85, 85, 200);"
        "}"
        );
    closeButton->setFixedSize(28, 28);
    closeButton->move(920, 12);
    connect(closeButton, &QPushButton::clicked, this, &QDialog::close);

    m_mousePressed = false;

    ui->pushButton_showPassword->setVisible(false);
    ui->pushButton_showPassword->setCheckable(true);
    connect(ui->pushButton_showPassword, &QPushButton::toggled,
            this, &new_pass_form::togglePasswordVisibility);
}

bool new_pass_form::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->graphicsView2->viewport()) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        switch (event->type()) {
        case QEvent::MouseButtonPress:
            mousePressEvent(mouseEvent);
            return true;
        case QEvent::MouseMove:
            mouseMoveEvent(mouseEvent);
            return true;
        default:
            break;
        }
    }
    return QWidget::eventFilter(obj, event);
}

void new_pass_form::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_mousePressed = true;
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    QWidget::mousePressEvent(event);
}

void new_pass_form::mouseMoveEvent(QMouseEvent *event) {
    if (m_mousePressed && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}

void new_pass_form::resizeEvent(QResizeEvent* event)
{
    if (closeButton) {
        closeButton->move(width() - closeButton->width() - 15, 15);
    }
    QWidget::resizeEvent(event);
}

void new_pass_form::togglePasswordVisibility(bool checked)
{
    QLineEdit::EchoMode mode = checked ? QLineEdit::Normal : QLineEdit::Password;
    ui->lineEdit->setEchoMode(mode);
    ui->lineEdit_2->setEchoMode(mode);

    if (checked) {
        QTimer::singleShot(3000, [this]() {
            if (ui->pushButton_showPassword->isChecked()) {
                ui->pushButton_showPassword->setChecked(false);
            }
        });
    }
}

new_pass_form::~new_pass_form()
{
    delete ui;
}
void new_pass_form::slot_pass_no_show(QString password) {

    if (AuthRegForm::randomValue == 1) {
        AuthRegForm::loadBackground(ui->graphicsView2, scene2, ":/dom/image/29.png");
    } else {
        AuthRegForm::loadBackground(ui->graphicsView2, scene2, ":/dom/image/30.png");
    }
    this->show();
    ui->lineEdit_cod->setFocus();
    ui->lineEdit_cod->setText("");
    ui->lineEdit_cod->setVisible(true);
    ui->lineEdit->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->pushButton_exit->setVisible(false);
    ui->pushButton_continue->setVisible(true);
}

void new_pass_form::on_pushButton_continue_clicked()
{
    scene2->clear();
    QString enteredCode = ui->lineEdit_cod->text();
    QString codes = clientApi->COD;
    qDebug () << codes;

    if (enteredCode.isEmpty()) {
        if (AuthRegForm::randomValue == 1) {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, ":/dom/image/31.png");
        } else {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, ":/dom/image/32.png");
        }
        return;
    }
    if (enteredCode != codes) {
        if (AuthRegForm::randomValue == 1) {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, ":/dom/image/33.png");
        } else {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, ":/dom/image/34.png");
        }
    }
    else {
        if (AuthRegForm::randomValue == 1) {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, ":/dom/image/35.png");
        } else {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, ":/dom/image/36.png");
        }
        ui->pushButton_showPassword->setVisible(true);
        ui->lineEdit_cod->setVisible(false);
        ui->lineEdit->setVisible(true);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit->setFocus();
        ui->pushButton_continue->setVisible(false);
        ui->pushButton_exit->setGeometry(400, 480, 161, 61);
        ui->pushButton_exit->setVisible(true);
    }
}

void new_pass_form::on_pushButton_exit_clicked()
{
    scene2->clear();
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() || ui->lineEdit->text().length() < 5 || ui->lineEdit_2->text().length() < 5)
    {
        if (AuthRegForm::randomValue == 1) {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, ":/dom/image/37.png");
        } else {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, ":/dom/image/38.png");
        }
        return;
    }
    else if (ui->lineEdit->text() != ui->lineEdit_2->text()) {
        if (AuthRegForm::randomValue == 1) {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, ":/dom/image/39.png");
        } else {
            AuthRegForm::loadBackground(ui->graphicsView2, scene2, ":/dom/image/40.png");
        }
        ui->lineEdit_2->setText("");
        ui->lineEdit_2->setFocus(); }
    else {

        QString password = ui->lineEdit->text();
        QByteArray salt = PasswordHasher::generateSalt();
        QByteArray hashedPassword = PasswordHasher::hashPassword(password, salt, 10000);

        QString UserDataAuth = QString("repas %1 %2").arg(QString::fromUtf8(hashedPassword)).arg(QString::fromUtf8(salt));
        QByteArray repas  = clientApi->query_to_server(UserDataAuth);
        ui->pushButton_showPassword->setVisible(false);
        this->close();
        emit pass_ok(password);
    }
}
