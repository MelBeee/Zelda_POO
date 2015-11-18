////////////////////////////////////////////////////////////
// Objet.h
// Declaration de la class CObjet
//
// Jeu de Zelda
// Activité Synthèse 420-KAB-LG
// Fait par Melissa Boucher
// 25 Mai 2014
////////////////////////////////////////////////////////////
#include <string>
#include "Animation.h"
using namespace std;
using namespace sf;
#pragma once

class CObjet :
   public Sprite
{
public:
   //--- Constructeur paramétrique
   CObjet(Texture& Texture, CPosition Position, string Nom, int Vie, int Attaque, int Defense);

   //--- Destructeur
   ~CObjet()
   {
      SetExiste(false);
   }

   //--- Méthodes
   void Afficher(RenderWindow& Fenetre);

   //--- Accesseurs
   string GetNom() const;
   int GetGainV() const;
   int GetGainA() const;
   int GetGainD() const;
   bool GetExiste() const;

   //--- Mutateurs 
   void SetNom(string Valeur);
   void SetGainV(int Valeur);
   void SetGainA(int Valeur);
   void SetGainD(int Valeur);
   void SetExiste(bool Valeur);


private:
   //--- Nom de l'objet
   string Nom_;
   //--- Gain points de vie, représente le nombre de points de vie qui seront ajoutés au personnage qui ramasse cet objet 
   int GainV_;
   //--- Gain points d’attaque, représente le nombre de points d’attaque qui seront ajoutés au personnage qui ramasse cet objet 
   int GainA_;
   //--- Gain points de défense, représente le nombre de points de défense qui seront ajoutés au personnage qui ramasse cet objet
   int GainD_;
   //--- Attribut pour savoir si l'objet existe encore, s'il a été ramassé Existe = false. S'il n'a pas été ramassé Existe = true; 
   bool Existe_;
};

