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

	inline int Get_Type() { return Type; };

	inline void Set_Descente(bool _bool) { Descente = _bool; };

	void Update();
	void Draw();
};

extern vector <SI_Ennemi> EnnemyList;

extern int Nombre_Ennemis;