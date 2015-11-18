////////////////////////////////////////////////////////////
// Objet.cpp
// Définition des méthodes de la class CObjet
//
// Jeu de Zelda
// Activité Synthèse 420-KAB-LG
// Fait par Melissa Boucher
// 25 Mai 2014
////////////////////////////////////////////////////////////
#include "Objet.h"


//------------------------------------------------\\
//----------------> CONSTRUCTEURS <---------------\\
//------------------------------------------------\\

//--- Constructeur paramétrique
CObjet::CObjet(Texture& Texture, CPosition Position, string Nom, int Vie, int Attaque, int Defense)
{
   SetNom(Nom);
   SetGainA(Attaque);
   SetGainD(Defense);
   SetGainV(Vie);
   setTexture(Texture);
   setPosition(Position);
   SetExiste(true);
}

//------------------------------------------------\\
//------------------> METHODES <------------------\\
//------------------------------------------------\\

//--- Afficher
void CObjet::Afficher(RenderWindow& Fenetre)
{
   Fenetre.draw(*this);
}

//------------------------------------------------\\
//-----------------> ACCESSEURS <-----------------\\
//------------------------------------------------\\

//--- Accesseur de l'attribut Nom_
// Intrants : Aucun
// Extrants : string Nom_
string CObjet::GetNom() const
{
   return Nom_;
}

//--- Accesseur de l'attribut GainV_
// Intrants : Aucun
// Extrants : int GainV_
int CObjet::GetGainV() const
{
   return GainV_;
}

//--- Accesseur de l'attribut GainA_
// Intrants : Aucun
// Extrants : int GainA_
int CObjet::GetGainA() const
{
   return GainA_;
}

//--- Accesseur de l'attribut GainD_
// Intrants : Aucun
// Extrants : int GainD_
int CObjet::GetGainD() const
{
   return GainD_;
}

//--- Accesseur de l'attribut Existe_
// Intrants : Aucun
// Extrants : bool Existe_
bool CObjet::GetExiste() const
{
   return Existe_;
}

//------------------------------------------------\\
//------------------> MUTATEURS <-----------------\\
//------------------------------------------------\\

//--- Mutateur de l'attribut Nom_
// Intrants : string Valeur
// Extrants : Aucun
void CObjet::SetNom(string Valeur)
{
   Nom_ = Valeur;
}

//--- Mutateur de l'attribut GainV_
// Intrants : int Valeur
// Extrants : Aucun
void CObjet::SetGainV(int Valeur)
{
   GainV_ = Valeur;
}

//--- Mutateur de l'attribut GainA_
// Intrants : int Valeur
// Extrants : Aucun
void CObjet::SetGainA(int Valeur)
{
   GainA_ = Valeur;
}

//--- Mutateur de l'attribut GainD_
// Intrants : int Valeur
// Extrants : Aucun
void CObjet::SetGainD(int Valeur)
{
   GainD_ = Valeur;
}

//--- Mutateur de l'attribut Existe_
// Intrants : bool Valeur
// Extrants : Aucun
void CObjet::SetExiste(bool Valeur)
{
   Existe_ = Valeur;
}
