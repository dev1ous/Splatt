#include "Aste_Enemies.h"

std::vector<Aste_Enemies*> EnemiesList;

sf::Vector2f Aste_Enemies::getPosition() const
{
	return m_pos;
}

sf::Vector2f Aste_Enemies::getVelocity() const
{
	return m_velocity;
}

int Aste_Enemies::getLife() const
{
	return m_life;
}

void Aste_Enemies::setPosition(sf::Vector2f pos)
{
	m_pos = pos;
}

void Aste_Enemies::setVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
}

void Aste_Enemies::RemoveLife()
{
	m_life = 0;
}

Aste_Enemies::Aste_Enemies()
{
}

Aste_Enemies::Aste_Enemies(sf::Vector2f position, float rotation, int life)
	: m_pos(position), m_rotation(rotation), m_life(life)
{
	float radiant = (m_rotation - 90) * (pi / 180);
	m_velocity.x = cos(radiant) * 200;
	m_velocity.y = sin(radiant) * 200;

}

Aste_Enemies::~Aste_Enemies()
{
}
