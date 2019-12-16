#include "addfigurewindow.h"
#include "ui_addfigurewindow.h"

AddFigureWindow::AddFigureWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddFigureWindow)
{
    ui->setupUi(this);
}

AddFigureWindow::~AddFigureWindow()
{
    delete ui;
}
