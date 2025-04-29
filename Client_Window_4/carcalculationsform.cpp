#include "carcalculationsform.h"
#include "ui_carcalculationsform.h" // Включаем сгенерированный файл
#include <QMessageBox>

CarCalculationsForm::CarCalculationsForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CarCalculationsForm) // Создаем объект UI
    , clientApi(ClientAPI::getInstance()) // Инициализируем ClientAPI
{
    ui->setupUi(this); // Настраиваем UI

    // Инициализация сцен
    scene3 = new QGraphicsScene(this);
    ui->graphicsView3->setScene(scene3);

    //qDebug() << AuthRegForm::randomValue;
    scene3->clear();
}

CarCalculationsForm::~CarCalculationsForm() {
    delete ui; // Удаляем объект UI
}

void CarCalculationsForm::slot_car_show(QString login) {
    this->show();

    ui->checkBox->setGeometry(750, 220, 161, 61);
    ui->lineEdit_brand->setGeometry(50, 220, 181, 61);
    ui->lineEdit_color->setGeometry(250, 220, 181, 61);
    ui->lineEdit_fuelTankVolume->setGeometry(450, 220, 231, 61);
    ui->lineEdit_fuelConsumption->setGeometry(50, 370, 241, 61);
    ui->lineEdit_loadCapacity->setGeometry(310, 370, 311, 61);
    ui->lineEdit_fuelPrice->setGeometry(640, 370, 241, 61);

    ui->lineEdit_finish->setVisible(false);
    ui->pushButton_back->setVisible(false);

    if (AuthRegForm::randomValue == 1) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/38.png");
    } else {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/37.png");
    }
}

void CarCalculationsForm::on_pushButton_calculateDistance_clicked() {

    if (!(ui->comboBox_2->currentText().isEmpty() ||
         ui->comboBox->currentText().isEmpty() ||
          ui->lineEdit_fuelTankVolume->text().isEmpty() ||
          ui->lineEdit_fuelConsumption->text().isEmpty() ||
          ui->lineEdit_loadCapacity->text().isEmpty() ||
          ui->lineEdit_fuelPrice->text().isEmpty())) {

    ui->checkBox->setGeometry(360, 340, 161, 61);
    ui->comboBox_2->setGeometry(350, 150, 181, 61);
    ui->comboBox->setGeometry(350, 210, 181, 61);
    ui->lineEdit_fuelTankVolume->setGeometry(350, 280, 161, 61);
    ui->lineEdit_fuelConsumption->setGeometry(350, 400, 181, 41);
    ui->lineEdit_loadCapacity->setGeometry(350, 450, 181, 51);
    ui->lineEdit_fuelPrice->setGeometry(350, 510, 181, 51);
    ui->pushButton_calculateDistance->setVisible(false);
    ui->pushButton_calculateLoadCapacity->setVisible(false);
    ui->pushButton_calculateTransportCost->setVisible(false);
    ui->lineEdit_finish->setVisible(true);
    ui->pushButton_back->setVisible(true);


    QString category = ui->checkBox->isChecked() ? "0" : "1";
    QString brand = ui->lineEdit_brand->text();
    QString color = ui->lineEdit_color->text();
    QString fuel_volume = ui->lineEdit_fuelTankVolume->text();
    QString fuel_power = ui->lineEdit_fuelConsumption->text();
    QString max_weight = ui->lineEdit_loadCapacity->text();
    QString fuel_price = ui->lineEdit_fuelPrice->text();

    if (AuthRegForm::randomValue == 1 && category == "1" ) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/48.png");
    }
    if (AuthRegForm::randomValue == 1 && category == "0" ) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/45.png");
    }
    if (AuthRegForm::randomValue == 2 && category == "1" ) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/39.png");
    }
    if (AuthRegForm::randomValue == 2 && category == "0" ) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/42.png");
    }

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

    ui->lineEdit_finish->setAlignment(Qt::AlignCenter);
    QString result_dist = result.section(' ', 1, 1);
    qDebug() << result;
    if (result_dist != "0" && result_dist != "command") {
        qDebug() << result_dist;
        ui->lineEdit_finish->setText(result_dist + " км"); }
    else { ui->lineEdit_finish->setText("Некорректные данные!"); }

    //QMessageBox::information(this, "Результат", result);
    }
    else {qDebug() << "Не все поля введены!"; }
}

void CarCalculationsForm::on_pushButton_calculateLoadCapacity_clicked() {

    if (!(ui->comboBox_2->currentText().isEmpty() ||
          ui->comboBox->currentText().isEmpty() ||
          ui->lineEdit_fuelTankVolume->text().isEmpty() ||
          ui->lineEdit_fuelConsumption->text().isEmpty() ||
          ui->lineEdit_loadCapacity->text().isEmpty() ||
          ui->lineEdit_fuelPrice->text().isEmpty())) {

    ui->checkBox->setGeometry(360, 340, 161, 61);
    ui->comboBox_2->setGeometry(350, 150, 181, 61);
    ui->comboBox->setGeometry(350, 210, 181, 61);
    ui->lineEdit_fuelTankVolume->setGeometry(350, 280, 161, 61);
    ui->lineEdit_fuelConsumption->setGeometry(350, 400, 181, 41);
    ui->lineEdit_loadCapacity->setGeometry(350, 450, 181, 51);
    ui->lineEdit_fuelPrice->setGeometry(350, 510, 181, 51);
    ui->pushButton_calculateDistance->setVisible(false);
    ui->pushButton_calculateLoadCapacity->setVisible(false);
    ui->pushButton_calculateTransportCost->setVisible(false);
    ui->lineEdit_finish->setVisible(true);
     ui->pushButton_back->setVisible(true);

    QString category = ui->checkBox->isChecked() ? "0" : "1";
    QString brand = ui->lineEdit_brand->text();
    QString color = ui->lineEdit_color->text();
    QString fuel_volume = ui->lineEdit_fuelTankVolume->text();
    QString max_weight = ui->lineEdit_loadCapacity->text();
    QString fuel_power = ui->lineEdit_fuelConsumption->text();
    QString fuel_price = ui->lineEdit_fuelPrice->text();

    if (AuthRegForm::randomValue == 1 && category == "1" ) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/49.png");
    }
    if (AuthRegForm::randomValue == 1 && category == "0" ) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/46.png");
    }
    if (AuthRegForm::randomValue == 2 && category == "1" ) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/40.png");
    }
    if (AuthRegForm::randomValue == 2 && category == "0" ) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/43.png");
    }

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
    ui->lineEdit_finish->setAlignment(Qt::AlignCenter);
    QString result_money = result.section(' ', 2, 2);
    qDebug() << result_money;
    if (result_money != "0" && result_money != "") {
        ui->lineEdit_finish->setText(result_money + " рублей"); }
    else { ui->lineEdit_finish->setText("Некорректные данные!"); }
    //QMessageBox::information(this, "Результат", result);
}
else {qDebug() << "Не все поля введены!"; }
}

void CarCalculationsForm::on_pushButton_calculateTransportCost_clicked() {

    if (!(ui->comboBox_2->currentText().isEmpty() ||
          ui->comboBox->currentText().isEmpty() ||
          ui->lineEdit_fuelTankVolume->text().isEmpty() ||
          ui->lineEdit_fuelConsumption->text().isEmpty() ||
          ui->lineEdit_loadCapacity->text().isEmpty() ||
          ui->lineEdit_fuelPrice->text().isEmpty())) {

    ui->checkBox->setGeometry(360, 340, 161, 61);
    ui->comboBox_2->setGeometry(350, 150, 181, 61);
    ui->comboBox->setGeometry(350, 210, 181, 61);
    ui->lineEdit_fuelTankVolume->setGeometry(350, 280, 161, 61);
    ui->lineEdit_fuelConsumption->setGeometry(350, 400, 181, 41);
    ui->lineEdit_loadCapacity->setGeometry(350, 450, 181, 51);
    ui->lineEdit_fuelPrice->setGeometry(350, 510, 181, 51);
    ui->pushButton_calculateDistance->setVisible(false);
    ui->pushButton_calculateLoadCapacity->setVisible(false);
    ui->pushButton_calculateTransportCost->setVisible(false);
    ui->lineEdit_finish->setVisible(true);
     ui->pushButton_back->setVisible(true);

    QString category = ui->checkBox->isChecked() ? "0" : "1";
    QString brand = ui->lineEdit_brand->text();
    QString color = ui->lineEdit_color->text();
    QString fuel_volume = ui->lineEdit_fuelTankVolume->text();
    QString max_weight = ui->lineEdit_loadCapacity->text();
    QString fuel_power = ui->lineEdit_fuelConsumption->text();
    QString fuel_price = ui->lineEdit_fuelPrice->text();

    if (AuthRegForm::randomValue == 1 && category == "1" ) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/50.png");
    }
    if (AuthRegForm::randomValue == 1 && category == "0" ) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/47.png");
    }
    if (AuthRegForm::randomValue == 2 && category == "1" ) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/41.png");
    }
    if (AuthRegForm::randomValue == 2 && category == "0" ) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/44.png");
    }

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
    ui->lineEdit_finish->setAlignment(Qt::AlignCenter);
    QString result_gruj = result.section(' ', 3, 3);
    qDebug() << result;
    if (result_gruj != "nan" && result_gruj != "") {
        ui->lineEdit_finish->setText(result_gruj + " руб/(т·км)"); }
    else { ui->lineEdit_finish->setText("Некорректные данные!"); }
    //QMessageBox::information(this, "Результат", result);
}
else {qDebug() << "Не все поля введены!"; }
}

void CarCalculationsForm::on_pushButton_back_clicked()
{
    ui->checkBox->setGeometry(750, 220, 161, 61);
    ui->comboBox->setGeometry(50, 220, 181, 61);
    ui->comboBox_2->setGeometry(250, 220, 181, 61);
    ui->lineEdit_fuelTankVolume->setGeometry(450, 220, 231, 61);
    ui->lineEdit_fuelConsumption->setGeometry(50, 370, 241, 61);
    ui->lineEdit_loadCapacity->setGeometry(310, 370, 311, 61);
    ui->lineEdit_fuelPrice->setGeometry(640, 370, 241, 61);

    ui->lineEdit_finish->setVisible(false);
    ui->pushButton_back->setVisible(false);

    ui->pushButton_calculateDistance->setVisible(true);
    ui->pushButton_calculateLoadCapacity->setVisible(true);
    ui->pushButton_calculateTransportCost->setVisible(true);

    if (AuthRegForm::randomValue == 1) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/38.png");
    } else {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, "D:/TMP/Client_Window/image/37.png");
    }
}

