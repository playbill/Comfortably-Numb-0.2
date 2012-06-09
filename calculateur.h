#ifndef CALCULATEUR_H
#define CALCULATEUR_H

#include "pile.h"
#define PI 3.14159265

class Calculateur
{
    private :
        Pile* pileC;
        bool modeComplexe;
        bool modeEntier;
        bool modeDegre;
        bool modeRadian;
        bool modeRationnel;
        bool modeReel;

    public:
        Calculateur();
        Element* cast(Element* );
        Element* addition();
        void multiplication();
        void soustraction();
        void division();
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
