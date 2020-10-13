#pragma once
#include "pch.h"
#include "Lunar_player.h"

class Ground
{
protected:

	int mId;
	Texture mTexture;
	Sprite mSprite;
	Vector2f mPosition;

public:
	Ground();
	Ground(float _posX, float _posY);
	bool IsCollide(Lander &_player);

#pragma region "Get/Set"

	Sprite GetSprite();
	float GetPosX();
	float GetPosY();
	float GetHeight();
	float GetWidth();
	string GetClass();
	int GetID();

#pragma endregion

	~Ground();

};