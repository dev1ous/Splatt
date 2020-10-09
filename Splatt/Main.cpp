#include "Tools.hpp"
#include "StateManager.hpp"

sf::RenderWindow App(sf::VideoMode(1920, 1080), "Splatt");
sf::Event event;

int main(int argc, char** argv)
{
	srand(time(NULL));
	LaunchArguments(argc, argv);
	Font.loadFromFile("../Ressources/times.ttf");

	while (App.isOpen())
	{
		EventsManager();
		UpdateManager();
		DisplayManager();
	}
		
	ProgramEnd();

	return 0;
}