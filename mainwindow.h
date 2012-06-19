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
#include <fstream>
#include <stream.h>




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
    QVector<Calculateur*>* getCalculateur(){return leCalculateur;}
    void saveContext (const char* path);
    void loadContext(const char* path);
    void show();


private slots:
    void clavier();
    void effacer();
    void addpile();
    void undo();
    void redo();
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
    QVector<Calculateur*>* leCalculateur;
    unsigned int current;
    GestionCommande* pileCommande;
    bool waitingForOperand;
    Affichage* view;

};




#endif // MAINWINDOW_H
