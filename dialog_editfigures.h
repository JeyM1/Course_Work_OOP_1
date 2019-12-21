#ifndef DIALOG_EDITFIGURES_H
#define DIALOG_EDITFIGURES_H

#include <QDialog>
#include "ArrayOfObjectsOnScreen.h"

namespace Ui {
class Dialog_EditFigures;
}

class Dialog_EditFigures : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_EditFigures(ArrayOfObjectsOnScreen*, QWidget *parent = nullptr);
    ~Dialog_EditFigures();

private slots:
    void tableWidget_onClicked();

    void on_tableCircle_cellDoubleClicked(int row, int column);

    void on_tableTriangle_cellDoubleClicked(int row, int column);

    void on_tableRect_cellDoubleClicked(int row, int column);

    void on_tableEllipse_cellDoubleClicked(int row, int column);

private:
    Ui::Dialog_EditFigures *ui;
    ArrayOfObjectsOnScreen* list_handler;
    void tableCircleUpdate(Circle*, int, int);
    void tableTriangleUpdate(Triangle*, int, int);
    void tableRectUpdate(Rectangle*, int, int);
    void tableEllipseUpdate(Ellipse*, int, int);
    void tablesUpdate();
};

#endif // DIALOG_EDITFIGURES_H
