#include "menegerforms.h"

MenegerForms::MenegerForms(QWidget *parent)
    : QMainWindow(parent)
{
    this->curr_auth = new AuthRegForm();
    this->curr_auth->setFixedSize(960, 720);
    this->car_form = new CarCalculationsForm();
    this->car_form->setFixedSize(960, 720);
    this->pass_form = new new_pass_form();
    this->pass_form->setFixedSize(960, 720);
    this->curr_auth->show();

    connect(curr_auth, &AuthRegForm::auth_ok, car_form, &CarCalculationsForm::slot_car_show);
    connect(curr_auth, &AuthRegForm::pass_no, pass_form, &new_pass_form::slot_pass_no_show);
    connect(pass_form, &new_pass_form::pass_ok, curr_auth, &AuthRegForm::slot_auth_reg_show);
    //connect(car_form, &CarCalculationsForm::to_back, curr_auth, &AuthRegForm::slot_auth_reg_show);
}

MenegerForms::~MenegerForms() {}
