#include "mainwindow.h"
#include"beginbackground.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
    beginbackground w;
    w.show();
    return a.exec();
}
