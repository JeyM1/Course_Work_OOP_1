#include "dialog_findfigure.h"
#include "ui_dialog_findfigure.h"
#include <QDebug>
#include <QStandardItem>
#include <QLineEdit>
#include <QComboBox>

Dialog_FindFigure::Dialog_FindFigure(ArrayOfObjectsOnScreen* lst, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_FindFigure)
{
	list_handler = lst;
	ui->setupUi(this);
	ui->btn_find->setEnabled(false);
	ui->CB_figure_type->
	connect(ui->CB_figure_type, (void (QComboBox::*)(const QString &))&QComboBox::activated, this, &Dialog_FindFigure::CB_first_time_clicked);

	//making first item not selectable
	QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->CB_figure_type->model());
	QModelIndex firstIndex = model->index(0, ui->CB_figure_type->modelColumn(), ui->CB_figure_type->rootModelIndex());
	QStandardItem* firstItem = model->itemFromIndex(firstIndex);
	firstItem->setEnabled(false);
}

Dialog_FindFigure::~Dialog_FindFigure()
{
	delete ui;
}

void Dialog_FindFigure::on_btn_find_clicked()
{

}

void Dialog_FindFigure::on_CB_figure_type_activated(int index)
{
	qDebug() << "ACTIVATED: " << index << endl;
}

void Dialog_FindFigure::CB_first_time_clicked(const QString&)
{
	ui->btn_find->setEnabled(true);
	disconnect(ui->CB_figure_type, (void (QComboBox::*)(const QString &))&QComboBox::activated, this, &Dialog_FindFigure::CB_first_time_clicked);
}
