////////////////////////////////////////////////////////////
// Personnage.h
// Declaration de la class CPersonnage
//
// Jeu de Zelda
// Activit� Synth�se 420-KAB-LG
// Fait par Melissa Boucher
// 25 Mai 2014
////////////////////////////////////////////////////////////
#pragma once
#include "Animation.h"
#include "Objet.h"
#include "Carte.h"
#include <string>
using namespace std;
using namespace sf;

class CPersonnage :
   public CAnimation
{
public:
   //--- Constructeur param�trique
   CPersonnage(Texture& Texture, CPosition Position, string Nom, int Vie, int Attaque, int Defense) : CAnimation(Texture, Position)
   {
      SetNom(Nom);
      SetAttaque(Attaque);
      SetDefense(Defense);
      SetVie(Vie);
      SetVivant(true);
   }

   //--- Delete du constructeur de copie pour ne pas qu'il soit utilis�
   CPersonnage(const CPersonnage& perso) = delete;

   //-------------------------------------------------\\
      //------------------> Deplacer <-------------------\\
      //-------------------------------------------------\\
      //--- Permet de creer un X et un Y al�atoire �tant 
   //--- valide dans la map. 
   //---
   //--- Intrant : CCarte& Objet
   //--- Extrant : True si la position est valide ou
   //---			false si la position est pas valide
   //-------------------------------------------------\\

   virtual bool Deplacer(CCarte& Objet) = 0;

   //-------------------------------------------------\\
      //-------------------> Prendre <-------------------\\
      //-------------------------------------------------\\
      //--- V�rifie dans un premier temps si l�objet pass� 
   //--- en param�tre est proche du personnage
   //---
   //--- Si c�est le cas, l�objet est ramass�. Lorsqu�un objet est ramass�,
   //--- les caract�ristiques de l�objet(GainVie, GainAttaque et GainDefense)
   //--- sont ajout�es aux caract�ristiques correspondantes(V.A.D.) du personnage
   //--- et un message contenant les nouvelles caract�ristiques du personnage ainsi
   //--- que les attributs de l�objet ramass� est affich� � la console.
   //---
   //--- Intrant : CObjet& Objet
   //--- Extrant : True si l'objet n'a pas �t� ramass�
   //---			false si l'objet a �t� ramass�
   //-------------------------------------------------\\

   bool Prendre(CObjet& Objet);

   //-------------------------------------------------\\
      //-------------------> Attaquer <------------------\\
      //-------------------------------------------------\\
      //--- V�rifie dans un premier temps si l�ennemi pass� 
   //--- en param�tre est proche du personnage
   //---
   //--- Si c�est le cas, alorsil y a tentative d�attaque
   //--- les caract�ristiques de l�objet(GainVie, GainAttaque et GainDefense)
   //--- sont ajout�es aux caract�ristiques correspondantes(V.A.D.) du personnage
   //--- et un message contenant les nouvelles caract�ristiques du personnage ainsi
   //--- que les attributs de l�objet ramass� est affich� � la console.
   //---
   //--- Intrant : CPersonnage& Personnage
   //--- Extrant : Si l�ennemi est mort la m�thode retourne false
   //---			sinon elle retourne true dans tous les autres cas
   //-------------------------------------------------\\

   bool Attaquer(CPersonnage& Personnage);

   //--- Accesseurs
   string GetNom() const;
   int GetAttaque() const;
   int GetVie() const;
   int GetDefense() const;
   bool GetVivant() const;

   //--- Mutateurs
   void SetNom(string Valeur);
   void SetAttaque(int Valeur);
   void SetVie(int Valeur);
   void SetDefense(int Valeur);
   void SetVivant(bool Valeur);

private:
   //--- Nom du personnage 
   string Nom_;
   //--- Nombre de point de vie, la vitalit� du personnage
   int V_;
   //--- Nombre de point d'attaque, le nombre de dommage inflig� lors d'une attaque r�ussie 
   int A_;
   //--- Nombre de points de d�fense, repr�sente l'agilit� du personnage � �viter une attaque
   int D_;
   //--- si le personnage est mort, Vivant_ = false  si il est vivant, Vivant_ = true
   bool Vivant_;
};

