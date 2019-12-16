#include "dialog_addnewcircle.h"
#include "ui_dialog_addnewcircle.h"

Dialog_AddNewCircle::Dialog_AddNewCircle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddNewCircle)
{
    ui->setupUi(this);
}

Dialog_AddNewCircle::~Dialog_AddNewCircle()
{
    delete ui;
}
