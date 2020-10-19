#pragma once
#include "pch.h"
#include "Lunar_player.h"

class Ground
{
protected:

	int mId;
	FloatRect mCollideBox;
	Vector2f mPosition;

public:
	Ground();
	Ground(float _posX, float _posY);

#pragma region "Get/Set"

	float GetPosX();
	float GetPosY();
	string GetClass();
	int GetID();

#pragma endregion

	~Ground();

};