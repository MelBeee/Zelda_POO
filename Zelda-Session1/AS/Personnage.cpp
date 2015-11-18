
////////////////////////////////////////////////////////////
// Personnage.cpp
// Définition des méthodes de la class CPersonnage
//
// Jeu de Zelda
// Activité Synthèse 420-KAB-LG
// Fait par Melissa Boucher
// 25 Mai 2014
////////////////////////////////////////////////////////////

#include "Personnage.h"



//------------------------------------------------\\
//------------------> MÉTHODES <------------------\\
//------------------------------------------------\\


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

bool CPersonnage::Prendre(CObjet& Objet)
{
   bool Ramasse = true;

   if (PositionsProches(getPosition(), Objet.getPosition()))
   {
      SetVie(GetVie() + Objet.GetGainV());
      SetAttaque(GetAttaque() + Objet.GetGainA());
      SetDefense(GetDefense() + Objet.GetGainD());

      Ramasse = false;
      cout << GetNom() << " a ramasse l'objet " << Objet.GetNom() << endl;
      cout << Objet.GetNom() << " lui donne " << Objet.GetGainV() << " de points de vie, il est donc rendu a " << GetVie() << " points de vie. " << endl;
      cout << Objet.GetNom() << " lui donne " << Objet.GetGainD() << " de points de defense, il est donc rendu a " << GetDefense() << " points de defense. " << endl;
      cout << Objet.GetNom() << " lui donne " << Objet.GetGainA() << " de points d'attaque, il est donc rendu a " << GetAttaque() << " points d'attaque. " << endl << endl;
   }
   return Ramasse;
}


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

bool CPersonnage::Attaquer(CPersonnage& Personnage)
{
   bool Mort = true;

   int NbreDeDmg = 0;

   if (PositionsProches(getPosition(), Personnage.getPosition()))
   {
      if (rand() % 20 + 1 >= Personnage.GetDefense())
      {
         NbreDeDmg = rand() % GetAttaque() + 1;
         Personnage.SetVie(Personnage.GetVie() - (NbreDeDmg));

         if (Personnage.GetVie() <= 0)
         {
            Mort = false;
            cout << GetNom() << " a tue " << Personnage.GetNom() << endl;
         }
      }

      cout << GetNom() << " a inflige " << NbreDeDmg << " degats a " << Personnage.GetNom() << ", il est donc rendu a " << Personnage.GetVie() << " points de vie. " << endl;
      cout << GetNom() << " Vie : " << GetVie() << " Defense : " << GetDefense() << " Attaque : " << GetAttaque() << endl;
      cout << Personnage.GetNom() << " Vie : " << Personnage.GetVie() << " Defense : " << Personnage.GetDefense() << " Attaque : " << Personnage.GetAttaque() << endl;
   }

   return Mort;
}

//--------------------------------------------------\\
//------------------> ACCESSEURS <------------------\\
//--------------------------------------------------\\

//--- Accesseur de l'attributs Nom_
// Intrants : Aucun
// Extrants : string Nom_ 
string CPersonnage::GetNom() const
{
   return Nom_;
}

//--- Accesseur de l'attributs A_
// Intrants : Aucun
// Extrants : int A_
int CPersonnage::GetAttaque() const
{
   return A_;
}

//--- Accesseur de l'attributs V_
// Intrants : Aucun
// Extrants : int V_
int CPersonnage::GetVie() const
{
   return V_;
}

//--- Accesseur de l'attributs D_
// Intrants : Aucun
// Extrants : int D_
int CPersonnage::GetDefense() const
{
   return D_;
}

//--- Accesseur de l'attribut Vivant_
// Intrants : Aucun
// Extrants : bool Vivant_
bool CPersonnage::GetVivant() const
{
   return Vivant_;
}

//-------------------------------------------------\\
//------------------> MUTATEURS <------------------\\
//-------------------------------------------------\\

//--- Mutateur de l'attribut Nom
// Intrants : string Valeur
// Extrants : Aucun
void CPersonnage::SetNom(string Valeur)
{
   Nom_ = Valeur;
}

//--- Mutateur de l'attribut V_
// Intrants : int Valeur
// Extrants : Aucun
void CPersonnage::SetVie(int Valeur)
{
   V_ = Valeur;
}

//--- Mutateur de l'attribut A_
// Intrants : int Valeur
// Extrants : Aucun
void CPersonnage::SetAttaque(int Valeur)
{
   A_ = Valeur;
}

//--- Mutateur de l'attribut D_
// Intrants : int Valeur
// Extrants : Aucun
void CPersonnage::SetDefense(int Valeur)
{
   D_ = Valeur;
}

//--- Mutateur de l'attribut Vivant_
// Intrants : int Valeur
// Extrants : Aucun
void CPersonnage::SetVivant(bool Valeur)
{
   Vivant_ = Valeur;
}