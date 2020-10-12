#pragma once
#include "pch.h"
class Ground
{
protected:

	Texture mTexture;
	Sprite mSprite;
	Vector2f mPosition;

public:
	Ground();
	Ground(float _posX, float _posY);

#pragma region "Get/Set"

	Sprite GetSprite();
	float GetPosX();
	float GetPosY();
	float GetHeight();
	float GetWidth();
	string GetClass();

#pragma endregion

	~Ground();

};