#ifndef MENEGERFORMS_H
#define MENEGERFORMS_H

#include <QMainWindow>
#include "authregform.h"
#include "mainwindow.h"
#include "carcalculationsform.h"
#include "new_pass_form.h"

class MenegerForms : public QMainWindow {
    Q_OBJECT

public:
    explicit MenegerForms(QWidget *parent = nullptr);
    ~MenegerForms();

private:
    AuthRegForm *curr_auth;
    //MainWindow *main_form;
    CarCalculationsForm *car_form;
    new_pass_form *pass_form;
};

#endif // MENEGERFORMS_H
