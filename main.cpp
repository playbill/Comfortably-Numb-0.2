#include <QtGui/QApplication>
#include "mainwindow.h"
#include "reel.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Reel e(2);
    return a.exec();
}
