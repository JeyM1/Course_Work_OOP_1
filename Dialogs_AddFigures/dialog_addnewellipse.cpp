#include <QValidator>
#include <QScreen>
#include <QDebug>
#include <QMessageBox>
#include "dialog_addnewellipse.h"
#include "ui_dialog_addnewellipse.h"

Dialog_AddNewEllipse::Dialog_AddNewEllipse(ArrayOfObjectsOnScreen* lst, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddNewEllipse)
{
    list_handler = lst;
    ui->setupUi(this);
    QSize size = qApp->screens()[0]->size();
    this->ui->lineEdit_x->setValidator(new QIntValidator(0, size.width()));
    this->ui->lineEdit_y->setValidator(new QIntValidator(0, size.height()));
    this->ui->lineEdit_radius_horizontal->setValidator(new QDoubleValidator(0, size.width(), 5));
    this->ui->lineEdit_radius_vertical->setValidator(new QDoubleValidator(0, size.height(), 5));
}

Dialog_AddNewEllipse::~Dialog_AddNewEllipse()
{
    delete ui;
}

void Dialog_AddNewEllipse::on_btn_Add_clicked()
{
    bool bf_input_isAcceptable = true;
    if(!ui->lineEdit_x->hasAcceptableInput()){
        bf_input_isAcceptable = false;
        QMessageBox::warning(this, "Error!",
                             "Coordinate 'x' needs to be inside your screen! Its maximum value can be: " +
                             QString::number(qApp->screens()[0]->size().width()));
    }
    if(!ui->lineEdit_y->hasAcceptableInput()){
        bf_input_isAcceptable = false;
        QMessageBox::warning(this, "Error!",
                             "Coordinate 'y' needs to be inside your screen! Its maximum value can be: " +
                             QString::number(qApp->screens()[0]->size().height()));
    }
    if(!ui->lineEdit_radius_horizontal->hasAcceptableInput()){
        bf_input_isAcceptable = false;
        QMessageBox::warning(this, "Error!",
                             "Horizontal radius needs to be a number, that can render inside your screen! Its maximum value can be: " +
                             QString::number(qApp->screens()[0]->size().width()));
    }
    if(!ui->lineEdit_radius_vertical->hasAcceptableInput()){
        bf_input_isAcceptable = false;
        QMessageBox::warning(this, "Error!",
                             "Vertical radius needs to be a number, that can render inside your screen! Its maximum value can be: " +
                             QString::number(qApp->screens()[0]->size().height()));
    }
    if(bf_input_isAcceptable){
        list_handler->add(new Ellipse(ui->lineEdit_x->text().toInt(), ui->lineEdit_y->text().toInt(),
                                      ui->lineEdit_radius_vertical->text().toDouble(), ui->lineEdit_radius_horizontal->text().toDouble()));
        QMessageBox::information(this, "Success!", "Successfully added Ellipse!");
        close();
    }
}
