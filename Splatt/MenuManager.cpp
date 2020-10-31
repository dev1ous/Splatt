#include "MenuManager.h"
#include "StateManager.hpp"
#include "Controles.h"
#include "Texture_SpriteManager.hpp"
#include "Aste_Manager.h"
#include "TronMenu.h"
#include "Si_Manager.h"

std::vector<std::string> VecMenu;
int choice = 1;
extern int Windowchoice;
extern int PrevWindowchoice;

void Menu_Credits(const int& x)
{
	getSprite("GA").setScale(0.5f, 0.5f);
	getSprite("GA").setOrigin(getMidle(getSprite("GA")));
	getSprite("GA").setPosition(x + ((1920 - x) / 2), 300);
	App.draw(getSprite("GA"));

	sf::Text Credies("", font, 40);
	
	Credies.setString("  Canonge Laurent\tFaltrauer Grégoire");
	Credies.setOrigin(getMidle(Credies));
	Credies.setPosition(x + ((1920 - x) / 2), 450 + (60 * 0));
	App.draw(Credies);

	Credies.setString("      Gonzalez Leo\tMadouche Amine");
	Credies.setOrigin(getMidle(Credies));
	Credies.setPosition(x + ((1920 - x) / 2), 450 + (60 * 1));
	App.draw(Credies);

	Credies.setString("       Maillard Martin\tPelegrin Quentin (?)");
	Credies.setOrigin(getMidle(Credies));
	Credies.setPosition(x + ((1920 - x) / 2), 450 + (60 * 2));
	App.draw(Credies);

	Credies.setString("Renevier Jeremy");
	Credies.setOrigin(getMidle(Credies));
	Credies.setPosition(x + ((1920 - x) / 2), 450 + (60 * 3));
	App.draw(Credies);

}

void Menu_Init()
{
	VecMenu.push_back("Space Invader");
	VecMenu.push_back("PacMan");
	VecMenu.push_back("Lunar Lander");
	VecMenu.push_back("Asteroids");
	VecMenu.push_back("Tetris");
	VecMenu.push_back("Tron");
	VecMenu.push_back("KingKong");
	VecMenu.push_back("Option");
	VecMenu.push_back("Credits");
	VecMenu.push_back("Quit");
}

bool isOption = false;
void Menu_Update()
{
	static bool onepass = false;
	static float menuTimer = 0.f;
	menuTimer += MainTime.GetTimeDeltaF();

	if (!onepass)
	{
		Menu_Init();
		onepass = true;
	}

	if (!isOption)
	{
		if (isButtonPressed(Action::Down) && menuTimer >= 0.3)
		{
			menuTimer = 0;

			if (choice < VecMenu.size())
				choice++;
			else
				choice = 1;
		}

		if (isButtonPressed(Action::UP) && menuTimer >= 0.3)
		{
			menuTimer = 0;

			if (choice > 1)
				choice--;
			else
				choice = VecMenu.size();
		}

		if (isButtonPressed(Action::Interact) && menuTimer >= 0.2)
		{
			menuTimer = 0;

			switch (choice)
			{
			case 1:
				ChangeState(State::SPACE_INVADER);
				break;
			case 2:
				ChangeState(State::PACMAN);
				break;
			case 3:
				ChangeState(State::LUNAR_LANDER);
				break;
			case 4:
				ChangeState(State::ASTEROID);
				break;
			case 5:
				//ChangeState(State::TETRIS);
				break;
			case 6:
				ChangeState(State::TRON);
				Pause = true;
				break;
			case 7:
				//ChangeState(State::);  KingKong
				break;
			case 8:
				isOption = true;
				PrevWindowchoice = Windowchoice;
				break;
			case 9:
				// credits
				break;
			case 10:
				App.close();
				break;

			default:
				break;
			}
		}
	}
	else
	{
		if (isButtonPressed(Action::Escape) && menuTimer >= 0.3)
		{
			OptionSave();
			isOption = false;
			App.setVerticalSyncEnabled(isVSync);
			if (Windowchoice != PrevWindowchoice)
			{
				switch (Windowchoice)
				{
				case 0:
					App.create(sf::VideoMode(1920, 1080), "Splatt", sf::Style::Default);
					break;
				case 1:
					App.create(sf::VideoMode(1920, 1080), "Splatt", sf::Style::None);
					break;
				case 2:
					App.create(sf::VideoMode(1920, 1080), "Splatt", sf::Style::Fullscreen);
					break;
				default:
					break;
				}
			}
		}

		MenuOptionUpdate();
	}
}

void Menu_Display()
{
	sf::Text TMenu("", font, 60);

	int i = 0;
	for (std::string& actu : VecMenu)
	{
		i++;

		if (choice == i)
			TMenu.setFillColor(sf::Color::Red);
		else
			TMenu.setFillColor(sf::Color::White);
			
		TMenu.setString(actu);
		TMenu.setCharacterSize(60.f + (5.f * -abs(i - choice)));
		TMenu.setOrigin(getMidle(TMenu));
		TMenu.setPosition(375.f, 540.f + ((50.f - abs((i - choice)) * 2.75f) * (i - choice)));
		App.draw(TMenu);
	}

	App.draw(getSprite("Main"));

	static const unsigned short int BaseX = 750;

	switch (choice)
	{
	case 1:
		Display_Controle(BaseX);
		break;
	case 2:
		// pacman
		break;
	case 3:
		// lunar
		break;
	case 4:
		Aste_Infos(BaseX);
		break;
	case 5:
		// tetris
		break;
	case 6:
		// tron
		TronTuto();
		break;
	case 7:
		// KingKong
		break;
	case 8:
		MenuOptionDisplay(BaseX);
		break;
	case 9:
		Menu_Credits(BaseX);
		break;
	case 10:
		// idk what to do 
		break;

	default:
		break;
	}
}