/********************************************************************************
** Form generated from reading UI file 'new_pass_form.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_PASS_FORM_H
#define UI_NEW_PASS_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_pass_form
{
public:
    QLabel *label_text;
    QLineEdit *lineEdit_cod;
    QLabel *label_text2;
    QPushButton *pushButton_continue;
    QLabel *label_error;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_exit;
    QGraphicsView *graphicsView2;

    void setupUi(QWidget *new_pass_form)
    {
        if (new_pass_form->objectName().isEmpty())
            new_pass_form->setObjectName("new_pass_form");
        new_pass_form->resize(960, 720);
        label_text = new QLabel(new_pass_form);
        label_text->setObjectName("label_text");
        label_text->setGeometry(QRect(890, 20, 41, 41));
        label_text->setStyleSheet(QString::fromUtf8("font: 700 italic 10pt \"Verdana\";\n"
"color: red;"));
        lineEdit_cod = new QLineEdit(new_pass_form);
        lineEdit_cod->setObjectName("lineEdit_cod");
        lineEdit_cod->setGeometry(QRect(290, 320, 391, 31));
        lineEdit_cod->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 11pt \"Segoe UI\";\n"
"border: 0px;"));
        label_text2 = new QLabel(new_pass_form);
        label_text2->setObjectName("label_text2");
        label_text2->setGeometry(QRect(130, 650, 221, 20));
        label_text2->setStyleSheet(QString::fromUtf8("font: italic 8pt \"Verdana\";\n"
"color: blue;"));
        pushButton_continue = new QPushButton(new_pass_form);
        pushButton_continue->setObjectName("pushButton_continue");
        pushButton_continue->setGeometry(QRect(400, 480, 161, 61));
        pushButton_continue->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 0px;"));
        label_error = new QLabel(new_pass_form);
        label_error->setObjectName("label_error");
        label_error->setGeometry(QRect(30, 660, 251, 16));
        label_error->setStyleSheet(QString::fromUtf8("font: 8pt \"Verdana\";\n"
"text-decoration: underline;\n"
"color: green;"));
        label = new QLabel(new_pass_form);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 240, 131, 41));
        label_2 = new QLabel(new_pass_form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 290, 131, 41));
        lineEdit = new QLineEdit(new_pass_form);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(210, 240, 391, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 11pt \"Segoe UI\";\n"
"border: 0px;"));
        lineEdit_2 = new QLineEdit(new_pass_form);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(210, 290, 391, 41));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 11pt \"Segoe UI\";\n"
"border: 0px;"));
        pushButton_exit = new QPushButton(new_pass_form);
        pushButton_exit->setObjectName("pushButton_exit");
        pushButton_exit->setGeometry(QRect(770, 620, 111, 24));
        pushButton_exit->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 0px;"));
        graphicsView2 = new QGraphicsView(new_pass_form);
        graphicsView2->setObjectName("graphicsView2");
        graphicsView2->setGeometry(QRect(0, 0, 960, 720));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView2->sizePolicy().hasHeightForWidth());
        graphicsView2->setSizePolicy(sizePolicy);
        graphicsView2->setStyleSheet(QString::fromUtf8("background-image: url(:/dom/image/27.png);"));
        graphicsView2->raise();
        label_text->raise();
        lineEdit_cod->raise();
        label_text2->raise();
        pushButton_continue->raise();
        label_error->raise();
        label->raise();
        label_2->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        pushButton_exit->raise();

        retranslateUi(new_pass_form);

        QMetaObject::connectSlotsByName(new_pass_form);
    } // setupUi

    void retranslateUi(QWidget *new_pass_form)
    {
        new_pass_form->setWindowTitle(QCoreApplication::translate("new_pass_form", "Form", nullptr));
        label_text->setText(QString());
        lineEdit_cod->setText(QString());
        label_text2->setText(QString());
        pushButton_continue->setText(QString());
        label_error->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        lineEdit->setText(QString());
        lineEdit_2->setText(QString());
        pushButton_exit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class new_pass_form: public Ui_new_pass_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_PASS_FORM_H
