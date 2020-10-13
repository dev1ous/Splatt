#pragma once
#include "Tools.hpp"

class Aste_Explosion
{
	sf::Vector2f m_position;
	sf::IntRect m_rect;
	float m_timer;
	bool m_dead;

public:
	Aste_Explosion();
	Aste_Explosion(sf::Vector2f pos);
	~Aste_Explosion();

	bool isDead() const { return m_dead; }
	sf::Vector2f getPosition() const { return m_position; }

	void update();
	void draw();
};

extern std::vector<Aste_Explosion> ExplosionList;