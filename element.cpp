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

Element& Reel::operator+(Element& e)
{

    if(typeid(e) == typeid(Complexe))
    {
        Complexe ecast = dynamic_cast<Complexe &>(e);

        if(typeid(ecast.getRe()) == typeid(Entier*))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Reel* tmp = new Reel((float)ccast->getX()+ this->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(rcast->getX() + this->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Reel* tmp = new Reel(((float)rcast->getX()/(float)rcast->getY()) + this->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier ecast = dynamic_cast<Entier &>(e);
        return *(new Reel((float)ecast.getX()+this->getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression ecast = dynamic_cast<Expression &>(e);
        return *(new Expression(' + ' + this->toQString() + ' ' + ecast.getX()));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel rcast = dynamic_cast<Rationnel &>(e);
        return *(new Reel(((float)rcast.getX()/(float)rcast.getY())+this->getX()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(rcast.getX()+this->getX()));
    }
}

Element& Reel::operator-(Element& e)
{

    if(typeid(e) == typeid(Complexe))
    {
        Complexe ecast = dynamic_cast<Complexe &>(e);

        if(typeid(ecast.getRe()) == typeid(Entier*))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() - (float)ccast->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() - rcast->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX()-((float)rcast->getX()/(float)rcast->getY()));
            return *(new Complexe(tmp, ecast.getIm()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier ecast = dynamic_cast<Entier &>(e);
        return *(new Reel(this->getX() - (float)ecast.getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression ecast = dynamic_cast<Expression &>(e);
        return *(new Expression(' - ' + this->toQString() + ' ' + ecast.getX()));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel rcast = dynamic_cast<Rationnel &>(e);
        return *(new Reel(this->getX()-((float)rcast.getX()/(float)rcast.getY())));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(this->getX()-rcast.getX()));
    }
}


Element& Reel::operator/(Element& e)
{

    if(typeid(e) == typeid(Complexe))
    {
        Complexe ecast = dynamic_cast<Complexe &>(e);

        if(typeid(ecast.getRe()) == typeid(Entier*))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() / (float)ccast->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel*))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() / rcast->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel*))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX()/((float)rcast->getX()/(float)rcast->getY()));
            return *(new Complexe(tmp, ecast.getIm()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier ecast = dynamic_cast<Entier &>(e);
        return *(new Reel(this->getX() / (float)ecast.getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression ecast = dynamic_cast<Expression &>(e);
        return *(new Expression(' / ' + this->toQString() + ' ' + ecast.getX()));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel rcast = dynamic_cast<Rationnel &>(e);
        return *(new Reel(this->getX()/((float)rcast.getX()/(float)rcast.getY())));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(this->getX() / rcast.getX()));
    }
}

Element& Reel::operator*(Element& e)
{
   {

    if(typeid(e) == typeid(Complexe))
    {
        Complexe ecast = dynamic_cast<Complexe &>(e);

        if(typeid(ecast.getRe()) == typeid(Entier*))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() * (float)ccast->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() * rcast->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX()*((float)rcast->getX()/(float)rcast->getY()));
            return *(new Complexe(tmp, ecast.getIm()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier ecast = dynamic_cast<Entier &>(e);
        return *(new Reel(this->getX() * (float)ecast.getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression ecast = dynamic_cast<Expression &>(e);
        return *(new Expression(' * ' + this->toQString() + ' ' + ecast.getX()));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel rcast = dynamic_cast<Rationnel &>(e);
        return *(new Reel(this->getX()*((float)rcast.getX()/(float)rcast.getY())));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(this->getX()*rcast.getX()));
    }
}
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
/**
*\fn Element& operator+(Element& e)
*
*/
Element& Entier::operator+(Element& e)
{    
    if(typeid(e) == typeid(Complexe))
    {
        Complexe ecast = dynamic_cast<Complexe &>(e);
        if(typeid(ecast.getRe()) == typeid(Entier*))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Entier* tmp = new Entier(ccast->getX()+ this->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel*))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(rcast->getX() + (float) this->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel*))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Rationnel* tmp = new Rationnel(rcast->getX() + this->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier ecast = dynamic_cast<Entier &>(e);
        return *(new Entier(ecast.getX()+this->getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression ecast = dynamic_cast<Expression &>(e);
        return *(new Expression(' + ' + this->toQString() + ' ' + ecast.getX()));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel(rcast.getX()+this->getX()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(rcast.getX()+(float)this->getX()));
    }    
}
/**
*\fn Element& operator-(Element& e)
*
*/
Element& Entier::operator-(Element& e)
{
     if(typeid(e) == typeid(Complexe))
    {
        Complexe ecast = dynamic_cast<Complexe &>(e);

        if(typeid(ecast.getRe()) == typeid(Entier*))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Entier* tmp = new Entier(this->getX() - ccast->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel*))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel((float) this->getX() - rcast->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel*))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Rationnel* tmp = new Rationnel(this->getX() - rcast->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier ecast = dynamic_cast<Entier &>(e);
        return *(new Entier(this->getX() - ecast.getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression ecast = dynamic_cast<Expression &>(e);
        return *(new Expression(' - ' + this->toQString() + ' ' + ecast.getX()));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel(this->getX() - rcast.getX()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel rcast = dynamic_cast<Reel &>(e);
        return *(new Reel((float)this->getX() - rcast.getX()));
    }
}
/**
*\fn Element& operator/(Element& c)
*
*/

Element& Entier::operator/(Element& e)
{
    if(typeid(e) == typeid(Complexe))
    {
        Complexe ecast = dynamic_cast<Complexe &>(e);
        if(typeid(ecast.getRe()) == typeid(Entier*))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Entier* tmp = new Entier(this->getX() / ccast->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel*))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel((float) this->getX()/rcast->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel*))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Rationnel* tmp = new Rationnel(this->getX() / rcast->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier ecast = dynamic_cast<Entier &>(e);
        return *(new Entier(this->getX()/ecast.getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression ecast = dynamic_cast<Expression &>(e);
        return *(new Expression('/' + this->toQString() + ' ' + ecast.getX())); /*! < \todo réfléchir à ça */
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel(this->getX() / rcast.getX()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel rcast = dynamic_cast<Reel &>(e);
        return *(new Reel((float)this->getX() / rcast.getX()));
    }
}

Element& Entier::operator*(Element& e)
{

    if(typeid(e) == typeid(Complexe))
    {
        Complexe ecast = dynamic_cast<Complexe &>(e);
        if(typeid(ecast.getRe()) == typeid(Entier*))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Entier* tmp = new Entier(ccast->getX()* this->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel*))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(rcast->getX() * (float) this->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel*))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Rationnel* tmp = new Rationnel(rcast->getX() * this->getX());
            return *(new Complexe(tmp, ecast.getIm()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier ecast = dynamic_cast<Entier &>(e);
        return *(new Entier(ecast.getX()*this->getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression ecast = dynamic_cast<Expression &>(e);
        return *(new Expression(' * ' + this->toQString() + ' ' + ecast.getX()));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel(rcast.getX()*this->getX()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(rcast.getX()*(float)this->getX()));
    }
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
Constante* Complexe::getIm(){return im; }

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
Element& Complexe::operator+(Element& c){}
Element& Complexe::operator-(Element& c){}
Element& Complexe::operator/(Element& c){}
Element& Complexe::operator*(Element& c){}

/**
*
*\class Expression
*
*/

Expression::Expression(QString s): Element(), x(s)
{

}

QString Expression::toQString() const
{
}

QString Expression::getX()
{
    return x;
}

Reel& Expression::toReel()
{
}

Rationnel& Expression::toRationnel()
{
}

Entier& Expression::toEntier()
{
}

Complexe& Expression::toComplexe()
{
}

Element& Expression::operator+(Element& c)
{
}

Element& Expression::operator-(Element& c)
{
}

Element& Expression::operator/(Element& c)
{
}

Element& Expression::operator*(Element& c)
{
}



