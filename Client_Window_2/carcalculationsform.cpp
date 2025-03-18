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
    QString brand = ui->lineEdit_brand->text();
    QString color = ui->lineEdit_color->text();
    QString fuelTankVolume = ui->lineEdit_fuelTankVolume->text();
    QString fuelConsumption = ui->lineEdit_fuelConsumption->text();

    QString carData = QString("brand:%1;color:%2;fuelTankVolume:%3;fuelConsumption:%4")
                          .arg(brand)
                          .arg(color)
                          .arg(fuelTankVolume)
                          .arg(fuelConsumption);

    QByteArray response = clientApi->query_to_server(carData);
    QString result = QString(response);
    QMessageBox::information(this, "Результат", result);
}

void CarCalculationsForm::on_pushButton_calculateTransportCost_clicked() {
    QString loadCapacity = ui->lineEdit_loadCapacity->text();
    QString fuelConsumption = ui->lineEdit_fuelConsumption->text();
    QString fuelPrice = ui->lineEdit_fuelPrice->text();

    QString transportCostData = QString("loadCapacity:%1;fuelConsumption:%2;fuelPrice:%3")
                                    .arg(loadCapacity)
                                    .arg(fuelConsumption)
                                    .arg(fuelPrice);

    QByteArray response = clientApi->query_to_server(transportCostData);
    QString result = QString(response);
    QMessageBox::information(this, "Результат", result);
}

void CarCalculationsForm::on_pushButton_calculateLoadCapacity_clicked() {
    QString loadCapacity = ui->lineEdit_loadCapacity->text();
    QString fuelConsumption = ui->lineEdit_fuelConsumption->text();
    QString fuelPrice = ui->lineEdit_fuelPrice->text();

    QString transportCostData = QString("loadCapacity:%1;fuelConsumption:%2;fuelPrice:%3")
                                    .arg(loadCapacity)
                                    .arg(fuelConsumption)
                                    .arg(fuelPrice);

    QByteArray response = clientApi->query_to_server(transportCostData);
    QString result = QString(response);
    QMessageBox::information(this, "Результат", result);
}
