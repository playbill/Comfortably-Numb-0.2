#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <QtGui/QTabWidget>
#include "Observer.h"
class MainWindow;

namespace Ui {
    class Affichage;
}

class Affichage : public QTabWidget, public Observer {
    Q_OBJECT
    Q_DISABLE_COPY(Affichage)
public:
    MainWindow* calculatrice;
    explicit Affichage(QWidget *parent,MainWindow * mainWindow);
    virtual ~Affichage();
    virtual void update(QString data, QString ok = 0);
    virtual void push(QString data, QString ok = 0);
    virtual void pop(QString data = 0, QString ok = 0);
    virtual void swap(QString data1, QString data2);
    virtual void pushCommand(QString data);
    /*virtual void pop(QString data = 0, QString ok = 0);
    virtual void swap(QString data1, QString data2);*/

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::Affichage *m_ui;
};

#endif // AFFICHAGE_H
