#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>
#include <iostream>

class Reel;
class Entier;
class Rationnel;
class Constante;
class Complexe;
class Expression;

class Element
{
    public:
        Element();
        virtual ~Element();
        /**
        * Les classes filles de Element doivent pouvoir
        * �tre transformer en toutes autres classe filles
        * en fonction du mode de la calculette
        */

        /**
        * \fn virtual Qstring toQstring()
        * \brief transforme l'�l�ment en Qstring pour l'afficher sur la calculatrice
        * Fonction virtual pure qui doit �tre impl�menter par toutes les classes filles
        */
        virtual QString toQString() const = 0;

        /**
        * \fn  virtual QString toReel() = 0;
        * \brief transforme l'�l�ment en r�el pour pouvoir l'utiliser
        * Fonction virtual pure qui doit �tre impl�menter par toutes les classes filles
        */

        virtual Reel& toReel() = 0;
        virtual Rationnel& toRationnel() = 0;
        virtual Entier& toEntier() = 0;
        virtual Complexe& toComplexe() = 0;
        virtual Element* clone() = 0;
        virtual Element* sign() = 0;


};

class Constante : public Element
{
    public:
        Constante();
        virtual ~Constante();
        virtual QString toQString() const = 0;
        virtual Reel& toReel() = 0;/*!< /todo quelle retour mettre reel? */
        virtual Rationnel& toRationnel() = 0; /*! idem */
        virtual Entier& toEntier() = 0; /*! idem */
        virtual Complexe& toComplexe() = 0; /*! idem */
        virtual void afficher(std::ostream& f=std::cout) const = 0;
        virtual Element& operator+(Element& c) = 0;
        virtual Element& operator-(Element& c) = 0;
        virtual Element& operator/(Element& c) = 0;
        virtual Element& operator*(Element& c) = 0;
        virtual Constante* clone() = 0;
        virtual Constante* sign() = 0;
        float getXAsFloat() const {}
        float getYAsFloat() const {}
        int getXAsInt() const {}
        int getYAsInt() const {}
    };


class Reel : public Constante
{
    private:
        float x;

    public:
        Reel(float r);
        Reel(const Reel& c);
        ~Reel();
        float getX()const {return x;}
        float getXAsFloat() const;
        int getXAsInt() const;
        void setX(float value);
        QString toQString() const;
        Reel& toReel();
        Rationnel& toRationnel();
        Entier& toEntier();
        Complexe& toComplexe();
        void afficher(std::ostream& f=std::cout) const;
        Element& operator+(Element& c);
        Element& operator-(Element& c);
        Element& operator/(Element& c);
        Element& operator*(Element& c);
        Reel* clone();
        Reel* sign();

};


class Rationnel : public Constante
{

    private:
        int x;
        int y;
    public:
        Rationnel(int x, int y = 1);
        ~Rationnel(){}
        int getX()const {return x;}
        int getY()const {return y;}
        float getXAsFloat()const;
        float getYAsFloat()const;
        int getXAsInt()const;
        int getYAsInt()const;
        void setX(int);
        void setY(int);
        QString toQString () const;
        Reel& toReel();
        Rationnel& toRationnel();
        Entier& toEntier();
        Complexe& toComplexe();
        void afficher(std::ostream& f=std::cout) const;
        Element& operator+(Element& c);
        Element& operator-(Element& c);
        Element& operator/(Element& c);
        Element& operator*(Element& c);
        Rationnel* clone();
        Rationnel* sign();
};



class Entier : public Constante
{
    private :
        int x;
    public:
        Entier(int r);
        ~Entier(){}
        int getX() const {return x;}
        float getXAsFloat() const;
        int getXAsInt()const;
        void setX();
        QString toQString() const;
        Reel& toReel();
        Rationnel& toRationnel();
        Entier& toEntier();
        Complexe& toComplexe();
        void afficher(std::ostream& f=std::cout) const;
        Element& operator+(Element& c);
        Element& operator-(Element& c);
        Element& operator/(Element& c);
        Element& operator*(Element& c);
        Entier* clone();
        Entier* sign();
};

class Complexe : public Element
{
    private:
       Constante* re;
       Constante* im;
    public:
        Complexe(Constante* x, Constante* y = 0);
        ~Complexe(){}
        Constante* getRe();
        Constante* getIm();
        QString toQString() const;
        Reel& toReel();
        Complexe* conjugue();
        Rationnel& toRationnel();
        Entier& toEntier();
        Complexe& toComplexe();
        void afficher(std::ostream& f=std::cout) const;
        Element& operator+(Element& c);
        Element& operator-(Element& c);
        Element& operator/(Element& c);
        Element& operator*(Element& c);
        Complexe* clone();
        Complexe* sign();
};

class Expression : public Element
{
    private :
        QString x;

    public :
        Expression(QString);
        ~Expression(){}
        QString toQString() const;
        QString getX();
        virtual Reel& toReel();
        virtual Rationnel& toRationnel();
        virtual Entier& toEntier();
        virtual Complexe& toComplexe();
        Element& operator+(Element& c);
        Element& operator-(Element& c);
        Element& operator/(Element& c);
        Element& operator*(Element& c);
        Expression* clone();
        Expression* sign(){}
};



#endif // ELEMENT_H
