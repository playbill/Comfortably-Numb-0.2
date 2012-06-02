#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "constante.h"

class Rationnel : public Constante
{

private:
    int x;
    int y;
public:
    Rationnel(int x, int y);
    ~Rationnel(){}
    QString toQstring();
    Rationnel& toReel();
    Element& toRationnel();
    Element& toEntier();
    Element& toComplexe();
    void afficher(std::ostream& f=std::cout) const;
    Rationnel& operator+(Constante& c);
    Rationnel& operator-(Constante& c);
    Rationnel& operator/(Constante& c);
    Rationnel& operator*(Constante& c);
    Rationnel& pow(int x);
    Rationnel& cos();
    Rationnel& sin();
    Rationnel& tan();
    Rationnel& cosh();
    Rationnel& sinh();
    Rationnel& tanh();
    Rationnel& ln();
    Rationnel& log();
    Rationnel& inv();
    Rationnel& sqrt();
    Rationnel& sqr();
    Rationnel& operator!();

};

#endif // RATIONNEL_H
