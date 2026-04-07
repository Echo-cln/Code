#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show(); //展示一个窗口，会被新窗口替代
    return a.exec();
}
