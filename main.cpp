#include "mainwindow.h"
#include "ArrayOfObjectsOnScreen.h"

#include <QMessageBox>
#include <QApplication>
#include <windows.h>

int main(int argc, char *argv[])
{
    FreeConsole();
    ArrayOfObjectsOnScreen main_list;
    QApplication a(argc, argv);
    MainWindow w(&main_list);

    w.show();
    return a.exec();
}
