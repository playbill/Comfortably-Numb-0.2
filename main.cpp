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
    Entier t(3.2);
    Reel r(3.2);
    Rationnel e(2,4);
    Entier res = dynamic_cast<Entier &>(s + t);
    Reel res2 = dynamic_cast<Reel &>(r * e);
    Reel res3 = dynamic_cast<Reel &>(r / e);
    Reel res4 = dynamic_cast<Reel &>(r - e);
    qDebug()<<res.getXAsInt()<<"/"/*res.getY()*/;
    qDebug()<<res2.getXAsFloat()<<"/"/*<<res2.getY()*/;
    qDebug()<<res3.getXAsFloat()<<"/"/*<<res3.getY()*/;
    qDebug()<<res4.getXAsFloat()<<"/"/*<<res4.getY()*/;
     qDebug()<<e.getXAsInt()<<"/"<<e.getYAsInt();


    return a.exec();
}
