#pragma once
#include "SI_Manager.h"

class SI_Perso
{
protected :
	Vector2f Position;
	Vector2f Origine;
	float Timer;
	int life;

	bool Droite;
	bool Gauche;
	bool Tir;

public :
	SI_Perso();
	~SI_Perso();

	Vector2f Get_Position();
	Vector2f Get_Origin();
	float Get_Timer();
	int Get_Life();

	bool Get_Droite();
	bool Get_Gauche();
	bool Get_Tir();

	void Set_Position(Vector2f _position);
	void Set_Origin(Vector2f _origine);
	void Set_Timer(float _timer);
	void Set_Life(int _life);

	void Set_Droite(bool _bool);
	void Set_Gauche(bool _bool);
	void Set_Tir(bool _bool);

	virtual void Update() = 0;
	virtual void Draw() = 0;
};

void FullDraw_Perso(SI_Perso& _p);
void FullUpdate(SI_Perso& _p);