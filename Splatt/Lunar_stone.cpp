#include "Lunar_stone.h"

Stone::Stone()
{	
}

Stone::Stone(float _posX, float _posY)
{
	mId = 1;

	mPosition.x = _posX;
	mPosition.y = _posY;

	mCollideBox.top = mPosition.y;
	mCollideBox.left = mPosition.x;
	mCollideBox.height = 1;
	mCollideBox.width = 1;
}

Stone::~Stone()
{
}