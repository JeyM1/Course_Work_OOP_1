#ifndef DIALOG_ADDNEWFIGURE_H
#define DIALOG_ADDNEWFIGURE_H

#include <QDialog>

namespace Ui {
class Dialog_AddNewFigure;
}

class Dialog_AddNewFigure : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddNewFigure(QWidget *parent = nullptr);
    ~Dialog_AddNewFigure();

private:
    Ui::Dialog_AddNewFigure *ui;
};

#endif // DIALOG_ADDNEWFIGURE_H
