#include "calculateur.h"
//je suis ici
Calculateur::Calculateur()
{
    pileC->donneInstance();
}

Element* Calculateur::cast(Element* e)
{
    if(typeid(e) == typeid(Expression*))
    {
        return e->clone();
    }
    else if(isEntier()) return &e->toEntier();
    else if(isReel()) return &e->toReel();
    else if(isRationnel()) return &e->toRationnel();
    else if(isComplexe()) return &e->toComplexe();
    else return 0;
}

void Calculateur::multiplication()
{

  if(pileC->donneInstance()->size()<2){
        //throw std::logic_error( "ADDITION : il n'y a pas assez de paramatres");
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
    }
}

void Calculateur::soustraction()
{
      if(pileC->donneInstance()->size()<2){
        //throw std::logic_error( "ADDITION : il n'y a pas assez de paramatres");
    }
  else
  {
        Element* e1 = pileC->donneInstance()->pop();
        Element* e2 = pileC->donneInstance()->pop();
        Element& tmp = e1->operator -(*e2);
        Element* res = (this->cast(&tmp));
        delete e1;
        delete e2;
        delete &tmp;
        this->pileC->push(res);
    }

}

void Calculateur::division()
{

      if(pileC->donneInstance()->size()<2){
        //throw std::logic_error( "ADDITION : il n'y a pas assez de paramatres");
    }
  else
  {
        Element* e1 = pileC->donneInstance()->pop();
        Element* e2 = pileC->donneInstance()->pop();
        Element& tmp = e1->operator /(*e2);
        Element* res = (this->cast(&tmp));
        delete e1;
        delete e2;
        delete &tmp;
        this->pileC->push(res);
    }

}

void Calculateur::addition()
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
        this->pileC->push(res);
    }

}

Element* Calculateur::pow()
{

    if(typeid(*this->pileC->top()) == typeid(Complexe))
    {
         // throw std::logic_error( "POW : le premier parametre doit être un entier");
    }
    else if(typeid(*this->pileC->top()) == typeid(Expression))
    {
         // \todo
    }
    else
    {
        Element* pow = this->pileC->top();

        if(typeid(*this->pileC->top()) == typeid(Entier))
        {
                    Element* e = this->pileC->top();
                    return new Entier(1);
        }
    }

}

Constante* cos()
{

}

Constante* sin()
{

}

Constante* tan()
{

}

Constante* cosh()
{

}

Constante* sinh()
{

}

Constante* tanh()
{

}

Constante* ln()
{

}

Constante* log()
{

}

Constante* inv()
{

}

Constante* sqrt()
{

}

Constante* sqr()
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

