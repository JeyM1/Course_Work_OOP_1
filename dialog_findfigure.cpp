#include "dialog_findfigure.h"
#include "ui_dialog_findfigure.h"
#include <QDebug>
#include <QValidator>
#include <QStandardItem>
#include <QLineEdit>
#include <QComboBox>
#include <QPropertyAnimation>
#include <memory>
#include "dialog_foundfigures.h"

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

	model = qobject_cast<QStandardItemModel*>(ui->CB_search_param->model());
	firstIndex = model->index(0, ui->CB_figure_type->modelColumn(), ui->CB_search_param->rootModelIndex());
	firstItem = model->itemFromIndex(firstIndex);
	firstItem->setEnabled(false);

	ui->CB_search_param->setEnabled(false);
	ui->btn_find->setEnabled(false);

	//hiding search widgets
	hideAllWidgets();

	//setting validators
	ui->LE_x->setValidator(new QIntValidator(0, 9999));
	ui->LE_y->setValidator(new QIntValidator(0, 9999));
	ui->LE_square->setValidator(new QDoubleValidator(0, Q_INFINITY, 15));
	//circle
	ui->LE_radius->setValidator(new QDoubleValidator(0, Q_INFINITY, 15));
	//triangle
	ui->LE_A_x->setValidator(new QIntValidator(0, 9999));
	ui->LE_A_y->setValidator(new QIntValidator(0, 9999));
	ui->LE_B_x->setValidator(new QIntValidator(0, 9999));
	ui->LE_B_y->setValidator(new QIntValidator(0, 9999));
	ui->LE_C_x->setValidator(new QIntValidator(0, 9999));
	ui->LE_C_y->setValidator(new QIntValidator(0, 9999));
	//rect
	ui->LE_width->setValidator(new QDoubleValidator(0, Q_INFINITY, 15));
	ui->LE_height->setValidator(new QDoubleValidator(0, Q_INFINITY, 15));
	//ellipse
	ui->LE_horizontal->setValidator(new QDoubleValidator(0, Q_INFINITY, 15));
	ui->LE_vertical->setValidator(new QDoubleValidator(0, Q_INFINITY, 15));
}

Dialog_FindFigure::~Dialog_FindFigure()
{
	delete ui;
}

void Dialog_FindFigure::on_CB_figure_type_activated(int index)
{
	//if user activates combobox again, hide all widgets and make button 'Find' unaccessable
	//until he choose params
	hideAllWidgets();
	ui->btn_find->setEnabled(false);
	QObject *context = new QObject(this);
	    connect(ui->CB_search_param, (void (QComboBox::*)(int))&QComboBox::activated, context,
		        [this, context](int) mutable {
			delete context;
			ui->btn_find->setEnabled(true);
	});

	//clearing all params
	int size = ui->CB_search_param->count();
	for(int i = 1; i < size; i++){
		ui->CB_search_param->removeItem(1);
	}
	//adding new params depending on type
	switch(index){
	case 1:
	{

		ui->CB_search_param->insertItems(1, QStringList() << "By central Point"
		                                 << "By Square");
		break;
	}
	case 2:
	{
		ui->CB_search_param->insertItems(1, QStringList() << "By central Point"
		                                 << "By Square"
		                                 << "By Radius");
		break;
	}
	case 3:
	{
		ui->CB_search_param->insertItems(1, QStringList() << "By central Point"
		                                 << "By Square"
		                                 << "By all Points");
		break;
	}
	case 4:
	{
		ui->CB_search_param->insertItems(1, QStringList() << "By central Point"
		                                 << "By Square"
		                                 << "By Width"
		                                 << "By Height"
		                                 << "By Width and Height");
		break;
	}
	case 5:
	{
		ui->CB_search_param->insertItems(1, QStringList() << "By central Point"
		                                 << "By Square"
		                                 << "By Horizontal Radius"
		                                 << "By Vertical Radius"
		                                 << "By both Radiuses");
		break;
	}
	}
}

void Dialog_FindFigure::CB_first_time_clicked(const QString&)
{
	disconnect(ui->CB_figure_type, (void (QComboBox::*)(const QString &))&QComboBox::activated, this, &Dialog_FindFigure::CB_first_time_clicked);
	ui->CB_search_param->setEnabled(true);
}


void Dialog_FindFigure::on_CB_search_param_activated(const QString &arg1)
{
	hideAllWidgets();
	if(arg1 == "By central Point"){
		ui->widget_point->setVisible(true);
	} else if(arg1 == "By Square"){
		ui->widget_square->setVisible(true);
	} else if(arg1 == "By Radius"){
		ui->widget_radius->setVisible(true);
	} else if(arg1 == "By all Points"){
		ui->widget_points->setVisible(true);
	} else if(arg1 == "By Width"){
		ui->widget_rect->setVisible(true);
		ui->widget_width->setVisible(true);
	} else if(arg1 == "By Height"){
		ui->widget_rect->setVisible(true);
		ui->widget_height->setVisible(true);
	} else if(arg1 == "By Width and Height"){
		ui->widget_rect->setVisible(true);
		ui->widget_width->setVisible(true);
		ui->widget_height->setVisible(true);
	} else if(arg1 == "By Horizontal Radius"){
		ui->widget_ellipse->setVisible(true);
		ui->widget_horizontal->setVisible(true);
	} else if(arg1 == "By Vertical Radius"){
		ui->widget_ellipse->setVisible(true);
		ui->widget_vertical->setVisible(true);
	} else if(arg1 == "By both Radiuses"){
		ui->widget_ellipse->setVisible(true);
		ui->widget_horizontal->setVisible(true);
		ui->widget_vertical->setVisible(true);
	}
}

void Dialog_FindFigure::hideAllWidgets()
{
	ui->widget_point->setVisible(false);
	ui->widget_square->setVisible(false);

	//circle
	ui->widget_radius->setVisible(false);
	//triangle
	ui->widget_points->setVisible(false);
	//rectangle
	ui->widget_rect->setVisible(false);
	ui->widget_width->setVisible(false);
	ui->widget_height->setVisible(false);
	//ellipse
	ui->widget_ellipse->setVisible(false);
	ui->widget_horizontal->setVisible(false);
	ui->widget_vertical->setVisible(false);
}

std::vector<int> Dialog_FindFigure::find()
{
	std::vector<int> ret;
	if(ui->CB_figure_type->currentText() == ui->CB_figure_type->itemText(1)){ //Any
		if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(1)){ //centr Point TUT OWIBKA

			ret = list_handler->find_by_point(Point(ui->LE_x->text().toInt(), ui->LE_y->text().toInt()));
		} else if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(2)){ //Square
			ret = list_handler->find_by_square(ui->LE_square->text().toDouble());
		}
	} else if(ui->CB_figure_type->currentText() == ui->CB_figure_type->itemText(2)){ //Circle
		//for Circles only
		if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(1)){ //centr Point
			ret = list_handler->find_by_point(Point(ui->LE_x->text().toInt(), ui->LE_y->text().toInt()), FigureName::Circle);
		} else if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(2)){ //Square
			ret = list_handler->find_by_square(ui->LE_square->text().toDouble(), FigureName::Circle);
		} else if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(3)){ //Radius
			for(int i = 0; i < list_handler->size(); i++){
				Figure* working = (*list_handler)[i];
				if(working->getFigureName() == FigureName::Circle &&
				        dynamic_cast<Circle*>(working)->getRadius() == ui->LE_radius->text().toDouble()){
					ret.push_back(i);
				}
			}
		}
	} else if(ui->CB_figure_type->currentText() == ui->CB_figure_type->itemText(3)){ //Triangle
		//for Triangles only
		if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(1)){ //centr Point
			ret = list_handler->find_by_point(Point(ui->LE_x->text().toInt(), ui->LE_y->text().toInt()), FigureName::Triangle);
		} else if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(2)){ //Square
			ret = list_handler->find_by_square(ui->LE_square->text().toDouble(), FigureName::Triangle);
		} else if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(3)){ //all Points
			Triangle::Points pnts;
			pnts.A = Point(ui->LE_A_x->text().toInt(), ui->LE_A_y->text().toInt());
			pnts.B = Point(ui->LE_B_x->text().toInt(), ui->LE_B_y->text().toInt());
			pnts.C = Point(ui->LE_C_x->text().toInt(), ui->LE_C_y->text().toInt());
			for(int i = 0; i < list_handler->size(); i++){
				Figure* working = (*list_handler)[i];
				if(working->getFigureName() == FigureName::Triangle &&
				        dynamic_cast<Triangle*>(working)->getrPoints() == pnts){
					ret.push_back(i);
				}
			}
		}
	} else if(ui->CB_figure_type->currentText() == ui->CB_figure_type->itemText(4)){ //Rectangle
		//for Rectangles only
		if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(1)){ //centr Point
			ret = list_handler->find_by_point(Point(ui->LE_x->text().toInt(), ui->LE_y->text().toInt()), FigureName::Rectangle);
		} else if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(2)){ //Square
			ret = list_handler->find_by_square(ui->LE_square->text().toDouble(), FigureName::Rectangle);
		} else if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(3)){ //Width
			for(int i = 0; i < list_handler->size(); i++){
				Figure* working = (*list_handler)[i];
				if(working->getFigureName() == FigureName::Rectangle &&
				        dynamic_cast<Rectangle*>(working)->getA() == ui->LE_width->text().toDouble()){
					ret.push_back(i);
				}
			}
		} else if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(4)){ //Height
			for(int i = 0; i < list_handler->size(); i++){
				Figure* working = (*list_handler)[i];
				if(working->getFigureName() == FigureName::Rectangle &&
				        dynamic_cast<Rectangle*>(working)->getB() == ui->LE_height->text().toDouble()){
					ret.push_back(i);
				}
			}
		} else if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(5)){ //Width & Height
			for(int i = 0; i < list_handler->size(); i++){
				Figure* working = (*list_handler)[i];
				if(working->getFigureName() == FigureName::Rectangle &&
				        dynamic_cast<Rectangle*>(working)->getA() == ui->LE_width->text().toDouble() &&
				        dynamic_cast<Rectangle*>(working)->getB() == ui->LE_height->text().toDouble()){
					ret.push_back(i);
				}
			}
		}
	} else if(ui->CB_figure_type->currentText() == ui->CB_figure_type->itemText(5)){ //Ellipse
		//for Ellipse only
		if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(1)){ //centr Point
			ret = list_handler->find_by_point(Point(ui->LE_x->text().toInt(), ui->LE_y->text().toInt()), FigureName::Ellipse);
		} else if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(2)){ //Square
			ret = list_handler->find_by_square(ui->LE_square->text().toDouble(), FigureName::Ellipse);
		} else if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(3)){ //Horizontal radius
			for(int i = 0; i < list_handler->size(); i++){
				Figure* working = (*list_handler)[i];
				if(working->getFigureName() == FigureName::Ellipse &&
				        dynamic_cast<Ellipse*>(working)->getRadiusHorizontal() == ui->LE_horizontal->text().toDouble()){
					ret.push_back(i);
				}
			}
		} else if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(4)){ //Vertical radius
			for(int i = 0; i < list_handler->size(); i++){
				Figure* working = (*list_handler)[i];
				if(working->getFigureName() == FigureName::Ellipse &&
				        dynamic_cast<Ellipse*>(working)->getRadiusVertical() == ui->LE_vertical->text().toDouble()){
					ret.push_back(i);
				}
			}
		} else if(ui->CB_search_param->currentText() == ui->CB_search_param->itemText(5)){ //Horizontal & Vertical
			for(int i = 0; i < list_handler->size(); i++){
				Figure* working = (*list_handler)[i];
				if(working->getFigureName() == FigureName::Ellipse &&
				        dynamic_cast<Ellipse*>(working)->getRadiusHorizontal() == ui->LE_horizontal->text().toDouble() &&
				        dynamic_cast<Ellipse*>(working)->getRadiusVertical() == ui->LE_vertical->text().toDouble()){
					ret.push_back(i);
				}
			}
		}
	}
	return ret;
}


void Dialog_FindFigure::on_btn_find_clicked()
{
	std::vector<int> found = find();
	qDebug() << found[0] << endl;
	Dialog_FoundFigures wnd_found(ui->CB_figure_type->currentIndex(), found, list_handler, this);
	wnd_found.setModal(true);
	wnd_found.exec();
}
