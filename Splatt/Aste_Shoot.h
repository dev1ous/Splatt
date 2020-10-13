#pragma once
#include "Tools.hpp"

class Aste_Shoot
{
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	bool m_isPlayer;
	bool m_dead;
	float m_distance;

public:
	Aste_Shoot();
	Aste_Shoot(sf::Vector2f pos, bool isPlayer);
	Aste_Shoot(sf::Vector2f pos, float rotation , bool isPlayer);
	~Aste_Shoot();

	sf::Vector2f getPosition() const;
	sf::Vector2f getVelocity() const;
	bool isDead() const;
	bool isPlayer() const {	return m_isPlayer; }

	void Update();
};

extern std::vector<Aste_Shoot> Aste_ShootList;