#include "StateManager.hpp"

State state = State::MENU;


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
		break;
	case State::ASTEROID:
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
		break;
	case State::ASTEROID:
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