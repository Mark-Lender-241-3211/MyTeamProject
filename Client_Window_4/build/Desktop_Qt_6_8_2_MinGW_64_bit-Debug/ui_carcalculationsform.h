/********************************************************************************
** Form generated from reading UI file 'carcalculationsform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARCALCULATIONSFORM_H
#define UI_CARCALCULATIONSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CarCalculationsForm
{
public:
    QGraphicsView *graphicsView3;
    QCheckBox *checkBox;
    QLineEdit *lineEdit_fuelPrice;
    QPushButton *pushButton_calculateLoadCapacity;
    QPushButton *pushButton_calculateDistance;
    QPushButton *pushButton_calculateTransportCost;
    QLineEdit *lineEdit_loadCapacity;
    QLineEdit *lineEdit_fuelConsumption;
    QLineEdit *lineEdit_fuelTankVolume;
    QLineEdit *lineEdit_color;
    QLineEdit *lineEdit_brand;
    QPushButton *pushButton_back;
    QLineEdit *lineEdit_finish;
    QComboBox *comboBox;
    QComboBox *comboBox_2;

    void setupUi(QDialog *CarCalculationsForm)
    {
        if (CarCalculationsForm->objectName().isEmpty())
            CarCalculationsForm->setObjectName("CarCalculationsForm");
        CarCalculationsForm->resize(960, 720);
        graphicsView3 = new QGraphicsView(CarCalculationsForm);
        graphicsView3->setObjectName("graphicsView3");
        graphicsView3->setGeometry(QRect(0, 0, 960, 720));
        graphicsView3->setStyleSheet(QString::fromUtf8("background-image: url(:/dom/image/42.png);"));
        checkBox = new QCheckBox(CarCalculationsForm);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(380, 350, 131, 51));
        checkBox->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;"));
        lineEdit_fuelPrice = new QLineEdit(CarCalculationsForm);
        lineEdit_fuelPrice->setObjectName("lineEdit_fuelPrice");
        lineEdit_fuelPrice->setGeometry(QRect(350, 510, 181, 51));
        lineEdit_fuelPrice->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;\n"
"border: 0px;"));
        pushButton_calculateLoadCapacity = new QPushButton(CarCalculationsForm);
        pushButton_calculateLoadCapacity->setObjectName("pushButton_calculateLoadCapacity");
        pushButton_calculateLoadCapacity->setGeometry(QRect(370, 560, 221, 91));
        pushButton_calculateLoadCapacity->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;\n"
"border: 0px;"));
        pushButton_calculateDistance = new QPushButton(CarCalculationsForm);
        pushButton_calculateDistance->setObjectName("pushButton_calculateDistance");
        pushButton_calculateDistance->setGeometry(QRect(60, 540, 241, 121));
        pushButton_calculateDistance->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;\n"
"border: 0px;"));
        pushButton_calculateTransportCost = new QPushButton(CarCalculationsForm);
        pushButton_calculateTransportCost->setObjectName("pushButton_calculateTransportCost");
        pushButton_calculateTransportCost->setGeometry(QRect(660, 540, 271, 121));
        pushButton_calculateTransportCost->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;\n"
"border: 0px;"));
        lineEdit_loadCapacity = new QLineEdit(CarCalculationsForm);
        lineEdit_loadCapacity->setObjectName("lineEdit_loadCapacity");
        lineEdit_loadCapacity->setGeometry(QRect(350, 450, 181, 51));
        lineEdit_loadCapacity->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;\n"
"border: 0px;"));
        lineEdit_fuelConsumption = new QLineEdit(CarCalculationsForm);
        lineEdit_fuelConsumption->setObjectName("lineEdit_fuelConsumption");
        lineEdit_fuelConsumption->setGeometry(QRect(350, 400, 181, 41));
        lineEdit_fuelConsumption->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;\n"
"border: 0px;"));
        lineEdit_fuelTankVolume = new QLineEdit(CarCalculationsForm);
        lineEdit_fuelTankVolume->setObjectName("lineEdit_fuelTankVolume");
        lineEdit_fuelTankVolume->setGeometry(QRect(350, 290, 181, 51));
        lineEdit_fuelTankVolume->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;\n"
"border: 0px;"));
        lineEdit_color = new QLineEdit(CarCalculationsForm);
        lineEdit_color->setObjectName("lineEdit_color");
        lineEdit_color->setGeometry(QRect(350, 220, 181, 51));
        lineEdit_color->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;\n"
"border: 0px;"));
        lineEdit_brand = new QLineEdit(CarCalculationsForm);
        lineEdit_brand->setObjectName("lineEdit_brand");
        lineEdit_brand->setGeometry(QRect(350, 160, 181, 51));
        lineEdit_brand->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;\n"
"border: 0px;"));
        pushButton_back = new QPushButton(CarCalculationsForm);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(700, 590, 151, 61));
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;\n"
"border: 0px;"));
        lineEdit_finish = new QLineEdit(CarCalculationsForm);
        lineEdit_finish->setObjectName("lineEdit_finish");
        lineEdit_finish->setGeometry(QRect(650, 310, 241, 51));
        lineEdit_finish->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;\n"
"border: 0px;"));
        comboBox = new QComboBox(CarCalculationsForm);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(60, 220, 171, 61));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;\n"
"padding-left: center;\n"
"border: 0px;\n"
""));
        comboBox_2 = new QComboBox(CarCalculationsForm);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(250, 220, 171, 61));
        comboBox_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 italic 14pt \"Segoe UI\";\n"
"color: white;\n"
"padding-left: center;\n"
"border: 0px;\n"
""));

        retranslateUi(CarCalculationsForm);

        QMetaObject::connectSlotsByName(CarCalculationsForm);
    } // setupUi

    void retranslateUi(QDialog *CarCalculationsForm)
    {
        CarCalculationsForm->setWindowTitle(QCoreApplication::translate("CarCalculationsForm", "MainWindow", nullptr));
        checkBox->setText(QCoreApplication::translate("CarCalculationsForm", "\320\223\321\200\321\203\320\267\320\276\320\262\320\276\320\271", nullptr));
        lineEdit_fuelPrice->setText(QString());
        pushButton_calculateLoadCapacity->setText(QString());
        pushButton_calculateDistance->setText(QString());
        pushButton_calculateTransportCost->setText(QString());
        lineEdit_loadCapacity->setText(QString());
        lineEdit_fuelConsumption->setText(QString());
        lineEdit_fuelTankVolume->setText(QString());
        lineEdit_color->setText(QString());
        lineEdit_brand->setText(QString());
        pushButton_back->setText(QCoreApplication::translate("CarCalculationsForm", "\320\235\320\220\320\227\320\220\320\224", nullptr));
        lineEdit_finish->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("CarCalculationsForm", "Audi", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("CarCalculationsForm", "BMW", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("CarCalculationsForm", "BYD", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("CarCalculationsForm", "Changan", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("CarCalculationsForm", "Chery", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("CarCalculationsForm", "Chevrolet", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("CarCalculationsForm", "Citro\303\253n", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("CarCalculationsForm", "Datsun", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("CarCalculationsForm", "Exeed", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("CarCalculationsForm", "FAW", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("CarCalculationsForm", "Fiat", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("CarCalculationsForm", "Ford", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("CarCalculationsForm", "GAZ", nullptr));
        comboBox->setItemText(13, QCoreApplication::translate("CarCalculationsForm", "Geely", nullptr));
        comboBox->setItemText(14, QCoreApplication::translate("CarCalculationsForm", "Genesis", nullptr));
        comboBox->setItemText(15, QCoreApplication::translate("CarCalculationsForm", "Haval", nullptr));
        comboBox->setItemText(16, QCoreApplication::translate("CarCalculationsForm", "Honda", nullptr));
        comboBox->setItemText(17, QCoreApplication::translate("CarCalculationsForm", "Hyundai", nullptr));
        comboBox->setItemText(18, QCoreApplication::translate("CarCalculationsForm", "Infiniti", nullptr));
        comboBox->setItemText(19, QCoreApplication::translate("CarCalculationsForm", "Jaguar", nullptr));
        comboBox->setItemText(20, QCoreApplication::translate("CarCalculationsForm", "Jeep", nullptr));
        comboBox->setItemText(21, QCoreApplication::translate("CarCalculationsForm", "Jetour", nullptr));
        comboBox->setItemText(22, QCoreApplication::translate("CarCalculationsForm", "Kaiyi", nullptr));
        comboBox->setItemText(23, QCoreApplication::translate("CarCalculationsForm", "Kia", nullptr));
        comboBox->setItemText(24, QCoreApplication::translate("CarCalculationsForm", "Lada", nullptr));
        comboBox->setItemText(25, QCoreApplication::translate("CarCalculationsForm", "Land Rover", nullptr));
        comboBox->setItemText(26, QCoreApplication::translate("CarCalculationsForm", "Lexus", nullptr));
        comboBox->setItemText(27, QCoreApplication::translate("CarCalculationsForm", "Lifan", nullptr));
        comboBox->setItemText(28, QCoreApplication::translate("CarCalculationsForm", "Mazda", nullptr));
        comboBox->setItemText(29, QCoreApplication::translate("CarCalculationsForm", "Mercedes-Benz", nullptr));
        comboBox->setItemText(30, QCoreApplication::translate("CarCalculationsForm", "MG", nullptr));
        comboBox->setItemText(31, QCoreApplication::translate("CarCalculationsForm", "Mitsubishi", nullptr));
        comboBox->setItemText(32, QCoreApplication::translate("CarCalculationsForm", "Moskvich", nullptr));
        comboBox->setItemText(33, QCoreApplication::translate("CarCalculationsForm", "Nissan", nullptr));
        comboBox->setItemText(34, QCoreApplication::translate("CarCalculationsForm", "Omoda", nullptr));
        comboBox->setItemText(35, QCoreApplication::translate("CarCalculationsForm", "Opel", nullptr));
        comboBox->setItemText(36, QCoreApplication::translate("CarCalculationsForm", "Peugeot", nullptr));
        comboBox->setItemText(37, QCoreApplication::translate("CarCalculationsForm", "Porsche", nullptr));
        comboBox->setItemText(38, QCoreApplication::translate("CarCalculationsForm", "Renault", nullptr));
        comboBox->setItemText(39, QCoreApplication::translate("CarCalculationsForm", "Skoda", nullptr));
        comboBox->setItemText(40, QCoreApplication::translate("CarCalculationsForm", "SsangYong", nullptr));
        comboBox->setItemText(41, QCoreApplication::translate("CarCalculationsForm", "Subaru", nullptr));
        comboBox->setItemText(42, QCoreApplication::translate("CarCalculationsForm", "Suzuki", nullptr));
        comboBox->setItemText(43, QCoreApplication::translate("CarCalculationsForm", "TagAZ", nullptr));
        comboBox->setItemText(44, QCoreApplication::translate("CarCalculationsForm", "Toyota", nullptr));
        comboBox->setItemText(45, QCoreApplication::translate("CarCalculationsForm", "UAZ", nullptr));
        comboBox->setItemText(46, QCoreApplication::translate("CarCalculationsForm", "Volvo", nullptr));
        comboBox->setItemText(47, QCoreApplication::translate("CarCalculationsForm", "Volkswagen", nullptr));
        comboBox->setItemText(48, QCoreApplication::translate("CarCalculationsForm", "Zotye", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("CarCalculationsForm", "\320\221\320\265\320\273\321\213\320\271", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("CarCalculationsForm", "\320\223\320\276\320\273\321\203\320\261\320\276\320\271", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("CarCalculationsForm", "\320\226\321\221\320\273\321\202\321\213\320\271", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("CarCalculationsForm", "\320\227\320\265\320\273\321\221\320\275\321\213\320\271", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("CarCalculationsForm", "\320\232\320\276\321\200\320\270\321\207\320\275\320\265\320\262\321\213\320\271", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("CarCalculationsForm", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("CarCalculationsForm", "\320\236\321\200\320\260\320\275\320\266\320\265\320\262\321\213\320\271", nullptr));
        comboBox_2->setItemText(7, QCoreApplication::translate("CarCalculationsForm", "\320\240\320\276\320\267\320\276\320\262\321\213\320\271", nullptr));
        comboBox_2->setItemText(8, QCoreApplication::translate("CarCalculationsForm", "\320\241\320\265\321\200\321\213\320\271", nullptr));
        comboBox_2->setItemText(9, QCoreApplication::translate("CarCalculationsForm", "\320\241\320\265\321\200\320\265\320\261\321\200\320\270\321\201\321\202\321\213\320\271", nullptr));
        comboBox_2->setItemText(10, QCoreApplication::translate("CarCalculationsForm", "\320\241\320\270\320\275\320\270\320\271", nullptr));
        comboBox_2->setItemText(11, QCoreApplication::translate("CarCalculationsForm", "\320\241\320\270\321\200\320\265\320\275\320\265\320\262\321\213\320\271", nullptr));
        comboBox_2->setItemText(12, QCoreApplication::translate("CarCalculationsForm", "\320\244\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\271", nullptr));
        comboBox_2->setItemText(13, QCoreApplication::translate("CarCalculationsForm", "\320\247\321\221\321\200\320\275\321\213\320\271", nullptr));
        comboBox_2->setItemText(14, QCoreApplication::translate("CarCalculationsForm", "\320\221\320\270\321\200\321\216\320\267\320\276\320\262\321\213\320\271", nullptr));

    } // retranslateUi

};

namespace Ui {
    class CarCalculationsForm: public Ui_CarCalculationsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARCALCULATIONSFORM_H
