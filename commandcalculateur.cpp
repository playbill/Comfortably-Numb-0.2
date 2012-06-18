/**
 * \file commandcalculateur.cpp
 * \brief Contient l''implementation des methodes des sous classes de la classe Command -
 * CommandUnArg, CommandPush, CommandDeuxArg, et CommandPolyArg
 *
 * \author Charrier Lucas et Rossier Titouan
 * \version 0.1
 * \date 31 Mai 2012
 *
 */

#include "commandcalculateur.h"


CommandUnArg::CommandUnArg(Calculateur* c,Element*(Calculateur::*m)()):cal(c),method(m)
{
    this->arg=c->getPile()->top()->clone();
}

CommandUnArg::~CommandUnArg(){
    delete arg;
}

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

    delete arg;
}

void CommandPush::Execute()
{
    cal->push(this->arg->clone());
    qDebug()<<"Command Push::execute"<<arg->toQString();
}


CommandDeuxArg::CommandDeuxArg(Calculateur* c,Element* e1,Element* e2,Element*(Calculateur::*m)()): cal(c), method(m)
{
    this->arg1=e1->clone();
    this->arg2=e2->clone();
}
CommandDeuxArg::~CommandDeuxArg()
{
    delete arg1;
    delete arg2;
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
{
    qDebug()<<"destructeur poyarg";
    delete[] tab;
}

void CommandPolyArg::Execute()
{
    (cal->*method)();
}
