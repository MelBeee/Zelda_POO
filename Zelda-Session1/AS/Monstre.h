////////////////////////////////////////////////////////////
// Monstre.h
// Declaration de la class CMonstre
//
// Jeu de Zelda
// Activit� Synth�se 420-KAB-LG
// Fait par Melissa Boucher
// 25 Mai 2014
////////////////////////////////////////////////////////////
#pragma once
#include "Personnage.h"

class CMonstre :
   public CPersonnage
{
public:
   //--- Constructeur param�trique li� au constructeur de la class CPersonnage
   CMonstre(Texture& Texture, CPosition Position, string Nom, int Vie, int Attaque, int Defense) : CPersonnage(Texture, Position, Nom, Vie, Attaque, Defense) {}


   //-------------------------------------------------\\
      //------------------> DEPLACER <-------------------\\
      //-------------------------------------------------\\
      //--- La m�thode Deplacer calcule une nouvelle position en fonction de sa direction actuelle 
   //---
   //--- Vers le bas : la position y est augment�e de 3
   //--- Vers le haut : la position y est diminu�e de 3
   //--- Vers la droite : la position x est augment�e de 3
   //--- Vers la gauche : la position x est diminu�e de 3
   //---
   //--- Si le monstre peut se trouver � cette position de la carte, 
   //--- alors la nouvelle position est affect�e � la position courante.
   //--- Si le monstre ne peut pas se trouver � cette position, 
   //--- alors une nouvelle direction est tir�e au hasard.
   //---
   //--- Intrant : CCarte& Objet
   //--- Extrant : La m�thode retourne True.
   //-------------------------------------------------\\

   virtual bool Deplacer(CCarte& Objet);
};

