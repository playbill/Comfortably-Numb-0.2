/**
 * \file element.h
 * \brief Contient la declaration de la classe Element et de ses classes filles
 * \author Charrier Lucas et Rossier Titouan
 * \version 0.1
 * \date 31 Mai 2012
 *
 */



#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>
#include <iostream>
#include <math.h>
#include <typeinfo>
# include <stdexcept>


class Reel;
class Entier;
class Rationnel;
class Constante;
class Complexe;
class Expression;

class Element
{

    /**
     *\class Element
     *\brief Element est une classe abstraite :
     * elle est la classe mere des classes Constante (Reel, Rationnel, Entier), Complexe et Expression.
     */
    public:
        Element();
        virtual ~Element();


        /**
        * \fn  virtual QString toQString() const = 0
        * \brief transforme l'Element en Qstring pour l'afficher sur la calculatrice
        * -- Fonction virtual pure qui doit être implementee par toutes les classes filles
        */
        virtual QString toQString() const = 0;

        /**
        * \fn  virtual Reel* toReel()
        * \brief transforme l'element en reel pour pouvoir l'utiliser
        * -- Fonction virtual qui peut être implementee par toutes les classes filles de la classe Element
        */
        virtual Reel* toReel(){}

        /**
        * \fn  virtual Rationnel* toRationnel ()
        * \brief transforme l'element en rationnel pour pouvoir l'utiliser
        * -- Fonction virtual qui peut être implementee par toutes les classes filles de la classe Element
        */
        virtual Rationnel* toRationnel(){}

        /**
        * \fn  virtual Entier* toEntier ()
        * \brief transforme l'element en entier pour pouvoir l'utiliser
        * -- Fonction virtual qui peut etre implementee par toutes les classes filles de la classe Element
        */
        virtual Entier* toEntier(){}

        /**
        * \fn  virtual Complexe* toComplexe ()
        * \brief transforme l'element en complexe pour pouvoir l'utiliser -
        * fonction virtual qui peut etre implementee par toutes les classes filles de la classe Element
        */
        virtual Complexe* toComplexe(){}


        /**
        * \fn  virtual Element* clone() const = 0
        * \brief permet de cloner un element -
        * fonction virtual pure qui est implementee par toutes les classes filles de la classe Element
        */
        virtual Element* clone() const = 0;

        /**
        * \fn  virtual Element* sign ()
        * \brief change le signe de l'element -
        * fonction virtual qui est implementee par toutes les classes filles de la classe Element sauf la classe expression
        */
        virtual Element* sign(){return 0;}

        /**
        * \fn  virtual Element& operator+(Element& c)
        * \brief surcharge de l'operateur + qui permet l'addition de deux elements -
        * fonction virtual qui est implementee dans les classes filles de la classe Element (sauf la classe expression)
        */
        virtual Element& operator+(Element& c){}

        /**
        * \fn virtual Element& operator-(Element& c)
        * \brief surcharge de l'operateur - qui permet la soustraction de deux elements -
        * fonction virtual qui est implementee dans les classes filles de la classe Element (sauf la classe expression)
        */
        virtual Element& operator-(Element& c){}

        /**
        * \fn  virtual Element& operator/(Element& c)
        * \brief surcharge de l'operateur / qui permet la division de deux elements -
        * fonction virtual qui est implementee dans les classes filles de la classe Element (sauf la classe expression)
        */
        virtual Element& operator/(Element& c){}

        /**
        * \fn  virtual Element& operator*(Element& c)
        * \brief surcharge de l'operateur * qui permet la multiplication de deux elements -
        * fonction virtual qui est implementee dans les classes filles de la classe Element (sauf la classe expression)
        */
        virtual Element& operator*(Element& c){}


        /**
        * \fn  virtual int getXAsInt() const
        * \brief permet de retourner X sous la forme d'un entier -
        * fonction virtual qui est implementee dans certaines classes filles de la classe Element (sauf la classe expression)
        */
        virtual int getXAsInt() const {}

        /**
        * \fn   virtual int getYAsInt() const
        * \brief permet de retourner Y sous la forme d'un entier
        * (return 1) si elle est appelee par une classe ou la fonction n'est pas redefinie (ex : appel avec un entier, valeur de Y nulle, donc getYAsInt non definie, return 1)
        * Fonction virtual qui est implementee dans certaines classes filles de la classe Element (sauf la classe expression)
        */
        virtual int getYAsInt() const { return 1.;}


};

class Constante : public Element
{


    /**
    * \class  Constante
    * \brief Regroupe tous les Element constants -
    *  classe abstraite, herite de la classe Element, classe mere des classes (Reel, Entier, Rationnel)
    */
    public:

    /**
    * \fn   Constante()
    * \brief Constructeur de la classe Constante -
    * ne fait rien car la classe Constante est abstraite
    */
        Constante();

        /**
        * \fn   virtual ~Constante();
        * \brief Destructeur de la classe Constante -
        * ne fait rien car la classe est Constante est abstraite
        */
        virtual ~Constante();

        /**
        * \fn  virtual QString toQString() const = 0
        * \brief transforme la constante en QString pour pouvoir l'afficher sur la calculatrice -
        * fonction virtual pure, implementee dans chaque classe fille de la classe Constante
        */
        virtual QString toQString() const = 0;

        /**
        * \fn  virtual Reel* toReel() = 0
        * \brief transforme la constante en reel pour pouvoir l'utiliser -
        * fonction virtual pure qui est implementee par toutes les classes filles de la classe Constante (Reel, Rationnel, Entier)
        */
        virtual Reel* toReel() = 0;

        /**
        * \fn  virtual Rationnel* toRationnel() = 0
        * \brief transforme la constante en rationnel pour pouvoir l'utiliser -
        * fonction virtual pure qui est implementee par toutes les classes filles de la classe Constante (Reel, Rationnel, Entier)
        */
        virtual Rationnel* toRationnel() = 0;

        /**
        * \fn  virtual Entier* toEntier() = 0
        * \brief transforme la constante en entier pour pouvoir l'utiliser -
        * fonction virtual pure qui est implementee par toutes les classes filles de la classe Constante (Reel, Rationnel, Entier)
        */
        virtual Entier* toEntier() = 0;

        /**
        * \fn  virtual Complexe* toComplexe() = 0
        * \brief transforme la constante en complexe pour pouvoir l'utiliser -
        * fonction virtual pure qui est implementee par toutes les classes filles de la classe Constante (Reel, Rationnel, Entier)
        */
        virtual Complexe* toComplexe() = 0;

        /**
        * \fn virtual void afficher(std::ostream& f=std::cout) const = 0
        * \brief permet d'afficher la constante a l'ecran
        * \deprecated La fonction n'est plus utilisee dans cette version du projet
        */
        virtual void afficher(std::ostream& f=std::cout) const = 0;

        /**
        * \fn  virtual Element& operator+(Element& c) = 0
        * \brief surcharge de l'operateur + qui permet l'addition entre une constante et un element -
        * fonction virtual pure qui est implementee dans les classes filles de la classe Constante (Reel, Rationnel, Entier)
        */
        virtual Element& operator+(Element& c) = 0;

        /**
        * \fn  virtual Element& operator-(Element& c) = 0
        * \brief surcharge de l'operateur - qui permet la soustraction entre une constante et un element -
        * fonction virtual pure qui est implementee dans les classes filles de la classe Constante (Reel, Rationnal, Entier)
        */
        virtual Element& operator-(Element& c) = 0;

        /**
        * \fn  virtual Element& operator/(Element& c) = 0
        * \brief surcharge de l'operateur / qui permet la division entre une constante et un element -
        * fonction virtual pure qui est implementee dans les classes filles de la classe Constante (Reel, Rationnal, Entier)
        */
        virtual Element& operator/(Element& c) = 0;

        /**
        * \fn  virtual Element& operator*(Element& c) = 0
        * \brief surcharge de l'operateur + qui permet la multiplication entre une constante et un element -
        * fonction virtual pure qui est implementee dans les classes filles de la classe Constante (Reel, Rationnal, Entier)
        */
        virtual Element& operator*(Element& c) = 0;

        /**
        * \fn  virtual Constante* clone() const = 0
        * \brief permet de cloner une constante -
        * fonction virtual pure qui est implementee dans les classes filles de la classe Constante (Reel, Rationnal, Entier)
        */
        virtual Constante* clone() const = 0;

        /**
        * \fn virtual Constante* sign() = 0
        * \brief permet de changer le signe d'une constante -
        * fonction virtual pure qui est implementee dans les classes filles de la classe Constante (Reel, Rationnal, Entier)
        */
        virtual Constante* sign() = 0;

        /**
        * \fn virtual float getXAsFloat() const
        * \brief permet de recuperer l'argument X d'une constante comme un float -
        * fonction virtual qui est implementee dans certaines classes filles de la classe Constante
        */
        virtual float getXAsFloat() const {}

        /**
        * \fn virtual float getYAsFloat() const
        * \brief permet de recuperer l'argument Y d'une constante comme un float -
        * fonction virtual qui est implementee dans certaines classes filles de la classe Constante
        */
        virtual float getYAsFloat() const { return 1.;}

        /**
        * \fn virtual float getXAsInt() const
        * \brief permet de recuperer l'argument X d'une constante comme un entier -
        * fonction virtual qui est implementee dans certaines classes filles de la classe Constante
        */
        virtual int getXAsInt() const {}

        /**
        * \fn virtual float getXAsInt() const
        * \brief permet de recuperer l'argument X d'une constante comme un entier -
        * fonction virtual qui est implementee dans certaines classes filles de la classe Constante
        */
        virtual int getYAsInt() const { return 1.;}
    };


class Reel : public Constante
{

    /**
    * \class Reel
    * \brief Classe modelisant les reels -
    * herite de la classe Constante
    */

    private:
        float x; /*!< float representant le reel*/


    public:

        /**
        * \fn Reel(float r)
        * \brief Constructeur de la classe Reel -
        * construit un objet Reel a partir d'un float r passe en argument
        */
        Reel(float r);

        /**
        * \fn Reel(const Reel& c)
        * \brief Constructeur par recopie de la classe Reel -
        * construit un objet Reel a partir d'une reference d'objet Reel passee en argument
        */
        Reel(const Reel& c);

        /**
        * \fn ~Reel()
        * \brief Destructeur de la classe Reel -
        * ne fait rien de special
        */
        ~Reel();

        /**
        * \fn float getX() const
        * \brief Accesseur en lecture d'un objet Reel
        * \return x : valeur du reel
        */
        float getX()const;

        /**
        * \fn float getXAsFloat() const
        * \brief Equivalent a la fonction float getX() const
        * \return x : valeur du reel
        */
        float getXAsFloat() const;

        /**
        * \fn float getXAsInt() const
        * \brief Renvoie la valeur entiere d'un reel - Cast d'un reel en entier
        * \return (int)x : valeur entiere du reel
        */
        int getXAsInt() const;

        /**
        * \fn void setX(float value)
        * \brief Accesseur en ecriture d'un objet Reel
        */
        void setX(float value);

        /**
        * \fn QString toQString() const
        * \brief Transforme un float en chaine de caractere QString pour pouvoir l'afficher sur la calculatrice
        */
        QString toQString() const;

        /**
        * \fn Reel* toReel()
        * \brief Creer un nouvel objet Reel et le renvoie
        */
        Reel* toReel();

        /**
        * \fn Rationnel* toRationnel()
        * \brief Creer un nouvel objet Rationnel a partir de l'objet Reel et le renvoie -
        * appel au constructeur de Rationnel
        * \return pointeur vers un rationnel : (int) x / 1
        *
        */
        Rationnel* toRationnel();

        /**
        * \fn Entier* toEntier()
        * \brief Creer un nouvel objet Entier a partir de l'objet Reel et le renvoie -
        * appel au constructeur de Entier
        * \return pointeur vers un entier : (int)x
        *
        */
        Entier* toEntier();

        /**
        * \fn  Complexe* toComplexe()
        * \brief Creer un nouvel objet Complexe a partir de l'objet Reel et le renvoie -
        * appel au constructeur de Complexe
        * \return pointeur vers complexe : x en partie reelle du complexe
        *
        */
        Complexe* toComplexe();


        void afficher(std::ostream& f=std::cout) const;

        /**
        * \fn   Element& operator+(Element& c)
        * \brief Surcharge de l'operateur + : permet l'addition d'un reel et d'un element -
        * depend du type de l'element c que l'on souhaite additionner au reel
        */
        Element& operator+(Element& c);

        /**
        * \fn   Element& operator-(Element& c)
        * \brief Surcharge de l'operateur - : permet la soustraction d'un reel et d'un element -
        * depend du type de l'element c que l'on souhaite soustraire au reel
        */
        Element& operator-(Element& c);

        /**
        * \fn   Element& operator/(Element& c)
        * \brief Surcharge de l'operateur / : permet la division d'un reel par un element -
        * depend du type de l'element c par lequel on souhaite diviser le reel
        */
        Element& operator/(Element& c);

        /**
        * \fn   Element& operator*(Element& c)
        * \brief Surcharge de l'operateur * : permet la multiplication d'un reel par un element -
        * depend du type de l'element c que par lequel on souhaite multiplier le reel
        */
        Element& operator*(Element& c);

        /**
        * \fn  Reel* clone() const
        * \brief Renvoie une clone du reel
        */
        Reel* clone() const;

        /**
        * \fn  Reel* sign()
        * \brief Change le signe du reel
        * \return -x, oppose du reel
        */
        Reel* sign();

};


class Rationnel : public Constante
{


    /**
       * \class Rationnel
       * \brief Classe modelisant les rationnels -
       * herite de la classe Constante
       */
    private:
        int x; //! x -> numerateur de la fraction
        int y; //! y -> denominateur de la fraction
    public:

        /**
                * \fn Rationnel(int x, int y = 1)
                * \brief Constructeur de la classe Reel -
                * construit un objet Rationnel a partir d'un ou deux entiers (Si un seul entier passe en parametre, le denominateur est fixe a 1)
                */
        Rationnel(int x, int y = 1);

        /**
        * \fn ~Rationnel()
        * \brief Destructeur de la classe Rationnel -
        * ne fait rien de particulier
        */
        ~Rationnel(){}

        /**
        * \fn int getX() const
        * \brief Accesseur en lecture du numerateur d'un objet Rationnel
        * \return x : valeur du numerateur
        */
        int getX()const;

        /**
        * \fn int getY() const
        * \brief Accesseur en lecture du denominateur d'un objet Rationnel
        * \return y : valeur du denominateur
        */
        int getY()const;

        /**
        * \fn float getXAsFloat() const
        * \brief Transforme le numerateur du Rationnel en un float
        * \return (float)x : valeur du numerateur sous la forme d'un reel
        */
        float getXAsFloat()const;

        /**
        * \fn float getYAsFloat() const
        * \brief Transforme le denominateur du Rationnel en un float
        * \return (float)y : valeur du denominateur sous la forme d'un reel
        */
        float getYAsFloat()const;

        /**
        * \fn int getXAsInt() const
        * \brief Equivalent a la fonction int getX() const
        * \return x : valeur du numerateur
        */
        int getXAsInt()const;

        /**
        * \fn int getYAsInt() const
        * \brief Equivalent a la fonction int getY() const
        * \return y : valeur du denominateur
        */
        int getYAsInt()const;

        /**
        * \fn void setX(int)
        * \brief Accesseur en ecriture du numerateur -
        * permet de modifier le numerateur
        *
        */
        void setX(int);

        /**
        * \fn void setY(int)
        * \brief Accesseur en ecriture du denominateur -
        * permet de modifier le denominateur
        *
        */
        void setY(int);

        /**
        * \fn QString toQString() const
        * \brief Transforme un rationnel en chaine de caractere QString pour pouvoir l'afficher sur la calculatrice
        * sous la forme num / den
        */
        QString toQString () const;

        /**
        * \fn Reel* toReel()
        * \brief Creer un nouvel objet Reel a partir du rationnel et le renvoi
        * \return pointeur sur un reel r = (float) num/den
        */
        Reel* toReel();

        /**
        * \fn Rationnel* toRationnel()
        * \brief Creer un nouvel objet Rationnel a partir du rationnel et le renvoi
        *
        */
        Rationnel* toRationnel();

        /**
        * \fn Entier* toEntier()
        * \brief Creer un nouvel objet Entier a partir du rationnel et le renvoi
        * \return pointeur sur un entier e = (int) num/den
        */
        Entier* toEntier();

        /**
        * \fn  Complexe* toComplexe()
        * \brief Creer un nouvel objet Complexe a partir de l'objet Rationnel et le renvoie -
        * appel au constructeur de Complexe
        * \return pointeur vers complexe : (x / y) en partie reelle du complexe
        *
        */
        Complexe* toComplexe();

        void afficher(std::ostream& f=std::cout) const;

        /**
        * \fn   Element& operator+(Element& c)
        * \brief Surcharge de l'operateur + : permet l'addition d'un rationnel et d'un element -
        * depend du type de l'element c que l'on souhaite additionner au rationnel
        */
        Element& operator+(Element& c);

        /**
        * \fn   Element& operator-(Element& c)
        * \brief Surcharge de l'operateur - : permet la soustraction d'un rationnel et d'un element -
        * depend du type de l'element c que l'on souhaite soustraire au rationnel
        */
        Element& operator-(Element& c);

        /**
        * \fn   Element& operator/(Element& c)
        * \brief Surcharge de l'operateur / : permet la division d'un rationnel par un element -
        * depend du type de l'element c par lequel on souhaite diviser le rationnel
        */
        Element& operator/(Element& c);

        /**
        * \fn   Element& operator*(Element& c)
        * \brief Surcharge de l'operateur * : permet la multiplication d'un rationnel par un element -
        * depend du type de l'element c que par lequel on souhaite multiplier le rationnel
        */
        Element& operator*(Element& c);

        /**
        * \fn  Rationnel* clone() const
        * \brief Renvoie une clone du rationnel
        */
        Rationnel* clone() const;

        /**
        * \fn  Rationnel* sign()
        * \brief Change le signe du Rationnel
        * \return -(x/y), oppose du rationnel
        */
        Rationnel* sign();
};



class Entier : public Constante
{

    /**
    * \class  Entier
    * \brief Classe modelisant les entiers -
    *  herite de la classe Constante
    */

    private :
        int x;
    public:

        /**
                * \fn Entier(int r)
                * \brief Constructeur de la classe Entier -
                * construit un objet entier a partir d'un entier r passe en parametre
                */
        Entier(int r);

        /**
                * \fn ~Entier()
                * \brief Destructeur de la classe Entier -
                * ne fait rien de special
                */
        ~Entier(){}

        /**
        * \fn int getX() const
        * \brief Accesseur en lecture d'un entier
        * \return int x : valeur de l'entier
        */
        int getX() const;

        /**
        * \fn float getXAsFloat() const
        * \brief Transforme un entier en float
        * \return (float) x : valeur de l'entier sous la forme d'un float
        */
        float getXAsFloat() const;

        /**
        * \fn int getXAsInt() const
        * \brief Identique a la fonction int getX() const
        * \return (int) x : valeur de l'entier
        */
        int getXAsInt()const;

        /**
        * \fn void setX() const
        * \brief Accesseur en ecriture d'un entier -
        * permet de modifier la valeur d'un entier
        *
        */
        void setX();

        /**
        * \fn QString toQString() const
        * \brief Transforme un entier en chaine de caractere QString pour pouvoir l'afficher sur la calculatrice
        *
        */
        QString toQString() const;

        /**
        * \fn Reel* toReel()
        * \brief Creer un nouvel objet Reel a partir de l'entier et le renvoi -
        * appel au constructeur de Reel
        * \return pointeur sur un reel r = (float) x
        */
        Reel* toReel();

        /**
        * \fn Rationnel* toRationnel()
        * \brief Creer un nouvel objet Rationnel a partir de l'entier et le renvoi -
        * appel au constructeur de Rationnel
        * \return pointeur sur un rationnel r =  x / 1
        *
        */
        Rationnel* toRationnel();

        /**
        * \fn Entier* toEntier()
        * \brief Creer un nouvel objet Entier a partir de l'entier et le renvoi -
        * appel au constructeur de Entier
        * \return pointeur sur un entier e = x
        */
        Entier* toEntier();

        /**
        * \fn Complexe* toComplexe()
        * \brief Creer un nouvel objet Complexe a partir de l'entier et le renvoi -
        * appel au constructeur de Complexe
        * \return pointeur sur un complexe avec x en partie reelle
        */
        Complexe* toComplexe();


        void afficher(std::ostream& f=std::cout) const;

        /**
        * \fn   Element& operator+(Element& c)
        * \brief Surcharge de l'operateur + : permet l'addition d'un entier et d'un element -
        * depend du type de l'element c que l'on souhaite additionner a l'entier
        */
        Element& operator+(Element& c);

        /**
        * \fn   Element& operator-(Element& c)
        * \brief Surcharge de l'operateur - : permet la soustraction d'un entier et d'un element -
        * depend du type de l'element c que l'on souhaite soustraire a l'entier
        */
        Element& operator-(Element& c);

        /**
        * \fn   Element& operator/(Element& c)
        * \brief Surcharge de l'operateur / : permet la division d'un entier par un element -
        * depend du type de l'element c par lequel on souhaite diviser l'entier
        */
        Element& operator/(Element& c);

        /**
        * \fn   Element& operator*(Element& c)
        * \brief Surcharge de l'operateur * : permet la multiplication d'un entier par un element -
        * depend du type de l'element c que par lequel on souhaite multiplier l'entier
        */
        Element& operator*(Element& c);

        /**
        * \fn  Entier* clone() const
        * \brief Renvoie une clone de l'entier
        */
        Entier* clone() const;

        /**
        * \fn  Entier* sign()
        * \brief Change le signe du Rationnel
        * \return - x, oppose du rationnel
        */
        Entier* sign();

};

class Complexe : public Element
{
    /**
    * \class  Complexe
    * \brief Classe modelisant les complexes -
    *  herite de la classe Element
    */
    private:
       Constante* re; //! re -> partie reelle du complexe
       Constante* im; //! im -> partie imaginaire du complexe
    public:

       /**
       * \fn  Complexe(Constante* x, Constante* y = new Entier(0))
       * \brief Constructeur de la classe complexe -
       *  prend une ou deux constante(s) en arguments.
       */
        Complexe(Constante* x, Constante* y = new Entier(0));

        /**
        * \fn  Complexe(Complexe* c)
        * \brief Constructeur par recopie de la classe complexe -
        *
        */
        Complexe(Complexe* c);

        /**
        * \fn  ~Complexe()
        * \brief Destructeur de la classe complexe -
        * Desalloue la memoire pour la partie reelle et imaginaire du complexe
        */
        ~Complexe();

        /**
        * \fn  Constante* getRe() const
        * \brief Accesseur en lecture pour la partie reelle
        * \return pointeur vers la constante correspondant a la partie reelle du complexe
        *
        */
        Constante* getRe() const;

        /**
        * \fn  Constante* getRe() const
        * \brief Accesseur en lecture pour la partie imaginaire
        * \return pointeur vers la constante correspondant a la partie imaginaire du complexe
        *
        */
        Constante* getIm() const;

        /**
        * \fn QString toQString() const
        * \brief Transforme un complexe en chaine de caractere QString pour pouvoir l'afficher sur la calculatrice -
        * sous la forme partReelle$partImaginaire
        *
        */
        QString toQString() const;

        /**
        * \fn Reel* toReel()
        * \brief Creer un nouvel objet Reel a partir du complexe et le renvoi -
        * appel au constructeur de Reel
        * \return pointeur sur un reel r = (float) Re(.x) (/ (float) Re(.y) si partie reelle est un Rationnel)
        */
        Reel* toReel();

        /**
        * \fn Complexe* conjugue()
        * \brief Creer un nouvel objet Complexe correspondant au conjugue du complexe -
        * appel au constructeur de Complexe
        * \return pointeur sur un complexe c => Re = Re, Im = -Im
        */
        Complexe* conjugue();

        /**
        * \fn Rationnel* toRationnel()
        * \brief Creer un nouvel objet Rationnel a partir du complexe et le renvoi -
        * appel au constructeur de Rationnel
        * \return pointeur sur un Rationnel r =(int) Re.X /(int) Re.Y
        */
        Rationnel* toRationnel();

        /**
        * \fn Entier* toEntier()
        * \brief Creer un nouvel objet Entier a partir du complexe et le renvoi -
        * appel au constructeur d'Entier
        * \return pointeur sur un entier e = (int) Re(.x) (/ Re(.y) si partie reelle est un Rationnel)
        */
        Entier* toEntier();

        /**
        * \fn Complexe* toComplexe()
        * \brief Creer un nouvel objet Complexe a partir du complexe et le renvoi -
        * appel au constructeur de recopie de Complexe
        * \return pointeur sur un Complexe c = clone du complexe appelant
        */
        Complexe* toComplexe();

        void afficher(std::ostream& f=std::cout) const;

        /**
        * \fn   Element& operator+(Element& c)
        * \brief Surcharge de l'operateur + : permet l'addition d'un complexe et d'un element -
        * depend du type de l'element c que l'on souhaite additionner au complexe
        */
        Element& operator+(Element& c);

        /**
        * \fn   Element& operator-(Element& c)
        * \brief Surcharge de l'operateur - : permet la soustraction d'un complexe et d'un element -
        * depend du type de l'element c que l'on souhaite soustraire au complexe
        */
        Element& operator-(Element& c);

        /**
        * \fn   Element& operator/(Element& c)
        * \brief Surcharge de l'operateur / : permet la division d'un complexe par un element -
        * depend du type de l'element c par lequel on souhaite diviser le complexe
        */
        Element& operator/(Element& c);

        /**
        * \fn   Element& operator*(Element& c)
        * \brief Surcharge de l'operateur * : permet la multiplication d'un complexe par un element -
        * depend du type de l'element c que par lequel on souhaite multiplier le complexe
        */
        Element& operator*(Element& c);

        /**
        * \fn  Complexe* clone() const
        * \brief Renvoie une clone du complexe
        */
         Complexe* clone() const;

        /**
        * \fn Complexe* sign()
        * \brief Change le signe du complexe
        * \return - x, oppose du rationnel
        */
        Complexe* sign();

        /**
        * \fn Constante* module()
        * \brief Calcul du module d'un complexe
        * \return pointeur vers une constante c : sqrt(Re^2 + Im^2)
        */
        Constante* module();
};

class Expression : public Element
{

    /**
    * \class Expression
    * \brief Classe modelisant les expressions -
    *  herite de la classe Element
    */
    private :
        QString x; //! Expression exprimee sous forme d'un QString

    public :

        /**
        * \fn   Expression(QString)
        * \brief Constructeur de la classe Expression -
        * initialise l'expression avec la QString passee en argument
        */
        Expression(QString);

        /**
        * \fn   Expression(QString)
        * \brief Constructeur de la classe Expression -
        *
        */
        ~Expression(){}

        /**
        * \fn QString toQString() const
        * \brief Renvoie l'expression
        *
        */
        QString toQString() const;

        /**
        * \fn QString getX() const
        * \brief Accesseur en lecture de l'expression
        *
        */
        QString getX() const;

        /**
        * \fn  Expression* clone() const
        * \brief Renvoi un clone de l'expression
        *
        */
        Expression* clone() const;

};



#endif // ELEMENT_H
