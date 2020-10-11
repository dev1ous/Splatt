#pragma once
#include "Aste_Enemies.h"

class Aste_Asteroid : public Aste_Enemies
{
public:
	Aste_Asteroid();
	Aste_Asteroid(sf::Vector2f position, float rotation, int life);
	~Aste_Asteroid();

	virtual void RemoveLife();
	virtual void Update();
	virtual void Draw();
	virtual void DrawDebug();
};

