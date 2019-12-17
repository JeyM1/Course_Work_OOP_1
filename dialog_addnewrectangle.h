#ifndef DIALOG_ADDNEWRECTANGLE_H
#define DIALOG_ADDNEWRECTANGLE_H

#include <QDialog>

namespace Ui {
class Dialog_AddNewRectangle;
}

class Dialog_AddNewRectangle : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddNewRectangle(QWidget *parent = nullptr);
    ~Dialog_AddNewRectangle();

private:
    Ui::Dialog_AddNewRectangle *ui;
};

#endif // DIALOG_ADDNEWRECTANGLE_H
