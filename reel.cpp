#include "reel.h"

Reel::Reel(float r): Constante(), x(r)
{
}

    QString Reel::toQstring(){}
    Reel& Reel::toReel(){return *this;}
    Element& Reel::toRationnel(){}
    Element& Reel::toEntier(){}
    Element& Reel::toComplexe(){}
    void Reel::afficher(std::ostream& f) const{}
    Reel& Reel::operator+(Constante& c){}
    Reel& Reel::operator-(Constante& c){}
    Reel& Reel::operator/(Constante& c){}
    Reel& Reel::operator*(Constante& c){}
    Reel& Reel::pow(int x){}
    Reel& Reel::cos(){}
    Reel& Reel::sin(){}
    Reel& Reel::tan(){}
    Reel& Reel::cosh(){}
    Reel& Reel::sinh(){}
    Reel& Reel::tanh(){}
    Reel& Reel::ln(){}
    Reel& Reel::log(){}
    Reel& Reel::inv(){}
    Reel& Reel::sqrt(){}
    Reel& Reel::sqr(){}
    Reel& Reel::operator!(){}

