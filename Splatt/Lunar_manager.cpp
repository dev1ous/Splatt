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

	mVelocityYText.setString("Velocity Y: " + to_string(player->GetVelocityY()));
	mVelocityYText.setFont(mMyFont);
	mVelocityYText.setCharacterSize(50);
	mVelocityYText.setPosition(_window.getSize().x - mVelocityYText.getGlobalBounds().width, _window.getSize().y - (mVelocityYText.getGlobalBounds().height) - 15);
	mVelocityYText.setFillColor(Color(Color::Black));

	mVelocityXText.setString("Velocity X: " + to_string(player->GetVelocityX()));
	mVelocityXText.setFont(mMyFont);
	mVelocityXText.setCharacterSize(50);
	mVelocityXText.setPosition(_window.getSize().x - mVelocityXText.getGlobalBounds().width, _window.getSize().y - (mVelocityYText.getGlobalBounds().height + mVelocityXText.getGlobalBounds().height)- 30);
	mVelocityXText.setFillColor(Color(Color::Black));

	mFuelText.setString("Fuel: " + to_string(player->GetFuel()));
	mFuelText.setFont(mMyFont);
	mFuelText.setCharacterSize(50);
	mFuelText.setPosition(_window.getSize().x - mFuelText.getGlobalBounds().width, 5);
	mFuelText.setFillColor(Color(Color::White));
}

void Lunar_manager::Lunar_update(RenderWindow& _window)
{
	myContainer->Update(_window);

	if (myContainer->GetLvl() >= 1)
	{
		TextUpdate();

		if (myContainer->GetNewGame() || PlayerHasNoFuel())
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
		
		_window.draw(mVelocityXText);
		_window.draw(mVelocityYText);
		_window.draw(mScoreText);
		_window.draw(mLifeText);
		_window.draw(mFuelText);
	}
}

void Lunar_manager::TextUpdate()
{
	mVelocityXText.setString("Velocity X: " + to_string(player->GetVelocityX()));
	mVelocityYText.setString("Velocity Y: " + to_string(player->GetVelocityY()));
	mScoreText.setString("Score: " + to_string(player->GetScore()));
	mLifeText.setString("Life number: " + to_string(player->GetNbLife()));
	mFuelText.setString("Fuel: " + to_string(player->GetFuel()));
}

bool Lunar_manager::PlayerHasNoFuel()
{
	if(player->GetFuel() <= 0)
		return true;

	return false;
}

Lunar_manager::~Lunar_manager()
{
}
