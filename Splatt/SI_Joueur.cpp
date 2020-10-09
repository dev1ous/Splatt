#include "SI_Joueur.h"

SI_Joueur::SI_Joueur()
{
	life = 1;
	Nombre_Joueur++;
	Numero_Joueur = Nombre_Joueur;
	Droite = false;
	Gauche = false;
	Tir = false;
	Timer = 0;
}

SI_Joueur::~SI_Joueur()
{
}

int SI_Joueur::Get_Numero()
{
	return Numero_Joueur;
}

bool SI_Joueur::Get_Droite()
{
	return Droite;
}

bool SI_Joueur::Get_Gauche()
{
	return Gauche;
}

bool SI_Joueur::Get_Tir()
{
	return Tir;
}

void SI_Joueur::Set_Droite(bool _bool)
{
	Droite = _bool;
}

void SI_Joueur::Set_Gauche(bool _bool)
{
	Gauche = _bool;
}

void SI_Joueur::Set_Tir(bool _bool)
{
	Tir = _bool;
}
