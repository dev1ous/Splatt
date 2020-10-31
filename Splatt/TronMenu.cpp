#include "TronMenu.h"
#include "Controles.h"
#include "TronTools.h"
#include "StateManager.hpp"
#include "TronJoueurs.h"

int TronChoix = 0;
int TronChoixIG = 0;
float TimerTronMenu;
sf::Text tronPlay("JOUER", Tronfont, 80);
sf::Text tronQuit("QUITTER", Tronfont, 80);
sf::Text TronBienvenue("Bienvenue dans la grille programme", Tronfont, 80);
sf::Text TronMiseEnGarde("veuillez commencez un duel ou fuir lachement", Tronfont, 40);
sf::Font Tronfont;
extern Joueurs joueur1;
extern Joueurs joueur2;

void TronMenuInit()
{
	Tronfont.loadFromFile("../Ressources/Tron/Tr2n.ttf");
	TronBienvenue.setOutlineThickness(2);
	TronBienvenue.setPosition(sf::Vector2f(100,40));
	TronMiseEnGarde.setOutlineThickness(2);
	TronMiseEnGarde.setPosition(sf::Vector2f(350, 300));
	tronPlay.setOutlineThickness(2);
	tronPlay.setPosition(sf::Vector2f(1920 / 2, 1080 / 2 - tronPlay.getCharacterSize() / 2));
	tronQuit.setOutlineThickness(2);
	tronQuit.setPosition(sf::Vector2f(1920 / 2, 1080 / 2 + tronQuit.getCharacterSize() / 2));
	tronPlay.setOrigin(sf::Vector2f(tronPlay.getLocalBounds().left + tronPlay.getLocalBounds().width / 2, tronPlay.getLocalBounds().top + tronPlay.getLocalBounds().height / 2));
	tronQuit.setOrigin(sf::Vector2f(tronQuit.getLocalBounds().left + tronQuit.getLocalBounds().width / 2, tronQuit.getLocalBounds().top + tronQuit.getLocalBounds().height / 2));
}

void TronMenuControl()
{
	static bool one_pass = false;
	TimerTronMenu += MainTime.GetTimeDeltaF();
	if (!one_pass)
	{
		TronMenuInit();
		one_pass = true;
	}
	if (isButtonPressed(Action::Down) && TimerTronMenu > 0.5f)
	{
		TronChoix--;
		if (TronChoix < 0)
			TronChoix = 1;
		TimerTronMenu = 0.f;
	}
	if (isButtonPressed(Action::UP) && TimerTronMenu > 0.5f)
	{
		TronChoix++;
		if (TronChoix > 1)
			TronChoix = 0;
		TimerTronMenu = 0.f;
	}
	if (TronChoix == 0)
	{
		tronPlay.setFillColor(sf::Color::Cyan);
		tronQuit.setFillColor(sf::Color::White);
	}
	if (TronChoix == 1)
	{
		tronPlay.setFillColor(sf::Color::White);
		tronQuit.setFillColor(sf::Color::Cyan);
	}
}


void TronMenuDisplay()
{
	sf::Texture textureTronBG;
	textureTronBG.loadFromFile("../Ressources/Tron/TronBackGround2.jpg");
	sf::Sprite spriteTronBG(textureTronBG);

	if (isButtonPressed(Action::Interact) && TimerTronMenu > 0.5f)
	{
		switch (TronChoix)
		{
		case 0:
			TronGame = 1;
			TronInit();
			joueur1.setAddVies();
			joueur2.setAddVies();
			Pause = 0;
			break;
		case 1:
			ChangeState(State::MENU);
			break;
		default:
			break;
		}
		TimerTronMenu = 0.f;
	}
	App.draw(spriteTronBG);
	App.draw(TronBienvenue);
	App.draw(TronMiseEnGarde);
	App.draw(tronPlay);
	App.draw(tronQuit);

}

void TronMenuControlIG()
{
	static float TimerTronMenuIG = 0.f;
	TimerTronMenuIG += MainTime.GetTimeDeltaF();
	if (isButtonPressed(Action::Down) && TimerTronMenuIG > 0.5f)
	{
		TronChoixIG--;
		if (TronChoixIG< 0)
			TronChoixIG= 1;
		TimerTronMenuIG= 0.f;
	}
	if (isButtonPressed(Action::UP) && TimerTronMenuIG> 0.5f)
	{
		TronChoixIG++;
		if (TronChoixIG > 1)
			TronChoixIG= 0;
		TimerTronMenuIG = 0.f;
	}
	if (isButtonPressed(Action::Interact) && TimerTronMenuIG > 0.5f)
	{
		switch (TronChoixIG)
		{
		case 0:
			TronPause = 0;
			break;

		case 1:
			Pause = 1;
			break;

		default:
			break;
		}
		TimerTronMenuIG = 0.f;
	}
}


void TronMenuDisplayIG()
{
	sf::Text TronContinuer("CONTINUER", Tronfont, 50);
	sf::Text TronQuitter("QUITTER", Tronfont, 50);

	TronContinuer.setOutlineThickness(2);
	TronQuitter.setOutlineThickness(2);
	TronContinuer.setPosition(sf::Vector2f(1920 / 2, 1080 / 2 - TronContinuer.getCharacterSize() / 2));
	TronQuitter.setPosition(sf::Vector2f(1920 / 2, 1080 / 2 + TronQuitter.getCharacterSize() / 2));
	TronContinuer.setOrigin(sf::Vector2f(TronContinuer.getLocalBounds().left + TronContinuer.getLocalBounds().width / 2, TronContinuer.getLocalBounds().top + TronContinuer.getLocalBounds().height / 2));
	TronQuitter.setOrigin(sf::Vector2f(TronQuitter.getLocalBounds().left + TronQuitter.getLocalBounds().width / 2, TronQuitter.getLocalBounds().top + TronQuitter.getLocalBounds().height / 2));

	if (TronChoixIG == 0)
	{
		TronContinuer.setFillColor(sf::Color::Cyan);
		TronQuitter.setFillColor(sf::Color::White);
	}
	if (TronChoixIG == 1)
	{
		TronContinuer.setFillColor(sf::Color::White);
		TronQuitter.setFillColor(sf::Color::Cyan);
	}

	App.draw(TronContinuer);
	App.draw(TronQuitter);

}
void TronTuto()
{
	sf::Texture TronTutoT;
	TronTutoT.loadFromFile("../Ressources/Tron/TronTuto.png");
	sf::Sprite SpriteTronTuto(TronTutoT);
	SpriteTronTuto.setPosition(750, 0);

	App.draw(SpriteTronTuto);
}
