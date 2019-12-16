#ifndef ADDFIGUREWINDOW_H
#define ADDFIGUREWINDOW_H

#include <QWidget>

namespace Ui {
class AddFigureWindow;
}

class AddFigureWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddFigureWindow(QWidget *parent = nullptr);
    ~AddFigureWindow();

private:
    Ui::AddFigureWindow *ui;
};

#endif // ADDFIGUREWINDOW_H
