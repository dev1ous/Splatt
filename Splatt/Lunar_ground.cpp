#include "Lunar_ground.h"

Ground::Ground()
{
	
}

Ground::Ground(float _posX, float _posY)
{
	
}

#pragma region "Get/Set"

float Ground::GetPosX()
{
	return mPosition.x;
}

float Ground::GetPosY()
{
	return mPosition.y;
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

