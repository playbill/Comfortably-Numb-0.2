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


CommandDeuxArg::CommandDeuxArg(Calculateur* c,Element*(Calculateur::*m)()): cal(c), method(m)
{
    this->arg1=c->getPile()->top()->clone();
    this->arg2=c->getPile()->getPile().at(c->getPile()->size()-1)->clone();
}
CommandDeuxArg::~CommandDeuxArg()
{
}

void CommandDeuxArg::Execute()
{
    (cal->*method)();
}

CommandPolyArg::CommandPolyArg(Calculateur* c,unsigned int n,Element*(Calculateur::*m)()): cal(c),method(m),nElements(n)
{
    for(unsigned i=0; i<n; i++)
    {
    this->tab[i]=c->getPile()->getPile().at(c->getPile()->size()-i)->clone();
    }
}

CommandPolyArg::~CommandPolyArg()
{
}

void CommandPolyArg::Execute()
{
    (cal->*method)();
}
