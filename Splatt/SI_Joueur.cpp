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
	life = 1;
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

		if (isButtonPressed(Action::SIJ2_Tir) && Timer > 0.25f && Nombre_Tir < Limite_Tir && app == true)
		{
			Set_Tir(true);
			Nombre_Tir++;
			Timer = 0;
		}
		else
			Set_Tir(false);
	}

	if (isButtonPressed(Action::Escape))
		Pause = true;

	if (Droite)
		Position.x += 200 * MainTime.GetTimeDeltaF();
	if (Gauche)
		Position.x -= 200 * MainTime.GetTimeDeltaF();

	if (Tir)
		Tir_Joueur.push_back(SI_Tir(Couleur, Position));
}

void SI_Joueur::Draw()
{
	string Sprite_Name = "Perso";

	Sprite_Name += to_string(Numero_Joueur);
	getSprite(Sprite_Name).setOrigin(getSprite(Sprite_Name).getGlobalBounds().width / 2, getSprite(Sprite_Name).getGlobalBounds().height / 2);
	getSprite(Sprite_Name).setPosition(Position);
	App.draw(getSprite(Sprite_Name));
	
	
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
			tSpecial.setPosition(Vector2f(20, 20));
			Special.setPosition(1880 - (23 * i), 50);
		}

		App.draw(tSpecial);
		App.draw(Special);
	}
	
}