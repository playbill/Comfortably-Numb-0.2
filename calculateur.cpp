#include "calculateur.h"
#include <QDEBUG>

Calculateur::Calculateur()
{
    pileC = Pile::donneInstance(); // on crée une instance la classe pile
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
        qDebug()<<e1->toQString();
        qDebug()<<e2->toQString();
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
        qDebug()<<"test";
        Element& tmp = e2->operator /(*e1);
        qDebug()<<"la division";
        Element* res = (this->cast(&tmp));
        delete e1;
        delete e2;
        qDebug()<<"tmp to qstring"<<res->toQString();
        delete &tmp;
        this->getPile()->push(res);
        qDebug()<<this->getPile()->top()->toQString();
    }

}

Element* Calculateur::addition()
{
      if(pileC->donneInstance()->size()<2){
          qDebug()<<"size<2";
        //throw std::logic_error( "ADDITION : il n'y a pas assez de paramatres");
    }
  else
  {     qDebug()<<"size>2";
        Element* e1 = pileC->donneInstance()->pop();
        qDebug()<<"element 1 pop";
        Element* e2 = pileC->donneInstance()->pop();
        qDebug()<<"element 2 pop";
        Element& tmp = e1->operator +(*e2);
        qDebug()<<"addition faite";
        qDebug()<<tmp.toQString();
        Element* res = (this->cast(&tmp));
        qDebug()<<res->toQString();
        delete e1;
        delete e2;
        delete &tmp;
        this->getPile()->push(res);
        return this->getPile()->top();
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
         // throw std::logic_error( "POW : le premier parametre doit être un entier");
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
        Constante* p = dynamic_cast<Constante*>(this->pileC->top());

        if((typeid(*this->pileC->top()) == typeid(Entier))||(typeid(*this->pileC->top()) == typeid(Rationnel)) || typeid(*this->pileC->top()) == typeid(Reel))
        {
            Constante* c = dynamic_cast<Constante*>(this->pileC->top());
            Reel* tmp = new Reel(::pow(c->getXAsFloat()/c->getYAsFloat(),p->getXAsFloat()/p->getYAsFloat()));
            Element* res = this->cast(tmp);
            delete p;
            delete c;
            delete tmp;
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
            Reel* resu = new Reel(::log((tmp->getXAsFloat()/tmp->getYAsFloat())*PI/180.0));
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
            Reel* resu = new Reel(::log10((tmp->getXAsFloat()/tmp->getYAsFloat())*PI/180.0));
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
    Element* e = this->pileC->pop();
    Element* res = e->sign();
    delete e;

   return res;
}

Element* Calculateur::sqrt()
{
Reel* e = new Reel(-1./2.);
   this->pileC->push(e);
   return pow();
}

Element* Calculateur::sqr()
{
   Entier* e = new Entier(2);
   this->pileC->push(e);
   return pow();
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


