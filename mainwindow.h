#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ArrayOfObjectsOnScreen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(ArrayOfObjectsOnScreen*, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_add_clicked();
    void on_btn_Display_clicked();
    void on_btn_edit_clicked();
    void on_btn_save_clicked();
    void on_btn_load_clicked();

private:
    ArrayOfObjectsOnScreen* m_figures_on_screen;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
