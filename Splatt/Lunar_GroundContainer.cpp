#include "Lunar_GroundContainer.h"

GroundContainer::GroundContainer()
{
	mNbLvl = 0;
}

GroundContainer::GroundContainer(RenderWindow& _window)
{
	mNbLvl = 0;

	if (!mMyImage.loadFromFile("../ressources/Lunar_lander/Lunar_Lander_Menu.png"))
		exit(EXIT_FAILURE);

	mPosition = Vector2f(_window.getSize().x / 2, _window.getSize().y / 2);
	mMyTexture.loadFromImage(mMyImage);
	mMySprite.setTexture(mMyTexture);
	mMySprite.setOrigin(mMySprite.getGlobalBounds().width / 2, mMySprite.getGlobalBounds().height / 2);
	mMySprite.setPosition(mPosition);
}

void GroundContainer::Update(RenderWindow& _window)
{
	Start(_window);
	ChangeLevel(_window);
}

void GroundContainer::Start(RenderWindow& _window)
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		if (mNbLvl <= 1)
			mNbLvl = 1;
	}
}

void GroundContainer::ChangeLevel(RenderWindow& _window)
{
	if (mNbLvl == 1)
	{
		if (!mMyImage.loadFromFile("../ressources/Lunar_lander/Luanar_lander_lvl_01_2.png"))
			exit(EXIT_FAILURE);
	}
	/*else if (mNbLvl == 2)
	{
		if (!mMyImage.loadFromFile("../ressources/Lunar_lander/Lunar_Lander_Menu.png"))
			exit(EXIT_FAILURE);
	}*/

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

Image& GroundContainer::GetImage()
{
	return mMyImage;
}

int GroundContainer::GetLvl()
{
	return mNbLvl;
}

GroundContainer::~GroundContainer()
{
}
