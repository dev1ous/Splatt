#pragma once
#include "Tools.hpp"

class Aste_Enemies
{
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	int m_life;

protected:
	sf::Vector2f getPosition() const;
	sf::Vector2f getVelocity() const;
	int getLife() const;

	void setPosition(sf::Vector2f);
	void setVelocity(sf::Vector2f);
	void RemoveLife();
public:
	Aste_Enemies(sf::Vector2f position, sf::Vector2f velocity, int life);
	~Aste_Enemies();
};



/*
Asteroïd

- black background

- player : ship
	- position
	- velocity
	- fire timer
	- score
	- lives
	- rotation

- enemies :
	- global :
		- position
		- lives
		- velocity

	- asteroid :
		-

	- small saucer :
		- shoot timer
		- shoot function

	- big saucer :
		- shoot timer
		- shoot function


- World Mecanique
 - switch of right side to left when left screen

- Player Mecanique
 - Shoot
 - Move
 - Velocity reduction
 - Start with 3 lives
 - Earn a live every 10'000

- Enemies Mecanique (asteroid)
 - Divide on death

- Enemies Mecanique (saucer)
 - small shoot at random "slowly"
 - big shoot at player "rapidely"
 - big don't appears after 40'000 points
*/