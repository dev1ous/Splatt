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

SI_Joueur::SI_Joueur(Vector2f _position, int _numerojoueur, Color _color)
{
	life = 1;
	Numero_Joueur = _numerojoueur;
	Couleur = _color;

	taille = 0;

	Limite_Tir = 2;
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

	if (Numero_Joueur == 1)
		Special.setPosition(20, 20);
	if (Numero_Joueur == 2)
		Special.setPosition(1900, 20);

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
		if (Keyboard::isKeyPressed(Keyboard::Q) && Position.x - getSprite("Perso1").getGlobalBounds().width / 2 > 0)
			Set_Gauche(true);
		else
			Set_Gauche(false);

		if (Keyboard::isKeyPressed(Keyboard::D) && Position.x + getSprite("Perso1").getGlobalBounds().width / 2 < 1920)
			Set_Droite(true);
		else
			Set_Droite(false);

		if (Keyboard::isKeyPressed(Keyboard::Space) && Timer > 0.5f && Nombre_Tir < Limite_Tir && app == true)
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
		if (Keyboard::isKeyPressed(Keyboard::Left) && Position.x - getSprite("Perso2").getGlobalBounds().width / 2 > 0)
			Set_Gauche(true);
		else
			Set_Gauche(false);

		if (Keyboard::isKeyPressed(Keyboard::Right) && Position.x + getSprite("Perso2").getGlobalBounds().width / 2 < 1920)
			Set_Droite(true);
		else
			Set_Droite(false);

		if (Keyboard::isKeyPressed(Keyboard::Numpad0) && Timer > 0.5f && Nombre_Tir < Limite_Tir && app == true)
		{
			Set_Tir(true);
			Nombre_Tir++;
			Timer = 0;
		}
		else
			Set_Tir(false);

		Special.setScale(Vector2f(-1.f, 1.f));
	}

	if (Keyboard::isKeyPressed(Keyboard::Escape))
		Pause = true;

	if (Droite)
		Position.x += 200 * MainTime.GetTimeDeltaF();
	if (Gauche)
		Position.x -= 200 * MainTime.GetTimeDeltaF();

	if (Tir)
		Tir_Joueur.push_back(SI_Tir(Couleur, Position));

	if (Special_Jaune > 0)
	{
		Special.setFillColor(Color::Yellow);
		Special.setSize(Vector2f(22 * Special_Jaune, 10));
	}
	if (Special_Bleu > 0)
	{
		Special.setFillColor(Color::Blue);
		Special.setSize(Vector2f(20 * Special_Bleu, 10));
	}
	if (Special_Violet > 0)
	{
		Special.setFillColor(Color::Magenta);
		Special.setSize(Vector2f(20 * Special_Violet, 10));
	}
	if (Special_Vert > 0)
	{
		Special.setFillColor(Color::Green);
		Special.setSize(Vector2f(20 * Special_Vert, 10));
	}
}

void SI_Joueur::Draw()
{
	string Sprite_Name = "Perso";

	Sprite_Name += to_string(Numero_Joueur);
	getSprite(Sprite_Name).setOrigin(getSprite(Sprite_Name).getGlobalBounds().width / 2, getSprite(Sprite_Name).getGlobalBounds().height / 2);
	getSprite(Sprite_Name).setPosition(Position);
	App.draw(getSprite(Sprite_Name));
	
	App.draw(Special);
}