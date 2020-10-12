#pragma once
#include "Si_Manager.h"

class SI_Perso
{
protected :
	Vector2f Position;
	Vector2f Origine;
	int life;

public :
	SI_Perso();
	~SI_Perso();

	Vector2f Get_Position();
	Vector2f Get_Origin();
	int Get_Life();

	void Set_Position(Vector2f _position);
	void Set_Origin(Vector2f _origine);
	void Set_Life(int _life);
};