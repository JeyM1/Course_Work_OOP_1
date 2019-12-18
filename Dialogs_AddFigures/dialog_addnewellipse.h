#ifndef DIALOG_ADDNEWELLIPSE_H
#define DIALOG_ADDNEWELLIPSE_H

#include <QDialog>
#include "ArrayOfObjectsOnScreen.h"

namespace Ui {
class Dialog_AddNewEllipse;
}

class Dialog_AddNewEllipse : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddNewEllipse(ArrayOfObjectsOnScreen*, QWidget *parent = nullptr);
    ~Dialog_AddNewEllipse();

private slots:
    void on_btn_Add_clicked();

private:
    Ui::Dialog_AddNewEllipse *ui;
    ArrayOfObjectsOnScreen* list_handler;
};

#endif // DIALOG_ADDNEWELLIPSE_H
