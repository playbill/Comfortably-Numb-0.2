#include <QtGui/QApplication>
#include "mainwindow.h"
#include "element.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Rationnel e(2);

    return a.exec();
}
