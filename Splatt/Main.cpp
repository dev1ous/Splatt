#include "Tools.hpp"
#include "StateManager.hpp"
#include "RessourcesManager.hpp"

sf::RenderWindow App(sf::VideoMode(1920, 1080), "Splatt");
sf::Event event;

int main(int argc, char** argv)
{
	App.setFramerateLimit(240);
	srand(time(NULL));
	Font.loadFromFile("../Ressources/times.ttf");

	RessourcesLoad("../Ressources/Asteroid/");
	LaunchArguments(argc, argv);

	while (App.isOpen())
	{
		EventsManager();
		UpdateManager();
		DisplayManager();
	}
		
	ProgramEnd();

	return 0;
}