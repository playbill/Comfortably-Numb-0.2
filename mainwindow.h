#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "commandcalculateur.h"



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
    void cos();
    void sin();
    void tan();
    void cosh();
    void sinh();
    void tanh();
    void ln();
    void log();
    void inv();
    void sqrt();
    void sqr();
    void sign();

private:
    Ui::MainWindow *ui;
    Calculateur leCalculateur;
    QStack<Command *> pileRedo;
    QStack<Command *> pileUndo;

};

#endif // MAINWINDOW_H
