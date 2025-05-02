/********************************************************************************
** Form generated from reading UI file 'authregform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHREGFORM_H
#define UI_AUTHREGFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AuthRegForm
{
public:
    QPushButton *pushButton_new_password;
    QPushButton *pushButton_pass_new;
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_passwordcheck;
    QLineEdit *lineEdit_mail;
    QLabel *label_passwordcheck;
    QLabel *label_password;
    QLabel *label_login;
    QLabel *label_mail;
    QLabel *label_error;
    QPushButton *pushButton_Reg;
    QPushButton *pushButton_toReg;
    QPushButton *pushButton_Auth;

    void setupUi(QDialog *AuthRegForm)
    {
        if (AuthRegForm->objectName().isEmpty())
            AuthRegForm->setObjectName("AuthRegForm");
        AuthRegForm->setWindowModality(Qt::NonModal);
        AuthRegForm->resize(960, 720);
        AuthRegForm->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SystemLockScreen));
        AuthRegForm->setWindowIcon(icon);
        AuthRegForm->setStyleSheet(QString::fromUtf8(""));
        pushButton_new_password = new QPushButton(AuthRegForm);
        pushButton_new_password->setObjectName("pushButton_new_password");
        pushButton_new_password->setGeometry(QRect(660, 230, 251, 101));
        pushButton_new_password->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 0px;"));
        pushButton_pass_new = new QPushButton(AuthRegForm);
        pushButton_pass_new->setObjectName("pushButton_pass_new");
        pushButton_pass_new->setGeometry(QRect(280, 310, 251, 101));
        pushButton_pass_new->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 0px;"));
        graphicsView = new QGraphicsView(AuthRegForm);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 960, 720));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/dom/image/1.png);"));
        lineEdit_login = new QLineEdit(AuthRegForm);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setGeometry(QRect(210, 240, 381, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(true);
        lineEdit_login->setFont(font);
        lineEdit_login->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 11pt \"Segoe UI\";\n"
"border: 0px;"));
        lineEdit_password = new QLineEdit(AuthRegForm);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(210, 290, 391, 31));
        lineEdit_password->setFont(font);
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 11pt \"Segoe UI\";\n"
"border: 0px;"));
        lineEdit_passwordcheck = new QLineEdit(AuthRegForm);
        lineEdit_passwordcheck->setObjectName("lineEdit_passwordcheck");
        lineEdit_passwordcheck->setGeometry(QRect(210, 190, 391, 31));
        lineEdit_passwordcheck->setFont(font);
        lineEdit_passwordcheck->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 11pt \"Segoe UI\";\n"
"border: 0px;"));
        lineEdit_mail = new QLineEdit(AuthRegForm);
        lineEdit_mail->setObjectName("lineEdit_mail");
        lineEdit_mail->setGeometry(QRect(210, 340, 391, 31));
        lineEdit_mail->setFont(font);
        lineEdit_mail->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 11pt \"Segoe UI\";\n"
"border: 0px;"));
        label_passwordcheck = new QLabel(AuthRegForm);
        label_passwordcheck->setObjectName("label_passwordcheck");
        label_passwordcheck->setGeometry(QRect(60, 180, 131, 41));
        label_passwordcheck->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Verdana\";\n"
"color: black;"));
        label_password = new QLabel(AuthRegForm);
        label_password->setObjectName("label_password");
        label_password->setGeometry(QRect(60, 290, 131, 41));
        label_password->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Verdana\";\n"
"color: black;\n"
""));
        label_login = new QLabel(AuthRegForm);
        label_login->setObjectName("label_login");
        label_login->setGeometry(QRect(70, 230, 111, 51));
        label_login->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Verdana\";\n"
"color: black;"));
        label_mail = new QLabel(AuthRegForm);
        label_mail->setObjectName("label_mail");
        label_mail->setGeometry(QRect(60, 340, 111, 41));
        label_mail->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Verdana\";\n"
"color: black;"));
        label_error = new QLabel(AuthRegForm);
        label_error->setObjectName("label_error");
        label_error->setGeometry(QRect(20, 690, 369, 16));
        pushButton_Reg = new QPushButton(AuthRegForm);
        pushButton_Reg->setObjectName("pushButton_Reg");
        pushButton_Reg->setGeometry(QRect(160, 650, 261, 61));
        pushButton_Reg->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 0px;"));
        pushButton_toReg = new QPushButton(AuthRegForm);
        pushButton_toReg->setObjectName("pushButton_toReg");
        pushButton_toReg->setGeometry(QRect(470, 640, 291, 51));
        pushButton_toReg->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 0px;"));
        pushButton_Auth = new QPushButton(AuthRegForm);
        pushButton_Auth->setObjectName("pushButton_Auth");
        pushButton_Auth->setGeometry(QRect(130, 610, 141, 51));
        pushButton_Auth->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 0px;"));
        graphicsView->raise();
        pushButton_new_password->raise();
        pushButton_pass_new->raise();
        lineEdit_login->raise();
        lineEdit_password->raise();
        lineEdit_passwordcheck->raise();
        lineEdit_mail->raise();
        label_passwordcheck->raise();
        label_password->raise();
        label_login->raise();
        label_mail->raise();
        label_error->raise();
        pushButton_Reg->raise();
        pushButton_toReg->raise();
        pushButton_Auth->raise();

        retranslateUi(AuthRegForm);

        QMetaObject::connectSlotsByName(AuthRegForm);
    } // setupUi

    void retranslateUi(QDialog *AuthRegForm)
    {
        AuthRegForm->setWindowTitle(QCoreApplication::translate("AuthRegForm", "start - Car's-Specific", nullptr));
        pushButton_new_password->setText(QString());
        pushButton_pass_new->setText(QString());
        lineEdit_login->setText(QString());
        lineEdit_password->setText(QString());
        lineEdit_passwordcheck->setText(QString());
        lineEdit_mail->setText(QString());
        label_passwordcheck->setText(QString());
        label_password->setText(QString());
        label_login->setText(QString());
        label_mail->setText(QString());
        label_error->setText(QString());
        pushButton_Reg->setText(QString());
        pushButton_toReg->setText(QString());
        pushButton_Auth->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AuthRegForm: public Ui_AuthRegForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHREGFORM_H
