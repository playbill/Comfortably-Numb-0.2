#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtGui/QMainWindow>
#include "commandcalculateur.h"
#include <QSignalMapper>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QStringList>
#include <QDEBUG>
#include <QMessageBox>
#include <typeinfo>
#include <stdexcept>
#include "affichage.h"
#include "gestioncommande.h"



namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Element* getComplexe(QString str);
    Constante* getConstante(QString str);
    void show();


private slots:
    void clickedBt(QString);
    void evaluate();
    void eval();
    void duplicate();
    void drop();
    void clear();
    void toModeEntier();
    void toModeReel();
    void toModeRationnel();
    void toModeComplexe();
    void toModeBestFit();
    void toModeRadiant();
    void toModeDegre();
    void cos(){}
    void sin(){}
    void tan(){}
    void cosh(){}
    void sinh(){}
    void tanh(){}
    void ln(){}
    void log(){}
    void inv(){}
    void sqrt(){}
    void sqr(){}
    void sign(){}


private:
    Ui::MainWindow *ui;
    QSignalMapper* mapper;
    Calculateur* leCalculateur;
    GestionCommande* pileCommande;
    bool waitingForOperand;
    Affichage* view;
    std::set<Affichage*> list_observers;

};




#endif // MAINWINDOW_H
