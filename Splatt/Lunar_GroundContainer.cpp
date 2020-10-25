#include "Lunar_GroundContainer.h"

GroundContainer::GroundContainer()
{
	mNbLvl = 0;
	mLvlCanChange = true;
}

GroundContainer::GroundContainer(RenderWindow& _window)
{
	mNbLvl = 0;
	mLvlCanChange = true;

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
	if (mLvlCanChange)
	{
		if (mNbLvl == 0)
			Start(_window);
		else if(mNbLvl > 0)
			ChangeLevel(_window);
	}
}

void GroundContainer::Start(RenderWindow& _window)
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
		mNbLvl++;
}

void GroundContainer::GoToNextLvl(RenderWindow& _window)
{
	mNbLvl++;
	mLvlCanChange = true;

	ChangeLevel(_window);
}

void GroundContainer::ChangeLevel(RenderWindow& _window)
{
	if (mNbLvl == 1)
	{
		mMyImage.loadFromFile("../ressources/Lunar_lander/Lunar_lvl_01.png");

		mLvlCanChange = false;
	}
	
	if (mNbLvl == 2)
	{
		mMyImage.loadFromFile("../ressources/Lunar_lander/Lunar_lvl_02.png");

		mLvlCanChange = false;
	}

	if (mNbLvl == 3)
	{
		mMyImage.loadFromFile("../ressources/Lunar_lander/Lunar_lvl_03.png");

		mLvlCanChange = false;
	}

	if (mNbLvl == 4)
	{
		mMyImage.loadFromFile("../ressources/Lunar_lander/Lunar_final_stage.png");

		mLvlCanChange = false;
	}

	mPosition = Vector2f(_window.getSize().x / 2, _window.getSize().y / 2);
	mMyTexture.loadFromImage(mMyImage);
	mMySprite.setTexture(mMyTexture);
	mMySprite.setOrigin(mMySprite.getGlobalBounds().width / 2, mMySprite.getGlobalBounds().height / 2);
	mMySprite.setPosition(mPosition);
}

void GroundContainer::DeathScreen(RenderWindow& _window)
{
	mMyImage.loadFromFile("../ressources/Lunar_lander/Lunar_death_screen.jpg");
	mLvlCanChange = false;

	mPosition = Vector2f(_window.getSize().x / 2, _window.getSize().y / 2);
	mMyTexture.loadFromImage(mMyImage);
	mMySprite.setTexture(mMyTexture);
	mMySprite.setOrigin(mMySprite.getGlobalBounds().width / 2, mMySprite.getGlobalBounds().height / 2);
	mMySprite.setPosition(mPosition);

	if (Keyboard::isKeyPressed(Keyboard::Space))
		Start(_window);
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

bool GroundContainer::GetLvlChange()
{
	return mLvlCanChange;
}

GroundContainer::~GroundContainer()
{
}
