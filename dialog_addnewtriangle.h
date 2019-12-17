#ifndef DIALOG_ADDNEWTRIANGLE_H
#define DIALOG_ADDNEWTRIANGLE_H

#include <QDialog>

namespace Ui {
class Dialog_AddNewTriangle;
}

class Dialog_AddNewTriangle : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddNewTriangle(QWidget *parent = nullptr);
    ~Dialog_AddNewTriangle();

private:
    Ui::Dialog_AddNewTriangle *ui;
};

#endif // DIALOG_ADDNEWTRIANGLE_H
