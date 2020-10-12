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

	Sprite GetSprite();
	float GetPosX();
	float GetPosY();
	float GetHeight();
	float GetWidth();

	~Ground();

};