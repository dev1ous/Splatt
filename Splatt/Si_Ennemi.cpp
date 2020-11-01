#include "SI_Ennemi.h"
#include "SI_Joueur.h"
#include "SI_Tir.h"

vector <SI_Tir> Tir_Ennemi;

SI_Ennemi::SI_Ennemi()
{
	life = 1;
	Type = 1;
	Droite = false;
	Gauche = false;
	Descente = false;
	Tir = false;
	Timer = 0;
}

SI_Ennemi::SI_Ennemi(Vector2f _position, int _type)
{
	Type = _type;
	Droite = false;
	Gauche = true;
	Descente = false;
	Tir = false;
	Timer = 0;
	Timer_degat = 0;
	ecart = 0;
	timer_tir = 0;
	x = 0;
	Nb_tir = 10;
	Position = _position;

	if (Type < 5)
		life = 1;
	else
	{
		life = 25;
		PV = RectangleShape(Vector2f(life * 4, 10));
		PV.setOrigin(PV.getGlobalBounds().width / 2, PV.getGlobalBounds().height / 2);
		PV.setPosition(Position.x, Position.y - 165);
		Encadré = PV;
		PV.setFillColor(Color::Red);
		Encadré.setFillColor(Color::Transparent);
		Encadré.setOutlineThickness(2);
		Encadré.setOutlineColor(Color::White);
	}

}

SI_Ennemi::~SI_Ennemi()
{
	
}

void SI_Ennemi::Update()
{
	if (Type == 1 || Type == 2 || Type == 3 || Type == 4)
	{
		string Sprite_Name = "Ennemi";
		Sprite_Name += to_string(Type);
		if (Position.x - getSprite(Sprite_Name).getGlobalBounds().width / 2 < 0 && Gauche == true)
			for (SI_Ennemi& Actual_Ennemy : EnnemyList)
			{
				Actual_Ennemy.Droite = true;
				Actual_Ennemy.Gauche = false;
				Actual_Ennemy.Descente = true;
			}

		if (Position.x + getSprite(Sprite_Name).getGlobalBounds().width / 2 > 1920 && Droite == true)
			for (SI_Ennemi& Actual_Ennemy : EnnemyList)
			{
				Actual_Ennemy.Droite = false;
				Actual_Ennemy.Gauche = true;
				Actual_Ennemy.Descente = true;
			}

		if (Gauche)
		{
			if (Descente)
			{
				Timer += MainTime.GetTimeDeltaF();
				Position.y += 50 * MainTime.GetTimeDeltaF();
				if (Timer > 0.5f)
				{
					Descente = false;
					Timer = 0;
				}
			}
			else
				Position.x -= Vitesse * Nombre_Joueur * MainTime.GetTimeDeltaF();
		}

		if (Droite)
		{
			if (Descente)
			{
				Timer += MainTime.GetTimeDeltaF();
				Position.y += 50 * MainTime.GetTimeDeltaF();
				if (Timer > 0.5f)
				{
					Descente = false;
					Timer = 0;
				}
			}
			else
				Position.x += Vitesse * Nombre_Joueur * MainTime.GetTimeDeltaF();
		}
	}
	else if (Type == 5 || Type == 6 || Type == 7)
	{
		timer_tir += MainTime.GetTimeDeltaF();
		if (Type == 5)
		{
			if (timer_tir > 2.0f)
			{
				float RandTir;
				for (int i = 0; i < 5; i++)
				{
					RandTir = (0.1 * i) - 0.2;
					Tir_Ennemi.push_back(SI_Tir(Get_Position(), 2, RandTir));
				}
				timer_tir = 0;
			}
		}
		if (Type == 6)
		{
			if (timer_tir > 2.0f)
			{
				for (int i = 0; i < 3; i++)
					Tir_Ennemi.push_back(SI_Tir(Vector2f(Get_Position().x - 150 + (150 * i), Get_Position().y), 3, 0));
				
				timer_tir = 0;
			}
		}
		if (Type == 7)
		{
			if (timer_tir > 4.0f)
			{
				ecart += MainTime.GetTimeDeltaF();
				if (ecart > 0.2f)
				{
					float angleCible;
					int rand = irandom(1, Nombre_Joueur + 1);
					int i = 0;
					for (SI_Joueur& Actual_Joueur : V_joueur)
					{
						i++;
						if (i = rand)
						{
							if (Actual_Joueur.Get_Position().y > Position.y)
								angleCible = acos(((double)Actual_Joueur.Get_Position().x - Position.x) / (sqrt(pow((double)Actual_Joueur.Get_Position().x - Position.x, 2) + pow((double)Actual_Joueur.Get_Position().y - Position.y, 2))));
							break;
						}
					}

					Tir_Ennemi.push_back(SI_Tir(Get_Position(), 4, angleCible));
					x++;
					if (x == Nb_tir)
					{
						x = 0;
						timer_tir = 0;
					}
					ecart = 0;
				}
			}
		}

		string Sprite_Name = "Ennemi";
		Sprite_Name += to_string(Type);
		if (Position.x - getSprite(Sprite_Name).getGlobalBounds().width / 2 < 0 && Gauche == true)
		{
			Droite = true;
			Gauche = false;
		}
		if (Position.x + getSprite(Sprite_Name).getGlobalBounds().width / 2 > 1920 && Droite == true)
		{
			Droite = false;
			Gauche = true;
		}


		if (Gauche)
			Position.x -= 100 * MainTime.GetTimeDeltaF();

		if (Droite)
			Position.x += 100 * MainTime.GetTimeDeltaF();

		PV.setSize(Vector2f(life * 4, 10));
		PV.setPosition(Position.x, Position.y - 165);
		Encadré.setPosition(Position.x, Position.y - 165);
	}

	if (Keyboard::isKeyPressed(Keyboard::Numpad1) && EnnemyList.size() > 1)
		for (SI_Ennemi& Actual_Ennemy : EnnemyList)
		{
			Actual_Ennemy.life = 0;
		}
}

void SI_Ennemi::Draw()
{
	string Sprite_Name = "Ennemi";

	Sprite_Name += to_string(Type);
	getSprite(Sprite_Name).setOrigin(getSprite(Sprite_Name).getGlobalBounds().width / 2, getSprite(Sprite_Name).getGlobalBounds().height / 2);
	getSprite(Sprite_Name).setPosition(Position);
	App.draw(getSprite(Sprite_Name));

	if (Type > 4)
	{
		App.draw(PV);
		App.draw(Encadré);
	}
}

void Ennemi_tir()
{
	static int rand_ennemi = 0;
	static float Rand_timer = 0;
	static float timer = 0;
	timer += MainTime.GetTimeDeltaF();

	static bool Declancheur = true;
	if (Declancheur == true)
	{
		Rand_timer = frandom(10.0f, 15.0f);

		Declancheur = false;
	}

	if (timer > Rand_timer && Declancheur == false)
	{
		rand_ennemi = irandom(1, EnnemyList.size() + 1);
		int i = 0;
		for (SI_Ennemi& Actual_Ennemy : EnnemyList)
		{
			i++;
			if (i == rand_ennemi)
			{
				float angleCible;
				int rand = irandom(1, Nombre_Joueur + 1);
				int x = 0;
				for (SI_Joueur& Actual_Joueur : V_joueur)
				{
					x++;
					if (i = rand)
					{
						if (Actual_Joueur.Get_Position().y > Actual_Ennemy.Get_Position().y)
							angleCible = acos(((double)Actual_Joueur.Get_Position().x - Actual_Ennemy.Get_Position().x) / (sqrt(pow((double)Actual_Joueur.Get_Position().x - Actual_Ennemy.Get_Position().x, 2) + pow((double)Actual_Joueur.Get_Position().y - Actual_Ennemy.Get_Position().y, 2))));
						break;
					}
				}
				Tir_Ennemi.push_back(SI_Tir(Actual_Ennemy.Get_Position(), 1, angleCible));
				
				timer = 0;
				Declancheur = true;
				break;
			}
		}
	}
}