#ifndef DIALOG_ADDNEWFIGURE_H
#define DIALOG_ADDNEWFIGURE_H

#include <QDialog>
#include "ArrayOfObjectsOnScreen.h"

namespace Ui {
class Dialog_AddNewFigure;
}

class Dialog_AddNewFigure : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddNewFigure(QWidget *parent = nullptr);
    Dialog_AddNewFigure(ArrayOfObjectsOnScreen*, QWidget *parent = nullptr);
    ~Dialog_AddNewFigure();

private slots:
    void on_btn_addCircle_clicked();
    void on_btn_addTriangle_clicked();

    void on_btn_addRect_clicked();

    void on_btn_addEllipse_clicked();

private:
    Ui::Dialog_AddNewFigure *ui;
protected:
    ArrayOfObjectsOnScreen* list_handler;
};

#endif // DIALOG_ADDNEWFIGURE_H
