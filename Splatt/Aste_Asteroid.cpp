#include "Aste_Asteroid.h"

Aste_Asteroid::Aste_Asteroid()
{
}

Aste_Asteroid::Aste_Asteroid(sf::Vector2f position, float rotation, int life) : Aste_Enemies(position, rotation, life)
{
}

Aste_Asteroid::~Aste_Asteroid()
{
}

void Aste_Asteroid::RemoveLife()
{
	if (getLife() > 1)
	{
		float newVelocity1(frandom(0,360));
		float newVelocity2(frandom(0, 360));
		EnemiesList.push_back(new Aste_Asteroid(getPosition(), newVelocity1, getLife() -1));
		EnemiesList.push_back(new Aste_Asteroid(getPosition(), newVelocity2, getLife() -1));
	}
	Kill();
}

void Aste_Asteroid::Update()
{
	setPosition(getPosition() + getVelocity() * MainTime.GetTimeDeltaF());

	if (getPosition().x < -15)
		setPosition(sf::Vector2f(1920 + 15, getPosition().y));
	else if (getPosition().x > 1920 + 15)
		setPosition(sf::Vector2f(-15, getPosition().y));

	if (getPosition().y < -15)
		setPosition(sf::Vector2f(getPosition().x, 1080 + 15));
	else if (getPosition().y > 1080 + 15)
		setPosition(sf::Vector2f(getPosition().x, -15));
}

void Aste_Asteroid::Draw()
{
	sf::CircleShape CAsteroid(getLife() * 10);

	CAsteroid.setOrigin(CAsteroid.getRadius(), CAsteroid.getRadius());
	CAsteroid.setPosition(getPosition());

	App.draw(CAsteroid);
}
