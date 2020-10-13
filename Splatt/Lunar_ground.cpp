#include "Lunar_ground.h"

Ground::Ground()
{
	
}

Ground::Ground(float _posX, float _posY)
{
	
}

bool Ground::IsCollide(Lander& _player)
{
	if (mSprite.getGlobalBounds().intersects(_player.GetSprite().getGlobalBounds()))
		return true;

	return false;
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

int Ground::GetID()
{
	return mId;
}

#pragma endregion

Ground::~Ground()
{
}

