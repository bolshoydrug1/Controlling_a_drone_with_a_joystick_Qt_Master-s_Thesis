#include "f_select_ctrl.h"
#include "ui_f_select_ctrl.h"

F_select_ctrl::F_select_ctrl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::F_select_ctrl)
{
    ui->setupUi(this);
}

F_select_ctrl::~F_select_ctrl()
{
    delete ui;
}
