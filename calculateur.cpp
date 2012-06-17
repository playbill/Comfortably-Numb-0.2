#include "calculateur.h"
#include <QDEBUG>

Calculateur::Calculateur()
{
    pileC = Pile::donneInstance(); // on cr�e une instance la classe pile
    this->modeEntier = false;
    this->modeRationnel = false;
    this->modeReel = false;
    this->modeDegre = true;
    this->modeRadian = false;
    this->modeComplexe = true;
}

Element* Calculateur::cast(Element* e)
{
    if(isComplexe())
    {   qDebug()<<"cast Complexe";
        return e->toComplexe();
    }
    if(typeid(e) == typeid(Expression*))
    { qDebug()<<"cast expression";
        return e->clone();
    }
    else if(isEntier())
    {   qDebug()<<"cast entier";
        return e->toEntier();
    }
    else if(isReel())
    {   qDebug()<<"cast reel";
        return e->toReel();
    }
    else if(isRationnel())
    {   qDebug()<<"cast rationnel";
        return e->toRationnel();
    }
    else
    {   qDebug()<<"cast else";
        return e->toReel();
    }
}

Element* Calculateur::multiplication()
{

  if(pileC->donneInstance()->size()<2){
        //throw std::logic_error( "Multiplication : il n'y a pas assez de paramatres");
    }
  else
  {
        Element* e1 = pileC->donneInstance()->pop();
        Element* e2 = pileC->donneInstance()->pop();
        Element& tmp = e1->operator *(*e2);
        Element* res = (this->cast(&tmp));
        delete e1;
        delete e2;
        delete &tmp;
        this->pileC->push(res);
        return this->pileC->top();
    }
}

Element* Calculateur::soustraction()
{
      if(pileC->donneInstance()->size()<2){
        //throw std::logic_error( "SOUSTRACTION : il n'y a pas assez de paramatres");
    }
  else
  {
        Element* e1 = pileC->donneInstance()->pop();
        Element* e2 = pileC->donneInstance()->pop();
        Element& tmp = e2->operator -(*e1);
        Element* res = (this->cast(&tmp));
        delete e1;
        delete e2;
        delete &tmp;
        this->pileC->push(res);
        return this->pileC->top();
    }

}

Element* Calculateur::division()
{

      if(pileC->donneInstance()->size()<2){
        //throw std::logic_error( "DIVISION : il n'y a pas assez de paramatres");
    }
  else
  {
        Element* e1 = pileC->donneInstance()->pop();
        Element* e2 = pileC->donneInstance()->pop();
        Element& tmp = e2->operator /(*e1);
        Element* res = (this->cast(&tmp));
        delete e1;
        delete e2;
        delete &tmp;
        this->getPile()->push(res);
    }

}

Element* Calculateur::addition()
{
      if(pileC->donneInstance()->size()<2){
        //throw std::logic_error( "ADDITION : il n'y a pas assez de paramatres");
    }
  else
  {
        Element* e1 = pileC->donneInstance()->pop();
        Element* e2 = pileC->donneInstance()->pop();
        Element& tmp = e1->operator +(*e2);
        Element* res = (this->cast(&tmp));
        delete e1;
        delete e2;
        delete &tmp;
        this->getPile()->push(res);
        return this->getPile()->top();
    }

}
Element* Calculateur::mod()
{
    if(typeid(*this->pileC->top()) == typeid(Expression))
    {
        this->eval();
    }
    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {   qDebug()<<"on est en complexe";
         // throw std::logic_error( "mod : le premier parametre doit �tre une constante");
    }
    if(typeid(*this->pileC->top()) != typeid(Entier))
    {   qDebug()<<"on est en non entier";
        // \todo throw stc:: il faut que ce soit un entier attention nous le convertissons
    }
    if(typeid(*this->pileC->top()) == typeid(Entier))
    {   qDebug()<<"on est en entier";
        Entier* m = dynamic_cast<Entier*>(this->pileC->pop()); /*!< module */
        qDebug()<<"l'entier est"<<m->toQString();

        if(typeid(*this->pileC->top()) == typeid(Expression))
        { qDebug()<<"on est en expression";
            this->eval();
        }
        if(typeid(*this->pileC->top()) == typeid(Complexe))
        {   qDebug()<<"on est en complexe";
            this->pileC->push(m);
            // \todo throw error
        }
        if(typeid(*this->pileC->top()) != typeid(Entier))
        {   qDebug()<<"on est en non entier";
            // \todo nous le convertissons
        }
        if(typeid(*this->pileC->top()) == typeid(Entier))
        {   qDebug()<<"on est en entier";
            Entier* e = dynamic_cast<Entier*>(this->pileC->pop());
            qDebug()<<e->toQString();
            Entier* tmp = new Entier(e->getXAsInt()%m->getXAsInt());
            qDebug()<<tmp->toQString();
            delete m;
            delete e;
            this->pileC->push(tmp);
            return tmp;
        }
        else
        {
            //\todo throw error
        }
    }
    else
    {
        //\todo throw error
    }
}

Element* Calculateur::pow()
{
    if(typeid(*this->pileC->top()) == typeid(Expression))
    {
        this->eval();
    }
    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {
         // throw std::logic_error( "POW : le premier parametre doit �tre un entier");
    }
    else if(typeid(*this->pileC->top())== typeid(Entier))
    {
        Entier* e = dynamic_cast<Entier*>(this->pileC->pop());

        if(typeid(*this->pileC->top()) == typeid(Expression))
        {
            Element* tmp = this->eval();
        }

        else if(typeid(*this->pileC->top())== typeid(Entier) || typeid(*this->pileC->top())== typeid(Rationnel))
        {
            Constante* c = dynamic_cast<Constante*>(this->pileC->pop());

            if(e->getXAsInt()>= 0)
            {
                Rationnel* tmp = new Rationnel(::pow(c->getXAsInt(),e->getXAsInt()),::pow(c->getYAsInt(),e->getXAsInt()));
                qDebug()<<tmp->toQString();
                Element* res = this->cast(tmp);
                delete e;
                delete c;
                delete tmp;
                this->pileC->push(res);
            }
            else
            {
                Reel* tmp = new Reel(::pow(c->getXAsFloat()/c->getYAsFloat(),e->getXAsInt()));

                Element* res = this->cast(tmp);
                delete e;
                delete c;
                delete tmp;
                this->pileC->push(res);
            }
        }
        else if(typeid(*this->pileC->top()) == typeid(Reel))
        {
            Constante* c = dynamic_cast<Constante*>(this->pileC->pop());
            Reel* tmp = new Reel(::pow(c->getXAsFloat(),e->getXAsFloat()));
            Element* res = this->cast(tmp);
            delete e;
            delete c;
            delete tmp;
            this->pileC->push(res);

        }
        else
        {
        // erreur
        }
    }
    else if(typeid(*this->pileC->top()) == typeid(Reel) || typeid(*this->pileC->top()) == typeid(Rationnel))
    {
        Constante* p = dynamic_cast<Constante*>(this->pileC->pop());

        if((typeid(*this->pileC->top()) == typeid(Entier))||(typeid(*this->pileC->top()) == typeid(Rationnel)) || typeid(*this->pileC->top()) == typeid(Reel))
        {
            Constante* c = dynamic_cast<Constante*>(this->pileC->pop());
            Reel* tmp = new Reel(::pow(c->getXAsFloat()/c->getYAsFloat(),p->getXAsFloat()/p->getYAsFloat()));
            Element* res = this->cast(tmp);
            delete p;
            delete c;
            delete tmp;
            this->pileC->push(res);
            return res;

        }
        else
        {
          // erreur
        }
    }
    else
    {
    // erreur
    }

}

Element* Calculateur::cos()
{
            if(typeid(*this->pileC->top()) == typeid(Expression))
    {
    this->eval();
    }
    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {
    //
    }
    if(isRadian())
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
    Reel* resu = new Reel(::cos(tmp->getXAsFloat()/tmp->getYAsFloat()));
    delete tmp;
    this->pileC->push(resu);
    return resu;
    }
    else
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
    Reel* resu = new Reel(::cos((tmp->getXAsFloat()/tmp->getYAsFloat())*PI/180.0));
    delete tmp;
    this->pileC->push(resu);
    return resu;

    }

}

Element* Calculateur::sin()
{
    if(typeid(*this->pileC->top()) == typeid(Expression))
    {
    this->eval();
    }
    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {
    //
    }
    if(isRadian())
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
    Reel* resu = new Reel(::sin(tmp->getXAsFloat()/tmp->getYAsFloat()));
    delete tmp;
    this->pileC->push(resu);
    return resu;
    }
    else
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
    Reel* resu = new Reel(::sin((tmp->getXAsFloat()/tmp->getYAsFloat())*PI/180.0));
    delete tmp;
    this->pileC->push(resu);
    return resu;

    }
}

Element* Calculateur::tan()
{
        if(typeid(*this->pileC->top()) == typeid(Expression))
    {
    this->eval();
    }
    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {
    //
    }
    if(isRadian())
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
    Reel* resu = new Reel(::tan(tmp->getXAsFloat()/tmp->getYAsFloat()));
    delete tmp;
    this->pileC->push(resu);
    return resu;
    }
    else
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
    Reel* resu = new Reel(::tan((tmp->getXAsFloat()/tmp->getYAsFloat())*PI/180.0));
    delete tmp;
    this->pileC->push(resu);
    return resu;

    }

}

Element* Calculateur::cosh()
{
        if(typeid(*this->pileC->top()) == typeid(Expression))
    {
    this->eval();
    }
    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {
    //
    }
    if(isRadian())
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
    Reel* resu = new Reel(::cosh(tmp->getXAsFloat()/tmp->getYAsFloat()));
    delete tmp;
    this->pileC->push(resu);
    return resu;
    }
    else
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
    Reel* resu = new Reel(::cosh((tmp->getXAsFloat()/tmp->getYAsFloat())*PI/180.0));
    delete tmp;
    this->pileC->push(resu);
    return resu;

    }
}

Element* Calculateur::sinh()
{
            if(typeid(*this->pileC->top()) == typeid(Expression))
    {
    this->eval();
    }
    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {
    //
    }
    if(isRadian())
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
    Reel* resu = new Reel(::sinh(tmp->getXAsFloat()/tmp->getYAsFloat()));
    delete tmp;
    this->pileC->push(resu);
    return resu;
    }
    else
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
    Reel* resu = new Reel(::sinh((tmp->getXAsFloat()/tmp->getYAsFloat())*PI/180.0));
    delete tmp;
    this->pileC->push(resu);
    return resu;

    }

}

Element* Calculateur::tanh()
{
        if(typeid(*this->pileC->top()) == typeid(Expression))
    {
    this->eval();
    }
    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {
    //
    }
    if(isRadian())
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
    Reel* resu = new Reel(::tanh(tmp->getXAsFloat()/tmp->getYAsFloat()));
    delete tmp;
    this->pileC->push(resu);
    return resu;
    }
    else
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
    Reel* resu = new Reel(::tanh((tmp->getXAsFloat()/tmp->getYAsFloat())*PI/180.0));
    delete tmp;
    this->pileC->push(resu);
    return resu;

    }
}

Element* Calculateur::ln()
{
            if(typeid(*this->pileC->top()) == typeid(Expression))
    {
    this->eval();
    }
    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {
    //
    }
    if(isRadian())
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
        if(tmp->getXAsFloat()<0 && tmp->getYAsFloat() <0)
        {
            //ERREUR
            return 0;
        }
        else
        {
            Reel* resu = new Reel(::log(tmp->getXAsFloat()/tmp->getYAsFloat()));
            delete tmp;
            this->pileC->push(resu);
            return resu;
        }
    }
    else
    {
        Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
        if(tmp->getXAsFloat()<0 && tmp->getYAsFloat() <0)
            {
                //ERREUR
                return 0;
            }
        else
        {
            Reel* resu = new Reel(::log((tmp->getXAsFloat()/tmp->getYAsFloat())));
            delete tmp;
            this->pileC->push(resu);
            return resu;
        }
    }

}

Element* Calculateur::log()
{
                if(typeid(*this->pileC->top()) == typeid(Expression))
    {
    this->eval();
    }
    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {
    //
    }
    if(isRadian())
    {
    Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
        if(tmp->getXAsFloat()<0 && tmp->getYAsFloat() <0)
        {
            //ERREUR
            return 0;
        }
        else
        {
            Reel* resu = new Reel(::log10(tmp->getXAsFloat()/tmp->getYAsFloat()));
            delete tmp;
            this->pileC->push(resu);
            return resu;
        }
    }
    else
    {
        Constante* tmp = dynamic_cast<Constante*> (this->pileC->pop());
        if(tmp->getXAsFloat()<0 && tmp->getYAsFloat() <0)
            {
                //ERREUR
                return 0;
            }
        else
        {
            Reel* resu = new Reel(::log10((tmp->getXAsFloat()/tmp->getYAsFloat())));
            delete tmp;
            this->pileC->push(resu);
            return resu;
        }
    }

}

Element* Calculateur::inv()
{
    if(typeid(*this->pileC->top()) == typeid(Expression))
    {
        this->eval();
    }
    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {
        //throw error \todo
    }

    Constante* c = dynamic_cast<Constante *>(this->pileC->pop());
    Element* res;
    if(typeid(*c)== typeid(Entier) || typeid(*c)== typeid(Rationnel))
    {

        res = new Rationnel(c->getYAsInt(),c->getXAsInt());

    }
    else
    {
        res = new Reel(1./c->getXAsFloat());

    }

        delete c;
        this->pileC->push(res);
        return res;
}

Element* Calculateur::sqrt()
{
Reel* e = new Reel(1./2.);
   this->pileC->push(e);
   return pow();
}


Element* Calculateur::sqr()
{
    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {   /*!< (a + bi)� = a� - b� + 2bai */
        qDebug()<<"Complexe sqr";
        Complexe* c = dynamic_cast<Complexe*>(this->pileC->pop());
        this->pileC->push(c->getRe()->clone());
        this->sqr();
        this->pileC->push(c->getIm()->clone());
        this->sqr();
        this->sign();
        this->pileC->push(c->getIm()->clone());
        this->pileC->push(c->getRe()->clone());
        this->pileC->push(new Entier(2));
        delete c;
        this->multiplication();
        this->multiplication();
        qDebug()<<this->pileC->top()->toQString();
        Complexe* im = dynamic_cast<Complexe*>(this->pileC->pop());
        this->push(new Complexe(new Entier(0),im->getRe()->clone()));
        delete im;
        this->addition();
        this->addition();
    }
    else
    {
        Entier* e = new Entier(2);
        this->pileC->push(e);
        return pow();
    }
}
Element* Calculateur::cube()
{
    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {   /*!< (a + bi)*(a + bi)� */
        Element* e = this->pileC->top()->clone();
        this->sqr();
        this->push(e);
        this->multiplication();
    }
    else
    {
        Entier* e = new Entier(3);
        this->pileC->push(e);
        return pow();
    }
}
Element* Calculateur::sign()
{
    if(typeid(*this->pileC->top()) == typeid(Expression))
    {   //trow_error
        return 0;
    }
    else
    {
        Element* tmp = this->pileC->pop();
        Element* e = tmp->sign();
        delete tmp;
        this->pileC->push(e);
        return e;
    }
}

Element* Calculateur::eval()
{

}

bool Calculateur::isEntier()
{
    return modeEntier;
}

bool Calculateur::isComplexe()
{
    return modeComplexe;
}

bool Calculateur::isDegre()
{
    return modeDegre;
}

bool Calculateur::isRadian()
{
    return modeRadian;
}

bool Calculateur::isRationnel()
{
    return modeRationnel;
}

bool Calculateur::isReel()
{
    return modeReel;
}

Element* Calculateur::duplicate()
{
    Element* e = this->pileC->top()->clone();
    this->pileC->push(e);
    return pileC->top();
}

Element* Calculateur::push(Element* e)
{
    this->pileC->push(e);
    return pileC->top();
}

Element* Calculateur::pop()
{
    return pileC->pop();
}

void Calculateur::setToComplexe()
{
    modeComplexe = true;
}
void Calculateur::setToNoComplexe()
{
    modeComplexe = false;
}

void Calculateur::setToEntier()
{
    modeEntier = true;
    modeReel = false;
    modeRationnel = false;
}

void Calculateur::setToDegre()
{
    modeDegre = true;
    modeRadian = false;

}

void Calculateur::setToRadian()
{
    modeDegre = false;
    modeRadian = true;
}

void Calculateur::setToRationnel()
{
    modeEntier = false;
    modeReel = false;
    modeRationnel = true;
}

void Calculateur::setToReel()
{
    modeEntier = false;
    modeReel = true;
    modeRationnel = false;
}
void Calculateur::setNoMode()
{
    modeEntier = false;
    modeReel = false;
    modeRationnel = false;
}

