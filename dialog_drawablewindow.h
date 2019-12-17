#ifndef DIALOG_DRAWABLEWINDOW_H
#define DIALOG_DRAWABLEWINDOW_H

#include <QDialog>

namespace Ui {
class Dialog_DrawableWindow;
}

class Dialog_DrawableWindow : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_DrawableWindow(QWidget *parent = nullptr);
    ~Dialog_DrawableWindow();

private:
    Ui::Dialog_DrawableWindow *ui;
};

#endif // DIALOG_DRAWABLEWINDOW_H
