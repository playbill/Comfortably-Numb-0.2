#ifndef COMMANDCALCULATEUR_H
#define COMMANDCALCULATEUR_H
#include "command.h"
#include "calculateur.h"
#include <QDEBUG>


class CommandUnArg : public Command
{
private:
    Calculateur* cal;
    Element* arg;
    Element* (Calculateur::*method)();
public:
    CommandUnArg(Calculateur*,Element*(Calculateur::*)()=0);
    Element* getArg(){return arg;}
    virtual ~CommandUnArg();
    void Execute();
    QString toQString();

};

class CommandPush : public Command
{
private:
    Calculateur* cal;
    Element* arg;
public:
    CommandPush(Calculateur*,Element*);
    virtual ~CommandPush();
    void Execute();
    QString toQString(){return arg->toQString() + " push ";}
};


class CommandDeuxArg : public Command
{
private:
    Calculateur* cal;
    Element* arg1;
    Element* arg2;
    Element* (Calculateur::*method)();
public:
    CommandDeuxArg(Calculateur*,Element*,Element*,Element*(Calculateur::*)());
    virtual ~CommandDeuxArg();
    Element* getArg1(){return arg1;}
    Element* getArg2(){return arg2;}
    void Execute();
    virtual QString toQString();
};

class CommandPolyArg : public Command
{
private:
    Calculateur* cal;
    Element** tab;
    unsigned int nElements;
    Element* (Calculateur::*method)();
public:
    Element* getArg(unsigned int i){return tab[i];}
    unsigned int getN(){return nElements;}
    CommandPolyArg(Calculateur*,unsigned int taille,unsigned int depart,Element*(Calculateur::*)());
    virtual ~CommandPolyArg();
    void Execute();
    virtual QString toQString();
};

#endif // COMMANDCALCULATEUR_H
