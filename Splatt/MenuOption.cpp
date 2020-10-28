#include "MenuManager.h"
#include "SoundManager.hpp"
#include "Texture_SpriteManager.hpp"
#include "Controles.h"

int OptionChoice = 1;
extern bool isOption;
int Windowchoice = 2;
int PrevWindowchoice = 2;

void MenuOptionUpdate()
{
	static float menuTimer = 0.f;
	menuTimer += MainTime.GetTimeDeltaF();

	if (isButtonPressed(Action::UP) && menuTimer >= 0.3)
	{
		menuTimer = 0;

		if (OptionChoice > 1)
			OptionChoice--;
		else
			OptionChoice = 3;
	}

	if (isButtonPressed(Action::Down) && menuTimer >= 0.3)
	{
		menuTimer = 0;

		if (OptionChoice < 4)
			OptionChoice++;
		else
			OptionChoice = 1;
	}

	if (isButtonPressed(Action::Left) && menuTimer >= 0.15)
	{
		menuTimer = 0;

		switch (OptionChoice)
		{
		case 1:
			if (MusicMultip > 0)
				MusicMultip--;
			break;

		case 2:
			if (SoundMultip > 0)
				SoundMultip--;
			break;

		case 3:
			menuTimer = -0.5f;
			if (Windowchoice > 0)
				Windowchoice--;
			else
				Windowchoice = 2;
			break;

		case 4:
			menuTimer = -0.25f;
			isVSync = !isVSync;
			break;

		default:
			break;
		}
	}

	if (isButtonPressed(Action::Right) && menuTimer >= 0.15)
	{
		menuTimer = 0;

		switch (OptionChoice)
		{
		case 1:
			if (MusicMultip < 100)
				MusicMultip++;
			break;

		case 2:
			if (SoundMultip < 100)
				SoundMultip++;
			break;

		case 3:
			menuTimer = -0.5f;
			if (Windowchoice < 2)
				Windowchoice++;
			else
				Windowchoice = 0;
			break;

		case 4:
			menuTimer = -0.25f;
			isVSync = !isVSync;
			break;

		default:
			break;
		}
	}
}

void MenuOptionDisplay(const int& x)
{
	getSprite("OptionBack").setScale(1.55, 1.55);
	getSprite("OptionBack").setPosition(x, 0);
	App.draw(getSprite("OptionBack"));

	sf::RectangleShape BackgroundBars(sf::Vector2f(500, 30));
	sf::RectangleShape Bars(sf::Vector2f(0, 30));
	sf::Text Values("", font, 35);
	sf::Text Title("", font, 35);

	BackgroundBars.setFillColor(sf::Color::Color(0, 0, 0, 25));
	BackgroundBars.setOutlineThickness(1);
	BackgroundBars.setOutlineColor(sf::Color::Black);
	BackgroundBars.setOrigin(getMidle(BackgroundBars));

	Bars.setFillColor(sf::Color::Color(sf::Color::Red));
	Values.setFillColor(sf::Color::White);
	Title.setFillColor(sf::Color::White);



	// MUSIC
	Title.setString("Music Volume");
	Values.setString(std::to_string(MusicMultip));
	Bars.setSize(sf::Vector2f(500 * (MusicMultip / 100.f), 30));
	Values.setOrigin(getMidle(Values));
	Bars.setOrigin(0, Bars.getSize().y / 2);
	Title.setOrigin(0, Title.getLocalBounds().top + Title.getLocalBounds().height / 2);

	BackgroundBars.setPosition(x + ((1920 - x) / 2), 315 + (61 * 1));
	Bars.setPosition(BackgroundBars.getPosition().x - BackgroundBars.getOrigin().x, BackgroundBars.getPosition().y - BackgroundBars.getOutlineThickness());
	Values.setPosition(BackgroundBars.getPosition().x, BackgroundBars.getPosition().y);
	Title.setPosition(BackgroundBars.getPosition().x - BackgroundBars.getSize().x / 2 - (Title.getLocalBounds().left + Title.getLocalBounds().width) - 15, BackgroundBars.getPosition().y);

	Title.setFillColor(sf::Color::White);
	if (isOption && OptionChoice == 1)
		Title.setFillColor(sf::Color::Red);

	App.draw(Title);
	App.draw(BackgroundBars);
	App.draw(Bars);
	App.draw(Values);



	// SFX
	Title.setString("SFX Volume");
	Values.setString(std::to_string(SoundMultip));
	Bars.setSize(sf::Vector2f(500 * (SoundMultip / 100.f), 30));
	Values.setOrigin(getMidle(Values));
	Bars.setOrigin(0, Bars.getSize().y / 2);
	Title.setOrigin(0, Title.getLocalBounds().top + Title.getLocalBounds().height / 2);

	BackgroundBars.setPosition(x + ((1920 - x) / 2), 315 + (61 * 2));
	Bars.setPosition(BackgroundBars.getPosition().x - BackgroundBars.getOrigin().x, BackgroundBars.getPosition().y - BackgroundBars.getOutlineThickness());
	Values.setPosition(BackgroundBars.getPosition().x, BackgroundBars.getPosition().y);
	Title.setPosition(BackgroundBars.getPosition().x - BackgroundBars.getSize().x / 2 - (Title.getLocalBounds().left + Title.getLocalBounds().width) - 15, BackgroundBars.getPosition().y);

	Title.setFillColor(sf::Color::White);
	if (isOption && OptionChoice == 2)
		Title.setFillColor(sf::Color::Red);

	App.draw(Title);
	App.draw(BackgroundBars);
	App.draw(Bars);
	App.draw(Values);


	// Window
	Title.setString("Window Type");
	Title.setOrigin(getMidle(Title));
	Title.setPosition(x + ((1920 - x) / 2), 315 + (61 * 3));
	Title.setFillColor(sf::Color::White);
	App.draw(Title);

	sf::Text TUseWindow("", font, 35);
	TUseWindow.setFillColor(sf::Color::White);
	if (isOption && OptionChoice == 3)
		TUseWindow.setFillColor(sf::Color::Red);

	switch (Windowchoice)
	{
	case 0:

		TUseWindow.setString("Window");
		TUseWindow.setCharacterSize(60.f);
		TUseWindow.setOrigin(getMidle(TUseWindow));
		TUseWindow.setPosition(x + ((1920 - x) / 2), 315 + 61 * 4);
		App.draw(TUseWindow);

		Title.setFillColor(sf::Color::Color(100, 100, 100));
		Title.setString("FullScreen");
		Title.setCharacterSize(30.f);
		Title.setOrigin(getMidle(Title).x * 2, getMidle(Title).y);
		Title.setPosition(TUseWindow.getGlobalBounds().left - 20, 315 + 61 * 4);
		App.draw(Title);

		Title.setFillColor(sf::Color::Color(100, 100, 100));
		Title.setString("Window FullScreen");
		Title.setCharacterSize(30.f);
		Title.setOrigin(0, getMidle(Title).y);
		Title.setPosition(TUseWindow.getGlobalBounds().left + TUseWindow.getGlobalBounds().width + 20, 315 + 61 * 4);
		App.draw(Title);
		break;
	case 1:
		TUseWindow.setString("Window FullScreen");
		TUseWindow.setCharacterSize(60.f);
		TUseWindow.setOrigin(getMidle(TUseWindow));
		TUseWindow.setPosition(x + ((1920 - x) / 2), 315 + 61 * 4);
		App.draw(TUseWindow);

		Title.setFillColor(sf::Color::Color(100, 100, 100));
		Title.setString("Window");
		Title.setCharacterSize(30.f);
		Title.setOrigin(getMidle(Title).x * 2, getMidle(Title).y);
		Title.setPosition(TUseWindow.getGlobalBounds().left - 20, 315 + 61 * 4);
		App.draw(Title);

		Title.setFillColor(sf::Color::Color(100, 100, 100));
		Title.setString("FullScreen");
		Title.setCharacterSize(30.f);
		Title.setOrigin(0, getMidle(Title).y);
		Title.setPosition(TUseWindow.getGlobalBounds().left + TUseWindow.getGlobalBounds().width + 20, 315 + 61 * 4);
		App.draw(Title);
		break;
	case 2:
		TUseWindow.setString("FullScreen");
		TUseWindow.setCharacterSize(60.f);
		TUseWindow.setOrigin(getMidle(TUseWindow));
		TUseWindow.setPosition(x + ((1920 - x) / 2), 315 + 61 * 4);
		App.draw(TUseWindow);

		Title.setFillColor(sf::Color::Color(100, 100, 100));
		Title.setString("Window FullScreen");
		Title.setCharacterSize(30.f);
		Title.setOrigin(getMidle(Title).x * 2, getMidle(Title).y);
		Title.setPosition(TUseWindow.getGlobalBounds().left - 20, 315 + 61 * 4);
		App.draw(Title);

		Title.setFillColor(sf::Color::Color(100, 100, 100));
		Title.setString("Window");
		Title.setCharacterSize(30.f);
		Title.setOrigin(0, getMidle(Title).y);
		Title.setPosition(TUseWindow.getGlobalBounds().left + TUseWindow.getGlobalBounds().width + 20, 315 + 61 * 4);
		App.draw(Title);
		break;

	default:
		break;
	}


	// VSync
	Title.setString("VSync");
	Title.setOrigin(getMidle(Title));
	Title.setPosition(x + ((1920 - x) / 2), 315 + (61 * 5));
	Title.setFillColor(sf::Color::White);
	App.draw(Title);

	if (isVSync)
	{
		Title.setFillColor(sf::Color::Color(sf::Color::White));
		if (isOption && OptionChoice == 4)
			Title.setFillColor(sf::Color::Red);
		Title.setString("Actif");
		Title.setCharacterSize(60.f);
		Title.setOrigin(getMidle(Title));
		Title.setPosition(x + ((1920 - x) / 2), 315 + 61 * 6);
		App.draw(Title);

		Title.setPosition(Title.getGlobalBounds().left + Title.getGlobalBounds().width + 20, 315 + 61 * 6);
		Title.setFillColor(sf::Color::Color(100, 100, 100));
		Title.setString("Inactif");
		Title.setCharacterSize(30.f);
		Title.setOrigin(0, getMidle(Title).y);
		App.draw(Title);
	}
	else
	{
		Title.setFillColor(sf::Color::Color(sf::Color::White));
		if (isOption && OptionChoice == 4)
			Title.setFillColor(sf::Color::Red);
		Title.setString("Inactif");
		Title.setCharacterSize(60.f);
		Title.setOrigin(getMidle(Title));
		Title.setPosition(x + ((1920 - x) / 2), 315 + 61 * 6);
		App.draw(Title);

		Title.setPosition(Title.getGlobalBounds().left + Title.getGlobalBounds().width + 20, 315 + 61 * 6);
		Title.setFillColor(sf::Color::Color(100, 100, 100));
		Title.setString("Actif");
		Title.setCharacterSize(30.f);
		Title.setOrigin(0, getMidle(Title).y);
		App.draw(Title);
	}
}

void OptionRead()
{
	std::ifstream OptionFile("../Ressources/Infos/Settings.bin");
	if (OptionFile.is_open())
	{
		OptionFile.read((char*)&MusicMultip, sizeof(int));
		OptionFile.read((char*)&SoundMultip, sizeof(int));
		OptionFile.read((char*)&Windowchoice, sizeof(int));
		OptionFile.read((char*)&isVSync, sizeof(bool));

		App.setVerticalSyncEnabled(isVSync);

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

void OptionSave()
{
	std::ofstream OptionFile("../Ressources/Infos/Settings.bin");
	if (OptionFile.is_open())
	{
		OptionFile.write((char*)&MusicMultip, sizeof(int));
		OptionFile.write((char*)&SoundMultip, sizeof(int));
		OptionFile.write((char*)&Windowchoice, sizeof(int));
		OptionFile.write((char*)&isVSync, sizeof(bool));
	}
}