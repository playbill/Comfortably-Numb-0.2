#ifndef ENTIER_H
#define ENTIER_H

#include "constante.h"
#include "reel.h"

class Entier : public Constante
{
private :
    int x;
public:
    Entier(int r);
    ~Entier(){}
    QString toQstring();
    Element& toReel();
    Element& toRationnel();
    Entier& toEntier();
    Element& toComplexe();
    void afficher(std::ostream& f=std::cout) const;
    Entier& operator+(Constante& c);
    Entier& operator-(Constante& c);
    Entier& operator/(Constante& c);
    Entier& operator*(Constante& c);
    Entier& pow(int x);
    Entier& cos();
    Entier& sin();
    Entier& tan();
    Entier& cosh();
    Entier& sinh();
    Entier& tanh();
    Entier& ln();
    Entier& log();
    Entier& inv();
    Entier& sqrt();
    Entier& sqr();
    Entier& operator!();

};

#endif // ENTIER_H
