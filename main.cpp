#include <QtGui/QApplication>
#include "mainwindow.h"
#include "element.h"
#include <QDEBUG>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Reel r(3);
    Rationnel e(2,4);
    Reel res = dynamic_cast<Reel &>(r + e);
    Reel res2 = dynamic_cast<Reel &>(r * e);
    Reel res3 = dynamic_cast<Reel &>(r / e);
    Reel res4 = dynamic_cast<Reel &>(r - e);
    qDebug()<<res.getX();
    qDebug()<<res2.getX();
    qDebug()<<res3.getX();
    qDebug()<<res4.getX();

    return a.exec();
}
