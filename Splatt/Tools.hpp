#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <list>
#include <math.h>

#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286

extern sf::RenderWindow App;
extern bool isVSync;
extern sf::Event event;
extern sf::Font font;

/////////////
/// \brief Class for Time
/////////////
class Times
{
public:
	Times() { m_fDeltaTime = 0; };
	~Times() {};

	/////////////
	/// \brief Get the elapsed time between to restart in second
	/// \return float : elaped time
	/////////////
	float GetTimeDeltaF() const { return m_fDeltaTime; };

	/////////////
	/// \brief Get the time of the last to restart
	/// \return sf::Time
	/////////////
	sf::Time GetTimeDeltaT() const { return m_tDeltaTime; };

	/////////////
	/// \brief Reset the clock to now and add elapsed time to variables
	/////////////
	void RestartClock() { m_tDeltaTime = m_Time.restart(); m_fDeltaTime = m_tDeltaTime.asSeconds(); };

private:
	float m_fDeltaTime;
	sf::Time m_tDeltaTime;
	sf::Clock m_Time;
};
extern Times MainTime;




/////////////
/// \brief Function for looking lauching arguments
/// \param argc : Number of parameters
/// \param argv : Array of pointers for a line
/////////////
void LaunchArguments(int argc, char** argv);

/////////////
/// \brief Function for when the program end
/////////////
void ProgramEnd();



/////////////
/// \brief get a random int beetween the min and max
/// \param Min : int
/// \param Max : int
/// \return int : random int
/////////////
int irandom(int Min, int Max);

/////////////
/// \brief get a random float beetween the min and max
/// \param Min : float
/// \param Max : float
/// \return double : random float / double
/////////////
double frandom(float Min, float Max);

/////////////
/// \brief Check if two cercle are inside each others
/// \param Pos1 : position of the center of the first circle
/// \param Pos2 : position of the center of the seconde circle
/// \param Rayon1 : rayon of the center of the first circle
/// \param Rayon2 : rayon of the center of the seconde circle
/// \return bool : true if they are inside each other
/////////////
bool Circle_Collision(sf::Vector2f _pos1, sf::Vector2f _pos2, float _rayon1, float _rayon2);

/////////////
/// \brief get the rotation beetween two points
/// \param pointA : sf::Vector2f
/// \param pointB : sf::Vector2f
/// \return float : rotation
/////////////
float Angle_calc(sf::Vector2f pointA, sf::Vector2f pointB);

sf::Vector2f getMidle(sf::Sprite& _o);
sf::Vector2f getMidle(sf::RectangleShape& _o);
sf::Vector2f getMidle(sf::Text& _o);
float lerp(float a, float b, float f);