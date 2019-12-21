#include "dialog_editfigures.h"
#include "ui_dialog_editfigures.h"
#include "Exception.h"
#include <QDebug>

Dialog_EditFigures::Dialog_EditFigures(ArrayOfObjectsOnScreen* lst, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_EditFigures)
{
    list_handler = lst;
    ui->setupUi(this);

    ui->tableCircle->hideColumn(0);
    ui->tableTriangle->hideColumn(0);
    ui->tableRect->hideColumn(0);
    ui->tableEllipse->hideColumn(0);
    ui->tableCircle->setShowGrid(true);
    tablesUpdate();
}

Dialog_EditFigures::~Dialog_EditFigures()
{
    delete ui;
}

void Dialog_EditFigures::tablesUpdate(){
    ui->tableCircle->clearContents();
    ui->tableTriangle->clearContents();
    ui->tableRect->clearContents();
    ui->tableEllipse->clearContents();

    ui->tableCircle->setRowCount(0);
    ui->tableTriangle->setRowCount(0);
    ui->tableRect->setRowCount(0);
    ui->tableEllipse->setRowCount(0);

    int cnt_circle = 0;
    int cnt_triangle = 0;
    int cnt_rect = 0;
    int cnt_ellipse = 0;
    /*ui->tableCircle->setRowCount(0);
    ui->tableCircle->setHorizontalHeaderLabels(QStringList() << "id"
                                               << "Central point"
                                               << "Square"
                                               << "Figure type"
                                               << "Action");*/
    for(int i = 0; i < list_handler->size(); i++){
        Figure* working = (*list_handler)[i];
        if(working->getFigureName() == FigureName::Circle){
            tableCircleUpdate(dynamic_cast<Circle*>(working), i, cnt_circle);
            cnt_circle++;
        }else if(working->getFigureName() == FigureName::Triangle){
            tableTriangleUpdate(dynamic_cast<Triangle*>(working), i, cnt_triangle);
            cnt_triangle++;
        }else if(working->getFigureName() == FigureName::Rectangle){
            tableRectUpdate(dynamic_cast<Rectangle*>(working), i, cnt_rect);
            cnt_rect++;
        }else if(working->getFigureName() == FigureName::Ellipse){
            tableEllipseUpdate(dynamic_cast<Ellipse*>(working), i, cnt_ellipse);
            cnt_ellipse++;
        }
    }
}

void Dialog_EditFigures::tableCircleUpdate(Circle* figure, int index, int row){
    ui->tableCircle->insertRow(row);
    ui->tableCircle->setItem(row, 0, new QTableWidgetItem(QString::number(index)));
    ui->tableCircle->setItem(row, 1, new QTableWidgetItem(QString::number(figure->getX())));
    ui->tableCircle->setItem(row, 2, new QTableWidgetItem(QString::number(figure->getY())));
    ui->tableCircle->setItem(row, 3, new QTableWidgetItem(QString::number(figure->getRadius())));
    //Remove Button
    QWidget* pWidget = new QWidget();
    QPushButton* btn_remove = new QPushButton();
    connect(btn_remove, SIGNAL(clicked()), SLOT(tableWidget_onClicked()));
    btn_remove->setText("Remove");
    btn_remove->setProperty("index", index);
    QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
    pLayout->addWidget(btn_remove);
    pLayout->setAlignment(Qt::AlignCenter);
    pLayout->setContentsMargins(0, 0, 0, 0);
    pWidget->setLayout(pLayout);
    ui->tableCircle->setCellWidget(row, 4, pWidget);
    ui->tableCircle->resizeColumnsToContents();
    QHeaderView *header = qobject_cast<QTableView *>(ui->tableCircle)->horizontalHeader();
    connect(header, &QHeaderView::sectionClicked, [this](int logicalIndex){
        ui->tableCircle->sortByColumn(logicalIndex, Qt::AscendingOrder);
    });
}

void Dialog_EditFigures::tableTriangleUpdate(Triangle* figure, int index, int row){
    ui->tableTriangle->insertRow(row);
    ui->tableTriangle->setItem(row, 0, new QTableWidgetItem(QString::number(index)));
    ui->tableTriangle->setItem(row, 1, new QTableWidgetItem(QString::number(figure->getPoints().A.getX())));
    ui->tableTriangle->setItem(row, 2, new QTableWidgetItem(QString::number(figure->getPoints().A.getY())));
    ui->tableTriangle->setItem(row, 3, new QTableWidgetItem(QString::number(figure->getPoints().B.getX())));
    ui->tableTriangle->setItem(row, 4, new QTableWidgetItem(QString::number(figure->getPoints().B.getY())));
    ui->tableTriangle->setItem(row, 5, new QTableWidgetItem(QString::number(figure->getPoints().C.getX())));
    ui->tableTriangle->setItem(row, 6, new QTableWidgetItem(QString::number(figure->getPoints().C.getY())));
    //Remove Button
    QWidget* pWidget = new QWidget();
    QPushButton* btn_remove = new QPushButton();
    connect(btn_remove, SIGNAL(clicked()), SLOT(tableWidget_onClicked()));
    btn_remove->setText("Remove");
    btn_remove->setProperty("index", index);
    QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
    pLayout->addWidget(btn_remove);
    pLayout->setAlignment(Qt::AlignCenter);
    pLayout->setContentsMargins(0, 0, 0, 0);
    pWidget->setLayout(pLayout);
    ui->tableTriangle->setCellWidget(row, 7, pWidget);
    ui->tableTriangle->resizeColumnsToContents();
    QHeaderView *header = qobject_cast<QTableView *>(ui->tableTriangle)->horizontalHeader();
    connect(header, &QHeaderView::sectionClicked, [this](int logicalIndex){
        ui->tableTriangle->sortByColumn(logicalIndex, Qt::AscendingOrder);
    });
}

void Dialog_EditFigures::tableRectUpdate(Rectangle* figure, int index, int row){
    ui->tableRect->insertRow(row);
    ui->tableRect->setItem(row, 0, new QTableWidgetItem(QString::number(index)));
    ui->tableRect->setItem(row, 1, new QTableWidgetItem(QString::number(figure->getX())));
    ui->tableRect->setItem(row, 2, new QTableWidgetItem(QString::number(figure->getY())));
    ui->tableRect->setItem(row, 3, new QTableWidgetItem(QString::number(figure->getA())));
    ui->tableRect->setItem(row, 4, new QTableWidgetItem(QString::number(figure->getB())));
    //Remove Button
    QWidget* pWidget = new QWidget();
    QPushButton* btn_remove = new QPushButton();
    connect(btn_remove, SIGNAL(clicked()), SLOT(tableWidget_onClicked()));
    btn_remove->setText("Remove");
    btn_remove->setProperty("index", index);
    QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
    pLayout->addWidget(btn_remove);
    pLayout->setAlignment(Qt::AlignCenter);
    pLayout->setContentsMargins(0, 0, 0, 0);
    pWidget->setLayout(pLayout);
    ui->tableRect->setCellWidget(row, 5, pWidget);
    ui->tableRect->resizeColumnsToContents();
    QHeaderView *header = qobject_cast<QTableView *>(ui->tableRect)->horizontalHeader();
    connect(header, &QHeaderView::sectionClicked, [this](int logicalIndex){
        ui->tableRect->sortByColumn(logicalIndex, Qt::AscendingOrder);
    });
}
void Dialog_EditFigures::tableEllipseUpdate(Ellipse* figure, int index, int row){
    ui->tableEllipse->insertRow(row);
    ui->tableEllipse->setItem(row, 0, new QTableWidgetItem(QString::number(index)));
    ui->tableEllipse->setItem(row, 1, new QTableWidgetItem(QString::number(figure->getX())));
    ui->tableEllipse->setItem(row, 2, new QTableWidgetItem(QString::number(figure->getY())));
    ui->tableEllipse->setItem(row, 3, new QTableWidgetItem(QString::number(figure->getRadiusHorizontal())));
    ui->tableEllipse->setItem(row, 4, new QTableWidgetItem(QString::number(figure->getRadiusVertical())));
    //Remove Button
    QWidget* pWidget = new QWidget();
    QPushButton* btn_remove = new QPushButton();
    connect(btn_remove, SIGNAL(clicked()), SLOT(tableWidget_onClicked()));
    btn_remove->setText("Remove");
    btn_remove->setProperty("index", index);
    QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
    pLayout->addWidget(btn_remove);
    pLayout->setAlignment(Qt::AlignCenter);
    pLayout->setContentsMargins(0, 0, 0, 0);
    pWidget->setLayout(pLayout);
    ui->tableEllipse->setCellWidget(row, 5, pWidget);
    ui->tableEllipse->resizeColumnsToContents();
    QHeaderView *header = qobject_cast<QTableView *>(ui->tableEllipse)->horizontalHeader();
    connect(header, &QHeaderView::sectionClicked, [this](int logicalIndex){
        ui->tableEllipse->sortByColumn(logicalIndex, Qt::AscendingOrder);
    });
}


void Dialog_EditFigures::tableWidget_onClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    QVariant var = button->property("index");
    if (!var.isValid()) return;
    list_handler->remove(var.toInt());
    tablesUpdate();
}

void Dialog_EditFigures::on_tableCircle_cellDoubleClicked(int row, int column)
{
    connect(ui->tableCircle, &QTableWidget::cellChanged, [this, row, column](){
        Circle* casted = dynamic_cast<Circle*>((*list_handler)[ui->tableCircle->item(row, 0)->text().toInt()]);
        QTableWidgetItem* cell = ui->tableCircle->item(row, column);
        if(column == 1){
            casted->setX(cell->text().toInt());
        }else if(column == 2){
            casted->setY(cell->text().toInt());
        }else if(column == 3){
            casted->setRadius(cell->text().toInt());
        }
    });
}

void Dialog_EditFigures::on_tableTriangle_cellDoubleClicked(int row, int column)
{
    connect(ui->tableTriangle, &QTableWidget::cellChanged, [this, row, column](){
        Triangle* casted = dynamic_cast<Triangle*>((*list_handler)[ui->tableTriangle->item(row, 0)->text().toInt()]);
        QTableWidgetItem* cell = ui->tableTriangle->item(row, column);
        if(column == 1){
            casted->getrPoints().A.setX(cell->text().toInt());
        }else if(column == 2){
            casted->getrPoints().A.setY(cell->text().toInt());
        }else if(column == 3){
            casted->getrPoints().B.setX(cell->text().toInt());
        }else if(column == 4){
            casted->getrPoints().B.setY(cell->text().toInt());
        }else if(column == 5){
            casted->getrPoints().C.setX(cell->text().toInt());
        }else if(column == 6){
            casted->getrPoints().C.setY(cell->text().toInt());
        }
        casted->recalculateSquare();
    });
}

void Dialog_EditFigures::on_tableRect_cellDoubleClicked(int row, int column)
{
    connect(ui->tableRect, &QTableWidget::cellChanged, [this, row, column](){
        Rectangle* casted = dynamic_cast<Rectangle*>((*list_handler)[ui->tableRect->item(row, 0)->text().toInt()]);
        QTableWidgetItem* cell = ui->tableRect->item(row, column);
        if(column == 1){
            casted->setX(cell->text().toInt());
        }else if(column == 2){
            casted->setY(cell->text().toInt());
        }else if(column == 3){
            casted->setA(cell->text().toInt());
        }else if(column == 4){
            casted->setB(cell->text().toInt());
        }
    });
}

void Dialog_EditFigures::on_tableEllipse_cellDoubleClicked(int row, int column)
{
    connect(ui->tableEllipse, &QTableWidget::cellChanged, [this, row, column](){
        Ellipse* casted = dynamic_cast<Ellipse*>((*list_handler)[ui->tableEllipse->item(row, 0)->text().toInt()]);
        QTableWidgetItem* cell = ui->tableEllipse->item(row, column);
        if(column == 1){
            casted->setX(cell->text().toInt());
        }else if(column == 2){
            casted->setY(cell->text().toInt());
        }else if(column == 3){
            casted->setRadiusHorizontal(cell->text().toInt());
        }else if(column == 4){
            casted->setRadiusVertical(cell->text().toInt());
        }
    });
}
