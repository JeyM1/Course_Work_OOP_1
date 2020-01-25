#include <QValidator>
#include <QScreen>
#include <QDebug>
#include <QMessageBox>
#include "dialog_addnewrectangle.h"
#include "ui_dialog_addnewrectangle.h"

Dialog_AddNewRectangle::Dialog_AddNewRectangle(ArrayOfObjectsOnScreen* lst, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddNewRectangle)
{
    list_handler = lst;
    ui->setupUi(this);
    QSize size = qApp->screens()[0]->size();
    this->ui->lineEdit_x->setValidator(new QIntValidator(0, size.width()));
    this->ui->lineEdit_y->setValidator(new QIntValidator(0, size.height()));
    this->ui->lineEdit_a->setValidator(new QDoubleValidator(0, size.width(), 5));
    this->ui->lineEdit_b->setValidator(new QDoubleValidator(0, size.width(), 5));
}

Dialog_AddNewRectangle::~Dialog_AddNewRectangle()
{
    delete ui;
}



void Dialog_AddNewRectangle::on_btn_Add_clicked()
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
    if(!ui->lineEdit_a->hasAcceptableInput() || !ui->lineEdit_a->hasAcceptableInput()){
        bf_input_isAcceptable = false;
        QMessageBox::warning(this, "Error!",
                             "Side of Rectangle needs to be a number, that can render inside your screen! Its maximum value can be: " +
                             QString::number(qApp->screens()[0]->size().width()) + "x" + QString::number(qApp->screens()[0]->size().height()));
    }
    if(bf_input_isAcceptable){
        list_handler->add(new Rectangle(this->ui->lineEdit_x->text().toInt(), this->ui->lineEdit_x->text().toInt(),
                                        this->ui->lineEdit_a->text().toDouble(), this->ui->lineEdit_b->text().toDouble()));
        QMessageBox::information(this, "Success!", "Successfully added Rectangle!");
        close();
    }
}
