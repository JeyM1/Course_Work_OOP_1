#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Dialogs_AddFigures/dialog_addnewfigure.h"
#include "dialog_drawablewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::MainWindow(ArrayOfObjectsOnScreen* lst, QWidget *parent)
    : QMainWindow(parent)
    , m_figures_on_screen(lst)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    Dialog_AddNewFigure dial_add(m_figures_on_screen, this);
    dial_add.setModal(true);
    dial_add.exec();
}

void MainWindow::on_btn_Display_clicked()
{
    Dialog_DrawableWindow render(m_figures_on_screen, this);
    render.setModal(true);
    render.exec();
}
