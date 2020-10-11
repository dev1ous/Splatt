#include "Lunar_player.h"
#include "Lunar_ground.h"

Lander::Lander(RenderWindow& _window)
{
	if (!mTexture.loadFromFile("../ressources/Lunar_lander/Lander.png"))
		exit(EXIT_FAILURE);

	mSprite.setTexture(mTexture);
	mSprite.setScale(Vector2f(2.0f, 2.0f));

	mPosition = Vector2f(_window.getSize().x / 2, _window.getSize().y / 2);
	mVelocity = Vector2f(0, 0);
	mAngle = 0;
	mEngineOn = false;

	mSprite.setPosition(mPosition);
	mSprite.setTextureRect(IntRect(0, 0, mTexture.getSize().x / 3, mTexture.getSize().y));
	mSprite.setOrigin(mSprite.getGlobalBounds().width / 2, mSprite.getGlobalBounds().height / 2);
	mSprite.setRotation(mAngle);
}

#pragma region "Lander_update"

void Lander::Update()
{
	mVelocity.y += .1f * MainTime.GetTimeDeltaF();

	MoveRight();
	MoveLeft();
	Inpulse();

	mPosition += mVelocity;
	mSprite.setPosition(mPosition);

}

void Lander::MoveRight()
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
		mVelocity.x += .1f * MainTime.GetTimeDeltaF();
}

void Lander::MoveLeft()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
		mVelocity.x -= .1f * MainTime.GetTimeDeltaF();
}

void Lander::Inpulse()
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		mEngineOn = true;

		mVelocity.y -= .2f * MainTime.GetTimeDeltaF();
		mSprite.setTextureRect(IntRect(mTexture.getSize().x / 3, 0, mTexture.getSize().x / 3, mTexture.getSize().y));
	}

	if (mEngineOn && !Keyboard::isKeyPressed(Keyboard::Up))
	{
		mEngineOn = false;

		mSprite.setTextureRect(IntRect(0, 0, mTexture.getSize().x / 3, mTexture.getSize().y));
	}
}

bool Lander::CollideTop()
{
	return false;
}

bool Lander::CollideBot()
{
	return false;
}

bool Lander::CollideLeft()
{
	return false;
}

bool Lander::CollideRight()
{
	return false;
}

bool Lander::IsLanding()
{

	return true;
}

#pragma endregion

void Lander::Display(RenderWindow& _window)
{
	_window.draw(mSprite);
}

Lander::~Lander()
{
}
