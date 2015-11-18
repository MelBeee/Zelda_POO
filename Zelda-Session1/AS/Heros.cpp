////////////////////////////////////////////////////////////
// Heros.cpp
// Définition des méthodes de la class CHeros
//
// Jeu de Zelda
// Activité Synthèse 420-KAB-LG
// Fait par Melissa Boucher
// 25 Mai 2014
////////////////////////////////////////////////////////////

#include "Heros.h"

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
//--- Extrant : La méthode retourne true si le joueur a pesé sur Escap, false dans le cas contraire
//-------------------------------------------------\\

bool CHeros::Deplacer(CCarte& Objet)
{
   CPosition LeHero = getPosition();
   bool Quitter = false;

   if (Keyboard::isKeyPressed(Keyboard::Left))
   {
      LeHero.x -= 3;
      SetDirection(Gauche);
   }
   if (Keyboard::isKeyPressed(Keyboard::Right))
   {
      LeHero.x += 3;
      SetDirection(Droite);
   }
   if (Keyboard::isKeyPressed(Keyboard::Down))
   {
      LeHero.y += 3;
      SetDirection(Bas);
   }
   if (Keyboard::isKeyPressed(Keyboard::Up))
   {
      LeHero.y -= 3;
      SetDirection(Haut);
   }

   if (Objet.EstPositionValide(LeHero) == true)
   {
      setPosition(LeHero.x, LeHero.y);
   }

   if (Keyboard::isKeyPressed(Keyboard::Escape))
   {
      Quitter = true;
   }

   return Quitter;
}