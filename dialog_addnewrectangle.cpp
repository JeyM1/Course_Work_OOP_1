#include "dialog_addnewrectangle.h"
#include "ui_dialog_addnewrectangle.h"

Dialog_AddNewRectangle::Dialog_AddNewRectangle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddNewRectangle)
{
    ui->setupUi(this);
}

Dialog_AddNewRectangle::~Dialog_AddNewRectangle()
{
    delete ui;
}
