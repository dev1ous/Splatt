#include "Lunar_GroundContainer.h"
#include "Lunar_stone.h"
#include "Lunar_landingZone.h"

GroundContainer::GroundContainer()
{
	if (!mMyImage.loadFromFile("../ressources/Lunar_lander/Luanar_lander_lvl_01.png"))
		exit(EXIT_FAILURE);
}

GroundContainer::GroundContainer(RenderWindow& _window)
{
	if (!mMyImage.loadFromFile("../ressources/Lunar_lander/Luanar_lander_lvl_01.png"))
		exit(EXIT_FAILURE);

	mPosition = Vector2f(_window.getSize().x / 2, _window.getSize().y / 2);

	mMyTexture.loadFromImage(mMyImage);
	mMySprite.setTexture(mMyTexture);

	mMySprite.setOrigin(mMySprite.getGlobalBounds().width / 2, mMySprite.getGlobalBounds().height / 2);
	mMySprite.setPosition(mPosition);
}



void GroundContainer::Display(RenderWindow& _window)
{
	_window.draw(mMySprite);
}

Image GroundContainer::GetImage()
{
	return mMyImage;
}

GroundContainer::~GroundContainer()
{
}
