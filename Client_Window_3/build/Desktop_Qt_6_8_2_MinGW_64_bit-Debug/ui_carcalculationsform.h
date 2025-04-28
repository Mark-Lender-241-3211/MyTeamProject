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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarCalculationsForm
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_calculateDistance;
    QPushButton *pushButton_calculateTransportCost;
    QPushButton *pushButton_calculateLoadCapacity;
    QLineEdit *lineEdit_brand;
    QLineEdit *lineEdit_color;
    QLineEdit *lineEdit_fuelTankVolume;
    QLineEdit *lineEdit_fuelConsumption;
    QLineEdit *lineEdit_loadCapacity;
    QLineEdit *lineEdit_fuelPrice;
    QCheckBox *checkBox;

    void setupUi(QDialog *CarCalculationsForm)
    {
        if (CarCalculationsForm->objectName().isEmpty())
            CarCalculationsForm->setObjectName("CarCalculationsForm");
        CarCalculationsForm->resize(800, 600);
        centralwidget = new QWidget(CarCalculationsForm);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(40, -50, 533, 671));
        pushButton_calculateDistance = new QPushButton(centralwidget);
        pushButton_calculateDistance->setObjectName("pushButton_calculateDistance");
        pushButton_calculateDistance->setGeometry(QRect(30, 430, 111, 71));
        pushButton_calculateTransportCost = new QPushButton(centralwidget);
        pushButton_calculateTransportCost->setObjectName("pushButton_calculateTransportCost");
        pushButton_calculateTransportCost->setGeometry(QRect(180, 430, 121, 71));
        pushButton_calculateLoadCapacity = new QPushButton(centralwidget);
        pushButton_calculateLoadCapacity->setObjectName("pushButton_calculateLoadCapacity");
        pushButton_calculateLoadCapacity->setGeometry(QRect(340, 430, 121, 71));
        lineEdit_brand = new QLineEdit(centralwidget);
        lineEdit_brand->setObjectName("lineEdit_brand");
        lineEdit_brand->setGeometry(QRect(30, 170, 113, 24));
        lineEdit_color = new QLineEdit(centralwidget);
        lineEdit_color->setObjectName("lineEdit_color");
        lineEdit_color->setGeometry(QRect(110, 200, 113, 24));
        lineEdit_fuelTankVolume = new QLineEdit(centralwidget);
        lineEdit_fuelTankVolume->setObjectName("lineEdit_fuelTankVolume");
        lineEdit_fuelTankVolume->setGeometry(QRect(160, 240, 113, 24));
        lineEdit_fuelConsumption = new QLineEdit(centralwidget);
        lineEdit_fuelConsumption->setObjectName("lineEdit_fuelConsumption");
        lineEdit_fuelConsumption->setGeometry(QRect(240, 270, 113, 24));
        lineEdit_loadCapacity = new QLineEdit(centralwidget);
        lineEdit_loadCapacity->setObjectName("lineEdit_loadCapacity");
        lineEdit_loadCapacity->setGeometry(QRect(320, 300, 113, 24));
        lineEdit_fuelPrice = new QLineEdit(centralwidget);
        lineEdit_fuelPrice->setObjectName("lineEdit_fuelPrice");
        lineEdit_fuelPrice->setGeometry(QRect(400, 340, 113, 24));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(350, 160, 111, 41));

        retranslateUi(CarCalculationsForm);

        QMetaObject::connectSlotsByName(CarCalculationsForm);
    } // setupUi

    void retranslateUi(QDialog *CarCalculationsForm)
    {
        CarCalculationsForm->setWindowTitle(QCoreApplication::translate("CarCalculationsForm", "MainWindow", nullptr));
        pushButton_calculateDistance->setText(QCoreApplication::translate("CarCalculationsForm", "PushButton", nullptr));
        pushButton_calculateTransportCost->setText(QCoreApplication::translate("CarCalculationsForm", "PushButton", nullptr));
        pushButton_calculateLoadCapacity->setText(QCoreApplication::translate("CarCalculationsForm", "PushButton", nullptr));
        checkBox->setText(QCoreApplication::translate("CarCalculationsForm", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarCalculationsForm: public Ui_CarCalculationsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARCALCULATIONSFORM_H
