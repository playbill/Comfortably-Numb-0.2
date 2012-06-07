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

Element* Calculateur::multiplication()
{

  if(pileC->donneInstance()->size()<2){
        //throw std::logic_error( "ADDITION : il n'y a pas assez de paramatres");
    }
  else
  {
        Element* e1 = pileC->donneInstance()->pop();
        Element* e2 = pileC->donneInstance()->pop();
        Element& res = e1->operator *(*e2);

    this->cast(&res);
    this->pileC->push(&res);
    }
}

Element* Calculateur::soustraction()
{
      if(pileC->donneInstance()->size()<2){
        //throw std::logic_error( "ADDITION : il n'y a pas assez de paramatres");
    }
  else
  {
        Element* e1 = pileC->donneInstance()->pop();
        Element* e2 = pileC->donneInstance()->pop();
        Element& res = e1->operator -(*e2);

    res = *(this->cast(&res));
    this->pileC->push(&res);
    }

}

Element* Calculateur::division()
{

      if(pileC->donneInstance()->size()<2){
        //throw std::logic_error( "ADDITION : il n'y a pas assez de paramatres");
    }
  else
  {
        Element* e1 = pileC->donneInstance()->pop();
        Element* e2 = pileC->donneInstance()->pop();
        Element& res = e1->operator /(*e2);

    res = *(this->cast(&res));
    this->pileC->push(&res);
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
        Element& res = e1->operator +(*e2);

    res = *(this->cast(&res));
    this->pileC->push(&res);
    }

}

Constante* pow()
{

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
    return Entier;
}

bool Calculateur::isComplexe()
{
    return Complexe;
}

bool Calculateur::isDegre()
{
    return Degre;
}

bool Calculateur::isRadian()
{
    return Radian;
}

bool Calculateur::isRationnel()
{
    return Rationnel;
}

bool Calculateur::isReel()
{
    return Reel;
}

