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

QString CommandUnArg::toQString(){
if(method == &Calculateur::fact){return arg->toQString() + " fact "; }
else if(method == &Calculateur::cos){return arg->toQString() + " cos "; }
else if(method == &Calculateur::cosh){return arg->toQString() + " cosh "; }
else if(method == &Calculateur::sin){return arg->toQString() + " sin ";}
else if(method == &Calculateur::sinh){return arg->toQString() + " sinh ";}
else if(method == &Calculateur::tan){return arg->toQString() + " tan ";}
else if(method == &Calculateur::tanh){return arg->toQString() + " tanh ";}
else if(method == &Calculateur::fact){return arg->toQString() + " fact ";}
else if(method == &Calculateur::eval){return arg->toQString() + " eval ";}
else if(method == &Calculateur::ln){return arg->toQString() + " ln ";}
else if(method == &Calculateur::log){return arg->toQString() + " log ";}
else if(method == &Calculateur::inv){return arg->toQString() + " inv ";}
else if(method == &Calculateur::sqrt){return arg->toQString() + " sqrt ";}
else if(method == &Calculateur::sqr){return arg->toQString() + " sqr ";}
else if(method == &Calculateur::cube){return arg->toQString() + " cube ";}
else if(method == &Calculateur::sign){return arg->toQString() + " sign ";}
else if(method == &Calculateur::duplicate){return arg->toQString() + " dup ";}
else if(method == &Calculateur::drop){return arg->toQString() + " drop ";}

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

QString CommandDeuxArg::toQString(){
if(method == &Calculateur::addition){return arg1->toQString() + ' ' + arg2->toQString() + " + "; }
else if(method == &Calculateur::multiplication){return arg1->toQString() + ' ' + arg2->toQString() + " * ";  }
else if(method == &Calculateur::division){return arg1->toQString() + ' ' + arg2->toQString() + " / ";  }
else if(method == &Calculateur::pow){return arg1->toQString() + ' ' + arg2->toQString() + " ^ ";  }
else if(method == &Calculateur::mod){return arg1->toQString() + ' ' + arg2->toQString() + " % ";  }
else if(method == &Calculateur::swap){return arg1->toQString() + ' ' + arg2->toQString() + " swap ";  }
else if(method == &Calculateur::soustraction){return arg1->toQString() + ' ' + arg2->toQString() + " - ";  }
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
QString CommandPolyArg::toQString(){
if(method == &Calculateur::mean){
    QString a = " mean ";
    for(unsigned i = 0; i<nElements; i++){
    a.push_front(' '+tab[i]->toQString()+' ');
    }
    return a;
}
else if(method == &Calculateur::sum){
        QString a = " sum ";
    for(unsigned i = 0; i<nElements; i++){
    a.push_front(' '+tab[i]->toQString()+' ');
    }
    return a;
}
else if(method == &Calculateur::clear){
    return " clear ";
}
}
