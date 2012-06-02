#include "rationnel.h"

Rationnel::Rationnel(int num, int den): x(num), y(den)
{
}
   QString Rationnel::toQstring(){}
    Rationnel& Rationnel::toReel(){return *this;}
    Element& Rationnel::toRationnel(){}
    Element& Rationnel::toEntier(){}
    Element& Rationnel::toComplexe(){}
    void Rationnel::afficher(std::ostream& f) const{}
    Rationnel& Rationnel::operator+(Constante& c){}
    Rationnel& Rationnel::operator-(Constante& c){}
    Rationnel& Rationnel::operator/(Constante& c){}
    Rationnel& Rationnel::operator*(Constante& c){}
    Rationnel& Rationnel::pow(int x){}
    Rationnel& Rationnel::cos(){}
    Rationnel& Rationnel::sin(){}
    Rationnel& Rationnel::tan(){}
    Rationnel& Rationnel::cosh(){}
    Rationnel& Rationnel::sinh(){}
    Rationnel& Rationnel::tanh(){}
    Rationnel& Rationnel::ln(){}
    Rationnel& Rationnel::log(){}
    Rationnel& Rationnel::inv(){}
    Rationnel& Rationnel::sqrt(){}
    Rationnel& Rationnel::sqr(){}
    Rationnel& Rationnel::operator!(){}
