#ifndef NEW_PASS_FORM_H
#define NEW_PASS_FORM_H

#include <QWidget>
#include "authregform.h"
#include "clientapi.h"
#include "functions_to_client.h"

namespace Ui {
class new_pass_form;
}

class new_pass_form : public QWidget
{
    Q_OBJECT

public:
    explicit new_pass_form(QWidget *parent = nullptr);
    ~new_pass_form();

public slots:
    void slot_pass_no_show(QString);

private slots:
    void on_pushButton_continue_clicked();
    void on_pushButton_exit_clicked();

private:
    Ui::new_pass_form *ui;
    ClientAPI *clientApi; // Указатель на ClientAPI
    AuthRegForm *AuthReg; // Указатель на ClientAPI
    QString generatedCode;
    bool isCodeGenerated;   // Флаг для проверки, был ли код сгенерирован
    QGraphicsScene* scene2; // Сцена для graphicsView2
    // AuthRegForm authReg;  // Убрали, так как используем статический метод

signals:
    void pass_ok(QString);
};

#endif // NEW_PASS_FORM_H
