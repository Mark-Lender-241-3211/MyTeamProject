#include "authregform.h"
#include "ui_authregform.h"
#include <QMessageBox>
#include <QLinearGradient>
#include <QGraphicsView>
#include <QDebug>

int AuthRegForm::randomValue = QRandomGenerator::global()->bounded(1, 3);

AuthRegForm::AuthRegForm(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::AuthRegForm),
    clientApi(ClientAPI::getInstance()),
    authAttempts(0),
    toRegAttempts(0),
    passwordHideTimer(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("CarSpecific");
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(960, 720);
    ui->graphicsView->viewport()->installEventFilter(this);

    closeButton = new QPushButton("✕", this);
    closeButton->setStyleSheet(
        "QPushButton {"
        "   color: white;"
        "   background-color: rgba(147, 112, 219, 150);"
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

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->viewport()->setMouseTracking(true);

    change_type_to_reg(false);
    ui->pushButton_new_password->setVisible(false);
    ui->pushButton_pass_new->setVisible(false);
    ui->lineEdit_password->setMaxLength(10);
    ui->lineEdit_passwordcheck->setMaxLength(10);
    ui->lineEdit_passwordcheck->setEchoMode(QLineEdit::Password);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    ui->pushButton_showPassword->setCheckable(true);
    connect(ui->pushButton_showPassword, &QPushButton::toggled, this, &AuthRegForm::togglePasswordVisibility);

    ui->lineEdit_login->setFocus();
    loadBackground(ui->graphicsView, scene,
                   (randomValue == 1) ? ":/dom/image/1.png"
                                      : ":/dom/image/2.png");
}

void AuthRegForm::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(QColor(138, 43, 226), 10);
    painter.setPen(pen);
    painter.setBrush(Qt::white);
    painter.drawRoundedRect(rect().adjusted(3, 3, -3, -3), 5, 5);

    QDialog::paintEvent(event);
}

bool AuthRegForm::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->graphicsView->viewport()) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        switch (event->type()) {
        case QEvent::MouseButtonPress:
            mousePressEvent(mouseEvent);
            return true;
        case QEvent::MouseMove:
            mouseMoveEvent(mouseEvent);
            return true;
        case QEvent::MouseButtonRelease:
            mouseReleaseEvent(mouseEvent);
            return true;
        default:
            break;
        }
    }
    return QDialog::eventFilter(obj, event);
}

void AuthRegForm::resizeEvent(QResizeEvent* event)
{
    ui->graphicsView->setGeometry(2, 2, width()-4, height()-4);
    closeButton->move(width() - closeButton->width() - 15, 15);
    QDialog::resizeEvent(event);
}

void AuthRegForm::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void AuthRegForm::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}

void AuthRegForm::mouseReleaseEvent(QMouseEvent *event) {
    m_mousePressed = false;
    QDialog::mouseReleaseEvent(event);
}

void AuthRegForm::hidePasswordAfterDelay()
{
    if (ui->pushButton_showPassword->isChecked()) {
        ui->pushButton_showPassword->setChecked(false);
    }
}

void AuthRegForm::togglePasswordVisibility(bool checked)
{
    QLineEdit::EchoMode mode = checked ? QLineEdit::Normal : QLineEdit::Password;
    ui->lineEdit_password->setEchoMode(mode);
    ui->lineEdit_passwordcheck->setEchoMode(mode);

    if (checked) {
        QTimer::singleShot(3000, this, [this]() {
            if (ui->pushButton_showPassword->isChecked()) {
                ui->pushButton_showPassword->setChecked(false);
            }
        });
    }
}

void AuthRegForm::loadBackground(QGraphicsView* view, QGraphicsScene* scene, const QString& imagePath)
{
    QPixmap background(imagePath);
    if (background.isNull()) return;
    scene->clear();
    scene->addPixmap(background);
    view->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

void AuthRegForm::on_pushButton_toReg_clicked()
{
    toRegAttempts++;
    qDebug() << randomValue;
    ui->lineEdit_mail->setText("");
    ui->lineEdit_passwordcheck->setText("");
    change_type_to_reg(!ui->lineEdit_mail->isVisible());
    ui->lineEdit_login->setText("");
    ui->lineEdit_password->setText("");
    ui->pushButton_new_password->setVisible(false);
    ui->lineEdit_login->setFocus();

    if (toRegAttempts % 2 != 0) {
        if (randomValue == 1) {
            loadBackground(ui->graphicsView, scene, ":/dom/image/7.png");
        } else {
            loadBackground(ui->graphicsView, scene, ":/dom/image/8.png");
        }
        ui->lineEdit_passwordcheck->setGeometry(210, 290, 391, 31);
        ui->lineEdit_password->setGeometry(210, 240, 381, 31);
        ui->lineEdit_login->setGeometry(210, 190, 391, 31);
        ui->pushButton_toReg->setGeometry(130, 610, 141, 51);
        ui->pushButton_Reg->setGeometry(470, 640, 291, 51);
        ui->lineEdit_mail->setVisible(true);
    } else {
        if (randomValue == 1) {
            loadBackground(ui->graphicsView, scene, ":/dom/image/1.png");
        } else {
            loadBackground(ui->graphicsView, scene, ":/dom/image/2.png");
        }
        ui->pushButton_toReg->setGeometry(470, 640, 291, 51);
        ui->pushButton_Reg->setVisible(false);
        ui->lineEdit_login->setGeometry(210, 240, 381, 31);
        ui->lineEdit_password->setGeometry(210, 290, 391, 31);
    }
}

void AuthRegForm::change_type_to_reg(bool is_reg)
{
    ui->lineEdit_passwordcheck->setVisible(is_reg);
    ui->lineEdit_mail->setVisible(is_reg);
    ui->pushButton_Reg->setVisible(is_reg);
    ui->pushButton_Auth->setVisible(!is_reg);
}

AuthRegForm::~AuthRegForm()
{
    delete ui;
}

void AuthRegForm::slot_auth_reg_show(QString login)
{
    this->show();
}

void AuthRegForm::on_pushButton_Auth_clicked()
{
    QByteArray testRequest = "test";
    clientApi->query_to_server(testRequest);

    if (clientApi->query_to_server(testRequest) == "Timeout error") {
        loadBackground(ui->graphicsView, scene,
                       (randomValue == 1) ? ":/dom/image/55.png"
                                          : ":/dom/image/57.png");
        return;
    }

    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    if (login.isEmpty() || password.isEmpty()) {
        loadBackground(ui->graphicsView, scene,
                       (randomValue == 1) ? ":/dom/image/56.png"
                                          : ":/dom/image/58.png");
    }
    else if (!clientApi->isAuthValid(login, password)) {
        if (randomValue == 1) {
            loadBackground(ui->graphicsView, scene, ":/dom/image/3.png");
        } else {
            loadBackground(ui->graphicsView, scene, ":/dom/image/4.png");
        }
        ui->lineEdit_password->setText("");
        ui->lineEdit_login->setText("");
        authAttempts++;
        ui->lineEdit_login->setFocus();
    } else {
        emit auth_ok(login);
        this->close();
    }

    if (authAttempts >= 3) {
        if (randomValue == 1) {
            loadBackground(ui->graphicsView, scene, ":/dom/image/5.png");
        } else {
            loadBackground(ui->graphicsView, scene, ":/dom/image/6.png");
        }
        ui->pushButton_new_password->setVisible(true);
    }
}

void AuthRegForm::clear()
{
    ui->lineEdit_login->setText("");
    ui->lineEdit_password->setText("");
    ui->lineEdit_passwordcheck->setText("");
    ui->lineEdit_mail->setText("");
}

bool AuthRegForm::isvalidEmail(QString email)
{
    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@(gmail\\.com|mail\\.ru|yandex\\.ru)$");
    QRegularExpressionMatch match = regex.match(email);
    return match.hasMatch();
}

void AuthRegForm::on_pushButton_Reg_clicked()
{
    ui->lineEdit_login->setFocus();
    if (ui->lineEdit_password->text().isEmpty() ||
        ui->lineEdit_login->text().isEmpty() ||
        ui->lineEdit_mail->text().isEmpty()) {
        if (randomValue == 1) {
            loadBackground(ui->graphicsView, scene, ":/dom/image/9.png");
        } else {
            loadBackground(ui->graphicsView, scene, ":/dom/image/10.png");
        }
    } else if (ui->lineEdit_password->text() != ui->lineEdit_passwordcheck->text()) {
        if (randomValue == 1) {
            loadBackground(ui->graphicsView, scene, ":/dom/image/11.png");
        } else {
            loadBackground(ui->graphicsView, scene, ":/dom/image/12.png");
        }
        ui->lineEdit_passwordcheck->setText("");
        ui->lineEdit_passwordcheck->setFocus();
    } else if (!isvalidEmail(ui->lineEdit_mail->text())) {
        if (randomValue == 1) {
            loadBackground(ui->graphicsView, scene, ":/dom/image/13.png");
        } else {
            loadBackground(ui->graphicsView, scene, ":/dom/image/14.png");
        }
        ui->lineEdit_mail->setText("");
        ui->lineEdit_mail->setFocus();
    } else {
        if (ui->lineEdit_password->text().length() < 5 || ui->lineEdit_passwordcheck->text().length() < 5) {
            QMessageBox::warning(this, "Input error", "Минимальная длина пароля - 5 символов!");
            return;
        }

        QString login = ui->lineEdit_login->text();
        QString mail = ui->lineEdit_mail->text();
        QString password = ui->lineEdit_password->text();

        if ((clientApi->isRegValid(login, password, mail)) == "reg+") {
            ui->lineEdit_passwordcheck->setText("");
            ui->lineEdit_mail->setText("");
            ui->pushButton_toReg->click();
        } else if ((clientApi->isRegValid(login, password, mail)) == "loginNotUNIQ") {
            ui->lineEdit_login->setText("");
            if (randomValue == 1) {
                loadBackground(ui->graphicsView, scene, ":/dom/image/15.png");
            } else {
                loadBackground(ui->graphicsView, scene, ":/dom/image/16.png");
            }
        } else if ((clientApi->isRegValid(login, password, mail)) == "emailNotUNIQ") {
            ui->lineEdit_mail->setText("");
            if (randomValue == 1) {
                loadBackground(ui->graphicsView, scene, ":/dom/image/17.png");
            } else {
                loadBackground(ui->graphicsView, scene, ":/dom/image/18.png");
            }
        } else {
            loadBackground(ui->graphicsView, scene,
                           (randomValue == 1) ? ":/dom/image/59.png"
                                              : ":/dom/image/60.png");
        }
    }
}

void AuthRegForm::on_pushButton_new_password_clicked()
{
    ui->pushButton_showPassword->setVisible(false);
    ui->lineEdit_login->setGeometry(210, 240, 381, 31);
    ui->lineEdit_password->setVisible(false);
    ui->lineEdit_passwordcheck->setVisible(false);
    ui->lineEdit_mail->setText("");
    ui->pushButton_Reg->setVisible(false);
    ui->pushButton_Auth->setVisible(false);
    ui->pushButton_toReg->setVisible(false);
    ui->pushButton_new_password->setVisible(false);
    ui->pushButton_pass_new->setVisible(true);
    ui->lineEdit_login->setFocus();

    if (randomValue == 1) {
        loadBackground(ui->graphicsView, scene, ":/dom/image/23.png");
    } else {
        loadBackground(ui->graphicsView, scene, ":/dom/image/24.png");
    }
}

void AuthRegForm::on_pushButton_pass_new_clicked()
{
    if (!ui->lineEdit_login->text().isEmpty()) {
        if (randomValue == 1) {
            loadBackground(ui->graphicsView, scene, ":/dom/image/27.png");
        } else {
            loadBackground(ui->graphicsView, scene, ":/dom/image/28.png");
        }

        QEventLoop loop;
        QTimer::singleShot(2000, &loop, &QEventLoop::quit);
        loop.exec();
        QString login = ui->lineEdit_login->text();

        if ((clientApi->sendMail(login)) == "cod-") {
            if (randomValue == 1) {
                loadBackground(ui->graphicsView, scene, ":/dom/image/25.png");
            } else {
                loadBackground(ui->graphicsView, scene, ":/dom/image/26.png");
            }
        } else {
            ui->lineEdit_login->setText("");
            ui->lineEdit_login->setVisible(true);
            ui->lineEdit_mail->setVisible(false);
            ui->lineEdit_password->setVisible(true);
            ui->lineEdit_passwordcheck->setVisible(false);
            ui->pushButton_pass_new->setVisible(false);
            ui->pushButton_Auth->setVisible(true);
            ui->pushButton_toReg->setVisible(true);
            ui->pushButton_Reg->setVisible(false);
            this->close();
            emit pass_no(ui->lineEdit_password->text());
            ui->lineEdit_mail->setText("");
            ui->lineEdit_mail->setGeometry(210, 350, 391, 21);
            ui->pushButton_showPassword->setVisible(true);
            ui->lineEdit_login->setFocus();

            if (randomValue == 1) {
                loadBackground(ui->graphicsView, scene, ":/dom/image/1.png");
            } else {
                loadBackground(ui->graphicsView, scene, ":/dom/image/2.png");
            }
        }
    } else {
        QMessageBox::warning(this, "Input error", "Логин не введён!");
    }
}
