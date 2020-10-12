#include "Aste_Shoot.h"
#include "Aste_Enemies.h"
#include "Aste_Player.h"
#include "Texture_SpriteManager.hpp"

std::vector<Aste_Shoot> Aste_ShootList;

Aste_Shoot::Aste_Shoot()
{
	m_velocity = sf::Vector2f(0, 0);
	m_dead = false;
	m_isPlayer = true;
	m_distance = 0;
}

Aste_Shoot::Aste_Shoot(sf::Vector2f position, bool isplayer) : m_pos(position), m_isPlayer(isplayer)
{
	m_velocity = sf::Vector2f(0, 0);
	m_dead = false;
	m_distance = 0;
}

Aste_Shoot::Aste_Shoot(sf::Vector2f position, float rotation, bool isplayer) : m_pos(position), m_isPlayer(isplayer)
{
	float radiant = (rotation - 90) * (pi / 180);
	m_velocity.x += cos(radiant) * 500;
	m_velocity.y += sin(radiant) * 500;

	m_dead = false;
	m_distance = 0;
}

Aste_Shoot::~Aste_Shoot()
{

}

sf::Vector2f Aste_Shoot::getPosition() const
{
	return m_pos;
}

sf::Vector2f Aste_Shoot::getVelocity() const
{
	return m_velocity;
}

bool Aste_Shoot::isDead() const
{
	return m_dead;
}

void Aste_Shoot::Update()
{
	m_pos += m_velocity * MainTime.GetTimeDeltaF();

	m_distance += abs(m_velocity.x) * MainTime.GetTimeDeltaF();
	m_distance += abs(m_velocity.y) * MainTime.GetTimeDeltaF();

	if (m_pos.x < -15)
		m_pos.x = 1920 + 15;
	else if (m_pos.x > 1920 + 15)
		m_pos.x = -15;

	if (m_pos.y < -15)
		m_pos.y = 1080 + 15;
	else if (m_pos.y > 1080 + 15)
		m_pos.y = -15;

	if (m_distance >= 1100.f)
		m_dead = true;


	if (!m_dead)
	{
		// balle joueur -> enemies
		if (m_isPlayer)
		{
			for (Aste_Enemies* ActualEnemie : EnemiesList)
			{
				int ennemie_rad = ActualEnemie->getLife() * 10;
				if (Circle_Collision(m_pos, ActualEnemie->getPosition(), 3, ennemie_rad))
				{
					m_dead = true;
					ActualEnemie->RemoveLife();
					break;
				}
			}
		}
		// balle enemies -> joueur
		else
		{
			if (Circle_Collision(m_pos, aste_player->getPosition(), 3, getSprite("astePlayer").getLocalBounds().width / 2))
			{
				m_dead = true;
				aste_player->DeathReset();
			}
		}
	}
}

