#pragma once
#include "Aste_Enemies.h"

class Aste_SmallSaucer : public Aste_Enemies
{
	float m_shoot_timer;

public:
	Aste_SmallSaucer();
	Aste_SmallSaucer(sf::Vector2f position, float rotation);
	~Aste_SmallSaucer();

	virtual void RemoveLife();
	virtual bool Update();
	virtual void Draw();
	virtual void DrawDebug();
};

