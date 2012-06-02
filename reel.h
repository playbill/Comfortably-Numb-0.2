#ifndef REEL_H
#define REEL_H

#include "constante.h"

class Reel : public Constante
{
public:
    Reel(float r);
    ~Reel(){}
    QString toQstring();
    Reel& toReel();
    Element& toRationnel();
    Element& toEntier();
    Element& toComplexe();
    void afficher(std::ostream& f=std::cout) const;
    Reel& operator+(Constante& c);
    Reel& operator-(Constante& c);
    Reel& operator/(Constante& c);
    Reel& operator*(Constante& c);
    Reel& pow(int x);
    Reel& cos();
    Reel& sin();
    Reel& tan();
    Reel& cosh();
    Reel& sinh();
    Reel& tanh();
    Reel& ln();
    Reel& log();
    Reel& inv();
    Reel& sqrt();
    Reel& sqr();
    Reel& operator!();

private:
            float x;
};

#endif // REEL_H
