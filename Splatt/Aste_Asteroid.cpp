#include "Aste_Asteroid.h"
#include "Aste_Player.h"
#include "Texture_SpriteManager.hpp"

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
	if (getLife() == 3)
		aste_player->AddScore(20);
	else if (getLife() == 2)
		aste_player->AddScore(50);
	else if (getLife() == 1)
		aste_player->AddScore(100);

	if (getLife() > 1)
	{
		float rotate1(frandom(0,360));
		float rotate2(frandom(0, 360));
		EnemiesList.push_back(new Aste_Asteroid(getPosition(), rotate1, getLife() -1));
		EnemiesList.push_back(new Aste_Asteroid(getPosition(), rotate2, getLife() -1));
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
	getSprite("Asteroid").setTextureRect(sf::IntRect(0,0,60,60));
	
	switch (getLife())
	{
	case 3:
		getSprite("Asteroid").setScale(1.f, 1.f);
		break;
	case 2:
		getSprite("Asteroid").setScale(0.666f, 0.666f);
		break;
	case 1:
		getSprite("Asteroid").setScale(0.333f, 0.333f);
		break;
	default:
		break;
	}
	getSprite("Asteroid").setOrigin(getSprite("Asteroid").getGlobalBounds().width / 2, getSprite("Asteroid").getGlobalBounds().width / 2);
	getSprite("Asteroid").setPosition(getPosition());

	App.draw(getSprite("Asteroid"));
}