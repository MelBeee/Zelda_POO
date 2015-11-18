////////////////////////////////////////////////////////////
// Monstre.cpp
// Définition des méthodes de la class CMonstre
//
// Jeu de Zelda
// Activité Synthèse 420-KAB-LG
// Fait par Melissa Boucher
// 25 Mai 2014
////////////////////////////////////////////////////////////

#include "Monstre.h"

//------------------------------------------------\\
//------------------> MÉTHODES <------------------\\
//------------------------------------------------\\


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
