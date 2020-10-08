#pragma once
#include "Tools.hpp"

class Aste_Player
{
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	float m_fireTimer;
	int m_score;
	int m_lives;
	float m_rotation;

public:
	Aste_Player();
	~Aste_Player();

	sf::Vector2f getPosition() const;
	float getRotation() const;

	void RotateClockWise();
	void RotateConterClockWise();
	void MoveForward();
	void Update();
	void Shoot();
};