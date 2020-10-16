#include "SI_Manager.h"
#include "SI_Collision.h"
#include "SI_Joueur.h"
#include "SI_Ennemi.h"
#include "SI_Tir.h"

vector <SI_Joueur> V_joueur;
vector <SI_Ennemi> EnnemyList;

State_SI Etat;
Text Play("Play", font, 50);
Text Quit("Quit", font, 50);
RectangleShape shape(Vector2f(130, 120));

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
		
		App_Ennemis(10, 4, 2, 4);

		Load = true;
	}


	if (Etat == State_SI::Niveau1 || Etat == State_SI::Niveau2 || Etat == State_SI::Niveau3)
	{
		Collision();
		Suppression();

		for (SI_Joueur& Actual_Joueur : V_joueur)
			FullUpdate(Actual_Joueur);

		for (SI_Ennemi& Actual_Ennemy : EnnemyList)
			FullUpdate(Actual_Ennemy);

		for (SI_Tir& Actual_Tir : Tir_Joueur)
			Actual_Tir.Update();
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
		for (SI_Joueur& Actual_Joueur : V_joueur)
			FullDraw_Perso(Actual_Joueur);

		for (SI_Ennemi& Actual_Ennemy : EnnemyList)
			FullDraw_Perso(Actual_Ennemy);

		for (SI_Tir& Actual_Tir : Tir_Joueur)
			Actual_Tir.Draw();
		if (Etat == State_SI::Niveau1)
			App.draw(getSprite("Niveau1"));
	}
	else if (Etat == State_SI::Menu)
	{
		App.draw(getSprite("Menu"));
		App.draw(shape);
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

	static bool Load = false;
	if (!Load)
	{
		shape.setFillColor(Color::Transparent);
		shape.setOutlineThickness(5);
		shape.setOutlineColor(Color::Color(150, 0, 255, 150));
		shape.setPosition(Vector2f(1920 / 2, 1080 / 2));
		shape.setOrigin(Vector2f(shape.getGlobalBounds().width / 2, shape.getGlobalBounds().height / 2));

		Play.setOrigin(Vector2f(Play.getLocalBounds().left + Play.getLocalBounds().width / 2, Play.getLocalBounds().top + Play.getLocalBounds().height / 2));
		Quit.setOrigin(Vector2f(Quit.getLocalBounds().left + Quit.getLocalBounds().width / 2, Quit.getLocalBounds().top + Quit.getLocalBounds().height / 2));
		Play.setPosition(Vector2f(shape.getPosition().x, shape.getPosition().y - 25));
		Quit.setPosition(Vector2f(shape.getPosition().x, shape.getPosition().y + 25));
		Play.setFillColor(Color::Color(200, 0, 200, 255));
		Quit.setFillColor(Color::Color(200, 0, 200, 255));

		Load = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		select++;
		if (select > 1)
			select = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		select--;
		if (select < 0)
			select = 1;
	}

	if (select == 0)
	{
		Play.setFillColor(Color::Red);
		Quit.setFillColor(Color::Color(200, 0, 200, 255));
	}
	if (select == 1)
	{
		Play.setFillColor(Color::Color(200, 0, 200, 255));
		Quit.setFillColor(Color::Red);
	}
}

void App_Ennemis(int _rangeX, int _rangeY, int _typeMin, int _typeMax)
{
	int Rand = 0;
	for (int y = 0; y < _rangeY; y++)
	{
		for (int x = 0; x < _rangeX; x++)
		{
			Rand = irandom(_typeMin, _typeMax);
			EnnemyList.push_back(SI_Ennemi(Vector2f((1920 / 11 * (x + 1)), 105 + (120 * y)), Rand));
		}
	}
}