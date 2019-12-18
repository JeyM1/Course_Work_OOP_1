#include <QValidator>
#include <QScreen>
#include <QDebug>
#include <QMessageBox>
#include "dialog_addnewtriangle.h"
#include "ui_dialog_addnewtriangle.h"


Dialog_AddNewTriangle::Dialog_AddNewTriangle(ArrayOfObjectsOnScreen* lst, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddNewTriangle)
{
    list_handler = lst;
    ui->setupUi(this);
    QSize size = qApp->screens()[0]->size();
    this->ui->lineEdit_A_X->setValidator(new QIntValidator(0, size.width()));
    this->ui->lineEdit_A_Y->setValidator(new QIntValidator(0, size.height()));
    this->ui->lineEdit_B_X->setValidator(new QIntValidator(0, size.width()));
    this->ui->lineEdit_B_Y->setValidator(new QIntValidator(0, size.height()));
    this->ui->lineEdit_C_X->setValidator(new QIntValidator(0, size.width()));
    this->ui->lineEdit_C_Y->setValidator(new QIntValidator(0, size.height()));
}

Dialog_AddNewTriangle::~Dialog_AddNewTriangle()
{
    delete ui;
}

void Dialog_AddNewTriangle::on_btn_Add_clicked()
{
    bool bf_input_isAcceptable = true;
    if(!(ui->lineEdit_A_X->hasAcceptableInput() || ui->lineEdit_A_Y->hasAcceptableInput() ||
         ui->lineEdit_B_X->hasAcceptableInput() || ui->lineEdit_B_Y->hasAcceptableInput() ||
         ui->lineEdit_C_X->hasAcceptableInput() || ui->lineEdit_C_Y->hasAcceptableInput())){
        bf_input_isAcceptable = false;
        QMessageBox::warning(this, "Error!",
                             "Coordinates 'x' and 'y' needs to be inside your screen! Its maximum value can be: " +
                             QString::number(qApp->screens()[0]->size().width()) + "x" + QString::number(qApp->screens()[0]->size().width()));
    }

    if(bf_input_isAcceptable){
        list_handler->add(new Triangle(Point(ui->lineEdit_A_X->text().toInt(), ui->lineEdit_A_Y->text().toInt()),
                                       Point(ui->lineEdit_B_X->text().toInt(), ui->lineEdit_B_Y->text().toInt()),
                                       Point(ui->lineEdit_C_X->text().toInt(), ui->lineEdit_C_Y->text().toInt())));
        QMessageBox::information(this, "Success!", "Successfully added Triangle!");
        close();
    }
}
