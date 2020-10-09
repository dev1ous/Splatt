#pragma once
#include "Tools.hpp"
#include "pch.h"

class SI_Perso
{
protected :
	Vector2f Position;
	Vector2f Origine;
	float Timer;
	int life;

public :
	SI_Perso();
	~SI_Perso();

	Vector2f Get_Position();
	Vector2f Get_Origin();
	int Get_Life();
};