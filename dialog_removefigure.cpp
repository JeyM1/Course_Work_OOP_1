#include "dialog_removefigure.h"
#include "ui_dialog_removefigure.h"
#include <QPushButton>
#include <QDebug>
#include <QObject>

Dialog_RemoveFigure::Dialog_RemoveFigure(ArrayOfObjectsOnScreen* lst, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_RemoveFigure)
{
    list_handler = lst;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
    //ui->tableWidget->horizontalHeader()->;
    tableWidgetUpdate();

}

Dialog_RemoveFigure::~Dialog_RemoveFigure()
{
    delete ui;
}

void Dialog_RemoveFigure::tableWidgetUpdate(){
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "id"
                                               << "Central point"
                                               << "Square"
                                               << "Figure type"
                                               << "Action");
    ui->tableWidget->hideColumn(0);
    for(int i = 0; i < list_handler->size(); i++){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem("[" + QString::number((*list_handler)[i]->getX()) +
                                                            ", " + QString::number((*list_handler)[i]->getY()) + "]"));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number((*list_handler)[i]->getSquare())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString((*list_handler)[i]->name())));
        QWidget* pWidget = new QWidget();
        QPushButton* btn_remove = new QPushButton();
        connect(btn_remove, SIGNAL(clicked()), SLOT(tableWidget_onClicked()));
        btn_remove->setText("Remove");
        btn_remove->setProperty("row", i);
        QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
        pLayout->addWidget(btn_remove);
        pLayout->setAlignment(Qt::AlignCenter);
        pLayout->setContentsMargins(0, 0, 0, 0);
        pWidget->setLayout(pLayout);
        ui->tableWidget->setCellWidget(i, 4, pWidget);
    }
    ui->tableWidget->resizeColumnsToContents();
}

void Dialog_RemoveFigure::tableWidget_onClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    QVariant var = button->property("row");
    if (!var.isValid()) return;
    list_handler->remove(var.toInt());
    tableWidgetUpdate();
}
