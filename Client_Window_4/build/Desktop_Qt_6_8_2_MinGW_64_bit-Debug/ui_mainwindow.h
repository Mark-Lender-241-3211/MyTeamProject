/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_exit;
    QTextBrowser *textBrowser;
    QLabel *label;
    QTextBrowser *textBrowser_2;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(764, 484);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_exit = new QPushButton(centralwidget);
        pushButton_exit->setObjectName("pushButton_exit");
        pushButton_exit->setGeometry(QRect(130, 310, 211, 81));
        pushButton_exit->setStyleSheet(QString::fromUtf8("font: 700 italic 28pt \"Verdana\";\n"
"color: rgb(60, 200, 9);\n"
"background-color: rgb(99, 107, 134);\n"
"background-color: transparent;\n"
"border: 0px;\n"
"color: rgb(246, 234, 250);\n"
"border-radius: 10;"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(0, 440, 781, 41));
        textBrowser->setStyleSheet(QString::fromUtf8("font: 700 italic 8pt \"Verdana\";\n"
"border-color: rgb(221, 69, 56);\n"
"background-color: transparent;\n"
"color: rgb(219, 219, 221);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(380, 90, 441, 381));
        label->setStyleSheet(QString::fromUtf8("image: url(:/dom/image/dom.png);\n"
"background-color: transparent;"));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(0, 50, 491, 181));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-image: url(:/dom/image/qw.png);\n"
"font: 700 italic 12pt \"Verdana\";\n"
"color:black;\n"
"border: none;"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, -20, 771, 491));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/dom/image/m1000x1000.jpg);"));
        MainWindow->setCentralWidget(centralwidget);
        graphicsView->raise();
        pushButton_exit->raise();
        label->raise();
        textBrowser_2->raise();
        textBrowser->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 764, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "hello - Car's-Specific", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_exit->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_exit->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\263\320\275\320\260\320\273\320\270!", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:8pt; font-weight:700; font-style:italic;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-style:normal;\"><br /></p></body></html>", nullptr));
        label->setText(QString());
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:12pt; font-weight:700; font-style:italic;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; color:#3cc809;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bot"
                        "tom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; color:#3cc809;\">\320\237\321\200\320\270\320\262\320\265\321\202, \321\201\320\265\320\263\320\276\320\264\320\275\321\217 \321\217 \320\277\320\276\320\274\320\276\320\263\321\203 \321\202\320\265\320\261\320\265 </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; color:#3cc809;\">\321\201 \321\200\320\260\321\201\321\207\321\221\321\202\320\260\320\274\320\270 \321\200\320\260\320\267\320\273\320\270\321\207\320\275\321\213\321\205 </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; color:#3cc809;\">\321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272  \320\260"
                        "\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\320\265\320\271 !</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
