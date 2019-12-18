#include "dialog_drawablewindow.h"
#include "ui_dialog_drawablewindow.h"
#include <QDebug>
#include <QSize>
#include <QScreen>
#include <QPainter>
#include <iostream>

Dialog_DrawableWindow::Dialog_DrawableWindow(ArrayOfObjectsOnScreen* lst, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_DrawableWindow)
{
    this->list_handler = lst;
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
    btn_showlist_clicked = false;
    //repaint();
    /* Generation of table */
    ui->tableWidget->hide();
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
    //ui->tableWidget->horizontalHeader()->;
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "id"
                                               << "Central x coordinate"
                                               << "Central y coordinate"
                                               << "Square"
                                               << "Figure type");
    ui->tableWidget->hideColumn(0);
    for(int i = 0; i < list_handler->size(); i++){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number((*list_handler)[i]->getX())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number((*list_handler)[i]->getY())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number((*list_handler)[i]->getSquare())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString((*list_handler)[i]->name())));
    }
    ui->tableWidget->resizeColumnsToContents();

}

Dialog_DrawableWindow::~Dialog_DrawableWindow()
{
    delete ui;
}

void Dialog_DrawableWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    Q_UNUSED(event)
    std::cout << "PAINT EVENT" << std::endl;
    //painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    for(int i = 0; i < (int)this->list_handler->size(); i++){
        Figure* curr_obj = (*list_handler)[i];
        if(curr_obj->getFigureName() == FigureName::Circle){
            Circle* casted = dynamic_cast<Circle*>(curr_obj);
            QRectF drawable(casted->getX() - casted->getRadius()/2, casted->getY() - casted->getRadius()/2, casted->getRadius(), casted->getRadius());
            painter.drawEllipse(drawable);
        }
        if(curr_obj->getFigureName() == FigureName::Triangle){
            Triangle* casted = dynamic_cast<Triangle*>(curr_obj);
            QPainterPath path;
            path.moveTo(casted->getPoints().A.getX(), casted->getPoints().A.getY());
            path.lineTo(casted->getPoints().B.getX(), casted->getPoints().B.getY());
            path.lineTo(casted->getPoints().C.getX(), casted->getPoints().C.getY());
            path.lineTo(casted->getPoints().A.getX(), casted->getPoints().A.getY());
            painter.drawPath(path);
        }
        if(curr_obj->getFigureName() == FigureName::Rectangle){
            Rectangle* casted = dynamic_cast<Rectangle*>(curr_obj);
            QRectF drawable(casted->getX() - casted->getA()/2, casted->getY() - casted->getB()/2, casted->getA(), casted->getB());
            painter.drawRect(drawable);
        }
        if(curr_obj->getFigureName() == FigureName::Ellipse){
            Ellipse* casted = dynamic_cast<Ellipse*>(curr_obj);
            QRectF drawable(casted->getX() - casted->getRadiusHorizontal()/2, casted->getY() - casted->getRadiusVertical()/2,
                            casted->getRadiusHorizontal(), casted->getRadiusVertical());
            painter.drawEllipse(drawable);
        }
    }

}

void Dialog_DrawableWindow::on_btn_showlist_clicked()
{
    if(!btn_showlist_clicked){
        this->ui->btn_showlist->setFlat(true);
        this->ui->btn_showlist->setDefault(true);
        this->ui->btn_showlist->setText("Hide list of figures");
        ui->tableWidget->show();
    }else{
        this->ui->btn_showlist->setFlat(false);
        this->ui->btn_showlist->setDefault(false);
        ui->tableWidget->hide();
        this->ui->btn_showlist->setText("Show list of figures");
    }
    btn_showlist_clicked = !btn_showlist_clicked;
}
