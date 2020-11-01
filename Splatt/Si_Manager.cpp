#include "SI_Manager.h"
#include "SI_Collision.h"
#include "SI_Joueur.h"
#include "SI_Ennemi.h"
#include "SI_Tir.h"

vector <SI_Joueur> V_joueur;
vector <SI_Ennemi> EnnemyList;

bool app = true;
bool Load = false;
float Vitesse = 50;
int Wave = 0;
int Wave_actuel = 0;
int Min = 0;
int Max = 0;
float Timer_Niveau;
bool Debut_Niveau = false;
int Nombre_Joueur = 1;

State_SI Etat;
string Niveau_Actuel("Felicitation vous passez au niveau : ");
String Nb_Joeur("Nombre de Joueur : ");
Text Play("Play", font, 100);
Text Quit("Quit", font, 100);
Text Game_Over("Game_Over", font, 200);
Text tNb_Joueur;

void reset()
{
	Etat = State_SI::Menu;
	app = true;
	Pause = false;
	Debut_Niveau = true;
	Wave = 0;
	Wave_actuel = 0;
	Min = 1;
	Max = 5;
	Nombre_Joueur = 1;
	Vitesse = 50;
	
	EnnemyList.clear();
	Tir_Joueur.clear();
	Tir_Ennemi.clear();
	reset_Joueur(1, 1);
}

void reset_Joueur(int Nombre_tirJ1, int Nombre_tirJ2)
{
	V_joueur.clear();

	Color Couleur;
	int Nombre_tir;
	for (int i = 0; i < Nombre_Joueur; i++)
	{
		if (i == 0)
		{
			Nombre_tir = Nombre_tirJ1;
			Couleur = Color::Red;
		}
		if (i == 1)
		{
			Nombre_tir = Nombre_tirJ2;
			Couleur = Color::Blue;
		}

		V_joueur.push_back(SI_Joueur(Vector2f(((1920 / (Nombre_Joueur + 1)) * (i + 1)), 1080 - 105), i + 1, Nombre_tir, Couleur));
	}
}

void SI_Update()
{
	if (!Load)
	{
		reset();
		Load = true;
	}

	if (Etat == State_SI::Niveau1 || Etat == State_SI::Niveau2 || Etat == State_SI::Niveau3)
	{
		Suppression();

		if (!Pause)
		{
			if (V_joueur.size() == 0)
			{
				static float timer = 0;
				timer += MainTime.GetTimeDeltaF();
				if (timer > 3.f)
				{
					Load = false;
					timer = 0;
				}
			}
			else
			{
				switch (Etat)
				{
				case State_SI::Niveau1:
					Niveau1();
					break;
				case State_SI::Niveau2:
					Niveau2();
					break;
				case State_SI::Niveau3:
					Niveau3();
					break;
				}

				for (SI_Joueur& Actual_Joueur : V_joueur)
					FullUpdate(Actual_Joueur);

				if (app == true)
				{
					Collision();

					for (SI_Ennemi& Actual_Ennemy : EnnemyList)
						FullUpdate(Actual_Ennemy);

					for (SI_Tir& Actual_Tir : Tir_Joueur)
						Actual_Tir.Update_Joueur();

					for (SI_Tir& Actual_Tir : Tir_Ennemi)
						Actual_Tir.Update_Ennemi();

					if (Wave < 9 && EnnemyList.size())
						Ennemi_tir();
				}
			}
		}

		if (Pause)
			Pause_update();
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
		static string Numero_Wave("Vague : ");
		static Text Affichage_Wave;
		switch (Etat)
		{
		case State_SI::Niveau1:
			App.draw(getSprite("Niveau1"));
			if (Debut_Niveau == true)
				App.draw(Text::Text(Niveau_Actuel + "1",font,100));
			break;
		case State_SI::Niveau2:
			App.draw(getSprite("Niveau2"));
			if (Debut_Niveau == true)
				App.draw(Text::Text(Niveau_Actuel + "2", font, 100));
			break;
		case State_SI::Niveau3:
			App.draw(getSprite("Niveau3"));
			if (Debut_Niveau == true)
				App.draw(Text::Text(Niveau_Actuel + "3", font, 100));
			break;
		}

		for (SI_Tir& Actual_Tir : Tir_Joueur)
			Actual_Tir.Draw();

		for (SI_Tir& Actual_Tir : Tir_Ennemi)
			Actual_Tir.Draw();

		for (SI_Ennemi& Actual_Ennemy : EnnemyList)
			FullDraw_Perso(Actual_Ennemy);

		Affichage_Wave = Text::Text(Numero_Wave + to_string(Wave_actuel + 1) + "/10", font, 30);
		Affichage_Wave.setOrigin(Vector2f(Affichage_Wave.getLocalBounds().left + Affichage_Wave.getLocalBounds().width / 2, Affichage_Wave.getLocalBounds().top + Affichage_Wave.getLocalBounds().height / 2));
		Affichage_Wave.setPosition(Vector2f(1920 / 2, 20));
		App.draw(Affichage_Wave);

		for (SI_Joueur& Actual_Joueur : V_joueur)
			FullDraw_Perso(Actual_Joueur);

		if (V_joueur.size() == 0)
		{
			Game_Over.setOrigin(Vector2f(Game_Over.getLocalBounds().left + Game_Over.getLocalBounds().width / 2, Game_Over.getLocalBounds().top + Game_Over.getLocalBounds().height / 2));
			Game_Over.setPosition(Vector2f(960, 540));
			App.draw(Game_Over);
		}

		if (Pause)
		{
			App.draw(Play);
			App.draw(Quit);
		}
	}

	else if (Etat == State_SI::Menu)
	{
		App.draw(getSprite("Menu"));
		App.draw(Play);
		App.draw(tNb_Joueur);
		App.draw(Quit);
	}
}

void Menu()
{
	static int select = 0;
	static float timer = 0;
	timer += MainTime.GetTimeDeltaF();

	static bool load = false;
	if (!load)
	{
		Play.setOrigin(Vector2f(Play.getLocalBounds().left + Play.getLocalBounds().width / 2, Play.getLocalBounds().top + Play.getLocalBounds().height / 2));
		Quit.setOrigin(Vector2f(Quit.getLocalBounds().left + Quit.getLocalBounds().width / 2, Quit.getLocalBounds().top + Quit.getLocalBounds().height / 2));
		Play.setPosition(Vector2f(1920 / 2, 1080 / 2 - Play.getCharacterSize()));
		Quit.setPosition(Vector2f(1920 / 2, 1080 / 2 + Play.getCharacterSize()));

		load = true;
	}

	tNb_Joueur = Text::Text(Nb_Joeur + to_string(Nombre_Joueur), font, 100);
	tNb_Joueur.setOrigin(Vector2f(tNb_Joueur.getLocalBounds().left + tNb_Joueur.getLocalBounds().width / 2, tNb_Joueur.getLocalBounds().top + tNb_Joueur.getLocalBounds().height / 2));
	tNb_Joueur.setPosition(Vector2f(1920 / 2, 1080 / 2));

	if (isButtonPressed(Action::Down) && timer > 0.2f)
	{
		select++;
		if (select > 2)
			select = 0;

		timer = 0;
	}
	if (isButtonPressed(Action::UP) && timer > 0.2f)
	{
		select--;
		if (select < 0)
			select = 2;

		timer = 0;
	}

	if (select == 0)
	{
		Play.setFillColor(Color::Red);
		tNb_Joueur.setFillColor(Color::White);
		Quit.setFillColor(Color::White);
	}
	if (select == 1)
	{
		Play.setFillColor(Color::White);
		tNb_Joueur.setFillColor(Color::Red);
		Quit.setFillColor(Color::White);
	}
	if (select == 2)
	{
		Play.setFillColor(Color::White);
		tNb_Joueur.setFillColor(Color::White);
		Quit.setFillColor(Color::Red);
	}

	if (isButtonPressed(Action::Interact) && timer > 0.2f)
	{
		if (select == 0)
		{
			Etat = State_SI::Niveau1;
			select = 0;
		}

		if (select == 1)
		{
			Nombre_Joueur++;
			if (Nombre_Joueur > 2)
				Nombre_Joueur = 1;
		}

		if (select == 2)
		{
			Load = false;
			ChangeState(State::MENU);
			select = 0;
		}

		timer = 0;
	}
}

void Pause_update()
{
	static int select = 0;
	static float timer = 0;
	timer += MainTime.GetTimeDeltaF();

	static bool load = false;
	if (!load)
	{
		Play.setOrigin(Vector2f(Play.getLocalBounds().left + Play.getLocalBounds().width / 2, Play.getLocalBounds().top + Play.getLocalBounds().height / 2));
		Quit.setOrigin(Vector2f(Quit.getLocalBounds().left + Quit.getLocalBounds().width / 2, Quit.getLocalBounds().top + Quit.getLocalBounds().height / 2));
		Play.setPosition(Vector2f(1920 / 2, 1080 / 2 - Play.getCharacterSize()));
		Quit.setPosition(Vector2f(1920 / 2, 1080 / 2 + Quit.getCharacterSize()));

		load = true;
	}

	if (isButtonPressed(Action::Down) && timer > 0.2f)
	{
		select++;
		if (select > 1)
			select = 0;

		timer = 0;
	}
	if (isButtonPressed(Action::UP) && timer > 0.2f)
	{
		select--;
		if (select < 0)
			select = 1;

		timer = 0;
	}

	if (select == 0)
	{
		Play.setFillColor(Color::Red);
		Quit.setFillColor(Color::White);
	}
	if (select == 1)
	{
		Play.setFillColor(Color::White);
		Quit.setFillColor(Color::Red);
	}

	if (isButtonPressed(Action::Interact) && timer > 0.2f)
	{
		if (select == 0)
			Pause = false;
		if (select == 1)
			reset();

		select = 0;
		timer = 0;
	}
}

void Niveau1()
{
	if (Debut_Niveau == true)
	{
		Timer_Niveau += MainTime.GetTimeDeltaF();
		if (Timer_Niveau > 2.0f)
		{
			Debut_Niveau = false;
			Timer_Niveau = 0;
		}
	}
	else
	{

		if (Wave == Wave_actuel)
		{
			switch (Wave)
			{
			case 0:
				Min = 1;
				Max = 2;
				break;
			case 1:
				Min = 2;
				Max = 3;
				break;
			case 2:
				Min = 3;
				Max = 4;
				break;
			case 3:
				Min = 4;
				Max = 5;
				break;
			case 4:
				Min = 1;
				Max = 3;
				break;
			case 5:
				Min = 3;
				Max = 5;
				break;
			case 6:
				Min = 1;
				Max = 4;
				break;
			case 7:
				Min = 2;
				Max = 5;
				break;
			case 8:
				Min = 1;
				Max = 5;
				break;
			case 9:
				Min = 5;
				Max = 6;
				break;
			case 10:
				Etat = State_SI::Niveau2;
				int i = 0;
				int x = 0;
				int y = 0;
				for (SI_Joueur& Actual_Joueur : V_joueur)
				{
					if (V_joueur.size() == 1)
					{
						reset_Joueur(Actual_Joueur.Get_Limit(), 0);
						break;
					}
					else
					{
						i++;
						if (i == 1)
							x = Actual_Joueur.Get_Limit();
						else if (i == 2)
						{
							y = Actual_Joueur.Get_Limit();
							reset_Joueur(x, y);
						}

					}
				}
				Wave = 0;
				Wave_actuel = 0;
				Min = 1;
				Max = 5;
				Debut_Niveau = true;
				break;
			}
			Vitesse += 1.5;
			Tir_Joueur.clear();
			Tir_Ennemi.clear();
			app = false;
			if (Wave < 10)
				Wave++;
		}

		if (app == false && Wave_actuel < 9)
			app = App_Ennemis(6, 3, Min, Max);
		else if (app == false && Wave_actuel == 9)
			app = App_Ennemis(1, 1, Min, Max);

		if (app == true && EnnemyList.size() == 0)
			Wave_actuel++;
	}
}

void Niveau2()
{
	if (Debut_Niveau == true)
	{
		Timer_Niveau += MainTime.GetTimeDeltaF();
		if (Timer_Niveau > 2.0f)
		{
			Debut_Niveau = false;
			Timer_Niveau = 0;
		}
	}
	else
	{
		if (Wave == Wave_actuel)
		{
			if (Wave == 9)
			{
				Min = 6;
				Max = 7;
			}
			if (Wave == 10)
			{
				Etat = State_SI::Niveau3;
				int i = 0;
				int x = 0;
				int y = 0;
				for (SI_Joueur& Actual_Joueur : V_joueur)
				{
					if (V_joueur.size() == 1)
					{
						reset_Joueur(Actual_Joueur.Get_Limit(), 0);
						break;
					}
					else
					{
						i++;
						if (i == 1)
							x = Actual_Joueur.Get_Limit();
						else if (i == 2)
						{
							y = Actual_Joueur.Get_Limit();
							reset_Joueur(x, y);
						}

					}
				}
				Wave = 0;
				Wave_actuel = 0;
				Min = 1;
				Max = 5;
				Debut_Niveau = true;
			}
			Vitesse += 1.5;
			Tir_Joueur.clear();
			Tir_Ennemi.clear();
			app = false;
			if (Wave < 10)
				Wave++;
		}

		if (app == false)
			app = App_Ennemis(7, 4, Min, Max);
		else if (app == false && Wave_actuel == 9)
			app = App_Ennemis(1, 1, Min, Max);

		if (app == true && EnnemyList.size() == 0)
			Wave_actuel++;
	}
}

void Niveau3()
{
	if (Debut_Niveau == true)
	{
		Timer_Niveau += MainTime.GetTimeDeltaF();
		if (Timer_Niveau > 2.0f)
		{
			Debut_Niveau = false;
			Timer_Niveau = 0;
		}
	}
	else
	{
		if (Wave == Wave_actuel)
		{
			if (Wave == 9)
			{
				Min = 7;
				Max = 8;
			}
			if (Wave == 10)
				reset();
			Vitesse += 1.5;
			app = false;
			Tir_Joueur.clear();
			Tir_Ennemi.clear();
			if (Wave < 10)
				Wave++;
		}

		if (app == false)
			app = App_Ennemis(10, 4, Min, Max);
		else if (app == false && Wave_actuel == 9)
			app = App_Ennemis(1, 1, Min, Max);

		if (app == true && EnnemyList.size() == 0 && Wave_actuel < 10)
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

	if (EnnemyList.size() == 0)
	{
		y = 0;
		x = 0;
	}

	if (timer > 0.05f && y < _rangeY && x < _rangeX)
	{
		Rand = irandom(_typeMin, _typeMax);
		if (Rand < 5)
			EnnemyList.push_back(SI_Ennemi(Vector2f(180 * (x + 1) + (960 - (180 * (((float)_rangeX / 2.f) + 0.5f))), 105 + (130 * y)), Rand));
		else
			EnnemyList.push_back(SI_Ennemi(Vector2f(960, 200), Rand));
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
		y = 0;
		return true;
	}
	else
		return false;
}

void Display_Controle(const int& x)
{
	getSprite("Controle").setPosition(x, 0);
	App.draw(getSprite("Controle"));
}