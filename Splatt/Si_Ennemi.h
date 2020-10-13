#pragma once
#include "SI_Perso.h"

class SI_Ennemi : public SI_Perso
{
protected :
	int Type;
	bool Descente;

public :
	SI_Ennemi();
	SI_Ennemi(Vector2f _position, int _type);
	~SI_Ennemi();

	int Get_Type();

	void Set_Descente(bool _bool);

	void Update();
	void Draw();
};

extern vector <SI_Ennemi> EnnemyList;

static int Nombre_Ennemis = 0;