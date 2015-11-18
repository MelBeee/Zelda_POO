////////////////////////////////////////////////////////////
// Heros.h
// Declaration de la class CHeros
//
// Jeu de Zelda
// Activit� Synth�se 420-KAB-LG
// Fait par Melissa Boucher
// 25 Mai 2014
////////////////////////////////////////////////////////////

#pragma once
#include "Personnage.h"

class CHeros :
   public CPersonnage
{
public:
   //--- Constructeur param�trique li� au constructeur de la class CPersonnage
   CHeros(Texture& Texture, CPosition Position, string Nom, int Vie, int Attaque, int Defense) : CPersonnage(Texture, Position, Nom, Vie, Attaque, Defense) {}

   //--- Methode Deplacer 
   virtual bool Deplacer(CCarte& Objet);
};

