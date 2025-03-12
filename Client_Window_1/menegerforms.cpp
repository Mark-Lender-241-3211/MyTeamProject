#include "menegerforms.h"

MenegerForms::MenegerForms(QWidget *parent)
    : QMainWindow(parent)
{
    this->curr_auth = new AuthRegForm();
    this->main_form = new MainWindow();
    this->curr_auth->show();
    connect(curr_auth, &AuthRegForm::auth_ok, main_form, &MainWindow::slot_show);
}

MenegerForms::~MenegerForms() {}
