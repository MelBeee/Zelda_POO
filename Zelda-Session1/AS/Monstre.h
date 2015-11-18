////////////////////////////////////////////////////////////
// Monstre.h
// Declaration de la class CMonstre
//
// Jeu de Zelda
// Activité Synthèse 420-KAB-LG
// Fait par Melissa Boucher
// 25 Mai 2014
////////////////////////////////////////////////////////////
#pragma once
#include "Personnage.h"

class CMonstre :
   public CPersonnage
{
public:
   //--- Constructeur paramétrique lié au constructeur de la class CPersonnage
   CMonstre(Texture& Texture, CPosition Position, string Nom, int Vie, int Attaque, int Defense) : CPersonnage(Texture, Position, Nom, Vie, Attaque, Defense) {}


   //-------------------------------------------------\\
      //------------------> DEPLACER <-------------------\\
      //-------------------------------------------------\\
      //--- La méthode Deplacer calcule une nouvelle position en fonction de sa direction actuelle 
   //---
   //--- Vers le bas : la position y est augmentée de 3
   //--- Vers le haut : la position y est diminuée de 3
   //--- Vers la droite : la position x est augmentée de 3
   //--- Vers la gauche : la position x est diminuée de 3
   //---
   //--- Si le monstre peut se trouver à cette position de la carte, 
   //--- alors la nouvelle position est affectée à la position courante.
   //--- Si le monstre ne peut pas se trouver à cette position, 
   //--- alors une nouvelle direction est tirée au hasard.
   //---
   //--- Intrant : CCarte& Objet
   //--- Extrant : La méthode retourne True.
   //-------------------------------------------------\\

   virtual bool Deplacer(CCarte& Objet);
};

