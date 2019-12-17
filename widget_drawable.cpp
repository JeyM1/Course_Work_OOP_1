#include "widget_drawable.h"
#include "ui_widget_drawable.h"

widget_drawable::widget_drawable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_drawable)
{
    ui->setupUi(this);
}

widget_drawable::~widget_drawable()
{
    delete ui;
}
