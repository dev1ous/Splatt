#include "Si_Ennemi.h"

Si_Ennemi::Si_Ennemi()
{
	life = 1;
	Nombre_Ennemis++;
	Droite = false;
	Gauche = false;
	Tir = false;
}

Si_Ennemi::~Si_Ennemi()
{
}

bool Si_Ennemi::Get_Droite()
{
	return Droite;
}

bool Si_Ennemi::Get_Gauche()
{
	return Gauche;
}

bool Si_Ennemi::Get_Tir()
{
	return Tir;
}

void Si_Ennemi::Set_Droite(bool _bool)
{
	Droite = _bool;
}

void Si_Ennemi::Set_Gauche(bool _bool)
{
	Gauche = _bool;
}

void Si_Ennemi::Set_Tir(bool _bool)
{
	Tir = _bool;
}