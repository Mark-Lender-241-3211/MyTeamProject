#ifndef CARCALCULATIONSFORM_H
#define CARCALCULATIONSFORM_H

#include <QDialog>
#include "clientapi.h"

namespace Ui {
class CarCalculationsForm; // Форвард-декларация
}

class CarCalculationsForm : public QDialog {
    Q_OBJECT

public:
    explicit CarCalculationsForm(QWidget *parent = nullptr);
    ~CarCalculationsForm();

public slots:
    void slot_car_show(QString);

private slots:
    void on_pushButton_calculateDistance_clicked();
    void on_pushButton_calculateTransportCost_clicked();
    void on_pushButton_calculateLoadCapacity_clicked();

private:
    Ui::CarCalculationsForm *ui; // Указатель на UI
    ClientAPI *clientApi;        // Указатель на ClientAPI
};

#endif // CARCALCULATIONSFORM_H
