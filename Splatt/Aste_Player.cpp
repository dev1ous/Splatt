#include "Aste_Player.h"
#include "Aste_Shoot.h"
#include "Aste_Enemies.h"
#include "Texture_SpriteManager.hpp"
#include "SoundManager.hpp"
#include "Aste_Manager.h"

Aste_Player::Aste_Player()
{
	m_lives = 3;
	m_score = 0;
	m_position = sf::Vector2f(1920 / 2, 1080 / 2);
	m_velocity = sf::Vector2f(0, 0);
	m_rotation = 0.0f;
	m_fireTimer = 0.f;
	m_rect = sf::IntRect(0, 0, 40, 60);
}

Aste_Player::~Aste_Player()
{
}

sf::Vector2f Aste_Player::getPosition() const
{
	return m_position;
}

float Aste_Player::getRotation() const
{
	return m_rotation;
}

void Aste_Player::setFrame(int frame)
{
	m_rect.left = frame * m_rect.width;
}

void Aste_Player::AddScore(int toAdd)
{
	if ((m_score + toAdd) % 10000 < m_score % 10000)
		m_lives++;
	m_score += toAdd;
}

void Aste_Player::ResetScore()
{
	m_score = 0;
}

void Aste_Player::RotateClockWise()
{
	m_rotation += 100 * MainTime.GetTimeDeltaF();
}

void Aste_Player::RotateConterClockWise()
{
	m_rotation -= 100 * MainTime.GetTimeDeltaF();
}

void Aste_Player::MoveForward()
{
	float radiant = (m_rotation - 90) * (pi / 180);

	m_velocity.x += cos(radiant) * 300 * MainTime.GetTimeDeltaF();
	m_velocity.y += sin(radiant) * 300 * MainTime.GetTimeDeltaF();
	setFrame(1);
}

void Aste_Player::DeathReset()
{
	// here
	if (m_lives > 1)
	{
		m_lives--;

		m_position = sf::Vector2f(1920 / 2, 1080 / 2);
		m_velocity = sf::Vector2f(0, 0);
		m_rotation = 0.0f;
		m_fireTimer = 0.f;
	}
}

void Aste_Player::Update()
{
	m_fireTimer += MainTime.GetTimeDeltaF();
	m_position += m_velocity * MainTime.GetTimeDeltaF();
	
	m_velocity.x /= 1 + 0.4 * MainTime.GetTimeDeltaF();
	m_velocity.y /= 1 + 0.4 * MainTime.GetTimeDeltaF();

	if ((m_velocity.x < 0.001f && m_velocity.x > -0.001f) && (m_velocity.y < 0.001f && m_velocity.y > -0.001f))
	{
		m_velocity.x = 0;
		m_velocity.y = 0;
	}

	if (m_position.x < -15)
		m_position.x = 1920 + 15;
	else if (m_position.x > 1920 + 15)
		m_position.x = -15;

	if (m_position.y < -15)
		m_position.y = 1080 + 15;
	else if (m_position.y > 1080 + 15)
		m_position.y = -15;

	for (Aste_Enemies* ActualEnemie : EnemiesList)
	{
		int ennemie_rad = ActualEnemie->getLife() * 10;
		if (Circle_Collision(m_position, ActualEnemie->getPosition(), getSprite("astePlayer").getLocalBounds().width / 2, ennemie_rad))
		{

			if (m_lives > 1)
			{
				ActualEnemie->RemoveLife();
				
				DeathReset();
			}
			else
			{
				Reset();
			}
			break;
		}
	}
}

void Aste_Player::Draw()
{
	getSprite("astePlayer").setTextureRect(m_rect);
	getSprite("astePlayer").setRotation(0);
	getSprite("astePlayer").setOrigin(getSprite("astePlayer").getGlobalBounds().width / 2, getSprite("astePlayer").getGlobalBounds().height / 2);
	getSprite("astePlayer").setPosition(aste_player->getPosition());
	getSprite("astePlayer").setRotation(aste_player->getRotation());

	App.draw(getSprite("astePlayer"));
}

void Aste_Player::Shoot()
{
	if (m_fireTimer >= 0.3)
	{
		m_fireTimer = 0;
		Aste_ShootList.push_back(Aste_Shoot(getPosition(), m_rotation, true));
		getSound("Shoot").play();
	}
}

void Aste_Player::DrawDebug()
{
	sf::CircleShape Colision(getSprite("astePlayer").getLocalBounds().width / 2);
	Colision.setOrigin(Colision.getRadius(), Colision.getRadius());
	Colision.setPosition(getPosition());

	Colision.setFillColor(sf::Color::Transparent);
	Colision.setOutlineThickness(1);
	Colision.setOutlineColor(sf::Color::Red);
	App.draw(Colision);


	sf::RectangleShape Dir(sf::Vector2f(1, Colision.getRadius()));
	Dir.setPosition(getPosition());
	float angle = (double)Angle_calc(m_position, m_position + m_velocity) * 180 / pi;
	Dir.setRotation(angle - 90);
	App.draw(Dir);
}
