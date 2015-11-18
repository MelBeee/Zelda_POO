////////////////////////////////////////////////////////////
// main.cpp
// 
// Programme principal de jeu de Zelda
// Activité Synthèse 420-KAB-LG
// Etienne Forest
// Joan-Sébastien Morales 
// Création: 28 avril 2010
// Version 1.0
// Version 2.0 - Adaptation à SFML - 10 mai 2014
////////////////////////////////////////////////////////////
#include <iostream>
#include <SFML/Audio.hpp>
#include "Carte.h"
#include "Heros.h"
#include "Monstre.h"
using namespace std;
using namespace sf;
#pragma warning (disable : 4244)

//-------------------------------------------------\\
//----------------> PosAleatoire <-----------------\\
//-------------------------------------------------\\
//--- Permet de creer un X et un Y aléatoire étant 
//--- valide dans la map. 
//---
//--- Intrant : X et Y en reference et la carte pour
//--- avoir les zones noirs de la carte.
//--- Extrant : Aucun. Puisqu'est en reference. 
//-------------------------------------------------\\

void PosAleatoire(CCarte& Monde, int& X, int& Y)
{
   do
   {
      X = rand() % 4096;
      Y = rand() % 4096;
   } while (!Monde.EstPositionValide(CPosition(X, Y)));
}

//-------------------------------------------------\\
//--------------------> MAIN <---------------------\\
//-------------------------------------------------\\

int main(int argc, char *argv[])
{
   //--- QUITTER 
   bool bQuitter = true;   //--- Vrai s'il faut continuer la partie
   bool AshVivant;			//--- Utiliser pour la fin 

   srand(static_cast<unsigned int>(time(0)));

   try
   {
      //--- Création des objets
      RenderWindow Fenetre(VideoMode(640, 480), "Zelda");
      Texture MondeText;
      MondeText.loadFromFile("res\\lemonde.bmp");
      Image MondeMasque;
      MondeMasque.loadFromFile("res\\MasqueDuMonde.bmp");

      CCarte Monde(MondeText, MondeMasque);

      //-------------------------------------------------\\
      //--------------------> SOUNDS <-------------------\\
      //-------------------------------------------------\\
      				
      //--- Musique dans le jeu
      Music Jeu;
      if (!Jeu.openFromFile("res\\musique.ogg"))
      {
         cout << " Cant find musique.ogg" << endl;
      }
      Jeu.setVolume(50);
      Jeu.play();
      Jeu.setLoop(true);

      //-------------------------------------------------\\
      //------------------> MONSTRES <-------------------\\
      //-------------------------------------------------\\
      					         
      //--- Load des textures des 5 pokemons différents 
      Texture Arbok;
      Arbok.loadFromFile("res\\Arbok.png");
      Texture Dragonite;
      Dragonite.loadFromFile("res\\Dragolite.png");
      Texture Rapidash;
      Rapidash.loadFromFile("res\\Rapidash.png");
      Texture Sandslash;
      Sandslash.loadFromFile("res\\Sandslash.png");
      Texture Houndour;
      Houndour.loadFromFile("res\\Houndour.png");

      //--- Creation des 50 pokemons
      const int NbreMonstre = 50;
      CMonstre* TabMonstres[NbreMonstre];
      int X, Y;

      for (int i = 0; i < NbreMonstre; i++)
      {
         int SorteDeMonstres = rand() % 5;

         PosAleatoire(Monde, X, Y);

         //--- Les stats sont celles utilisés dans le vrai jeu de pokemon (HP de base + 2 / Attack de base + 2 / Defense de base + 2)
         switch (SorteDeMonstres)
         {
         case 0:
            TabMonstres[i] = new CMonstre(Arbok, CPosition(X, Y), "Arbok", 5, 6, 5);
            break;
         case 1:
            TabMonstres[i] = new CMonstre(Dragonite, CPosition(X, Y), "Dragonite", 6, 10, 6);
            break;
         case 2:
            TabMonstres[i] = new CMonstre(Houndour, CPosition(X, Y), "Houndour", 4, 5, 4);
            break;
         case 3:
            TabMonstres[i] = new CMonstre(Rapidash, CPosition(X, Y), "Rapidash", 6, 10, 8);
            break;
         case 4:
            TabMonstres[i] = new CMonstre(Sandslash, CPosition(X, Y), "Sandslash", 5, 8, 8);
            break;
         }
      }

      //--- Creation du Pokemon finale 
      Texture BossPokemon;
      BossPokemon.loadFromFile("res\\Palkia.png");
      CMonstre Palkia(BossPokemon, CPosition(3929, 1611), "Palkia", 100, 20, 10);

      //-------------------------------------------------\\
      //-----------------> CHARACTER <-------------------\\
      //-------------------------------------------------\\

      //--- Creation de AshK
      Texture AshKetchum;
      AshKetchum.loadFromFile("res\\AshK.png");
      CHeros AshK(AshKetchum, CPosition(848, 1989), "AshKetchum", 2, 2, 0);

      //-------------------------------------------------\\
      //--------------------> ITEMS <--------------------\\
      //-------------------------------------------------\\

      const int NbreItemDeChaque = 15;

      //--- Item qui heal
      Texture Heal;
      Heal.loadFromFile("res\\Heal.png");
      CObjet* TabHeal[NbreItemDeChaque];

      for (int i = 0; i < NbreItemDeChaque; i++)
      {
         PosAleatoire(Monde, X, Y);
         TabHeal[i] = new CObjet(Heal, CPosition(X, Y), "Heal", 5, 0, 0);
      }

      //--- Item qui donne de la defense
      Texture Defense;
      Defense.loadFromFile("res\\Armure.png");
      CObjet* TabDef[NbreItemDeChaque];

      for (int i = 0; i < NbreItemDeChaque; i++)
      {
         PosAleatoire(Monde, X, Y);
         TabDef[i] = new CObjet(Defense, CPosition(X, Y), "Defense", 0, 0, 1);
      }

      //--- Item qui rajoute de l'attaque
      Texture Attaque;
      Attaque.loadFromFile("res\\Arme.png");
      CObjet* TabAtk[NbreItemDeChaque];

      for (int i = 0; i < NbreItemDeChaque; i++)
      {
         PosAleatoire(Monde, X, Y);
         TabAtk[i] = new CObjet(Attaque, CPosition(X, Y), "Attaque", 0, 5, 0);
      }

      //--- Item qui te fait du degat et te fait perdre de l'armure
      Texture Degat;
      Degat.loadFromFile("res\\Poison.png");
      CObjet* TabDegat[NbreItemDeChaque];

      for (int i = 0; i < NbreItemDeChaque; i++)
      {
         PosAleatoire(Monde, X, Y);
         TabDegat[i] = new CObjet(Degat, CPosition(X, Y), "Degat", -2, 0, -2);
      }

      //--- Item OverPower qui permet de battre le Pokemon finale ! 
      Texture Doll;
      Doll.loadFromFile("res\\Doll.png");
      CObjet Clefairy(Doll, CPosition(1065, 157), "Doll", 20, 20, 20);

      //-------------------------------------------------\\
      //--------------> BOUCLE PRINCIPALE <--------------\\
      //-------------------------------------------------\\

      do
      {
         //-------------------------------------------------\\
         //-----------------> DEPLACEMENT <-----------------\\
         //-------------------------------------------------\\

         //--- AshK se déplace
         bQuitter = AshK.Deplacer(Monde);

         //--- Les monstres se déplace
         for (int i = 0; i < NbreMonstre; i++)
         {
            bQuitter = TabMonstres[i]->Deplacer(Monde);
         }

         //--- Monstre de la fin Polkia, ne se deplace pas ! 

         //-------------------------------------------------\\
         //------------------> RAMASSAGE <------------------\\
         //-------------------------------------------------\\
         	

         for (int i = 0; i < NbreItemDeChaque; i++)
         {
            //--- Items d'attaque
            if (TabAtk[i]->GetExiste())
            {
               TabAtk[i]->SetExiste(AshK.Prendre(*TabAtk[i]));
            }
            //--- Mettre a 0 les items d'attaque ramassés
            if (!TabAtk[i] && TabAtk[i] != 0)
            {
               TabAtk[i] = 0;
            }
            //--- Items de defense
            if (TabDef[i]->GetExiste())
            {
               TabDef[i]->SetExiste(AshK.Prendre(*TabDef[i]));
            }
            //--- Mettre a 0 les items de defense ramassés
            if (!TabDef[i] && TabDef[i] != 0)
            {
               TabDef[i] = 0;
            }
            //--- Items de heal
            if (TabHeal[i]->GetExiste())
            {
               TabHeal[i]->SetExiste(AshK.Prendre(*TabHeal[i]));
            }
            //--- Mettre a 0 les items de heal ramassés
            if (!TabHeal[i] && TabHeal[i] != 0)
            {
               TabHeal[i] = 0;
            }
            //--- Items de degat
            if (TabDegat[i]->GetExiste())
            {
               TabDegat[i]->SetExiste(AshK.Prendre(*TabDegat[i]));
            }
            //--- Mettre a 0 les items de degat ramassés
            if (!TabDegat[i] && TabDegat[i] != 0)
            {
               TabDegat[i] = 0;
            }

         }
         //--- Item OverPower 
         if (Clefairy.GetExiste())
         {
            Clefairy.SetExiste(AshK.Prendre(Clefairy));
         }

         //-------------------------------------------------\\
         	//-------------------> ATTAQUE <-------------------\\
         	//-------------------------------------------------\\

         for (int i = 0; i < NbreMonstre; i++)
         {
            //--- AshK Attaque les Pokemons
            if (TabMonstres[i]->GetVivant() && AshK.GetVivant())
            {
               TabMonstres[i]->SetVivant(AshK.Attaquer(*TabMonstres[i]));
            }

            //--- Les Pokemons Attaque AshK
            if (TabMonstres[i]->GetVivant() && AshK.GetVivant())
            {
               AshK.SetVivant(TabMonstres[i]->Attaquer(AshK));
            }
         }

         //--- AshK Attaque Palkia
         if (Palkia.GetVivant() && AshK.GetVivant())
         {
            AshK.SetVivant(Palkia.Attaquer(AshK));
         }

         //--- AshK Attaque Palkia
         if (Palkia.GetVivant() && AshK.GetVivant())
         {
            Palkia.SetVivant(AshK.Attaquer(Palkia));
         }

         //-------------------------------------------------\\
         //------------------> AFFICHAGE <------------------\\
         //-------------------------------------------------\\

         View Vue = Fenetre.getView();
         Vue.setCenter(AshK.getPosition());
         Fenetre.setView(Vue);

         Monde.Afficher(Fenetre);

         //--- Afficher les items
         for (int i = 0; i < NbreItemDeChaque; i++)
         {
            if (TabDef[i]->GetExiste())
            {
               TabDef[i]->Afficher(Fenetre);
            }
            if (TabAtk[i]->GetExiste())
            {
               TabAtk[i]->Afficher(Fenetre);
            }
            if (TabHeal[i]->GetExiste())
            {
               TabHeal[i]->Afficher(Fenetre);
            }
            if (TabDegat[i]->GetExiste())
            {
               TabDegat[i]->Afficher(Fenetre);
            }
         }

         if (Clefairy.GetExiste())
         {
            Clefairy.Afficher(Fenetre);
         }


         //--- Afficher les Pokemons
         for (int i = 0; i < NbreMonstre; i++)
         {
            if (TabMonstres[i]->GetVivant())
            {
               TabMonstres[i]->Afficher(Fenetre);
            }
         }

         //--- Afficher Palkia
         if (Palkia.GetVivant())
         {
            Palkia.Afficher(Fenetre);
         }

         //--- Afficher Ash Ketchum
         if (AshK.GetVivant())
         {
            AshK.Afficher(Fenetre);
         }

         //--- Rafraichir la fenêtre
         Fenetre.display();

         //--- On inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
         Event event;
         while (Fenetre.pollEvent(event))
         {
            //--- évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == Event::Closed)
            {
               Fenetre.close();
            }
         }

         //--- Attendre 30 millisecondes	
         sleep(milliseconds(30));

         AshVivant = AshK.GetVivant();
      } while (!bQuitter && AshK.GetVivant() && Fenetre.isOpen());

      for (int i = 0; i < NbreMonstre; i++)
      {
         delete TabMonstres[i];
      }
      for (int i = 0; i < NbreItemDeChaque; i++)
      {
         delete TabDef[i];
         delete TabAtk[i];
         delete TabHeal[i];
         delete TabDegat[i];
      }
   }
   catch (string s)
   {
      cout << s;
   }

   if (!AshVivant)
   {
      cout << "Tu n'est pas digne d'etre un Pokemon Trainer, meurt ! " << endl;
   }

   return 0;
}

