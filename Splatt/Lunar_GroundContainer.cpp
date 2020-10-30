#include "Lunar_GroundContainer.h"

GroundContainer::GroundContainer(RenderWindow& _window)
{
	mNbLvl = 4;
	mLvlCanChange = true;
	mIsOnDS = false;
	mPosition = Vector2f(_window.getSize().x / 2, _window.getSize().y / 2);
	mStartNewGame = false;
}

void GroundContainer::Update(RenderWindow& _window)
{
	if (mLvlCanChange)
	{
		if (mNbLvl == 0)
			Start();
		else if(mNbLvl > 0)
			ChangeLevel(_window);
	}
}

void GroundContainer::Start()
{
	if (!mMyImage.loadFromFile("../ressources/Lunar_lander/Lunar_Lander_Menu.png"))
		exit(EXIT_FAILURE);

	mMyTexture.loadFromImage(mMyImage);
	mMySprite.setTexture(mMyTexture);
	mMySprite.setOrigin(mMySprite.getGlobalBounds().width / 2, mMySprite.getGlobalBounds().height / 2);
	mMySprite.setPosition(mPosition);

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
		mLvlCanChange = true;
		mMyImage.loadFromFile("../ressources/Lunar_lander/Lunar_final_stage.png");

		if (Keyboard::isKeyPressed(Keyboard::Space))
			mNbLvl++;
	}
	
	if (mNbLvl == 5)
	{
		mMyImage.loadFromFile("../ressources/Lunar_lander/Lunar_lvl_04.png");

		mLvlCanChange = false;
	}

	mMyTexture.loadFromImage(mMyImage);
	mMySprite.setTexture(mMyTexture);
	mMySprite.setOrigin(mMySprite.getGlobalBounds().width / 2, mMySprite.getGlobalBounds().height / 2);
	mMySprite.setPosition(mPosition);
}

void GroundContainer::DeathScreen(RenderWindow& _window)
{
	mIsOnDS = true;
	mMyImage.loadFromFile("../ressources/Lunar_lander/Lunar_death_screen.jpg");

	mMyTexture.loadFromImage(mMyImage);
	mMySprite.setTexture(mMyTexture);
	mMySprite.setOrigin(mMySprite.getGlobalBounds().width / 2, mMySprite.getGlobalBounds().height / 2);
	mMySprite.setPosition(mPosition);

	mLvlCanChange = true;

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		mNbLvl = 0;
		mIsOnDS = false;
		mStartNewGame = true;
	}

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

bool GroundContainer::GetNewGame()
{
	return mStartNewGame;
}

bool GroundContainer::GetIsOnDeathScreen()
{
	return mIsOnDS;
}

void GroundContainer::SetNbLvl(int _nbLvl)
{
	mNbLvl = _nbLvl;
}

void GroundContainer::SetNewGame(bool _newGame)
{
	mStartNewGame = _newGame;
}

GroundContainer::~GroundContainer()
{
}
