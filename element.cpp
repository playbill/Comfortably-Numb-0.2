#include "element.h"

Element::Element()
{
}

Element::~Element()
{
}

/**
* \fn Constante()
* \brief Constructeur
* Fonction Ne fait rien car la classe est abstraite
*/
Constante::Constante()
{
}

/**
* \fn ~Constante()
* \brief Destructeur
* Fonction Ne fait rien car la classe est abstraite
*/
Constante::~Constante()
{
}

/**
* \fn ~Constante(const Constance& c)
* \brief Cons
* Fonction Ne fait rien car la classe est abstraite
*/
//Constante::Constante(const Constante& c){}

/**
*\class REEL
*
*
*/

Reel::Reel(float r): Constante(), x(r)
{
}

Reel::Reel(const Reel &r): x (r.getX())
{
}

Reel::~Reel()
{
}

float Reel::getX() const
{
    return x;
}

void Reel::setX(float value)
{
    x = value;
}


QString Reel::toQString () const
{   return QString::number(x);
}

Reel& Reel::toReel()
{
    Reel* tmp = new Reel(*this);
    return *tmp;
}

Rationnel& Reel::toRationnel()
{
    Rationnel* tmp = new Rationnel(x);
    return *tmp;
}

Entier& Reel::toEntier()
{
    Entier* tmp = new Entier(x);
    return *tmp;
}

Complexe& Reel::toComplexe()
{
    Complexe* tmp = new Complexe(this);
    return *tmp;
}

void Reel::afficher(std::ostream& f) const{}

Reel& Reel::operator+(Constante& c)
{
    x = x + c.toReel().x;
    return *this;
}

Reel& Reel::operator-(Constante& c)
{
    x = x - c.toReel().x;
    return *this;
}

Reel& Reel::operator/(Constante& c)
{
    x = x/ c.toReel().x;
    return *this;
}

Reel& Reel::operator*(Constante& c)
{
    x = x* c.toReel().x;
    return *this;
}


Rationnel::Rationnel(int num, int den): x(num), y(den)
{

}

QString Rationnel::toQString() const
{
    return QString(x/y);

}

Reel& Rationnel::toReel()
{
}

Rationnel& Rationnel::toRationnel()
{
    Rationnel* tmp = new Rationnel(*this);
    return *tmp;
}

Entier& Rationnel::toEntier()
{
    Entier* tmp = new Entier(x/y);
    return *tmp;
}

Complexe& Rationnel::toComplexe()
{
    Complexe* tmp = new Complexe(this);
    return *tmp;
}

void Rationnel::afficher(std::ostream& f) const
{

}

Rationnel& Rationnel::operator+(Constante& c)
{

}

Rationnel& Rationnel::operator-(Constante& c)
{

}

Rationnel& Rationnel::operator/(Constante& c)
{

}

Rationnel& Rationnel::operator*(Constante& c)
{

}


Entier::Entier(int r): Constante(), x(r)
{
}

    QString Entier::toQString() const {return QString(x);}
    Entier& Entier::toEntier(){return *this;}
    Rationnel& Entier::toRationnel(){}
    Reel& Entier::toReel(){}
    Complexe& Entier::toComplexe(){}
    void Entier::afficher(std::ostream& f) const{}
    Entier& Entier::operator+(Constante& c){}
    Entier& Entier::operator-(Constante& c){}
    Entier& Entier::operator/(Constante& c){}
    Entier& Entier::operator*(Constante& c){}


    Complexe::Complexe(Constante* x, Constante* y): re(x),im(y)
{
}

    QString Complexe::toQString() const
    {   QString tmp;
        tmp = 'a';
        return tmp;
    }
    Reel& Complexe::toReel(){}
    Rationnel& Complexe::toRationnel(){}
    Entier& Complexe::toEntier(){}
    Complexe& Complexe::toComplexe(){return *this;}
    void Complexe::afficher(std::ostream& f) const{}
    Complexe& Complexe::operator+(Constante& c){}
    Complexe& Complexe::operator-(Constante& c){}
    Complexe& Complexe::operator/(Constante& c){}
    Complexe& Complexe::operator*(Constante& c){}


