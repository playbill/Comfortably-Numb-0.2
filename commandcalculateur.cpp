#include "commandcalculateur.h"


CommandUnArg::CommandUnArg(Calculateur* c,Element*(Calculateur::*m)()):cal(c),method(m)
{
    this->arg=c->getPile()->top()->clone();
}

CommandUnArg::~CommandUnArg(){}

void CommandUnArg::Execute()
{
    (cal->*method)();
}


CommandPush::CommandPush(Calculateur* c, Element* e): cal(c)
{
    this->arg = e;
}
CommandPush::~CommandPush()
{
}

void CommandPush::Execute()
{
    cal->push(this->arg->clone());
    qDebug()<<"execute"<<arg->toQString();
}


CommandDeuxArg::CommandDeuxArg(Calculateur* c,Element* e1,Element* e2,Element*(Calculateur::*m)()): cal(c), method(m)
{
    this->arg1=e1->clone();
    this->arg2=e2->clone();
}
CommandDeuxArg::~CommandDeuxArg()
{
}

void CommandDeuxArg::Execute()
{
    (cal->*method)();
}

CommandPolyArg::CommandPolyArg(Calculateur* c,unsigned int taille, unsigned int depart,Element*(Calculateur::*m)()): cal(c),method(m),nElements(taille), tab(new Element*[nElements])
{
    for(unsigned int i=0; i<taille; i++)
    {
    this->tab[i]=(c->getPile()->getPile().at(c->getPile()->size()-1-depart-i)->clone());
    }
}

CommandPolyArg::~CommandPolyArg()
{ qDebug()<<"destructeur poyarg";
}

void CommandPolyArg::Execute()
{
    (cal->*method)();
}
