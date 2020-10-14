#pragma once
#include "Tools.hpp"

class Aste_Explosion
{
	sf::Vector2f m_position;
	sf::IntRect m_rect;
	float m_timer;
	bool m_dead;
	int m_frame;
public:
	Aste_Explosion();
	Aste_Explosion(sf::Vector2f pos);
	~Aste_Explosion();

	bool isDead() const { return m_dead; }
	sf::Vector2f getPosition() const { return m_position; }
	int getFrame() const { return m_frame; }

	void update();
	void draw();
};

extern std::vector<Aste_Explosion> ExplosionList;