#include "lunar_landingZone.h"

LandingZone::LandingZone()
{
	mId = 2;

	if (!mTexture.loadFromFile("../ressources/Lunar_lander/LunarGrass.png"))
		exit(EXIT_FAILURE);

	mSprite.setTexture(mTexture);
	mSprite.setTextureRect(IntRect(0, 0, mTexture.getSize().x, mTexture.getSize().y));
}

LandingZone::LandingZone(float _posX, float _posY)
{
	mId = 2;

	if (!mTexture.loadFromFile("../ressources/Lunar_lander/LunarGrass.png"))
		exit(EXIT_FAILURE);

	mSprite.setTexture(mTexture);

	mPosition.x = _posX;
	mPosition.y = _posY;

	mSprite.setPosition(mPosition);
}

LandingZone::~LandingZone()
{
}
