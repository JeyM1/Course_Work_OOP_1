#include "mainwindow.h"
#include "ArrayOfObjectsOnScreen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    ArrayOfObjectsOnScreen main_list;
    QApplication a(argc, argv);
    MainWindow w(&main_list);
    w.show();
    return a.exec();
}
