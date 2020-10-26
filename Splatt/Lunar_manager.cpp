#include "Lunar_manager.h"

Lander* player;
GroundContainer* myContainer;

Lunar_manager::Lunar_manager(RenderWindow &_window)
{
	if (!mMyFont.loadFromFile("../ressources/Lunar_lander/Lunar_font.ttf"))
		exit(EXIT_FAILURE);

	myContainer = new GroundContainer(App);
	player = new Lander(App);
	
	TextInit(_window);
}

void Lunar_manager::TextInit(RenderWindow &_window)
{
	mLifeText.setString("Life: " + to_string(player->GetNbLife()));
	mLifeText.setFont(mMyFont);
	mLifeText.setCharacterSize(50);
	mLifeText.setPosition(5, _window.getSize().y - mLifeText.getGlobalBounds().height -15);
	mLifeText.setFillColor(Color(Color::Black));

	mScoreText.setString("Score: " + player->GetScore());
	mScoreText.setFont(mMyFont);
	mScoreText.setCharacterSize(50);
	mScoreText.setPosition(5, _window.getSize().y - (mLifeText.getGlobalBounds().height + mScoreText.getGlobalBounds().height) - 30);
	mScoreText.setFillColor(Color(Color::Black));

	mPosYText.setString("Pos Y: " + to_string(player->GetPosY()));
	mPosYText.setFont(mMyFont);
	mPosYText.setCharacterSize(50);
	mPosYText.setPosition(_window.getSize().x - mPosYText.getGlobalBounds().width, _window.getSize().y - (mPosYText.getGlobalBounds().height) - 15);
	mPosYText.setFillColor(Color(Color::Black));

	mPosXText.setString("Pos X: " + to_string(player->GetPosX()));
	mPosXText.setFont(mMyFont);
	mPosXText.setCharacterSize(50);
	mPosXText.setPosition(_window.getSize().x - mPosXText.getGlobalBounds().width, _window.getSize().y - (mPosYText.getGlobalBounds().height + mPosXText.getGlobalBounds().height)- 30);
	mPosXText.setFillColor(Color(Color::Black));
}

void Lunar_manager::Lunar_update(RenderWindow& _window)
{
	myContainer->Update(_window);

	if (myContainer->GetLvl() >= 1)
	{
		TextUpdate();

		if (myContainer->GetNewGame())
		{
			delete player;

			player = new Lander(App);

			myContainer->SetNewGame(false);
		}
		else
			player->Update(_window, *myContainer);
	}
}

void Lunar_manager::Lunar_display(RenderWindow& _window)
{
	myContainer->Display(_window);

	if (!myContainer->GetIsOnDeathScreen() && myContainer->GetLvl() >= 1 && player != nullptr)
	{
		player->Display(_window);
		
		_window.draw(mPosXText);
		_window.draw(mPosYText);
		_window.draw(mScoreText);
		_window.draw(mLifeText);
	}
}

void Lunar_manager::TextUpdate()
{
	mPosXText.setString("Pos X: " + to_string(player->GetPosX()));
	mPosYText.setString("Pos Y: " + to_string(player->GetPosY()));
	mScoreText.setString("Score: " + to_string(player->GetScore()));
	mLifeText.setString("Life: " + to_string(player->GetNbLife()));
}

Lunar_manager::~Lunar_manager()
{
}
