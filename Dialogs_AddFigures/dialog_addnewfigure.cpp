#include "dialog_addnewfigure.h"
#include "ui_dialog_addnewfigure.h"
#include "dialog_addnewcircle.h"
#include "dialog_addnewtriangle.h"
#include "dialog_addnewrectangle.h"
#include "dialog_addnewellipse.h"

Dialog_AddNewFigure::Dialog_AddNewFigure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddNewFigure)
{
    ui->setupUi(this);
}

Dialog_AddNewFigure::Dialog_AddNewFigure(ArrayOfObjectsOnScreen* lst, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddNewFigure)
{
    list_handler = lst;
    ui->setupUi(this);
}

Dialog_AddNewFigure::~Dialog_AddNewFigure()
{
    delete ui;
}

void Dialog_AddNewFigure::on_btn_addCircle_clicked()
{
    Dialog_AddNewCircle wind_add(list_handler, this);
    wind_add.setModal(true);
    wind_add.exec();
}

void Dialog_AddNewFigure::on_btn_addTriangle_clicked()
{
    Dialog_AddNewTriangle wind_add(list_handler, this);
    wind_add.setModal(true);
    wind_add.exec();
}

void Dialog_AddNewFigure::on_btn_addRect_clicked()
{
    Dialog_AddNewRectangle wind_add(list_handler, this);
    wind_add.setModal(true);
    wind_add.exec();
}

void Dialog_AddNewFigure::on_btn_addEllipse_clicked()
{
    Dialog_AddNewEllipse wind_add(list_handler, this);
    wind_add.setModal(true);
    wind_add.exec();
}
