#include "Aste_Enemies.h"

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
	m_life--;
}

Aste_Enemies::Aste_Enemies()
{
}

Aste_Enemies::Aste_Enemies(sf::Vector2f position, sf::Vector2f velocity, int life)
	: m_pos(position), m_velocity(velocity), m_life(life)
{
}

Aste_Enemies::~Aste_Enemies()
{
}
