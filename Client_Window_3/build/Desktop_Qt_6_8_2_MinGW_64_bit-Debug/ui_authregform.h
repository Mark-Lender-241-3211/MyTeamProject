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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthRegForm
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Auth;
    QPushButton *pushButton_toReg;
    QPushButton *pushButton_Reg;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QWidget *gridLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_login;
    QLabel *label_password;
    QLabel *label_passwordcheck;
    QLabel *label_mail;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_passwordcheck;
    QLineEdit *lineEdit_mail;
    QLabel *label_error;
    QPushButton *pushButton_new_password;

    void setupUi(QDialog *AuthRegForm)
    {
        if (AuthRegForm->objectName().isEmpty())
            AuthRegForm->setObjectName("AuthRegForm");
        AuthRegForm->setWindowModality(Qt::NonModal);
        AuthRegForm->resize(406, 458);
        AuthRegForm->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SystemLockScreen));
        AuthRegForm->setWindowIcon(icon);
        AuthRegForm->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget = new QWidget(AuthRegForm);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(9, 415, 388, 34));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Auth = new QPushButton(horizontalLayoutWidget);
        pushButton_Auth->setObjectName("pushButton_Auth");
        pushButton_Auth->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Verdana\";\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(pushButton_Auth);

        pushButton_toReg = new QPushButton(horizontalLayoutWidget);
        pushButton_toReg->setObjectName("pushButton_toReg");
        pushButton_toReg->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Verdana\";\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(pushButton_toReg);

        pushButton_Reg = new QPushButton(horizontalLayoutWidget);
        pushButton_Reg->setObjectName("pushButton_Reg");
        pushButton_Reg->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Verdana\";\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(pushButton_Reg);

        textBrowser = new QTextBrowser(AuthRegForm);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(9, 9, 388, 91));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;"));
        textBrowser_2 = new QTextBrowser(AuthRegForm);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(9, 320, 388, 89));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;"));
        gridLayoutWidget = new QWidget(AuthRegForm);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 160, 371, 156));
        formLayout = new QFormLayout(gridLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_login = new QLabel(gridLayoutWidget);
        label_login->setObjectName("label_login");
        label_login->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Verdana\";\n"
"color: black;"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_login);

        label_password = new QLabel(gridLayoutWidget);
        label_password->setObjectName("label_password");
        label_password->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Verdana\";\n"
"color: black;\n"
""));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_password);

        label_passwordcheck = new QLabel(gridLayoutWidget);
        label_passwordcheck->setObjectName("label_passwordcheck");
        label_passwordcheck->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Verdana\";\n"
"color: black;"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_passwordcheck);

        label_mail = new QLabel(gridLayoutWidget);
        label_mail->setObjectName("label_mail");
        label_mail->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Verdana\";\n"
"color: black;"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_mail);

        lineEdit_login = new QLineEdit(gridLayoutWidget);
        lineEdit_login->setObjectName("lineEdit_login");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_login);

        lineEdit_password = new QLineEdit(gridLayoutWidget);
        lineEdit_password->setObjectName("lineEdit_password");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_password);

        lineEdit_passwordcheck = new QLineEdit(gridLayoutWidget);
        lineEdit_passwordcheck->setObjectName("lineEdit_passwordcheck");

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_passwordcheck);

        lineEdit_mail = new QLineEdit(gridLayoutWidget);
        lineEdit_mail->setObjectName("lineEdit_mail");

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_mail);

        label_error = new QLabel(gridLayoutWidget);
        label_error->setObjectName("label_error");

        formLayout->setWidget(7, QFormLayout::SpanningRole, label_error);

        pushButton_new_password = new QPushButton(AuthRegForm);
        pushButton_new_password->setObjectName("pushButton_new_password");
        pushButton_new_password->setGeometry(QRect(10, 380, 101, 24));

        retranslateUi(AuthRegForm);

        QMetaObject::connectSlotsByName(AuthRegForm);
    } // setupUi

    void retranslateUi(QDialog *AuthRegForm)
    {
        AuthRegForm->setWindowTitle(QCoreApplication::translate("AuthRegForm", "start - Car's-Specific", nullptr));
        pushButton_Auth->setText(QCoreApplication::translate("AuthRegForm", "\320\222\321\205\320\276\320\264", nullptr));
        pushButton_toReg->setText(QCoreApplication::translate("AuthRegForm", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        pushButton_Reg->setText(QCoreApplication::translate("AuthRegForm", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("AuthRegForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700; font-style:italic; color:#000000;\">\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214 \320"
                        "\262 \320\275\320\260\321\210\320\265 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265!<br />\320\247\321\202\320\276\320\261\321\213 \320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214, \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\270\321\200\321\203\320\271\321\202\320\265\321\201\321\214 \320\270\320\273\320\270 \320\277\321\200\320\276\320\271\320\264\320\270\321\202\320\265 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\216!</span></p></body></html>", nullptr));
        label_login->setText(QCoreApplication::translate("AuthRegForm", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_password->setText(QCoreApplication::translate("AuthRegForm", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_passwordcheck->setText(QCoreApplication::translate("AuthRegForm", "\320\237\320\260\321\200\320\276\320\273\321\214 (\320\265\321\211\321\221 \321\200\320\260\320\267)", nullptr));
        label_mail->setText(QCoreApplication::translate("AuthRegForm", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        label_error->setText(QCoreApplication::translate("AuthRegForm", "TextLabel", nullptr));
        pushButton_new_password->setText(QCoreApplication::translate("AuthRegForm", "\320\227\320\260\320\261\321\213\320\273\320\270 \320\277\320\260\321\200\320\276\320\273\321\214?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthRegForm: public Ui_AuthRegForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHREGFORM_H
