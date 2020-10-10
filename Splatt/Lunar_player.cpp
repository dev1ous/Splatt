#include "Lunar_player.h"

Lander::Lander(RenderWindow& _window)
{
	if (!mTexture.loadFromFile("../ressources/Lunar_lander/Lander.png"))
		exit(EXIT_FAILURE);

	mSprite.setTexture(mTexture);
	mSprite.setScale(Vector2f(2.0f, 2.0f));
	
	mPosition = Vector2f(_window.getSize().x / 2, _window.getSize().y / 2);
	mVelocity = Vector2f(0, 0);
	mAngle = -90;

	mSprite.setPosition(mPosition);
	mSprite.setTextureRect(IntRect(0, 0, mTexture.getSize().y / 3, mTexture.getSize().x));
	mSprite.setOrigin(mSprite.getGlobalBounds().width / 2, mSprite.getGlobalBounds().height / 2);

	
}

#pragma region "Lander_update"

void Lander::Update()
{
	MoveRight();
	MoveLeft();
	Inpulse();

	//mPosition = mVelocity;
}

void Lander::MoveRight()
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
		mVelocity.x += .5f * MainTime.GetTimeDeltaF();
}

void Lander::MoveLeft()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
		mVelocity.x -= .5f * MainTime.GetTimeDeltaF();
}

void Lander::Inpulse()
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
		mVelocity.y -= .5f * MainTime.GetTimeDeltaF();
}

#pragma endregion

void Lander::Display(RenderWindow& _window)
{
	_window.draw(mSprite);
}

Lander::~Lander()
{
}
