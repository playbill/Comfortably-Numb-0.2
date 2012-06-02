#include <QtGui/QApplication>
#include "mainwindow.h"
#include "reel.h"
#include "entier.h"
#include "rationnel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Rationnel e(2,4);
    return a.exec();
}
