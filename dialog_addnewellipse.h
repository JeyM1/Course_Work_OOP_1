#ifndef DIALOG_ADDNEWELLIPSE_H
#define DIALOG_ADDNEWELLIPSE_H

#include <QDialog>

namespace Ui {
class Dialog_AddNewEllipse;
}

class Dialog_AddNewEllipse : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddNewEllipse(QWidget *parent = nullptr);
    ~Dialog_AddNewEllipse();

private:
    Ui::Dialog_AddNewEllipse *ui;
};

#endif // DIALOG_ADDNEWELLIPSE_H
