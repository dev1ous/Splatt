#include "Lunar_ground.h"

Ground::Ground()
{
	
}

Ground::Ground(float _posX, float _posY)
{
	
}

#pragma region "Get/Set"

Sprite Ground::GetSprite()
{
	return mSprite;
}

float Ground::GetPosX()
{
	return mPosition.x;
}

float Ground::GetPosY()
{
	return mPosition.y;
}

float Ground::GetHeight()
{
	return mSprite.getGlobalBounds().height;
}

float Ground::GetWidth()
{
	return mSprite.getGlobalBounds().width;
}

string Ground::GetClass()
{
	return typeid(this).name();
}

#pragma endregion

Ground::~Ground()
{
}

