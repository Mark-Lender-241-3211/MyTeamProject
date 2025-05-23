#ifndef CARCALCULATIONSFORM_H
#define CARCALCULATIONSFORM_H

#include <QDialog>
#include "clientapi.h"
#include "authregform.h"
#include <QMouseEvent>
#include <QLineEdit>

namespace Ui {
class CarCalculationsForm;
}

class CarCalculationsForm : public QDialog {
    Q_OBJECT

public:
    explicit CarCalculationsForm(QWidget *parent = nullptr);
    ~CarCalculationsForm();
    static void applyErrorStyleToLineEdit(QLineEdit* lineEdit);
    static void applyErrorStyleToLineEditBack(QLineEdit* lineEdit);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    bool eventFilter(QObject *obj, QEvent *event) override;

public slots:
    void slot_car_show(QString);

private slots:
    void on_pushButton_calculateDistance_clicked();
    void on_pushButton_calculateTransportCost_clicked();
    void on_pushButton_calculateLoadCapacity_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_exit_clicked();

signals:
    void to_back(QString);

private:
    Ui::CarCalculationsForm *ui;
    ClientAPI *clientApi;
    AuthRegForm *AuthReg;
    QGraphicsScene* scene3;

    QPoint m_dragPosition;
    bool m_mousePressed = false;
};

#endif // CARCALCULATIONSFORM_H
