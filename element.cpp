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

Element& Reel::operator+(Element& c)
{
    x = x + c.toReel().x;
    return *this;
}

Element& Reel::operator-(Element& c)
{
    x = x - c.toReel().x;
    return *this;
}

Element& Reel::operator/(Element& c)
{
    x = x/ c.toReel().x;
    return *this;
}

Element& Reel::operator*(Element& c)
{
    x = x* c.toReel().x;
    return *this;
}

/**
*\class Rationnel
*
*
*/


Rationnel::Rationnel(int num, int den): x(num), y(den)
{

}

int Rationnel::getX()
{
    return x;
}

int Rationnel::getY()
{
    return y;
}

int Rationnel::setX(int value)
{
    return x = value ;
}

int Rationnel::setY(int value)
{
    return y = value ;
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

Element& Rationnel::operator+(Element& c)
{

}

Element& Rationnel::operator-(Element& c)
{

}

Element& Rationnel::operator/(Element& c)
{

}

Element& Rationnel::operator*(Element& c)
{

}

/**
*
*\class Entier
*
*/

Entier::Entier(int r): Constante(), x(r)
{
}

int Entier::getX()
{
    return x;
}

QString Entier::toQString() const
{
    return QString(x);
}

Entier& Entier::toEntier()
{
    return *this;
}

Rationnel& Entier::toRationnel()
{

}

Reel& Entier::toReel()
{

}

Complexe& Entier::toComplexe()
{

}

void Entier::afficher(std::ostream& f) const
{
}

Element& Entier::operator+(Element& e)
{    
    if(typeid(e) == typeid(Complexe))
    {
        Complexe ecast = dynamic_cast<Complexe &>(e);
        if(typeid(ecast.getRe()) == typeid(Entier))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Entier* tmp = new Entier(ccast->getX()+ this->getX());
            return *(new Complexe(tmp));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(rcast->getX() + (float) this->getX());
            return *(new Complexe(tmp));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Rationnel* tmp = new Rationnel(rcast->getX() + this->getX());
            return *(new Complexe(tmp));
        }

    }
    if(typeid(e) == typeid(Entier))
    {
        Entier ecast = dynamic_cast<Entier &>(e);
        return *(new Entier(ecast.getX()+this->getX()));
    }
    if(typeid(e) == typeid(Rationnel))
    {
        Rationnel rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel(rcast.getX()+this->getX()));
    }
    if(typeid(e) == typeid(Reel))
    {
        Reel rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(rcast.getX()+(float)this->getX()));
    }
}

Element& Entier::operator-(Element& c)
{
    if(typeid(c) == typeid(Complexe)){}
    if(typeid(c) == typeid(Entier)){}
    if(typeid(c) == typeid(Rationnel)){}
    if(typeid(c) == typeid(Reel)){}
}

Element& Entier::operator/(Element& c)
{
    if(typeid(c) == typeid(Complexe)){
    }
    if(typeid(c) == typeid(Entier)){}
    if(typeid(c) == typeid(Rationnel)){}
    if(typeid(c) == typeid(Reel)){}
}

Element& Entier::operator*(Element& c)
{
if(typeid(c) == typeid(Complexe)){}
if(typeid(c) == typeid(Entier)){}
if(typeid(c) == typeid(Rationnel)){}
if(typeid(c) == typeid(Reel)){}
}

/**
*
*\class Complexe
*
*/
    Complexe::Complexe(Constante* x, Constante* y): re(x),im(y)
{
}

Constante* Complexe::getRe(){return re; }

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


