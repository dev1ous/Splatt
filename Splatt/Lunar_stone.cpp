#include "Lunar_stone.h"

Stone::Stone()
{
	if (!mTexture.loadFromFile("../ressources/Lunar_lander/LunarGround.png"))
		exit(EXIT_FAILURE);

	mSprite.setTexture(mTexture);
	mSprite.setTextureRect(IntRect(0, 0, mTexture.getSize().x, mTexture.getSize().y));
}

Stone::Stone(float _posX, float _posY)
{
	mId = 1;

	if (!mTexture.loadFromFile("../ressources/Lunar_lander/LunarGround.png"))
		exit(EXIT_FAILURE);

	mSprite.setTexture(mTexture);

	mPosition.x = _posX;
	mPosition.y = _posY;

	mSprite.setPosition(mPosition);
}

Stone::~Stone()
{
}