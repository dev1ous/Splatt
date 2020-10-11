#include "Lunar_ground.h"

Ground::Ground(float _posX, float _posY)
{
	if (!mTexture.loadFromFile("../ressources/Lunar_lander/LunarGround.png"))
		exit(EXIT_FAILURE);

	mSprite.setTexture(mTexture);
	mSprite.setScale(Vector2f(.5f, .5f));

	mPosition.x = _posX;
	mPosition.y = _posY;

	mSprite.setPosition(mPosition);
	mSprite.setTextureRect(IntRect(0, 0, mTexture.getSize().x, mTexture.getSize().y));
	mSprite.setOrigin(mSprite.getGlobalBounds().width / 2, mSprite.getGlobalBounds().height / 2);
}

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
	return mSize.x;
}

float Ground::GetWidth()
{
	return mSize.y;
}

Ground::~Ground()
{
}

