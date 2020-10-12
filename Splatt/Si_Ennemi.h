#pragma once
#include "SI_Perso.h"

class SI_Ennemi : public SI_Perso
{
protected :
	int Type;
	bool Droite;
	bool Gauche;
	bool Tir;

public :
	SI_Ennemi();
	SI_Ennemi(Vector2f _position, int _type);
	~SI_Ennemi();

	bool Get_Droite();
	bool Get_Gauche();
	bool Get_Tir();

	void Set_Droite(bool _bool);
	void Set_Gauche(bool _bool);
	void Set_Tir(bool _bool);

	void Update();
	void Draw();
};

extern vector <SI_Ennemi*> EnnemyList;

static int Nombre_Ennemis = 0;