#pragma once
#include "SI_Perso.h"

class SI_Ennemi : public SI_Perso
{
protected :
	int Type;
	bool Descente;
	RectangleShape PV;
	RectangleShape Encadré;
	float ecart;
	float timer_tir;
	int x;
	int Nb_tir;

public :
	SI_Ennemi();
	SI_Ennemi(Vector2f _position, int _type);
	~SI_Ennemi();

	float Timer_degat;

	inline int Get_Type() { return Type; };

	inline void Set_Descente(bool _bool) { Descente = _bool; };

	void Update();
	void Draw();
};

void Ennemi_tir();

extern vector <SI_Ennemi> EnnemyList;

extern float Vitesse;