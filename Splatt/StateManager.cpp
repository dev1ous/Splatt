#include "StateManager.hpp"
#include "Aste_Manager.h"
#include "Pac_Manager.h"
#include "Lunar_manager.h"
#include "SI_Manager.h"
#include "SoundManager.hpp"
#include "Texture_SpriteManager.hpp"
#include "SoundManager.hpp"
#include "Controles.h"
#include "TronTools.h"
#include "MenuManager.h"
#include "TronMenu.h"

State state = State::MENU;

Lunar_manager* l_manager;
bool Pause = false;

void EventsManager()
{
	while (App.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			App.close();


		if (event.type == sf::Event::KeyPressed)
			PressedKey.push_back(event.key.code);

		if (event.type == sf::Event::KeyReleased)
			PressedKey.remove(event.key.code);
		
		for (int i = 0; i < 8; i++)
			GamepadManager(i, event);
	}
}

void ChangeState(State NextState)
{
	RemoveAllSounds();
	RemoveAllSprites();

	state = NextState;

	LoadSounds(NextState);
	LoadSprite(NextState);
}

void UpdateManager()
{
	static bool one = false;
	if (!one)
	{
		l_manager = new Lunar_manager(App);
		one = true;
	}

	//restart of the clock (time per frame)
	MainTime.RestartClock();

	for (SSound& ActualSound : SoundList)
		ActualSound.update();

	for (Musics* ActualMusic : MusicList)
		ActualMusic->update();

	switch (state)
	{
	case State::RTNULL:
		break;
	case State::MENU:
		Menu_Update();
		break;
	case State::SPACE_INVADER:
		SI_Update();
		break;
	case State::PACMAN:
		Pac_Update();
		break;
	case State::LUNAR_LANDER:
		l_manager->Lunar_update(App);
		break;
	case State::ASTEROID:
		if (!Pause)
			Aste_Update();
		else
			Aste_UpdatePause();
		break;
	case State::TETRIS:
		break;
	case State::TRON:
		if(Pause)
			TronMenuControl();
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
		Menu_Display();
		break;
	case State::SPACE_INVADER:
		SI_Display();
		break;
	case State::PACMAN:
		Pac_Display();
		break;
	case State::LUNAR_LANDER:
		l_manager->Lunar_display(App);
		break;
	case State::ASTEROID:
		Aste_Display();
		if (Pause)
			Aste_DisplayPause();
		break;
	case State::TETRIS:
		break;
	case State::TRON:
		if (Pause)
			TronMenuDisplay();
		else
			TronDisplay();
		break;

	default:
		break;
	}

	// Display on window
	App.display();
}