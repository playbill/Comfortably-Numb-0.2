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

Reel::Reel(const Reel &r): x (r.getXAsFloat())
{
}

Reel::~Reel()
{
}

float Reel::getXAsFloat() const
{
    return x;
}

int Reel::getXAsInt() const
{
    return (int) x;
}

float Reel::getX()const
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
    Rationnel* tmp = new Rationnel((int)x);
    return *tmp;
}

Entier& Reel::toEntier()
{
    Entier* tmp = new Entier((int)x);
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
            Reel* tmp = new Reel(ccast->getX()+ this->getXAsFloat());
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
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel))
        {
            Reel* tmp = new Reel(this->getX() * ecast.getRe()->getXAsFloat());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel))
        {

            Reel* tmp = new Reel(this->getX()*(ecast.getRe()->getXAsFloat()/ecast.getRe()->getYAsFloat()));
            return *(new Complexe(tmp, ecast.getIm()->clone()));
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
        return *(new Reel(this->getX()*(rcast.getXAsFloat()/rcast.getYAsFloat())));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(this->getX()*rcast.getX()));
    }
}
}

Reel* Reel::clone()
{
    return new Reel(this->getX());
}

Reel* Reel::sign()
{
    return new Reel(-this->getX());
}

/**
*\class Rationnel
*
*
*/


Rationnel::Rationnel(int num, int den): x(num), y(den)
{

}

int Rationnel::getX()const
{
    return x;
}

int Rationnel::getY()const
{
    return y;
}

float Rationnel::getXAsFloat() const
{
    return (float)x;
}

int Rationnel::getXAsInt() const
{
    return x;
}

float Rationnel::getYAsFloat() const
{
    return (float)y;
}

int Rationnel::getYAsInt() const
{
    return y;
}

void Rationnel::setX(int value)
{
     x = value ;
}

void Rationnel::setY(int value)
{
     y = value ;
}

QString Rationnel::toQString() const
{
    return QString::number(x/y);

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
    Entier* tmp = new Entier((int)(this->getX()/this->getY()));
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

Rationnel* Rationnel::clone()
{
    return new Rationnel(this->getX(),this->getY());
}

Rationnel* Rationnel::sign()
{
    return new Rationnel(-this->getX(),this->getY());
}

/**
*
*\class Entier
*
*/

Entier::Entier(int r): Constante(), x(r)
{
}

int Entier::getX() const
{
    return x;
}

float Entier::getXAsFloat() const
{
    return (float)x;
}

int Entier::getXAsInt() const
{
    return x;
}

QString Entier::toQString() const
{
    return QString::number(x);
}

Entier& Entier::toEntier()
{
    return *(this->clone());
}

Rationnel& Entier::toRationnel()
{
    return *(new Rationnel(this->getX()));
}

Reel& Entier::toReel()
{

}

Complexe& Entier::toComplexe()
{
return *(new Complexe(this));
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
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel*))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(rcast->getX() + this->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone())); //toclone
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel*))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Rationnel* tmp = new Rationnel(rcast->getX() + (this->getX()*rcast->getY()), rcast->getY());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier ecast = dynamic_cast<Entier &>(e);
        return *(new Entier((ecast.getX()+this->getX())));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression ecast = dynamic_cast<Expression &>(e);
        return *(new Expression(' + ' + this->toQString() + ' ' + ecast.getX()));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel(rcast.getX()+(this->getX()*rcast.getY()), rcast.getY()));
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
            Rationnel* tmp = new Rationnel(this->getX()*rcast->getY() - rcast->getX(), rcast->getY());
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
        return *(new Rationnel(this->getX()*rcast.getY() - rcast.getX(), rcast.getY()));
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
        Complexe ecast = e.toComplexe();
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
            Rationnel* tmp = new Rationnel(this->getX()*rcast->getY() , rcast->getX());
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
        return *(new Expression('/' + this->toQString() + ' ' + ecast.getX())); /*! < \todo r�fl�chir � �a */
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel(this->getX()*rcast.getY(), rcast.getX()));
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
            Rationnel* tmp = new Rationnel(rcast->getX() * this->getX(), rcast->getY());
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
        return *(new Rationnel(rcast.getX()*this->getX(), rcast.getY()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(rcast.getX()*(float)this->getX()));
    }
}

Entier* Entier::clone()
{
    return new Entier(this->getX());
}

Entier* Entier::sign()
{
    return new Entier(-this->getX());
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
Rationnel& Complexe::toRationnel()
{
    //
}
Entier& Complexe::toEntier(){}
Complexe& Complexe::toComplexe()
{
    return *(this->clone());
}
Complexe* Complexe::conjugue()
{
   Constante* c1 = this->getRe()->clone();
   Constante* c2 = this->getIm()->sign();

    return (new Complexe(c1,c2));
}
void Complexe::afficher(std::ostream& f) const{}
Element& Complexe::operator+(Element& c){}
Element& Complexe::operator-(Element& c){}
Element& Complexe::operator/(Element& c){}
Element& Complexe::operator*(Element& c){}

Complexe* Complexe::clone()
{
    Constante* c1 = this->getRe()->clone();
    Constante* c2 = this->getIm()->clone();

    return new Complexe(c1,c2);
}

Complexe* Complexe::sign()
{
    Constante* c1 = this->getRe()->sign();
    Constante* c2 = this->getIm()->sign();

    return new Complexe(c1,c2);
}
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
Expression* Expression::clone()
{
    return new Expression(this->getX());
}


