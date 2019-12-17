#include "dialog_addnewtriangle.h"
#include "ui_dialog_addnewtriangle.h"

Dialog_AddNewTriangle::Dialog_AddNewTriangle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddNewTriangle)
{
    ui->setupUi(this);
}

Dialog_AddNewTriangle::~Dialog_AddNewTriangle()
{
    delete ui;
}
