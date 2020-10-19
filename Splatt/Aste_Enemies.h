#pragma once
#include "Tools.hpp"

enum class EnemiesType
{
	Asteroids,
	Small_Saucer,
	Big_Saucer,
};

class Aste_Enemies
{
	EnemiesType m_type;
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
	Aste_Enemies(EnemiesType type, sf::Vector2f position, float rotation, int life);
	~Aste_Enemies();

	void Kill();
	sf::Vector2f getPosition() const;
	EnemiesType getType() const { return m_type; }
	int getLife() const;
	virtual void RemoveLife();
	virtual bool Update() = 0;
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
 - switch of right side to left when left screen (Done)

- Player Mecanique
 - Shoot					(Done)
 - Move						(Done)
 - Velocity reduction		(Done)
 - Start with 3 lives		(Done)
 - Earn a live every 10'000 (Done)

- Enemies Mecanique (asteroid)
 - Divide on death			    (Done)

- Enemies Mecanique (saucer)
 - can die when hit a asteroid			 (Done)
 - small shoot at player "rapidely"		 (Done)
 - big shoot at random "slowly"			 (Done)
 - big don't appears after 40'000 points (Done)
*/