#ifndef DIALOG_ADDNEWCIRCLE_H
#define DIALOG_ADDNEWCIRCLE_H

#include <QDialog>

namespace Ui {
class Dialog_AddNewCircle;
}

class Dialog_AddNewCircle : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddNewCircle(QWidget *parent = nullptr);
    ~Dialog_AddNewCircle();

private:
    Ui::Dialog_AddNewCircle *ui;
};

#endif // DIALOG_ADDNEWCIRCLE_H
