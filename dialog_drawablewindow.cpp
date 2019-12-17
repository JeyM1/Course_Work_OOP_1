#include "dialog_drawablewindow.h"
#include "ui_dialog_drawablewindow.h"

Dialog_DrawableWindow::Dialog_DrawableWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_DrawableWindow)
{
    ui->setupUi(this);
}

Dialog_DrawableWindow::~Dialog_DrawableWindow()
{
    delete ui;
}
