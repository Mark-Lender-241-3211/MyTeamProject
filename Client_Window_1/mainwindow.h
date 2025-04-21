#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <vector>
#include <cstdlib>
#include <ctime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<QString> quotes; // Вектор для хранения цитат

    void loadQuotes(); // Метод для загрузки цитат
    void displayRandomQuote(); // Метод для отображения случайной цитаты

public slots:
    void slot_show(QString);
private slots:
    void on_pushButton_exit_clicked();
};

#endif // MAINWINDOW_H
