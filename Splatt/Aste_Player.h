#pragma once
#include "Tools.hpp"

class Aste_Player
{
	sf::Vector2f m_position;
	sf::Vector2f velocity;
	float m_fireTimer;
	int m_score;
	int m_lives;
	float m_rotation;

public:
	Aste_Player();
	~Aste_Player();
};

