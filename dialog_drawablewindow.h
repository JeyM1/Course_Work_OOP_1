#ifndef DIALOG_DRAWABLEWINDOW_H
#define DIALOG_DRAWABLEWINDOW_H

#include <QDialog>
#include "ArrayOfObjectsOnScreen.h"

namespace Ui {
class Dialog_DrawableWindow;
}

class Dialog_DrawableWindow : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_DrawableWindow(ArrayOfObjectsOnScreen*, QWidget *parent = nullptr);
    ~Dialog_DrawableWindow();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_btn_showlist_clicked();

private:
    Ui::Dialog_DrawableWindow *ui;
    ArrayOfObjectsOnScreen* list_handler;
    bool btn_showlist_clicked;
};

#endif // DIALOG_DRAWABLEWINDOW_H
