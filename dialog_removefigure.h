#ifndef DIALOG_REMOVEFIGURE_H
#define DIALOG_REMOVEFIGURE_H

#include <QDialog>
#include "ArrayOfObjectsOnScreen.h"

namespace Ui {
class Dialog_RemoveFigure;
}

class Dialog_RemoveFigure : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_RemoveFigure(ArrayOfObjectsOnScreen*, QWidget *parent = nullptr);
    ~Dialog_RemoveFigure();

private slots:
    void tableWidget_onClicked();

private:
    Ui::Dialog_RemoveFigure *ui;
    ArrayOfObjectsOnScreen* list_handler;
    void tableWidgetUpdate();
};

#endif // DIALOG_REMOVEFIGURE_H
