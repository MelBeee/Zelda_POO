////////////////////////////////////////////////////////////
// Monstre.cpp
// D�finition des m�thodes de la class CMonstre
//
// Jeu de Zelda
// Activit� Synth�se 420-KAB-LG
// Fait par Melissa Boucher
// 25 Mai 2014
////////////////////////////////////////////////////////////

#include "Monstre.h"

//------------------------------------------------\\
//------------------> M�THODES <------------------\\
//------------------------------------------------\\


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

bool CMonstre::Deplacer(CCarte& Objet)
{
   CPosition UnMonstre = getPosition();
   bool Quitter = false;
   Direction Dir = GetDirection();

   switch (Dir)
   {
   case Haut:
      UnMonstre.y -= 3;
      break;
   case Bas:
      UnMonstre.y += 3;
      break;
   case Droite:
      UnMonstre.x += 3;
      break;
   case Gauche:
      UnMonstre.x -= 3;
      break;
   }

   if (Objet.EstPositionValide(UnMonstre) == true)
   {
      setPosition(UnMonstre.x, UnMonstre.y);
   }
   else
   {
      int Hasard = rand() % 4 + 1;
      switch (Hasard)
      {
      case 1:
         SetDirection(Haut);
         break;
      case 2:
         SetDirection(Bas);
         break;
      case 3:
         SetDirection(Gauche);
         break;
      case 4:
         SetDirection(Droite);
         break;
      }
   }
   if (Keyboard::isKeyPressed(Keyboard::Escape))
   {
      Quitter = true;
   }

   return Quitter;
}
