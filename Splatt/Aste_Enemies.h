#pragma once
#include "Tools.hpp"

class Aste_Enemies
{
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	int m_life;
	float m_rotation;

protected:
	sf::Vector2f getVelocity() const;

	void setPosition(sf::Vector2f);
	void setVelocity(sf::Vector2f);

public:
	Aste_Enemies();
	Aste_Enemies(sf::Vector2f position, float rotation, int life);
	~Aste_Enemies();

	void Kill() { m_life = 0; };
	sf::Vector2f getPosition() const;
	int getLife() const;
	virtual void RemoveLife();
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void DrawDebug() = 0;
};

extern std::vector<Aste_Enemies*> EnemiesList;

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
 pv :
  3          2          1
 (grand -> 2moyen -> 4petit)
 (moyen -> 2petit)
 (petit = disparition)

- Enemies Mecanique (saucer)
 - small shoot at random "slowly"
 - big shoot at player "rapidely"
 - big don't appears after 40'000 points
*/