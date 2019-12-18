#ifndef DIALOG_ADDNEWCIRCLE_H
#define DIALOG_ADDNEWCIRCLE_H

#include <QDialog>
#include "Dialogs_AddFigures/dialog_addnewfigure.h"

namespace Ui {
class Dialog_AddNewCircle;
}

class Dialog_AddNewCircle : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddNewCircle(QWidget *parent = nullptr);
    Dialog_AddNewCircle(ArrayOfObjectsOnScreen*, QWidget *parent = nullptr);
    ~Dialog_AddNewCircle();

private slots:
    void on_btn_Add_clicked();

private:
    Ui::Dialog_AddNewCircle *ui;
    ArrayOfObjectsOnScreen* list_handler;
};

#endif // DIALOG_ADDNEWCIRCLE_H
