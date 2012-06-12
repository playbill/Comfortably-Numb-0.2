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
        Complexe& ecast = dynamic_cast<Complexe &>(e);

        if(typeid(ecast.getRe()) == typeid(Entier*))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Reel* tmp = new Reel(ccast->getX()+ this->getXAsFloat());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(rcast->getX() + this->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Reel* tmp = new Reel(((float)rcast->getX()/(float)rcast->getY()) + this->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier& ecast = dynamic_cast<Entier &>(e);
        return *(new Reel((float)ecast.getX()+this->getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression& ecast = dynamic_cast<Expression &>(e);
        return *(new Expression( this->toQString() + ' ' + ecast.getX() + ' + '));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel& rcast = dynamic_cast<Rationnel &>(e);
        return *(new Reel(((float)rcast.getX()/(float)rcast.getY())+this->getX()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel& rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(rcast.getX()+this->getX()));
    }
}

Element& Reel::operator-(Element& e)
{

    if(typeid(e) == typeid(Complexe))
    {
        Complexe& ecast = dynamic_cast<Complexe &>(e);

        if(typeid(ecast.getRe()) == typeid(Entier*))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() - (float)ccast->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() - rcast->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX()-((float)rcast->getX()/(float)rcast->getY()));
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier& ecast = dynamic_cast<Entier &>(e);
        return *(new Reel(this->getX() - (float)ecast.getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression& ecast = dynamic_cast<Expression &>(e);
        return *(new Expression( this->toQString() + ' ' + ecast.getX() + ' - '));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel& rcast = dynamic_cast<Rationnel &>(e);
        return *(new Reel(this->getX()-((float)rcast.getX()/(float)rcast.getY())));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel& rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(this->getX()-rcast.getX()));
    }
}


Element& Reel::operator/(Element& e)
{

    if(typeid(e) == typeid(Complexe))
    {
        Complexe& ecast = dynamic_cast<Complexe &>(e);

        if(typeid(ecast.getRe()) == typeid(Entier*))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() / (float)ccast->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel*))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() / rcast->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel*))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX()/((float)rcast->getX()/(float)rcast->getY()));
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier& ecast = dynamic_cast<Entier &>(e);
        return *(new Reel(this->getX() / (float)ecast.getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression& ecast = dynamic_cast<Expression &>(e);
        return *(new Expression(this->toQString() + ' ' + ecast.getX() + ' / '));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel& rcast = dynamic_cast<Rationnel &>(e);
        return *(new Reel(this->getX()/((float)rcast.getX()/(float)rcast.getY())));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel& rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(this->getX() / rcast.getX()));
    }
}

Element& Reel::operator*(Element& e)
{
   {

    if(typeid(e) == typeid(Complexe))
    {
        Complexe& ecast = dynamic_cast<Complexe &>(e);

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
        Entier& ecast = dynamic_cast<Entier &>(e);
        return *(new Reel(this->getX() * (float)ecast.getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression& ecast = dynamic_cast<Expression &>(e);
        return *(new Expression( this->toQString() + ' ' + ecast.getX() + ' * '));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel& rcast = dynamic_cast<Rationnel &>(e);
        return *(new Reel(this->getX()*(rcast.getXAsFloat()/rcast.getYAsFloat())));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel& rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(this->getX()*rcast.getX()));
    }
}
}

Reel* Reel::clone() const
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

Rationnel* Rationnel::clone() const
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
        Complexe& ecast = dynamic_cast<Complexe &>(e);
        if(typeid(ecast.getRe()) == typeid(Entier*))
        {
            Entier* tmp = new Entier(ecast.getRe()->getXAsInt()+ this->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel*))
        {
            Reel* tmp = new Reel(ecast.getRe()->getXAsFloat() + this->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone())); //toclone
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel*))
        {
            Rationnel* tmp = new Rationnel(ecast.getRe()->getXAsInt() + (this->getX()*ecast.getRe()->getYAsInt()), ecast.getRe()->getYAsInt());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier& ecast = dynamic_cast<Entier &>(e);
        return *(new Entier((ecast.getX()+this->getX())));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression& ecast = dynamic_cast<Expression &>(e);
        return *(new Expression( this->toQString() + ' ' + ecast.getX() + ' + '));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel& rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel(rcast.getX()+(this->getX()*rcast.getY()), rcast.getY()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel& rcast = dynamic_cast<Reel &>(e);
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
        Complexe& ecast = dynamic_cast<Complexe &>(e);

        if(typeid(ecast.getRe()) == typeid(Entier*))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Entier* tmp = new Entier(this->getX() - ccast->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(ecast.getRe()) == typeid(Reel*))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel((float) this->getX() - rcast->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(ecast.getRe()) == typeid(Rationnel*))
        {
            Rationnel* rcast = dynamic_cast<Rationnel *>(ecast.getRe());
            Rationnel* tmp = new Rationnel(this->getX()*rcast->getY() - rcast->getX(), rcast->getY());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier& ecast = dynamic_cast<Entier &>(e);
        return *(new Entier(this->getX() - ecast.getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression& ecast = dynamic_cast<Expression &>(e);
        return *(new Expression( this->toQString() + ' ' + ecast.getX() + ' - '));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel& rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel(this->getX()*rcast.getY() - rcast.getX(), rcast.getY()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel& rcast = dynamic_cast<Reel &>(e);
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
        return e.operator /(*this);
    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier& ecast = dynamic_cast<Entier &>(e);
        return *(new Entier(this->getX()/ecast.getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression& ecast = dynamic_cast<Expression &>(e);
        return *(new Expression( this->toQString() + ' ' + ecast.getX() + ' / ')); /*! < \todo réfléchir à ça */
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel& rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel(this->getX()*rcast.getY(), rcast.getX()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel& rcast = dynamic_cast<Reel &>(e);
        return *(new Reel((float)this->getX() / rcast.getX()));
    }
}

Element& Entier::operator*(Element& e)
{

    if(typeid(e) == typeid(Complexe))
    {
        return e.operator *(*this);

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier& ecast = dynamic_cast<Entier &>(e);
        return *(new Entier(ecast.getX()*this->getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression& ecast = dynamic_cast<Expression &>(e);
        return *(new Expression( this->toQString() + ' ' + ecast.getX() + ' * ')); // que renvoie toQString
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel& rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel(rcast.getX()*this->getX(), rcast.getY()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel& rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(rcast.getX()*(float)this->getX()));
    }
}

Entier* Entier::clone() const
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

Constante* Complexe::getRe() const{return re; }
Constante* Complexe::getIm() const {return im; }

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

Element& Complexe::operator+(Element& e)
{
    if(typeid(e)==typeid(Expression))
    {
    return *(new Expression(this->toQString() + " " + e.toQString() + ' + '));
    }
    else
    {
        Complexe& c = e.toComplexe();
        Constante* c1 = this->getRe()->clone();
        Constante* c2 = this->getIm()->clone();
        Constante* c3 = c.getRe()->clone();
        Constante* c4 = c.getIm()->clone();
        Constante& c5 = dynamic_cast<Constante&>(c1->operator+(*(c3)));
        Constante& c6 = dynamic_cast<Constante&>(c2->operator +(*(c4)));
        Complexe* c7 = new Complexe(&c5,&c6);
        delete &c;
        delete c1;
        delete c2;
        delete c3;
        delete c4;
        delete &c5;
        delete &c6;

    return *c7;
    }


}
Element& Complexe::operator-(Element& e)
{
 if(typeid(e)==typeid(Expression))
    {
    return *(new Expression( this->toQString() + " " + e.toQString() + ' - ' ));
    }
    else
    {
        Complexe& c = e.toComplexe();
        Constante* c1 = this->getRe()->clone();
        Constante* c2 = this->getIm()->clone();
        Constante* c3 = c.getRe()->clone();
        Constante* c4 = c.getIm()->clone();
        Constante& c5 = dynamic_cast<Constante&>(c1->operator-(*(c3)));
        Constante& c6 = dynamic_cast<Constante&>(c2->operator -(*(c4)));
        Complexe* c7 = new Complexe(&c5,&c6);
        delete &c;
        delete c1;
        delete c2;
        delete c3;
        delete c4;
        delete &c5;
        delete &c6;

    return *c7;
    }

}

Element& Complexe::operator/(Element& e)
{
     if(typeid(e)==typeid(Expression))
    {
    return *(new Expression( this->toQString() + " " + e.toQString() + ' / '));
    }
    else
    {
        Complexe& c = e.toComplexe();
        Complexe* c_bar = c.conjugue();
        Constante* c1 = this->getRe()->clone();
        Constante* c2 = this->getIm()->clone();
        Constante* c_barr = c_bar->getRe()->clone();
        Constante* c_bari = c_bar->getIm()->clone();
        Constante* module = c.module();
        /*(Z1/Z2) = Z1*Z2bar / |Z1| */
        Constante& resr = dynamic_cast<Constante&>(((c1->operator *(*c_barr)).operator -(c2->operator *(*c_bari))));
        Constante& resi = dynamic_cast<Constante&>(((c1->operator *(*c_bari)).operator +(c2->operator *(*c_barr))));
        Complexe* res = new Complexe(&resr,&resi);
        delete &c;
        delete c_bar;
        delete c1;
        delete c2;
        delete c_barr;
        delete c_bari;
        delete module;
        delete &resr;
        delete &resi;

    return *res;
    }
}

Element& Complexe::operator*(Element& e)
{
    if(typeid(e)==typeid(Expression))
    {
        return *(new Expression(this->toQString() + " " + e.toQString() + ' * '));
    }
    else
    {
        Complexe& c = e.toComplexe();
        Constante* c1 = this->getRe()->clone();
        Constante* c2 = this->getIm()->clone();
        Constante* cr = c.getRe()->clone();
        Constante* ci = c.getIm()->clone();
        /* (aa' - bb') + (ab' + a'b)*/
        Constante& resr = dynamic_cast<Constante&>((c1->operator *(*cr)).operator -(c2->operator *(*ci)));
        Constante& resi = dynamic_cast<Constante&>((c1->operator *(*ci)).operator +(c2->operator *(*cr)));
        Complexe* res = new Complexe(&resr,&resi);
        delete &c;
        delete c1;
        delete c2;
        delete cr;
        delete ci;
        delete &resr;
        delete &resi;

    return *res;

    }


}

Complexe* Complexe::clone() const
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

Constante* Complexe::module()
{
    Reel* tmp = new Reel (sqrt(pow(this->getIm()->getXAsFloat()/this->getIm()->getYAsFloat(),2)+pow(this->getRe()->getXAsFloat()/this->getRe()->getYAsFloat(),2)));
    return tmp;
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
    return x;
}

QString Expression::getX() const
{
    return x;
}

Expression* Expression::clone() const
{
    return new Expression(this->getX());
}


