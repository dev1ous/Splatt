#include "Lunar_player.h"
#include "Lunar_ground.h"
#include "Lunar_GroundContainer.h"

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



void Lander::Update(GroundContainer& _myContainer)
{

	mVelocity.y += .2f * MainTime.GetTimeDeltaF();

	MoveRight();
	MoveLeft();
	Inpulse();

	mPosition += mVelocity;
	mSprite.setPosition(mPosition);

	if (IsCollide(_myContainer))
		Explode();
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
	{
		mEngineOn = true;

		mVelocity.y -= .5f * MainTime.GetTimeDeltaF();
		mSprite.setTextureRect(IntRect(mTexture.getSize().x / 3, 0, mTexture.getSize().x / 3, mTexture.getSize().y));
	}

	if (mEngineOn && !Keyboard::isKeyPressed(Keyboard::Up))
	{
		mEngineOn = false;

		mSprite.setTextureRect(IntRect(0, 0, mTexture.getSize().x / 3, mTexture.getSize().y));
	}
}

void Lander::Landing()
{
	mVelocity.x = 0.0f;
	mVelocity.y = 0.0f;

	cout << "You Win !" << endl;
	cout << "GG WP" << endl;
}

bool Lander::IsCollide(GroundContainer& _myContainer)
{
	Color color = _myContainer.GetImage().getPixel(mPosition.x, mPosition.y);
	cout << "x" << mPosition.x << endl;
	cout << "y" << mPosition.y << endl;
		//to_string(color.r) << to_string(color.g) << to_string(color.b) << to_string(color.a) << endl;

	if (_myContainer.GetImage().getPixel((int)mSprite.getPosition().x, (int)mSprite.getPosition().y) == Color::Color(255, 255, 255))
	{
		return true;
	}

	//for (int i = 0; i <= mSprite.getGlobalBounds().width; i++)
	//{
	//	for (int j = 0; j <= mSprite.getGlobalBounds().height; j++)
	//	{
	//		/*int x = mSprite.getPosition().x - mSprite.getOrigin().x + i;
	//		int y = mSprite.getPosition().y - mSprite.getOrigin().y + j;

	//		*/
	//	}
	//}

	return false;
}

#pragma endregion

void Lander::Display(RenderWindow& _window)
{
	_window.draw(mSprite);
}

void Lander::Explode()
{
	mVelocity.x = 0.0f;
	mVelocity.y = 0.0f;

	if (!mTexture.loadFromFile("../ressources/Lunar_lander/Lander_explode.png"))
		exit(EXIT_FAILURE);

	mSprite.setPosition(mPosition);
	mSprite.setTexture(mTexture);
	mSprite.setScale(Vector2f(2.0f, 2.0f));
	mSprite.setTextureRect(IntRect(0, 0, mTexture.getSize().x, mTexture.getSize().y));
	mSprite.setOrigin(mSprite.getGlobalBounds().width / 2, mSprite.getGlobalBounds().height / 2);
}

Lander::~Lander()
{

}

float Lander::GetPosX()
{
	return mPosition.x;
}

float Lander::GetPosY()
{
	return mPosition.y;
}

Vector2f Lander::GetPos()
{
	return mPosition;
}

float Lander::GetVelocityX()
{
	return mVelocity.x;
}

float Lander::GetVelocityY()
{
	return mVelocity.y;
}

float Lander::GetHeight()
{
	return mSprite.getGlobalBounds().height;
}

float Lander::GetWidth()
{
	return mSprite.getGlobalBounds().width;
}

Sprite Lander::GetSprite()
{
	return mSprite;
}

FloatRect Lander::GetBound()
{
	return mSprite.getGlobalBounds();
}
