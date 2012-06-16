#include "element.h"
#include <QDEBUG>
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
{qDebug()<<"getXasf";
    return x;
}

int Reel::getXAsInt() const
{qDebug()<<"getXasi";
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

Reel* Reel::toReel()
{
    Reel* tmp = new Reel(*this);
    return tmp;
}

Rationnel* Reel::toRationnel()
{
    Rationnel* tmp = new Rationnel((int)x);
    return tmp;
}

Entier* Reel::toEntier()
{
    Entier* tmp = new Entier((int)x);
    return tmp;
}

Complexe* Reel::toComplexe()
{   qDebug()<<"reel to Complexe()";
    Complexe* tmp = new Complexe(this->clone());
    return tmp;
}

void Reel::afficher(std::ostream& f) const{}

Element& Reel::operator+(Element& e)
{    qDebug()<<"reel operator+ ";

    if(typeid(e) == typeid(Complexe))
    {
        Complexe& ecast = dynamic_cast<Complexe &>(e);

        if(typeid(*ecast.getRe()) == typeid(Entier*))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Reel* tmp = new Reel(ccast->getX()+ this->getXAsFloat());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(*ecast.getRe()) == typeid(Reel))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(rcast->getX() + this->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(*ecast.getRe()) == typeid(Rationnel))
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
{    qDebug()<<"reel operator- ";

    if(typeid(e) == typeid(Complexe))
    {
        Complexe& ecast = dynamic_cast<Complexe &>(e);

        if(typeid(*ecast.getRe()) == typeid(Entier))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() - (float)ccast->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(*ecast.getRe()) == typeid(Reel))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() - rcast->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(*ecast.getRe()) == typeid(Rationnel))
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
{    qDebug()<<"reel operator/ ";

    if(typeid(e) == typeid(Complexe))
    {
        Complexe& ecast = dynamic_cast<Complexe &>(e);

        if(typeid(*ecast.getRe()) == typeid(Entier))
        {
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() / (float)ccast->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(*ecast.getRe()) == typeid(Reel))
        {
            Reel* rcast = dynamic_cast<Reel *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() / rcast->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(*ecast.getRe()) == typeid(Rationnel))
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
    else{qDebug()<<"erreur";}
}

Element& Reel::operator*(Element& e)
{   qDebug()<<"reel operator* ";
   {

    if(typeid(e) == typeid(Complexe))
    {
        Complexe& ecast = dynamic_cast<Complexe &>(e);

        if(typeid(*ecast.getRe()) == typeid(Entier))
        {    qDebug()<<"re.typeid = entier ";
            Entier* ccast = dynamic_cast<Entier *>(ecast.getRe());
            Reel* tmp = new Reel(this->getX() * (float)ccast->getX());
            Reel* tmpim = new Reel(this->getXAsFloat() * ecast.getIm()->getXAsFloat());
            return *(new Complexe(tmp, tmpim));
        }
        else if(typeid(*ecast.getRe()) == typeid(Reel))
        {
            Reel* tmp = new Reel(this->getX() * ecast.getRe()->getXAsFloat());
            Reel* tmpim = new Reel(this->getXAsFloat() * ecast.getIm()->getXAsFloat());
            return *(new Complexe(tmp, tmpim));
        }
        else if(typeid(*ecast.getRe()) == typeid(Rationnel))
        {

            Reel* tmp = new Reel(this->getX()*(ecast.getRe()->getXAsFloat()/ecast.getRe()->getYAsFloat()));
            Reel* tmpim = new Reel(this->getXAsFloat()* (ecast.getIm()->getXAsFloat()/ecast.getIm()->getYAsFloat()));
            return *(new Complexe(tmp, tmpim));
        }
        else{ qDebug()<<"je suis passé par ici";}

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
    else{}
}
}

Reel* Reel::clone() const
{   qDebug()<<"clone reel";
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
    return QString::number(x)+'/'+QString::number(y);

}

Reel* Rationnel::toReel()
{
    Reel* tmp = new Reel((this->getXAsFloat()/this->getYAsFloat()));
    return tmp;
}

Rationnel* Rationnel::toRationnel()
{
    Rationnel* tmp = new Rationnel(*this);
    return tmp;
}

Entier* Rationnel::toEntier()
{
    Entier* tmp = new Entier((int)(this->getX()/this->getY()));
    return tmp;
}

Complexe* Rationnel::toComplexe()
{
    Complexe* tmp = new Complexe(this->clone());
    return tmp;
}

void Rationnel::afficher(std::ostream& f) const
{

}

Element& Rationnel::operator+(Element& e)
{
    if(typeid(e) == typeid(Complexe))
    {
        Complexe& ecast = dynamic_cast<Complexe &>(e);
        if(typeid(*ecast.getRe()) == typeid(Entier))
        {
            Rationnel* tmp = new Rationnel((ecast.getRe()->getXAsInt()*this->getYAsInt())+ this->getX(),this->getYAsInt());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(*ecast.getRe()) == typeid(Reel))
        {
            Reel* tmp = new Reel((ecast.getRe()->getXAsFloat()/(ecast.getRe()->getYAsFloat())) + this->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone())); //toclone
        }
        else if(typeid(*ecast.getRe()) == typeid(Rationnel))
        {
            Rationnel* tmp = new Rationnel((ecast.getRe()->getXAsInt()*this->getYAsInt()) + (this->getX()*ecast.getRe()->getYAsInt()), ecast.getRe()->getYAsInt() * ecast.getRe()->getYAsInt());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier& ecast = dynamic_cast<Entier &>(e);
        return *(new Rationnel(((ecast.getX()*this->getYAsInt())+this->getX()),this->getYAsInt()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression& ecast = dynamic_cast<Expression &>(e);
        return *(new Expression( this->toQString() + ' ' + ecast.getX() + ' + '));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel& rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel((rcast.getX()*(this->getY()))+(rcast.getY() * this->getXAsInt()), rcast.getY()*this->getYAsInt()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel& rcast = dynamic_cast<Reel &>(e);
        return *(new Reel((this->getXAsFloat()/this->getYAsFloat())+rcast.getXAsFloat()));
    }
}

Element& Rationnel::operator-(Element& e)
{
        if(typeid(e) == typeid(Complexe))
    {
        Complexe& ecast = dynamic_cast<Complexe &>(e);
        if(typeid(*ecast.getRe()) == typeid(Entier))
        {
            Rationnel* tmp = new Rationnel((ecast.getRe()->getXAsInt()*this->getYAsInt())- this->getX(),this->getYAsInt());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }
        else if(typeid(*ecast.getRe()) == typeid(Reel))
        {
            Reel* tmp = new Reel((ecast.getRe()->getXAsFloat()/(ecast.getRe()->getYAsFloat())) - this->getX());
            return *(new Complexe(tmp, ecast.getIm()->clone())); //toclone
        }
        else if(typeid(*ecast.getRe()) == typeid(Rationnel))
        {
            Rationnel* tmp = new Rationnel((ecast.getRe()->getXAsInt()*this->getYAsInt()) - (this->getX()*ecast.getRe()->getYAsInt()), ecast.getRe()->getYAsInt() * ecast.getRe()->getYAsInt());
            return *(new Complexe(tmp, ecast.getIm()->clone()));
        }

    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier& ecast = dynamic_cast<Entier &>(e);
        return *(new Rationnel(((ecast.getX()*this->getYAsInt())-this->getX()),this->getYAsInt()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression& ecast = dynamic_cast<Expression &>(e);
        return *(new Expression( this->toQString() + ' ' + ecast.getX() + ' + '));
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel& rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel((rcast.getX()*(this->getY()))-(rcast.getY() * this->getXAsInt()), rcast.getY()*this->getYAsInt()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel& rcast = dynamic_cast<Reel &>(e);
        return *(new Reel((this->getXAsFloat()/this->getYAsFloat())-rcast.getXAsFloat()));
    }

}

Element& Rationnel::operator/(Element& e)
{
    if(typeid(e) == typeid(Complexe))
    {
        return e.operator /(*this);
    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier& ecast = dynamic_cast<Entier &>(e);
        return *(new Rationnel(this->getX(),this->getY()*ecast.getX()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression& ecast = dynamic_cast<Expression &>(e);
        return *(new Expression( this->toQString() + ' ' + ecast.getX() + ' / ')); /*! < \todo réfléchir à ça */
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel& rcast = dynamic_cast<Rationnel &>(e);
        return *(new Rationnel(this->getX()*rcast.getY(), rcast.getX()*this->getY()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel& rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(((float)this->getX()/this->getXAsFloat()) / rcast.getX()));
    }
    else{//\todo throw
    }
}

Element& Rationnel::operator*(Element& e)
{
        if(typeid(e) == typeid(Complexe))
    {
        return e.operator *(*this);
    }
    else if(typeid(e) == typeid(Entier))
    {
        Entier& ecast = dynamic_cast<Entier &>(e);
        qDebug()<<this->getY();
        return *(new Rationnel(this->getX()*ecast.getXAsInt(),this->getY()));
    }
    else if(typeid(e) == typeid(Expression))
    {
        Expression& ecast = dynamic_cast<Expression &>(e);
        return *(new Expression( this->toQString() + ' ' + ecast.getX() + ' * ')); /*! < \todo réfléchir à ça */
    }
    else if(typeid(e) == typeid(Rationnel))
    {
        Rationnel& rcast = dynamic_cast<Rationnel &>(e);
        qDebug()<<rcast.getY();
        return *(new Rationnel(this->getX()*rcast.getX(), rcast.getY()*this->getY()));
    }
    else if(typeid(e) == typeid(Reel))
    {
        Reel& rcast = dynamic_cast<Reel &>(e);
        return *(new Reel(((float)this->getX()/this->getXAsFloat()) * rcast.getX()));
    }
    else{//\todo throw
    }

}

Rationnel* Rationnel::clone() const
{   qDebug()<<"clone rationnel";
    return new Rationnel(this->getXAsInt(),this->getYAsInt());
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
    return (float) x;
}

int Entier::getXAsInt() const
{
    return x;
}

QString Entier::toQString() const
{
    return QString::number(x);
}

Entier* Entier::toEntier()
{
    return (this->clone());
}

Rationnel* Entier::toRationnel()
{
    return (new Rationnel(this->getX()));
}

Reel* Entier::toReel()
{
    return (new Reel(this->getXAsFloat()));
}

Complexe* Entier::toComplexe()
{qDebug()<<"entier::toComplexe()";
return new Complexe(this->clone());
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
{   qDebug()<<"entier operator/ ";
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
    qDebug()<<"entier operator* ";
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
{   qDebug()<<"clone entier";
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
{   qDebug()<<x->toQString();
}
        Complexe::Complexe(Complexe* c): re(c->re),im(c->im)
{
}

Constante* Complexe::getRe() const{return re; }
Constante* Complexe::getIm() const {return im; }

QString Complexe::toQString() const
{
    QString tmp = re->toQString() + '$';
    if(im != 0)
    tmp += im->toQString();
    return tmp;
}

Reel* Complexe::toReel()
{
    return new Reel(this->getRe()->getXAsFloat()/this->getRe()->getYAsFloat());
}
Rationnel* Complexe::toRationnel()
{
    return new Rationnel(this->getRe()->getXAsInt(),this->getRe()->getYAsInt());
}
Entier* Complexe::toEntier()
{
    return new Entier((int)(this->getRe()->getXAsFloat()/this->getRe()->getYAsFloat()));
}
Complexe* Complexe::toComplexe()
{ qDebug()<<"complexe to complexe()";
    return (this->clone());
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
        qDebug()<<"expression";
    return *(new Expression(this->toQString() + " " + e.toQString() + ' + '));
    }
    else
    {    qDebug()<<"pas expression";
        Complexe* c = e.toComplexe();
        Constante* c1 = this->getRe()->clone();
        Constante* c2 = this->getIm()->clone();
        Constante* c3 = c->getRe()->clone();
        Constante* c4 = c->getIm()->clone();
        Constante& c5 = dynamic_cast<Constante&>(c1->operator+(*(c3)));
        Constante& c6 = dynamic_cast<Constante&>(c2->operator +(*(c4)));
        qDebug()<<"test";
        Complexe* c7 = new Complexe(&c5,&c6);
        delete c;
        delete c1;
        delete c2;
        delete c3;
        delete c4;

qDebug()<<"va t-elle jusqu'au bout";
    return *c7;
    }


}
Element& Complexe::operator-(Element& e)
{
    if(typeid(e)==typeid(Expression))
    {
        qDebug()<<"expression";
    return *(new Expression(this->toQString() + " " + e.toQString() + ' - '));
    }
    else
    {    qDebug()<<"pas expression";
        Complexe* c = e.toComplexe();
        Constante* c1 = this->getRe()->clone();
        Constante* c2 = this->getIm()->clone();
        Constante* c3 = c->getRe()->clone();
        Constante* c4 = c->getIm()->clone();
        Constante& c5 = dynamic_cast<Constante&>(c1->operator-(*(c3)));
        Constante& c6 = dynamic_cast<Constante&>(c2->operator -(*(c4)));
        qDebug()<<"test";
        Complexe* c7 = new Complexe(&c5,&c6);
        delete c;
        delete c1;
        delete c2;
        delete c3;
        delete c4;

qDebug()<<"va t-elle jusqu'au bout";
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
        Complexe* c = e.toComplexe();
        Complexe* c_bar = c->conjugue();
        Constante* c1 = this->getRe()->clone();
        Constante* c2 = this->getIm()->clone();
        Constante* c_barr = c_bar->getRe()->clone();
        Constante* c_bari = c_bar->getIm()->clone();
        Constante* module = c->module();
        /*(Z1/Z2) = Z1*Z2bar / |Z2| */
        qDebug()<<"c_bar to qstring"<<module->toQString();
        Constante& resr = dynamic_cast<Constante&>(((c1->operator *(*c_barr)).operator -(c2->operator *(*c_bari))).operator /(module->operator *(*module)));
        Constante& resi = dynamic_cast<Constante&>(((c1->operator *(*c_bari)).operator +(c2->operator *(*c_barr))).operator /(module->operator *(*module)));
        qDebug()<<((c1->operator *(*c_barr)).operator +(c2->operator *(*c_bari))).toQString();
        Complexe* res = new Complexe(&resr,&resi);
        delete c;
        delete c_bar;
        delete c1;
        delete c2;
        delete c_barr;
        delete c_bari;
        delete module;
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
        Complexe c = e.toComplexe();
        Constante* c1 = this->getRe()->clone();
        Constante* c2 = this->getIm()->clone();
        Constante* cr = c.getRe()->clone();
        Constante* ci = c.getIm()->clone();
        /* (aa' - bb') + (ab' + a'b)*/
        Constante& resr = dynamic_cast<Constante&>((c1->operator *(*cr)).operator -(c2->operator *(*ci)));
        Constante& resi = dynamic_cast<Constante&>((c1->operator *(*ci)).operator +(c2->operator *(*cr)));
        Complexe* res = new Complexe(&resr,&resi);
        qDebug()<<resr.toQString();
        delete &c;
        delete c1;
        delete c2;
        delete cr;
        delete ci;

    return *res;

    }


}

Complexe* Complexe::clone() const
{   qDebug()<<"clone complexe";
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
    //Reel* tmp = new Reel (sqrt(pow(this->getIm()->getXAsFloat()/this->getIm()->getYAsFloat(),2)+pow(this->getRe()->getXAsFloat()/this->getRe()->getYAsFloat(),2)));
    float tmpf = (::pow((this->getIm()->getXAsFloat()/this->getIm()->getYAsFloat()),2)) + (float)::pow((this->getRe()->getXAsFloat()/this->getRe()->getYAsFloat()),2);
    Reel* tmp = new Reel (::sqrt(tmpf));
    qDebug()<<tmpf;
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
{   qDebug()<<"clone expression";
    return new Expression(this->getX());
}


