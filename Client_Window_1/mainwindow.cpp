#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    loadQuotes(); // Загружаем цитаты
    displayRandomQuote(); // Отображаем случайную цитату
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadQuotes() {
    // Заполняем вектор цитат
    quotes.push_back("Я живу свою жизнь четверть мили за раз...");
    quotes.push_back("Неважно, выиграл ты на дюйм или на милю. Победа есть победа.");
    quotes.push_back("Автомобиль достиг полного совершенства, — дальнейшего его улучшения не требуется");
    quotes.push_back("Дешевле иметь 35 автомобилей и одну женщину, чем 35 женщин и один автомобиль");
    quotes.push_back("Моя жизнь длится всего 10 секунд – между стартом и разгоном.");
    quotes.push_back("...Я из тех кто может оценить красивые формы в любой модели...");
    quotes.push_back("Высшая ступень автомобилизации будет достигнута тогда, когда парковка станет дороже, чем езда на автомобиле");
    quotes.push_back("Куда люди так торопятся в час пик? Постоять в пробке?");
    quotes.push_back("Только ты выбираешь, как управлять своим путем.");
    quotes.push_back("Самая быстрое угонка — это путь к мечте.");
}

void MainWindow::displayRandomQuote() {
    int randomIndex = rand() % quotes.size(); // Получаем случайный индекс
    ui->textBrowser->setHtml("<p align=\"center\">" + quotes[randomIndex] + "</p>"); // Устанавливаем текст в QTextBrowser
}

void MainWindow::slot_show(QString login)
{
    this->show();
}

void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}
