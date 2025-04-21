#include "carcalculationsform.h"
#include "ui_carcalculationsform.h" // Включаем сгенерированный файл
#include <QMessageBox>

CarCalculationsForm::CarCalculationsForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CarCalculationsForm) // Создаем объект UI
    , clientApi(ClientAPI::getInstance()) // Инициализируем ClientAPI
{
    ui->setupUi(this); // Настраиваем UI
}

CarCalculationsForm::~CarCalculationsForm() {
    delete ui; // Удаляем объект UI
}

void CarCalculationsForm::slot_car_show(QString login) {
    this->show();
}

void CarCalculationsForm::on_pushButton_calculateDistance_clicked() {
    QString category = ui->checkBox->isChecked() ? "0" : "1";
    QString brand = ui->lineEdit_brand->text();
    QString color = ui->lineEdit_color->text();
    QString fuel_volume = ui->lineEdit_fuelTankVolume->text();
    QString fuel_power = ui->lineEdit_fuelConsumption->text();
    QString max_weight = ui->lineEdit_loadCapacity->text();
    QString fuel_price = ui->lineEdit_fuelPrice->text();

    QString carData = QString("cars %1 %2 %3 %4 %5 %6 %7")
                          .arg(category)
                          .arg(brand)
                          .arg(color)
                          .arg(fuel_volume)
                          .arg(fuel_power)
                          .arg(max_weight)
                          .arg(fuel_price);

    QByteArray response = clientApi->query_to_server(carData);
    QString result = QString(response);
    QMessageBox::information(this, "Результат", result);
}

void CarCalculationsForm::on_pushButton_calculateLoadCapacity_clicked() {
    QString category = ui->checkBox->isChecked() ? "0" : "1";
    QString brand = ui->lineEdit_brand->text();
    QString color = ui->lineEdit_color->text();
    QString fuel_volume = ui->lineEdit_fuelTankVolume->text();
    QString max_weight = ui->lineEdit_loadCapacity->text();
    QString fuel_power = ui->lineEdit_fuelConsumption->text();
    QString fuel_price = ui->lineEdit_fuelPrice->text();

    QString transportCostData = QString("cars %1 %2 %3 %4 %5 %6 %7")
                                    .arg(category)
                                    .arg(brand)
                                    .arg(color)
                                    .arg(fuel_volume)
                                    .arg(max_weight)
                                    .arg(fuel_power)
                                    .arg(fuel_price);

    QByteArray response = clientApi->query_to_server(transportCostData);
    QString result = QString(response);
    QMessageBox::information(this, "Результат", result);
}

void CarCalculationsForm::on_pushButton_calculateTransportCost_clicked() {
    QString category = ui->checkBox->isChecked() ? "0" : "1";
    QString brand = ui->lineEdit_brand->text();
    QString color = ui->lineEdit_color->text();
    QString fuel_volume = ui->lineEdit_fuelTankVolume->text();
    QString max_weight = ui->lineEdit_loadCapacity->text();
    QString fuel_power = ui->lineEdit_fuelConsumption->text();
    QString fuel_price = ui->lineEdit_fuelPrice->text();

    QString transportCostData = QString("cars %1 %2 %3 %4 %5 %6 %7")
                                    .arg(category)
                                    .arg(brand)
                                    .arg(color)
                                    .arg(fuel_volume)
                                    .arg(max_weight)
                                    .arg(fuel_power)
                                    .arg(fuel_price);

    QByteArray response = clientApi->query_to_server(transportCostData);
    QString result = QString(response);
    QMessageBox::information(this, "Результат", result);
}
