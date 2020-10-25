#include "Tools.hpp"
#include "StateManager.hpp"
#include "RessourcesManager.hpp"
#include "Controles.h"
#include "SoundManager.hpp"
#include "Texture_SpriteManager.hpp"

sf::RenderWindow App(sf::VideoMode(1920, 1080), "Splatt", sf::Style::Fullscreen);
sf::Event event;

int main(int argc, char** argv)
{
	App.setFramerateLimit(240);
	srand(time(NULL));
	font.loadFromFile("../Ressources/times.ttf");

	InitControles();
	RessourcesLoad("../Ressources/Asteroid/");
	RessourcesLoad("../Ressources/Space Invaders/");
	RessourcesLoad("../Ressources/PacMan/");
	LaunchArguments(argc, argv);

	LoadSounds(State::ALL);
	LoadSprite(State::ALL);

	while (App.isOpen())
	{
		EventsManager();
		UpdateManager();
		DisplayManager();
	}
		
	ProgramEnd();

	return 0;
}