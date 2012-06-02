#ifndef CONSTANTE_H
#define CONSTANTE_H
#include "element.h"
class Constante : public Element
{
public:
    Constante();
    virtual ~Constante();
            virtual QString toQstring() = 0;
            virtual Element& toReel() = 0;/*!< /todo quelle retour mettre reel? */
            virtual Element& toRationnel() = 0; /*! idem */
            virtual Element& toEntier() = 0; /*! idem */
            virtual Element& toComplexe() = 0; /*! idem */
            virtual void afficher(std::ostream& f=std::cout) const = 0;
            virtual Constante& operator+(Constante& c) = 0;
            virtual Constante& operator-(Constante& c) = 0;
            virtual Constante& operator/(Constante& c) = 0;
            virtual Constante& operator*(Constante& c) = 0;
            virtual Constante& pow(int x) = 0;
            virtual Constante& cos() = 0;
            virtual Constante& sin() = 0;
            virtual Constante& tan() = 0;
            virtual Constante& cosh() = 0;
            virtual Constante& sinh() = 0;
            virtual Constante& tanh() = 0;
            virtual Constante& ln() = 0;
            virtual Constante& log() = 0;
            virtual Constante& inv() = 0;
            virtual Constante& sqrt() = 0;
            virtual Constante& sqr() = 0;
            virtual Constante& operator!() = 0;
};

#endif // CONSTANTE_H
