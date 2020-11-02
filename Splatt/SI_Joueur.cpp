#include "SI_Joueur.h"
#include "SI_Tir.h"

vector <SI_Tir> Tir_Joueur;

SI_Joueur::SI_Joueur()
{
	life = 1;
	Numero_Joueur = 1;
	taille = 20;

	Limite_Tir = 0;
	Nombre_Tir = 0;

	Special_Jaune = 0;
	Special_Bleu = 0;
	Special_Violet = 0;
	Special_Vert = 0;

	Droite = false;
	Gauche = false;
	Tir = false;
	Timer = 0;
}

SI_Joueur::SI_Joueur(Vector2f _position, int _numerojoueur, int Nombre_tir, Color _color)
{
	life = 3;

	PV = RectangleShape(Vector2f(life * 30, 10));
	PV.setOrigin(PV.getGlobalBounds().width / 2, PV.getGlobalBounds().height / 2);
	PV.setPosition(Position.x, Position.y + 80);
	Encadré = PV;
	PV.setFillColor(Color::Red);
	Encadré.setFillColor(Color::Transparent);
	Encadré.setOutlineThickness(2);
	Encadré.setOutlineColor(Color::White);

	Numero_Joueur = _numerojoueur;
	Couleur = _color;

	taille = 0;

	Limite_Tir = Nombre_tir;
	Nombre_Tir = 0;

	Special_Jaune = 0;
	Special_Bleu = 0;
	Special_Violet = 0;
	Special_Vert = 0;

	Droite = false;
	Gauche = false;
	Tir = false;
	ColiJ = false;
	Timer_col = 0;
	Timer = 0;
	Position = _position;

	Special.setSize(Vector2f(20, 20));
	Special.setOutlineColor(Color::White);
	Special.setOutlineThickness(1);
}

SI_Joueur::~SI_Joueur()
{
}

void SI_Joueur::Set_NombreTir(int _NbTir)
{
	Nombre_Tir = _NbTir;
	if (Nombre_Tir < 0)
		Nombre_Tir = 0;
}

void SI_Joueur::Update()
{
	Timer += MainTime.GetTimeDeltaF();

	if (Get_Numero() == 1)
	{
		if (isButtonPressed(Action::SIJ1_Gauche) && Position.x - getSprite("Perso1").getGlobalBounds().width / 2 > 0)
			Set_Gauche(true);
		else
			Set_Gauche(false);

		if (isButtonPressed(Action::SIJ1_Droite) && Position.x + getSprite("Perso1").getGlobalBounds().width / 2 < 1920)
			Set_Droite(true);
		else
			Set_Droite(false);

		if (isButtonPressed(Action::SIJ1_Tir) && Timer > 0.25f && Nombre_Tir < Limite_Tir && app == true)
		{
			Set_Tir(true);
			Nombre_Tir++;
			Timer = 0;
		}
		else
			Set_Tir(false);

		if (isButtonPressed(Action::SIJ1_TirSpe) && (Special_Jaune == 4 || Special_Bleu == 4 || Special_Violet == 4 || Special_Vert == 4) && app == true && Nombre_Tir < Limite_Tir)
		{
			Set_TirSpecial(true);
			Nombre_Tir++;
			Timer = 0;
		}
	}

	if (Get_Numero() == 2)
	{
		if (isButtonPressed(Action::SIJ2_Gauche) && Position.x - getSprite("Perso2").getGlobalBounds().width / 2 > 0)
			Set_Gauche(true);
		else
			Set_Gauche(false);

		if (isButtonPressed(Action::SIJ2_Droite) && Position.x + getSprite("Perso2").getGlobalBounds().width / 2 < 1920)
			Set_Droite(true);
		else
			Set_Droite(false);

		if (isButtonPressed(Action::SIJ2_Tir) && Timer > 0.25f && Nombre_Tir < Limite_Tir && app == true && Debut_Niveau == false)
		{
			Set_Tir(true);
			Nombre_Tir++;
			Timer = 0;
		}
		else
			Set_Tir(false);

		if (isButtonPressed(Action::SIJ2_TirSpe) && (Special_Jaune == 4 || Special_Bleu == 4 || Special_Violet == 4 || Special_Vert == 4) && app == true && Debut_Niveau == false && Nombre_Tir < Limite_Tir)
		{
			Set_TirSpecial(true);
			Nombre_Tir++;
			Timer = 0;
		}
	}

	if (isButtonPressed(Action::Escape))
		Pause = true;

	if (Droite)
		Position.x += 300 * MainTime.GetTimeDeltaF();
	if (Gauche)
		Position.x -= 300 * MainTime.GetTimeDeltaF();

	if (Tir)
		Tir_Joueur.push_back(SI_Tir(Couleur, Position, 1));

	if (Tir_Special)
	{
		if (Special_Jaune == 4)
		{
			Tir_Joueur.push_back(SI_Tir(Couleur, Position, 2));
			Special_Jaune = 0;
		}
		if (Special_Bleu == 4)
		{
			Tir_Joueur.push_back(SI_Tir(Couleur, Position, 3));
			Special_Bleu = 0;
		}
		if (Special_Violet == 4)
		{
			Tir_Joueur.push_back(SI_Tir(Couleur, Position, 4));
			Special_Violet = 0;
		}
		if (Special_Vert == 4)
		{
			Tir_Joueur.push_back(SI_Tir(Couleur, Position, 5));
			Special_Vert = 0;
		}

		Set_TirSpecial(false);
	}

	PV.setSize(Vector2f(life * 30, 10));
	PV.setPosition(Position.x, Position.y + 80);
	Encadré.setPosition(Position.x, Position.y + 80);
}

void SI_Joueur::Draw()
{
	string Sprite_Name = "Perso";

	Sprite_Name += to_string(Numero_Joueur);
	if (ColiJ == true)
	{
		Timer_col += MainTime.GetTimeDeltaF();
		getSprite(Sprite_Name).setColor(Color::Color(255, 255, 255, 150));
		if (Timer_col > 0.5F)
		{
			ColiJ = false;
			getSprite(Sprite_Name).setColor(Color::Color(255, 255, 255, 255));
			Timer_col = 0;
		}
	}
	getSprite(Sprite_Name).setOrigin(getSprite(Sprite_Name).getGlobalBounds().width / 2, getSprite(Sprite_Name).getGlobalBounds().height / 2);
	getSprite(Sprite_Name).setPosition(Position);
	App.draw(getSprite(Sprite_Name));
	
	if (Debut_Niveau == false)
	{
		for (int i = 0; i < Special_Jaune || i < Special_Bleu || i < Special_Violet || i < Special_Vert; i++)
		{
			if (Numero_Joueur == 1)
			{
				tSpecial = Text::Text(sTir_Special, font, 25);
				tSpecial.setPosition(Vector2f(20, 20));
				Special.setPosition(20 + (23 * i), 50);
			}

			if (Numero_Joueur == 2)
			{
				tSpecial = Text::Text(sTir_Special, font, 25);
				tSpecial.setPosition(Vector2f(1811, 20));
				Special.setPosition(1880 - (23 * i), 50);
			}

			App.draw(tSpecial);
			App.draw(Special);
		}

	}

	App.draw(PV);
	App.draw(Encadré);
}