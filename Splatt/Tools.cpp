#include "Tools.hpp"
#include "StateManager.hpp"

Times MainTime;
sf::Font font;


int irandom(int Min, int Max)
{
	return rand() % (Max - Min) + Min;
}

double frandom(float Min, float Max)
{
	return ((rand() / (double)RAND_MAX) * ((double)Max - (double)Min) + (double)Min);
}

bool Circle_Collision(sf::Vector2f Pos1, sf::Vector2f Pos2, float Rayon1, float Rayon2)
{
	if (sqrt(pow(Pos1.x - Pos2.x, 2) + pow(Pos1.y - Pos2.y, 2)) < Rayon1 + Rayon2)
	{
		return true;
	}
	else return false;
}

float Angle_calc(sf::Vector2f pointA, sf::Vector2f pointB)
{
	float angle;
	if (pointA.y < pointB.y)
		angle = (float)acos(((double)pointB.x - pointA.x) / (sqrt(pow((double)pointB.x - pointA.x, 2) + pow((double)pointB.y - pointA.y, 2))));
	else
		angle = (float)-acos(((double)pointB.x - pointA.x) / (sqrt(pow((double)pointB.x - pointA.x, 2) + pow((double)pointB.y - pointA.y, 2))));

	return angle;
}

sf::Vector2f getMidle(sf::Sprite& _o)
{
	return sf::Vector2f(_o.getGlobalBounds().width / 2, _o.getGlobalBounds().height / 2);
}

sf::Vector2f getMidle(sf::RectangleShape& _o)
{
	return sf::Vector2f(_o.getGlobalBounds().width / 2, _o.getGlobalBounds().height / 2);
}

sf::Vector2f getMidle(sf::Text& _o)
{
	return sf::Vector2f(_o.getLocalBounds().left + _o.getLocalBounds().width / 2, _o.getLocalBounds().top + _o.getLocalBounds().height / 2);
}




void LaunchArguments(int argc, char** argv)
{
	int i = 0;

	while (argv[++i])
	{
		std::cout << argv[i] << std::endl;

		if (std::string(argv[i]) == "-asteroid")
			ChangeState(State::ASTEROID);
		else if(std::string(argv[i]) == "-Lunar")
			ChangeState(State::LUNAR_LANDER);
		else if(std::string(argv[i]) == "-SpaceI")
			ChangeState(State::SPACE_INVADER);
		else if (std::string(argv[i]) == "-PacMan")
			ChangeState(State::PACMAN);
	}

}

void ProgramEnd()
{

}