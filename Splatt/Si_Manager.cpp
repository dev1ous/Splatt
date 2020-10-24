#include "SI_Manager.h"
#include "SI_Collision.h"
#include "SI_Joueur.h"
#include "SI_Ennemi.h"
#include "SI_Tir.h"

vector <SI_Joueur> V_joueur;
vector <SI_Ennemi> EnnemyList;
bool app = true;
int Nombre_Ennemis = 0;

State_SI Etat;
Text Play("Play", font, 100);
Text Quit("Quit", font, 100);


void SI_Update()
{
	static bool Load = false;
	if (!Load)
	{
		Etat = State_SI::Menu;
		Color Couleur;
		for (int i = 0; i < Nombre_Joueur; i++)
		{
			if (i == 0)
				Couleur = Color::Red;
			if (i == 1)
				Couleur = Color::Blue;

			V_joueur.push_back(SI_Joueur(Vector2f(((1920 / (Nombre_Joueur + 1)) * (i + 1)), 1080 - 105), i + 1, Couleur));
		}

		Load = true;
	}


	if (Etat == State_SI::Niveau1 || Etat == State_SI::Niveau2 || Etat == State_SI::Niveau3)
	{
		switch (Etat)
		{
		case State_SI::Niveau1:
			Niveau1();
			break;
		case State_SI::Niveau2:
			break;
		case State_SI::Niveau3:
			break;
		}

		Collision();
		Suppression();

		if (app == true)
		{
			for (SI_Joueur& Actual_Joueur : V_joueur)
				FullUpdate(Actual_Joueur);

			for (SI_Ennemi& Actual_Ennemy : EnnemyList)
				FullUpdate(Actual_Ennemy);

			for (SI_Tir& Actual_Tir : Tir_Joueur)
				Actual_Tir.Update();
		}
	}
	else if (Etat == State_SI::Menu)
	{
		Menu();
	}
}

void SI_Display()
{
	if (Etat == State_SI::Niveau1 || Etat == State_SI::Niveau2 || Etat == State_SI::Niveau3)
	{
		switch (Etat)
		{
		case State_SI::Niveau1:
			App.draw(getSprite("Niveau1"));
			break;
		case State_SI::Niveau2:
			App.draw(getSprite("Niveau2"));
			break;
		case State_SI::Niveau3:
			App.draw(getSprite("Niveau3"));
			break;
		}

		for (SI_Joueur& Actual_Joueur : V_joueur)
			FullDraw_Perso(Actual_Joueur);

		for (SI_Ennemi& Actual_Ennemy : EnnemyList)
			FullDraw_Perso(Actual_Ennemy);

		for (SI_Tir& Actual_Tir : Tir_Joueur)
			Actual_Tir.Draw();
	}

	else if (Etat == State_SI::Menu)
	{
		App.draw(getSprite("Menu"));
		App.draw(Play);
		App.draw(Quit);
	}

	else if (Etat == State_SI::Intro)
	{

	}
}

void Intro()
{

}

void Menu()
{
	static int select = 0;
	static float timer = 0;
	timer += MainTime.GetTimeDeltaF();

	static bool Load = false;
	if (!Load)
	{
		Play.setOrigin(Vector2f(Play.getLocalBounds().left + Play.getLocalBounds().width / 2, Play.getLocalBounds().top + Play.getLocalBounds().height / 2));
		Quit.setOrigin(Vector2f(Quit.getLocalBounds().left + Quit.getLocalBounds().width / 2, Quit.getLocalBounds().top + Quit.getLocalBounds().height / 2));
		Play.setPosition(Vector2f(1920 / 2, 1080 / 2 - Play.getCharacterSize() / 2));
		Quit.setPosition(Vector2f(1920 / 2, 1080 / 2 + Play.getCharacterSize() / 2));

		Load = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Up) && timer > 0.2f)
	{
		select++;
		if (select > 1)
			select = 0;

		timer = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && timer > 0.2f)
	{
		select--;
		if (select < 0)
			select = 1;

		timer = 0;
	}

	if (select == 0)
	{
		Play.setFillColor(Color::Red);
		Quit.setFillColor(Color::Color(255, 255, 255, 255));
	}
	if (select == 1)
	{
		Play.setFillColor(Color::Color(255, 255, 255, 255));
		Quit.setFillColor(Color::Red);
	}

	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		if (select == 0)
			Etat = State_SI::Niveau1;
		if (select == 1)
		{
			Etat = State_SI::Intro;
			state = State::MENU;
		}
	}
}

void Niveau1()
{
	static int Min = 0;
	static int Max = 0;
	static int Wave = 0;
	static int Wave_actuel = 0;

	if (Wave == Wave_actuel)
	{
		switch (Wave)
		{
		case 0:
			Min = 1;
			Max = 2;
			break;
		case 1:
			Min = 1;
			Max = 2;
			break;
		case 2:
			Min = 1;
			Max = 2;
			break;
		case 3:
			Min = 1;
			Max = 2;
			break;
		case 4:
			Min = 1;
			Max = 2;
			break;
		case 5:
			Min = 1;
			Max = 2;
			break;
		case 6:
			Min = 1;
			Max = 2;
			break;
		case 7:
			Min = 1;
			Max = 2;
			break;
		case 8:
			Min = 1;
			Max = 2;
			break;
		case 9:
			Min = 1;
			Max = 2;
			break;
		}
		app = false;
		Wave++;
	}

	if (app == false)
		app = App_Ennemis(10, 4, Min, Max);

	if (app == true && Nombre_Ennemis == 0)
	{

		Wave_actuel++;
	}
}

bool App_Ennemis(int _rangeX, int _rangeY, int _typeMin, int _typeMax)
{
	int Rand = 0;
	static int y = 0;
	static int x = 0;
	static float timer = 0;
	timer += MainTime.GetTimeDeltaF();

	if (timer > 0.05f && y < _rangeY && x < _rangeX)
	{
		Rand = irandom(_typeMin, _typeMax);
		EnnemyList.push_back(SI_Ennemi(Vector2f((1920 / 11 * (x + 1)), 105 + (130 * y)), Rand));
		x++;

		if (x == _rangeX && y < _rangeY)
		{
			x = 0;
			y++;
		}
		timer = 0;
	}

	if (y == _rangeY)
	{
		return true;
		y = 0;
	}
	else
		return false;
}