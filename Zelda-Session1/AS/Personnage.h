////////////////////////////////////////////////////////////
// Personnage.h
// Declaration de la class CPersonnage
//
// Jeu de Zelda
// Activité Synthèse 420-KAB-LG
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
   //--- Constructeur paramétrique
   CPersonnage(Texture& Texture, CPosition Position, string Nom, int Vie, int Attaque, int Defense) : CAnimation(Texture, Position)
   {
      SetNom(Nom);
      SetAttaque(Attaque);
      SetDefense(Defense);
      SetVie(Vie);
      SetVivant(true);
   }

   //--- Delete du constructeur de copie pour ne pas qu'il soit utilisé
   CPersonnage(const CPersonnage& perso) = delete;

   //-------------------------------------------------\\
      //------------------> Deplacer <-------------------\\
      //-------------------------------------------------\\
      //--- Permet de creer un X et un Y aléatoire étant 
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
      //--- Vérifie dans un premier temps si l’objet passé 
   //--- en paramètre est proche du personnage
   //---
   //--- Si c’est le cas, l’objet est ramassé. Lorsqu’un objet est ramassé,
   //--- les caractéristiques de l’objet(GainVie, GainAttaque et GainDefense)
   //--- sont ajoutées aux caractéristiques correspondantes(V.A.D.) du personnage
   //--- et un message contenant les nouvelles caractéristiques du personnage ainsi
   //--- que les attributs de l’objet ramassé est affiché à la console.
   //---
   //--- Intrant : CObjet& Objet
   //--- Extrant : True si l'objet n'a pas été ramassé
   //---			false si l'objet a été ramassé
   //-------------------------------------------------\\

   bool Prendre(CObjet& Objet);

   //-------------------------------------------------\\
      //-------------------> Attaquer <------------------\\
      //-------------------------------------------------\\
      //--- Vérifie dans un premier temps si l’ennemi passé 
   //--- en paramètre est proche du personnage
   //---
   //--- Si c’est le cas, alorsil y a tentative d’attaque
   //--- les caractéristiques de l’objet(GainVie, GainAttaque et GainDefense)
   //--- sont ajoutées aux caractéristiques correspondantes(V.A.D.) du personnage
   //--- et un message contenant les nouvelles caractéristiques du personnage ainsi
   //--- que les attributs de l’objet ramassé est affiché à la console.
   //---
   //--- Intrant : CPersonnage& Personnage
   //--- Extrant : Si l’ennemi est mort la méthode retourne false
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
   //--- Nombre de point de vie, la vitalité du personnage
   int V_;
   //--- Nombre de point d'attaque, le nombre de dommage infligé lors d'une attaque réussie 
   int A_;
   //--- Nombre de points de défense, représente l'agilité du personnage à éviter une attaque
   int D_;
   //--- si le personnage est mort, Vivant_ = false  si il est vivant, Vivant_ = true
   bool Vivant_;
};

