#include <QtGui/QApplication>
#include "mainwindow.h"
#include "element.h"
#include <QDEBUG>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /** Jeux de test **/
    Entier s(3);
    Reel r(3.2);
    Rationnel e(2,4);
    Rationnel res = dynamic_cast<Rationnel &>(s + e);
    Rationnel res2 = dynamic_cast<Rationnel &>(s * e);
    Rationnel res3 = dynamic_cast<Rationnel &>(s / e);
    Rationnel res4 = dynamic_cast<Rationnel &>(s - e);
    qDebug()<<res.getX()<<"/"<<res.getY();
    qDebug()<<res2.getX()<<"/"<<res2.getY();
    qDebug()<<res3.getX()<<"/"<<res3.getY();
    qDebug()<<res4.getX()<<"/"<<res4.getY();
     qDebug()<<e.getX()<<"/"<<e.getY();


    return a.exec();
}
