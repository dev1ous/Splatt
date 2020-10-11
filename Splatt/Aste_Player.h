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
	int getScore() const { return m_score; }
	int getLives() const { return m_lives; }

	void AddScore(int);
	void ResetScore();
	void RotateClockWise();
	void RotateConterClockWise();
	void MoveForward();
	void DeathReset();
	void Update();
	void Draw();
	void Shoot();
	void DrawDebug();
};

extern Aste_Player* aste_player;