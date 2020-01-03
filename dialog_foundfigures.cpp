#include "dialog_foundfigures.h"
#include "ui_dialog_foundfigures.h"


Dialog_FoundFigures::Dialog_FoundFigures(int mode, std::vector<int>& found, ArrayOfObjectsOnScreen* lst, Dialog_FindFigure* parent) :
    QDialog(parent),
    ui(new Ui::Dialog_FoundFigures)
{
	this->found = found;
	this->mode = mode;
	list_handler = lst;
	ui->setupUi(this);
	tableUpdate();
}

Dialog_FoundFigures::~Dialog_FoundFigures()
{
	delete ui;
}

//TODO:
void Dialog_FoundFigures::tableUpdate()
{
	switch(this->mode){
	case 1:
	{
		ui->tableWidget->setColumnCount(5);
		this->ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "id"
		                                           << "Central x coordinate"
		                                           << "Central y coordinate"
		                                           << "Square"
		                                           << "Figure type");

		break;
	}
	case 2:
	{
		ui->tableWidget->setColumnCount(6);
		this->ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "id"
		                                           << "Central x coordinate"
		                                           << "Central y coordinate"
		                                           << "Square"
		                                           << "Figure type"
		                                           << "Radius");

		for(int i = 0; i < found.size(); i++){
			ui->tableWidget->insertRow(i);
			QTableWidgetItem* radius = new QTableWidgetItem(
			            QString::number(dynamic_cast<Circle*>((*list_handler)[found[i]])->getRadius()));
			radius->setFlags(radius->flags() ^ Qt::ItemIsEditable);
			ui->tableWidget->setItem(i, 5, radius);
		}
		break;
	}
	case 3:
	{
		ui->tableWidget->setColumnCount(8);
		this->ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "id"
		                                           << "Central x coordinate"
		                                           << "Central y coordinate"
		                                           << "Square"
		                                           << "Figure type"
		                                           << "Point A"
		                                           << "Point B"
		                                           << "Point C");

		for(int i = 0; i < found.size(); i++){
			Triangle* working = dynamic_cast<Triangle*>((*list_handler)[found[i]]);
			ui->tableWidget->insertRow(i);
			QTableWidgetItem* pnt_A = new QTableWidgetItem("[" + QString::number(working->getrPoints().A.getX())
			                                               + ", " + QString::number(working->getrPoints().A.getY()) + "]");
			QTableWidgetItem* pnt_B = new QTableWidgetItem("[" + QString::number(working->getrPoints().B.getX())
			                                               + ", " + QString::number(working->getrPoints().B.getY()) + "]");
			QTableWidgetItem* pnt_C = new QTableWidgetItem("[" + QString::number(working->getrPoints().C.getX())
			                                               + ", " + QString::number(working->getrPoints().C.getY()) + "]");
			pnt_A->setFlags(pnt_A->flags() ^ Qt::ItemIsEditable);
			pnt_B->setFlags(pnt_B->flags() ^ Qt::ItemIsEditable);
			pnt_C->setFlags(pnt_C->flags() ^ Qt::ItemIsEditable);
			ui->tableWidget->setItem(i, 5, pnt_A);
			ui->tableWidget->setItem(i, 6, pnt_B);
			ui->tableWidget->setItem(i, 7, pnt_C);
		}
		break;
	}
	case 4:
	{
		ui->tableWidget->setColumnCount(7);
		this->ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "id"
		                                           << "Central x coordinate"
		                                           << "Central y coordinate"
		                                           << "Square"
		                                           << "Figure type"
		                                           << "Width"
		                                           << "Height");

		for(int i = 0; i < found.size(); i++){
			Rectangle* working = dynamic_cast<Rectangle*>((*list_handler)[found[i]]);
			ui->tableWidget->insertRow(i);
			QTableWidgetItem* width = new QTableWidgetItem(QString::number(working->getA()));
			QTableWidgetItem* height = new QTableWidgetItem(QString::number(working->getB()));
			width->setFlags(width->flags() ^ Qt::ItemIsEditable);
			height->setFlags(height->flags() ^ Qt::ItemIsEditable);
			ui->tableWidget->setItem(i, 5, width);
			ui->tableWidget->setItem(i, 6, height);
		}
		break;
	}
	case 5:
	{
		ui->tableWidget->setColumnCount(7);
		this->ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "id"
		                                           << "Central x coordinate"
		                                           << "Central y coordinate"
		                                           << "Square"
		                                           << "Figure type"
		                                           << "Horizontal radius"
		                                           << "Vertical radius");

		for(int i = 0; i < found.size(); i++){
			Ellipse* working = dynamic_cast<Ellipse*>((*list_handler)[found[i]]);
			ui->tableWidget->insertRow(i);
			QTableWidgetItem* horizontal = new QTableWidgetItem(QString::number(working->getRadiusHorizontal()));
			QTableWidgetItem* vertical = new QTableWidgetItem(QString::number(working->getRadiusVertical()));
			horizontal->setFlags(horizontal->flags() ^ Qt::ItemIsEditable);
			vertical->setFlags(vertical->flags() ^ Qt::ItemIsEditable);
			ui->tableWidget->setItem(i, 5, horizontal);
			ui->tableWidget->setItem(i, 6, vertical);
		}
		break;
	}
	}
	//for all figures add basic params
	for(int i = 0; i < found.size(); i++){
		if(mode == 1)
			ui->tableWidget->insertRow(i);
		Figure* working = (*list_handler)[found[i]];
		ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(found[i])));
		ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(working->getX())));
		ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(working->getY())));
		QTableWidgetItem *square = new QTableWidgetItem(QString::number(working->getSquare(), 'g', 10));
		square->setFlags(square->flags() ^ Qt::ItemIsEditable);
		ui->tableWidget->setItem(i, 3, square);
		QTableWidgetItem *fig_name = new QTableWidgetItem(QString(working->name()));
		fig_name->setFlags(fig_name->flags() ^ Qt::ItemIsEditable);
		ui->tableWidget->setItem(i, 4, fig_name);
	}
	ui->tableWidget->resizeColumnsToContents();
	ui->tableWidget->hideColumn(0);
	QHeaderView *header = qobject_cast<QTableView *>(ui->tableWidget)->horizontalHeader();
	connect(header, &QHeaderView::sectionClicked, [this](int logicalIndex){
		ui->tableWidget->sortByColumn(logicalIndex, Qt::AscendingOrder);
	});
}
