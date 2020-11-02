#include "Pac_Manager.h"
#include "Perso_Pacman.h"
#include "Pac_Fantomes.h"
#include "Pac_Gum.h"
#include "Pac_Bonus.h"

Perso_Pacman Pac;
Pac_Fantomes Fantome0(0);
Pac_Fantomes Fantome1(1);
Pac_Fantomes Fantome2(2);
Pac_Fantomes Fantome3(3);

Pac_Bonus Bonus1(1);
Pac_Bonus Bonus2(2);
Pac_Bonus Bonus3(3);
Pac_Bonus Bonus4(4);
Pac_Bonus Bonus5(5);
Pac_Bonus Bonus6(6);

Pac_Gum Gums[32][18];

int score = 0;
int win = 0;

string Sco = "Score: ";
string Sco2;
Text Score_Pac(Sco, font, 50);
Text Score_Pac2(Sco, font, 50);

Text Jouer("Jouer", font, 100);
Text Quitter("Quitter", font, 100);

Image Image_Masque;

State_Pac State_PacMan;

void Pac_Update()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		State_PacMan = State_Pac::Pause;
	}

	switch (State_PacMan)
	{
	case State_Pac::Niveau1:
		Niveau1_Pac();
		Pac.Update();

		Fantome0.Update();
		Fantome1.Update();
		Fantome2.Update();
		Fantome3.Update();
		break;
	case State_Pac::Menu:
		PacMenu();
		break;
	case State_Pac::Pause:
		PacPause();
		break;
	default:
		break;
	}
}


void Pac_Display()
{
	static bool one_pass = true;
	if (one_pass == true)
	{
		State_PacMan = State_Pac::Niveau1;

		Image_Masque.loadFromFile("../Ressources/PacMan/PacMasque.png");
		one_pass = false;
	}


	float PosX = 30;
	float PosY = 30;
	static Color Pix;

	switch (State_PacMan)
	{
	case State_Pac::Niveau1:


		App.draw(getSprite("PacMap"));


		for (int i = 0; i < 17; i++)
		{
			for (int j = 0; j < 31; j++)
			{

				if (Gums[i][j].Get_Mort() == false)
				{

					Pix = Image_Masque.getPixel(PosX, PosY);

					if (Pix == Color::White || Pix == Color::Red)
					{
						if (Pac.Get_Rect().intersects(Gums[i][j].Get_Rect()))
						{
							score += 10;
							Sco += to_string(score);
							Gums[i][j].Set_Mort();
							getSprite("Gums").setPosition(-500, -500);
							win++;
						}

						if (Gums[i][j].Get_Mort() == false)
						{
							Gums[i][j].Set_PosX(PosX);
							Gums[i][j].Set_PosY(PosY);

							getSprite("Gums").setPosition(PosX, PosY);
							Gums[i][j].Set_Rect(getSprite("Gums").getGlobalBounds());
							Gums[i][j].Display();
						}
					}
				}
				PosX += 60;

			}
			if (PosX == 1890)
			{
				PosX = 30;
				PosY += 60;
			}

		}

		Bonus1.Display();
		Bonus2.Display();
		Bonus3.Display();
		Bonus4.Display();
		Bonus5.Display();
		Bonus6.Display();

		Pac.Display();
		Fantome0.Display();
		Fantome1.Display();
		Fantome2.Display();
		Fantome3.Display();
		App.draw(Score_Pac);
		App.draw(Score_Pac2);

		if (Pac.Get_Vie() == 0)
		{
			App.draw(getSprite("GameOver"));
		}
		if (win > 179)
		{
			App.draw(getSprite("GameOver"));
		}
		break;
	case State_Pac::Menu:
		App.draw(getSprite("PacMenu"));
		App.draw(Jouer);
		App.draw(Quitter);
		break;
	case State_Pac::Pause:
		App.draw(getSprite("PacMap"));
		App.draw(Jouer);
		App.draw(Quitter);
		break;
	default:
		break;
	}
}

void Niveau1_Pac()
{

	if (Pac.Get_Vie() == 0)
	{
		Pac_GameOver();
	}
	if (win > 179)
	{
		Pac_GameOver();
	}

	Score_Pac2.setPosition(140, 0);
	Sco2 = to_string(score);
	Score_Pac2.setString(Sco2);
	static bool True = true;
	static bool False = false;
	static float timer = 0;
	static float timer2 = 0;

	timer += MainTime.GetTimeDeltaF();
	if (Pac.Get_Power_up() == true)
	{
		Fantome0.Set_Anim(60);
		Fantome1.Set_Anim(60);
		Fantome2.Set_Anim(60);
		Fantome3.Set_Anim(60);
		timer2 += MainTime.GetTimeDeltaF();
		if (timer2 > 7.f)
		{
			Pac.Set_Power_up(False);
			Fantome0.Set_Anim(0);
			Fantome1.Set_Anim(0);
			Fantome2.Set_Anim(0);
			Fantome3.Set_Anim(0);
			timer2 = 0;

		}
	}

	if (Pac.Get_Rect().intersects(Bonus1.Get_Rect()))
	{
		Bonus1.Set_PosX();
		Pac.Set_Power_up(True);
		score += 50;

	}
	if (Pac.Get_Rect().intersects(Bonus2.Get_Rect()))
	{
		Bonus2.Set_PosX();
		Pac.Set_Power_up(True);
		score += 50;

	}
	if (Pac.Get_Rect().intersects(Bonus3.Get_Rect()))
	{
		Bonus3.Set_PosX();
		Pac.Set_Power_up(True);
		score += 50;

	}
	if (Pac.Get_Rect().intersects(Bonus4.Get_Rect()))
	{
		Bonus4.Set_PosX();
		Pac.Set_Power_up(True);
		score += 50;

	}
	if (Pac.Get_Rect().intersects(Bonus5.Get_Rect()))
	{
		Bonus5.Set_PosX();
		Pac.Set_Power_up(True);
		score += 50;

	}
	if (Pac.Get_Rect().intersects(Bonus6.Get_Rect()))
	{
		Bonus6.Set_PosX();
		Pac.Set_Power_up(True);
		score += 50;

	}

	if (Pac.Get_Rect().intersects(Fantome0.Get_Rect()))
	{
		if (Pac.Get_Power_up() == false && timer > 1)
		{
			Pac.Mort();
			timer = 0;
			Fantome0.Mort();
			Fantome1.Mort();
			Fantome2.Mort();
			Fantome3.Mort();
		}
		else if (timer > 1)
		{
			score += 100;
			Fantome0.Mort();
		}

	}
	if (Pac.Get_Rect().intersects(Fantome1.Get_Rect()))
	{
		if (Pac.Get_Power_up() == false && timer > 1)
		{
			Pac.Mort();
			timer = 0;
			Fantome0.Mort();
			Fantome1.Mort();
			Fantome2.Mort();
			Fantome3.Mort();
		}
		else if (timer > 1)
		{
			score += 100;
			Fantome1.Mort();
		}
	}
	if (Pac.Get_Rect().intersects(Fantome2.Get_Rect()))
	{
		if (Pac.Get_Power_up() == false && timer > 1)
		{
			Pac.Mort();
			timer = 0;
			Fantome0.Mort();
			Fantome1.Mort();
			Fantome2.Mort();
			Fantome3.Mort();
		}
		else if (timer > 1)
		{
			score += 100;
			Fantome2.Mort();
		}
	}
	if (Pac.Get_Rect().intersects(Fantome3.Get_Rect()))
	{
		if (Pac.Get_Power_up() == false && timer > 1)
		{
			Pac.Mort();
			timer = 0;
			Fantome0.Mort();
			Fantome1.Mort();
			Fantome2.Mort();
			Fantome3.Mort();
		}
		else if (timer > 1)
		{
			score += 100;
			Fantome3.Mort();
		}
	}
}

void PacMenu()
{
	static bool Choix = false;
	static float timer = 0;
	timer += MainTime.GetTimeDeltaF();

	static bool one_pass = false;
	if (!one_pass)
	{
		Jouer.setPosition(860, 540);
		Quitter.setPosition(860, 800);

		one_pass = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Z) && timer > 0.2f)
	{
		Choix = false;
		timer = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::S) && timer > 0.2f)
	{
		Choix = true;
		timer = 0;
	}

	if (Choix == false)
	{
		Jouer.setFillColor(Color::Blue);
		Quitter.setFillColor(Color::Color(255, 255, 255, 255));
	}
	if (Choix == true)
	{
		Jouer.setFillColor(Color::Color(255, 255, 255, 255));
		Quitter.setFillColor(Color::Blue);
	}

	if (Keyboard::isKeyPressed(Keyboard::Enter) && timer > 0.2f)
	{
		if (Choix == false)
		{
			State_PacMan = State_Pac::Niveau1;

		}
		if (Choix == true)
		{
			ChangeState(State::MENU);
		}

		Choix = false;
		timer = 0;
	}
}

void PacPause()
{
	static bool Choix = false;
	static float timer = 0;
	timer += MainTime.GetTimeDeltaF();

	static bool one_pass = false;
	if (!one_pass)
	{
		Jouer.setPosition(860, 540);
		Quitter.setPosition(860, 800);

		one_pass = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Z) && timer > 0.2f)
	{
		Choix = false;
		timer = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::S) && timer > 0.2f)
	{
		Choix = true;
		timer = 0;
	}

	if (Choix == false)
	{
		Jouer.setFillColor(Color::Blue);
		Quitter.setFillColor(Color::Color(255, 255, 255, 255));
	}
	if (Choix == true)
	{
		Jouer.setFillColor(Color::Color(255, 255, 255, 255));
		Quitter.setFillColor(Color::Blue);
	}

	if (Keyboard::isKeyPressed(Keyboard::Enter) && timer > 0.2f)
	{
		if (Choix == false)
		{
			State_PacMan = State_Pac::Niveau1;

		}
		if (Choix == true)
		{
			State_PacMan = State_Pac::Menu;
			Pac_Reset();
		}

		Choix = false;
		timer = 0;
	}
}

void Pac_Reset()
{
	win = 0;
	score = 0;
	score -= 10;
	Pac.Reset();
	Fantome0.Mort();
	Fantome1.Mort();
	Fantome2.Mort();
	Fantome3.Mort();
	Bonus1.Reset();
	Bonus2.Reset();
	Bonus3.Reset();
	Bonus4.Reset();
	Bonus5.Reset();
	Bonus6.Reset();

	Fantome0.Set_Anim(0);
	Fantome1.Set_Anim(0);
	Fantome2.Set_Anim(0);
	Fantome3.Set_Anim(0);

	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			Gums[i][j].Reset();
		}
	}
	ChangeState(State::MENU);

}

void Pac_GameOver()
{
	static float timer = 0;
	timer += MainTime.GetTimeDeltaF();


	if (timer > 5.f)
	{
		Pac_Reset();
		timer = 0;
	}



}