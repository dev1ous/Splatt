#pragma once
#include "Aste_Enemies.h"

class Aste_BigSaucer : public Aste_Enemies
{
	float m_shoot_timer;

public:
	Aste_BigSaucer();
	Aste_BigSaucer(sf::Vector2f position, float rotation);
	~Aste_BigSaucer();

	virtual void RemoveLife();
	virtual bool Update();
	virtual void Draw();
	virtual void DrawDebug();

};

