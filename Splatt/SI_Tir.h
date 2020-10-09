#pragma once
#include "Tools.hpp"
#include "pch.h"

class SI_Tir
{
protected :
	Vector2f Position;

public :
	SI_Tir();
	~SI_Tir();

	Vector2f Get_Position();
	void Set_Position(Vector2f _position);
};

