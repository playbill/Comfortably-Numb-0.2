#ifndef COMMANDCALCULATEUR_H
#define COMMANDCALCULATEUR_H
#include "command.h"
#include "calculateur.h"


class CommandUnArg : public Command
{
private:
    Calculateur* cal;
    Element* arg;
    Element* (Calculateur::*method)();
public:
    CommandUnArg(Calculateur*,Element*(Calculateur::*)()=0);
    virtual ~CommandUnArg();
    void Execute();
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
};


class CommandDeuxArg : public Command
{
private:
    Calculateur* cal;
    Element* arg1;
    Element* arg2;
    Element* (Calculateur::*method)();
public:
    CommandDeuxArg(Calculateur*,Element*(Calculateur::*)());
    virtual ~CommandDeuxArg();
    void Execute();
};

class CommandPolyArg : public Command
{
private:
    Calculateur* cal;
    Element** tab;
    unsigned int nElements;
    Element* (Calculateur::*method)();
public:
    CommandPolyArg(Calculateur*,unsigned int,Element*(Calculateur::*)());
    virtual ~CommandPolyArg();
    void Execute();
};

#endif // COMMANDCALCULATEUR_H
