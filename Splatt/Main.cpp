#include "Tools.hpp"
#include "StateManager.hpp"
#include "RessourcesManager.hpp"
#include "Controles.h"
#include "SoundManager.hpp"
#include "Texture_SpriteManager.hpp"
#include "MenuManager.h"

sf::RenderWindow App(sf::VideoMode(1920, 1080), "Splatt", sf::Style::Fullscreen);
bool isVSync = false;
sf::Event event;

int main(int argc, char** argv)
{
	App.setFramerateLimit(240);
	App.setVerticalSyncEnabled(isVSync);

	srand(time(NULL));
	font.loadFromFile("../Ressources/times.ttf");

	InitControles();
	RessourcesLoad("../Ressources/Asteroid/");
	RessourcesLoad("../Ressources/Space Invaders/");
	RessourcesLoad("../Ressources/PacMan/");
	RessourcesLoad("../Ressources/Menu/");
	LaunchArguments(argc, argv);

	OptionRead();

	LoadSounds(State::ALL);
	LoadSprite(State::ALL);
	ChangeState(state);

	while (App.isOpen())
	{
		EventsManager();
		UpdateManager();
		DisplayManager();
	}
		
	ProgramEnd();

	return 0;
}