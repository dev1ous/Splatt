#include "Aste_Player.h"
#include "Aste_Shoot.h"

Aste_Player::Aste_Player()
{
	m_lives = 3;
	m_score = 0;
	m_position = sf::Vector2f(1920 / 2, 1080 / 2);
	m_velocity = sf::Vector2f(0, 0);
	m_rotation = 0.0f;
	m_fireTimer = 0.f;
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

void Aste_Player::RotateClockWise()
{
	m_rotation += 90 * MainTime.GetTimeDeltaF();
}

void Aste_Player::RotateConterClockWise()
{
	m_rotation -= 90 * MainTime.GetTimeDeltaF();
}

void Aste_Player::MoveForward()
{
	float radiant = (m_rotation - 90) * (pi / 180);
	m_position.x += cos(radiant) * (200 * MainTime.GetTimeDeltaF());
	m_position.y += sin(radiant) * (200 * MainTime.GetTimeDeltaF());

	m_velocity.x = cos(radiant) * 200;
	m_velocity.y = sin(radiant) * 200;
}

void Aste_Player::Update()
{
	m_fireTimer += MainTime.GetTimeDeltaF();
	m_position += m_velocity * MainTime.GetTimeDeltaF();
	
	m_velocity.x /= 1 + 0.4 * MainTime.GetTimeDeltaF();
	m_velocity.y /= 1 + 0.4 * MainTime.GetTimeDeltaF();

	if (m_position.x < -15)
		m_position.x = 1920 + 15;
	else if (m_position.x > 1920 + 15)
		m_position.x = -15;

	if (m_position.y < -15)
		m_position.y = 1080 + 15;
	else if (m_position.y > 1080 + 15)
		m_position.y = -15;
}

void Aste_Player::Shoot()
{
	if (m_fireTimer >= 0.3)
	{
		m_fireTimer = 0;
		Aste_ShootList.push_back(Aste_Shoot(getPosition(), m_rotation, true));
	}
}
