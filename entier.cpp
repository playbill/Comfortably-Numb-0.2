#include "entier.h"

Entier::Entier(int r): Constante(), x(r)
{
}

    QString Entier::toQstring(){}
    Entier& Entier::toEntier(){return *this;}
    Element& Entier::toRationnel(){}
    Element& Entier::toReel(){}
    Element& Entier::toComplexe(){}
    void Entier::afficher(std::ostream& f) const{}
    Entier& Entier::operator+(Constante& c){}
    Entier& Entier::operator-(Constante& c){}
    Entier& Entier::operator/(Constante& c){}
    Entier& Entier::operator*(Constante& c){}
    Entier& Entier::pow(int x){}
    Entier& Entier::cos(){}
    Entier& Entier::sin(){}
    Entier& Entier::tan(){}
    Entier& Entier::cosh(){}
    Entier& Entier::sinh(){}
    Entier& Entier::tanh(){}
    Entier& Entier::ln(){}
    Entier& Entier::log(){}
    Entier& Entier::inv(){}
    Entier& Entier::sqrt(){}
    Entier& Entier::sqr(){}
    Entier& Entier::operator!(){}
