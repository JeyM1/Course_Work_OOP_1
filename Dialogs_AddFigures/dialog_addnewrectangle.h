#ifndef DIALOG_ADDNEWRECTANGLE_H
#define DIALOG_ADDNEWRECTANGLE_H

#include <QDialog>
#include "ArrayOfObjectsOnScreen.h"

namespace Ui {
class Dialog_AddNewRectangle;
}

class Dialog_AddNewRectangle : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddNewRectangle(ArrayOfObjectsOnScreen*, QWidget *parent = nullptr);
    ~Dialog_AddNewRectangle();

private slots:
    void on_btn_Add_clicked();

private:
    Ui::Dialog_AddNewRectangle *ui;
    ArrayOfObjectsOnScreen* list_handler;
};

#endif // DIALOG_ADDNEWRECTANGLE_H
