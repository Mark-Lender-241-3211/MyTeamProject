#include "carcalculationsform.h"
#include "ui_carcalculationsform.h"
#include <QMessageBox>
#include <QApplication>

CarCalculationsForm::CarCalculationsForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CarCalculationsForm)
    , clientApi(ClientAPI::getInstance())
{
    ui->setupUi(this);
    setWindowTitle("CarSpecific");
    scene3 = new QGraphicsScene(this);
    ui->graphicsView3->setScene(scene3);
    scene3->clear();
    ui->lineEdit_fuelConsumption->setMaxLength(2);
    ui->lineEdit_fuelConsumption->setAlignment(Qt::AlignCenter);
    ui->lineEdit_fuelPrice->setMaxLength(3);
    ui->lineEdit_fuelPrice->setAlignment(Qt::AlignCenter);
    ui->lineEdit_fuelTankVolume->setMaxLength(3);
    ui->lineEdit_fuelTankVolume->setAlignment(Qt::AlignCenter);
    ui->lineEdit_loadCapacity->setMaxLength(3);
    ui->lineEdit_loadCapacity->setAlignment(Qt::AlignCenter);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->graphicsView3->viewport()->installEventFilter(this); // Фильтр событий для перемещения
    ui->graphicsView3->setAttribute(Qt::WA_TransparentForMouseEvents, false);

    // Добавлена инициализация m_mousePressed
    m_mousePressed = false;
}
CarCalculationsForm::~CarCalculationsForm() {
    delete ui;
}

void CarCalculationsForm::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_mousePressed = true;
        m_dragPosition = event->globalPos() - frameGeometry().topLeft(); // Исправлено geometry() на frameGeometry()
        event->accept();
    }
    QDialog::mousePressEvent(event);
}

void CarCalculationsForm::mouseMoveEvent(QMouseEvent *event) {
    if (m_mousePressed && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
    QDialog::mouseMoveEvent(event);
}

// Исправленный eventFilter
bool CarCalculationsForm::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->graphicsView3->viewport()) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        switch (event->type()) {
        case QEvent::MouseButtonPress:
            mousePressEvent(mouseEvent);
            return true;
        case QEvent::MouseMove:
            mouseMoveEvent(mouseEvent);
            return true;
        default:
            break;
        }
    }
    return QDialog::eventFilter(obj, event);
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
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, ":/dom/image/42.png");
    } else {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, ":/dom/image/41.png");
    }
}
void CarCalculationsForm::on_pushButton_calculateDistance_clicked()
{
    // Проверка заполненности всех полей
    if (ui->comboBox_2->currentText().isEmpty() ||
        ui->comboBox->currentText().isEmpty() ||
        ui->lineEdit_fuelTankVolume->text().isEmpty() ||
        ui->lineEdit_fuelConsumption->text().isEmpty() ||
        ui->lineEdit_loadCapacity->text().isEmpty() ||
        ui->lineEdit_fuelPrice->text().isEmpty())
    {
        QMessageBox::warning(this, "Input error", "Заполните все поля!");
        return;
    }

    // Проверка что все числовые поля содержат положительные числа
    auto checkPositive = [this](const QString& text, const QString& fieldName) -> bool {
        bool ok;
        double value = text.toDouble(&ok);
        if (!ok || value < 0) {
            QMessageBox::warning(this, "Input error",
                                 QString("%1 - параметр может быть только положительным числом!").arg(fieldName));
            return false;
        }
        return true;
    };

    if (!checkPositive(ui->lineEdit_fuelTankVolume->text(), "Объем топливного бака") ||
        !checkPositive(ui->lineEdit_fuelConsumption->text(), "Расход топлива") ||
        !checkPositive(ui->lineEdit_loadCapacity->text(), "Грузоподъемность") ||
        !checkPositive(ui->lineEdit_fuelPrice->text(), "Цена топлива"))
    {
        return; // Прерываем если есть ошибки
    }

    // Получаем данные из полей ввода
    QString category = ui->checkBox->isChecked() ? "0" : "1";
    QString brand = ui->lineEdit_brand->text();
    QString color = ui->lineEdit_color->text();
    QString fuel_volume = ui->lineEdit_fuelTankVolume->text();
    QString fuel_power = ui->lineEdit_fuelConsumption->text();
    QString max_weight = ui->lineEdit_loadCapacity->text();
    QString fuel_price = ui->lineEdit_fuelPrice->text();

    // Формируем запрос к серверу
    QString carData = QString("cars %1 %2 %3 %4 %5 %6 %7")
                          .arg(category)
                          .arg(brand)
                          .arg(color)
                          .arg(fuel_volume)
                          .arg(fuel_power)
                          .arg(max_weight)
                          .arg(fuel_price);

    // Отправляем запрос и получаем ответ
    QByteArray response = clientApi->query_to_server(carData);
    QString result = QString(response);

    // Обрабатываем результат
    ui->lineEdit_finish->setAlignment(Qt::AlignCenter);
    QString result_dist = result.section(' ', 1, 1).trimmed();
    qDebug() << "Server response:" << result << "| Extracted distance:" << result_dist;

    bool ok;
    int distance = result_dist.toInt(&ok);

    if (ok && distance > 0 && distance < 1000000)
    {
        // Успешный результат - показываем расстояние
        ui->lineEdit_finish->setText(result_dist + " км");
        ui->lineEdit_finish->setReadOnly(true);

        // Изменяем интерфейс для отображения результата
        ui->checkBox->setGeometry(390, 350, 151, 41);
        ui->comboBox_2->setGeometry(350, 150, 181, 61);
        ui->comboBox->setGeometry(350, 210, 181, 61);
        ui->lineEdit_fuelTankVolume->setGeometry(350, 280, 181, 61);
        ui->lineEdit_fuelConsumption->setGeometry(350, 400, 181, 41);
        ui->lineEdit_loadCapacity->setGeometry(350, 450, 181, 51);
        ui->lineEdit_fuelPrice->setGeometry(350, 510, 181, 51);
        ui->pushButton_calculateDistance->setVisible(false);
        ui->pushButton_calculateLoadCapacity->setVisible(false);
        ui->pushButton_calculateTransportCost->setVisible(false);
        ui->lineEdit_finish->setVisible(true);
        ui->pushButton_back->setVisible(true);

        ui->pushButton_back->setFocus();
        ui->pushButton_exit->setVisible(false);
        // Обновляем фон в зависимости от категории
        if (AuthRegForm::randomValue == 1 && category == "1") {
            AuthRegForm::loadBackground(ui->graphicsView3, scene3, ":/dom/image/49.png");
        }
        else if (AuthRegForm::randomValue == 1 && category == "0") {
            AuthRegForm::loadBackground(ui->graphicsView3, scene3, ":/dom/image/50.png");
        }
        else if (AuthRegForm::randomValue == 2 && category == "1") {
            AuthRegForm::loadBackground(ui->graphicsView3, scene3, ":/dom/image/43.png");
        }
        else if (AuthRegForm::randomValue == 2 && category == "0") {
            AuthRegForm::loadBackground(ui->graphicsView3, scene3, ":/dom/image/44.png");
        }
    }
    else {
        QMessageBox::warning(this, "Input error", "Введены некорректные данные!");
    }
}

void CarCalculationsForm::on_pushButton_calculateLoadCapacity_clicked()
{
    // Проверка заполненности всех полей
    if (ui->comboBox_2->currentText().isEmpty() ||
        ui->comboBox->currentText().isEmpty() ||
        ui->lineEdit_fuelTankVolume->text().isEmpty() ||
        ui->lineEdit_fuelConsumption->text().isEmpty() ||
        ui->lineEdit_loadCapacity->text().isEmpty() ||
        ui->lineEdit_fuelPrice->text().isEmpty())
    {
        QMessageBox::warning(this, "Input error", "Заполните все поля!");
        return;
    }

    // Проверка что все числовые поля содержат положительные числа
    auto checkPositive = [this](const QString& text, const QString& fieldName) -> bool {
        bool ok;
        double value = text.toDouble(&ok);
        if (!ok || value < 0) {
            QMessageBox::warning(this, "Input error",
                                 QString("%1 - параметр может быть только положительным числом!").arg(fieldName));
            return false;
        }
        return true;
    };

    if (!checkPositive(ui->lineEdit_fuelTankVolume->text(), "Объем топливного бака") ||
        !checkPositive(ui->lineEdit_fuelConsumption->text(), "Расход топлива") ||
        !checkPositive(ui->lineEdit_loadCapacity->text(), "Грузоподъемность") ||
        !checkPositive(ui->lineEdit_fuelPrice->text(), "Цена топлива"))
    {
        return;
    }

    // Получаем данные из полей ввода
    QString category = ui->checkBox->isChecked() ? "0" : "1";
    QString brand = ui->lineEdit_brand->text();
    QString color = ui->lineEdit_color->text();
    QString fuel_volume = ui->lineEdit_fuelTankVolume->text();
    QString max_weight = ui->lineEdit_loadCapacity->text();
    QString fuel_power = ui->lineEdit_fuelConsumption->text();
    QString fuel_price = ui->lineEdit_fuelPrice->text();

    // Формируем запрос к серверу
    QString transportCostData = QString("cars %1 %2 %3 %4 %5 %6 %7")
                                    .arg(category)
                                    .arg(brand)
                                    .arg(color)
                                    .arg(fuel_volume)
                                    .arg(max_weight)
                                    .arg(fuel_power)
                                    .arg(fuel_price);

    // Отправляем запрос и получаем ответ
    QByteArray response = clientApi->query_to_server(transportCostData);
    QString result = QString(response);

    // Обрабатываем результат
    ui->lineEdit_finish->setAlignment(Qt::AlignCenter);
    QString result_money = result.section(' ', 2, 2).trimmed();
    qDebug() << "Server response:" << result << "| Extracted money:" << result_money;

    bool ok;
    int money = result_money.toInt(&ok);

    if (ok && money > 0 && money < 1000000)
    {
        // Успешный результат - показываем стоимость
        ui->lineEdit_finish->setText(QString("%1 рублей").arg(money));
        ui->lineEdit_finish->setReadOnly(true);

        // Изменяем интерфейс для отображения результата
        ui->checkBox->setGeometry(390, 350, 151, 41);
        ui->comboBox_2->setGeometry(350, 150, 181, 61);
        ui->comboBox->setGeometry(350, 210, 181, 61);
        ui->lineEdit_fuelTankVolume->setGeometry(350, 280, 181, 61);
        ui->lineEdit_fuelConsumption->setGeometry(350, 400, 181, 41);
        ui->lineEdit_loadCapacity->setGeometry(350, 450, 181, 51);
        ui->lineEdit_fuelPrice->setGeometry(350, 510, 181, 51);
        ui->pushButton_calculateDistance->setVisible(false);
        ui->pushButton_calculateLoadCapacity->setVisible(false);
        ui->pushButton_calculateTransportCost->setVisible(false);
        ui->lineEdit_finish->setVisible(true);
        ui->pushButton_back->setVisible(true);
        ui->pushButton_back->setFocus();
        ui->pushButton_exit->setVisible(false);
        // Обновляем фон в зависимости от категории
        if (AuthRegForm::randomValue == 1) {
            AuthRegForm::loadBackground(ui->graphicsView3, scene3,
                                        category == "1" ? ":/dom/image/51.png"
                                                        : ":/dom/image/52.png");
        } else {
            AuthRegForm::loadBackground(ui->graphicsView3, scene3,
                                        category == "1" ? ":/dom/image/45.png"
                                                        : ":/dom/image/46.png");
        }
    }
    else {
        QMessageBox::warning(this, "Input error", "Введены некорректные данные!");
    }
}

void CarCalculationsForm::on_pushButton_calculateTransportCost_clicked()
{
    // Проверка заполненности всех полей
    if (ui->comboBox_2->currentText().isEmpty() ||
        ui->comboBox->currentText().isEmpty() ||
        ui->lineEdit_fuelTankVolume->text().isEmpty() ||
        ui->lineEdit_fuelConsumption->text().isEmpty() ||
        ui->lineEdit_loadCapacity->text().isEmpty() ||
        ui->lineEdit_fuelPrice->text().isEmpty())
    {
        QMessageBox::warning(this, "Input error", "Заполните все поля!");
        return;
    }

    // Проверка что все числовые поля содержат положительные числа
    auto checkPositive = [this](const QString& text, const QString& fieldName) -> bool {
        bool ok;
        double value = text.toDouble(&ok);
        if (!ok || value < 0) {
            QMessageBox::warning(this, "Input error",
                                 QString("%1 - параметр может быть только положительным числом!").arg(fieldName));
            return false;
        }
        return true;
    };

    if (!checkPositive(ui->lineEdit_fuelTankVolume->text(), "Объем топливного бака") ||
        !checkPositive(ui->lineEdit_fuelConsumption->text(), "Расход топлива") ||
        !checkPositive(ui->lineEdit_loadCapacity->text(), "Грузоподъемность") ||
        !checkPositive(ui->lineEdit_fuelPrice->text(), "Цена топлива"))
    {
        return;
    }

    // Получаем данные из полей ввода
    QString category = ui->checkBox->isChecked() ? "0" : "1";
    QString brand = ui->lineEdit_brand->text();
    QString color = ui->lineEdit_color->text();
    QString fuel_volume = ui->lineEdit_fuelTankVolume->text();
    QString max_weight = ui->lineEdit_loadCapacity->text();
    QString fuel_power = ui->lineEdit_fuelConsumption->text();
    QString fuel_price = ui->lineEdit_fuelPrice->text();

    // Формируем запрос к серверу
    QString transportCostData = QString("cars %1 %2 %3 %4 %5 %6 %7")
                                    .arg(category)
                                    .arg(brand)
                                    .arg(color)
                                    .arg(fuel_volume)
                                    .arg(max_weight)
                                    .arg(fuel_power)
                                    .arg(fuel_price);

    // Отправляем запрос и получаем ответ
    QByteArray response = clientApi->query_to_server(transportCostData);
    QString result = QString(response);

    // Обрабатываем результат
    ui->lineEdit_finish->setAlignment(Qt::AlignCenter);
    QString result_gruj = result.section(' ', 3, 3).trimmed();
    QString price = ui->lineEdit_fuelPrice->text();
    qDebug() << "Server response:" << result << "| Extracted transport cost:" << result_gruj;

    bool ok;
    double transportCost = result_gruj.toDouble(&ok);
    double fuelPrice = price.toDouble(&ok);

    if (ok && transportCost > 0 && transportCost < 10000000)
    {
        // Успешный результат - показываем стоимость перевозки
        ui->lineEdit_finish->setText(QString("%1 руб/(т·км)").arg(transportCost, 0, 'f', 2));
        ui->lineEdit_finish->setReadOnly(true);

        // Изменяем интерфейс для отображения результата
        ui->checkBox->setGeometry(390, 350, 151, 41);
        ui->comboBox_2->setGeometry(350, 150, 181, 61);
        ui->comboBox->setGeometry(350, 210, 181, 61);
        ui->lineEdit_fuelTankVolume->setGeometry(350, 280, 181, 61);
        ui->lineEdit_fuelConsumption->setGeometry(350, 400, 181, 41);
        ui->lineEdit_loadCapacity->setGeometry(350, 450, 181, 51);
        ui->lineEdit_fuelPrice->setGeometry(350, 510, 181, 51);
        ui->pushButton_calculateDistance->setVisible(false);
        ui->pushButton_calculateLoadCapacity->setVisible(false);
        ui->pushButton_calculateTransportCost->setVisible(false);
        ui->lineEdit_finish->setVisible(true);
        ui->pushButton_back->setVisible(true);
        ui->pushButton_back->setFocus();
        ui->pushButton_exit->setVisible(false);
        // Обновляем фон в зависимости от категории
        if (AuthRegForm::randomValue == 1) {
            AuthRegForm::loadBackground(ui->graphicsView3, scene3,
                                        category == "1" ? ":/dom/image/53.png"
                                                        : ":/dom/image/54.png");
        } else {
            AuthRegForm::loadBackground(ui->graphicsView3, scene3,
                                        category == "1" ? ":/dom/image/47.png"
                                                        : ":/dom/image/48.png");
        }
    }
    else if (result_gruj == "nan" && fuelPrice > 0) {QMessageBox::warning(this, "No input error", "Данная характеристика расчитывается только для грузовых автомобилей!"); }
    else { QMessageBox::warning(this, "Input error", "Введены некорректные данные!"); }
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
    ui->pushButton_exit->setVisible(true);
    if (AuthRegForm::randomValue == 1) {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, ":/dom/image/42.png");
    } else {
        AuthRegForm::loadBackground(ui->graphicsView3, scene3, ":/dom/image/41.png");
    }
}


void CarCalculationsForm::on_pushButton_exit_clicked()
{
    //QString back = ui->lineEdit_loadCapacity->text();
    //this->close();
    //emit to_back(back);
    QApplication::quit();
}

