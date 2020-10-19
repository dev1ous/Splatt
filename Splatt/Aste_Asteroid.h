#pragma once
#include "Aste_Enemies.h"

class Aste_Asteroid : public Aste_Enemies
{
	int m_spriteType;

public:
	Aste_Asteroid();
	Aste_Asteroid(sf::Vector2f position, float rotation, int life);
	~Aste_Asteroid();

	virtual void RemoveLife();
	virtual bool Update();
	virtual void Draw();
	virtual void DrawDebug();
};

