#include <QValidator>
#include <QScreen>
#include <QDebug>
#include <QMessageBox>
#include "dialog_addnewcircle.h"
#include "ui_dialog_addnewcircle.h"


Dialog_AddNewCircle::Dialog_AddNewCircle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddNewCircle)
{
    ui->setupUi(this);
}

Dialog_AddNewCircle::Dialog_AddNewCircle(ArrayOfObjectsOnScreen* lst, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddNewCircle)
{
    list_handler = lst;
    ui->setupUi(this);
    QSize size = qApp->screens()[0]->size();
    this->ui->lineEdit_x->setValidator(new QIntValidator(0, size.width()));
    this->ui->lineEdit_y->setValidator(new QIntValidator(0, size.height()));
    this->ui->lineEdit_radius->setValidator(new QDoubleValidator(0, size.width(), 5));
}

Dialog_AddNewCircle::~Dialog_AddNewCircle()
{
    delete ui;
}

void Dialog_AddNewCircle::on_btn_Add_clicked()
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
    if(!ui->lineEdit_radius->hasAcceptableInput()){
        bf_input_isAcceptable = false;
        QMessageBox::warning(this, "Error!",
                             "Radius needs to be a number, that can render inside your screen! Its maximum value can be: " +
                             QString::number(qApp->screens()[0]->size().width()));
    }
    if(bf_input_isAcceptable){
        list_handler->add(new Circle(ui->lineEdit_x->text().toInt(), ui->lineEdit_y->text().toInt(),
                                     ui->lineEdit_radius->text().toDouble()));
        QMessageBox::information(this, "Success!", "Successfully added Circle!");
        close();
    }

}
