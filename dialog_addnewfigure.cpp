#include "dialog_addnewfigure.h"
#include "ui_dialog_addnewfigure.h"

Dialog_AddNewFigure::Dialog_AddNewFigure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddNewFigure)
{
    ui->setupUi(this);
}

Dialog_AddNewFigure::~Dialog_AddNewFigure()
{
    delete ui;
}
