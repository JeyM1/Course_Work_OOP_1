#ifndef DIALOG_ADDNEWTRIANGLE_H
#define DIALOG_ADDNEWTRIANGLE_H

#include <QDialog>
#include "ArrayOfObjectsOnScreen.h"

namespace Ui {
class Dialog_AddNewTriangle;
}

class Dialog_AddNewTriangle : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddNewTriangle(ArrayOfObjectsOnScreen*, QWidget *parent = nullptr);
    ~Dialog_AddNewTriangle();

private slots:
    void on_btn_Add_clicked();

private:
    Ui::Dialog_AddNewTriangle *ui;
    ArrayOfObjectsOnScreen* list_handler;
};

#endif // DIALOG_ADDNEWTRIANGLE_H
