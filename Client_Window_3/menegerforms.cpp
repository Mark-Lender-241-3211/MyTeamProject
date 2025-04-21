#include "menegerforms.h"

MenegerForms::MenegerForms(QWidget *parent)
    : QMainWindow(parent)
{
    this->curr_auth = new AuthRegForm();
    this->main_form = new MainWindow();
    this->car_form = new CarCalculationsForm();
    this->curr_auth->show();

    connect(curr_auth, &AuthRegForm::reg_ok, main_form, &MainWindow::slot_help_show);
    connect(curr_auth, &AuthRegForm::auth_ok, car_form, &CarCalculationsForm::slot_car_show);
}

MenegerForms::~MenegerForms() {}
