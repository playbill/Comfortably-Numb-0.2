#ifndef CALCULATEUR_H
#define CALCULATEUR_H
#include "command.h"
#include "pile.h"
#define PI 3.14159265

class Calculateur
{
    private :
        Pile* pileC;
        int taille;
        bool modeComplexe;
        bool modeEntier;
        bool modeDegre;
        bool modeRadian;
        bool modeRationnel;
        bool modeReel;

    public:

        Calculateur();
        Pile* getPile() const {return pileC;}
        Element* cast(Element* );
        Element* addition();
        Element* multiplication();
        Element* soustraction();
        Element* division();
        Element* eval();
        Element* pow();
        Constante* cos();
        Constante* sin();
        Constante* tan();
        Constante* cosh();
        Constante* sinh();
        Constante* tanh();
        Constante* ln();
        Constante* log();
        Element* inv();
        Element* sqrt();
        Element* sqr();
        Element* sign();
        Constante* operator!();
        bool isComplexe();
        bool isEntier();
        bool isDegre();
        bool isRadian();
        bool isRationnel();
        bool isReel();
};

#endif // CALCULATEUR_H
