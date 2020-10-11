#include "StateManager.hpp"
#include "Aste_Manager.h"
#include "Lunar_manager.h"

State state = State::MENU;

Lunar_manager* l_manager = new Lunar_manager;

void EventsManager()
{
	while (App.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			App.close();
	}
}


void UpdateManager()
{
	//restart of the clock (time per frame)
	MainTime.RestartClock();

	switch (state)
	{
	case State::RTNULL:
		break;
	case State::MENU:
		break;
	case State::SPACE_INVADER:
		break;
	case State::PACMAN:
		break;
	case State::LUNAR_LANDER:
		l_manager->Lunar_update();
		break;
	case State::ASTEROID:
		Aste_Update();
		break;
	case State::TETRIS:
		break;
	case State::TRON:
		break;

	default:
		break;
	}
}


void DisplayManager()
{
	// Clear the Window
	App.clear(sf::Color::Black);

	switch (state)
	{
	case State::RTNULL:
		break;
	case State::MENU:
		break;
	case State::SPACE_INVADER:
		break;
	case State::PACMAN:
		break;
	case State::LUNAR_LANDER:
		l_manager->Lunar_display(App);
		break;
	case State::ASTEROID:
		Aste_Display();
		break;
	case State::TETRIS:
		break;
	case State::TRON:
		break;

	default:
		break;
	}

	// Display on window
	App.display();
}