#include "dialog_addnewellipse.h"
#include "ui_dialog_addnewellipse.h"

Dialog_AddNewEllipse::Dialog_AddNewEllipse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddNewEllipse)
{
    ui->setupUi(this);
}

Dialog_AddNewEllipse::~Dialog_AddNewEllipse()
{
    delete ui;
}
