////////////////////////////////////////////////////////////
// Heros.cpp
// D�finition des m�thodes de la class CHeros
//
// Jeu de Zelda
// Activit� Synth�se 420-KAB-LG
// Fait par Melissa Boucher
// 25 Mai 2014
////////////////////////////////////////////////////////////

#include "Heros.h"

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
//--- Extrant : La m�thode retourne true si le joueur a pes� sur Escap, false dans le cas contraire
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