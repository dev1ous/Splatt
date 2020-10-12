#pragma once
#include "SI_Perso.h"

class Si_Ennemi : public SI_Perso
{
protected :
	bool Droite;
	bool Gauche;
	bool Tir;

public :
	Si_Ennemi();
	~Si_Ennemi();

	bool Get_Droite();
	bool Get_Gauche();
	bool Get_Tir();

	void Set_Droite(bool _bool);
	void Set_Gauche(bool _bool);
	void Set_Tir(bool _bool);
};

int Nombre_Ennemis = 0;