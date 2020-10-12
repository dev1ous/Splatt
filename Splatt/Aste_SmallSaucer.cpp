#include "Aste_SmallSaucer.h"
#include "Aste_Player.h"
#include "Texture_SpriteManager.hpp"
#include "Aste_Shoot.h"

Aste_SmallSaucer::Aste_SmallSaucer()
{
	m_shoot_timer = 0;
}

Aste_SmallSaucer::Aste_SmallSaucer(sf::Vector2f position, float rotation) : Aste_Enemies(EnemiesType::Small_Saucer, position, rotation, 1)
{
	m_shoot_timer = 0;
}

Aste_SmallSaucer::~Aste_SmallSaucer()
{
}

void Aste_SmallSaucer::RemoveLife()
{
	aste_player->AddScore(1000);
	Kill();
}

void Aste_SmallSaucer::Update()
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

	m_shoot_timer += MainTime.GetTimeDeltaF();
	if (m_shoot_timer >= 1.5f)
	{
		m_shoot_timer = 0;
		float rotation = Angle_calc(aste_player->getPosition(), getPosition()) * 180 / pi;
		Aste_ShootList.push_back(Aste_Shoot(getPosition(), rotation - 90, false));
	}

	for (Aste_Enemies* ActualEnemie : EnemiesList)
	{
		if (ActualEnemie->getType() == EnemiesType::Asteroids)
		{
			int ennemie_rad = ActualEnemie->getLife() * 10;
			if (Circle_Collision(getPosition(), ActualEnemie->getPosition(), getLife() * 10, ennemie_rad))
			{
				ActualEnemie->RemoveLife();
				RemoveLife();
				break;
			}
		}
	}
}

void Aste_SmallSaucer::Draw()
{
	getSprite("alien").setScale(1.f, 1.f);
	getSprite("alien").setOrigin(getSprite("alien").getGlobalBounds().width / 2, getSprite("alien").getGlobalBounds().height / 2);
	getSprite("alien").setPosition(getPosition());
	getSprite("alien").setScale(0.5f, 0.5f);

	App.draw(getSprite("alien"));
}

void Aste_SmallSaucer::DrawDebug()
{
	sf::CircleShape Colision(getLife() * 10);
	Colision.setOrigin(Colision.getRadius(), Colision.getRadius());
	Colision.setPosition(getPosition());

	Colision.setFillColor(sf::Color::Transparent);
	Colision.setOutlineThickness(1);
	Colision.setOutlineColor(sf::Color::Red);
	App.draw(Colision);


	sf::RectangleShape Dir(sf::Vector2f(1, Colision.getRadius()));
	Dir.setPosition(getPosition());
	float angle = (double)Angle_calc(getPosition(), getPosition() + getVelocity()) * 180 / pi;
	Dir.setRotation(angle - 90);
	App.draw(Dir);
}
