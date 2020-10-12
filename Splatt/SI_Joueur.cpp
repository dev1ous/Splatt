#include "SI_Joueur.h"

SI_Joueur::SI_Joueur()
{
	life = 1;
	Numero_Joueur = 1;
	Droite = false;
	Gauche = false;
	Tir = false;
	life = 1;
	Timer = 0;
}

SI_Joueur::SI_Joueur(Vector2f _position, int _numerojoueur)
{
	life = 1;
	Numero_Joueur = _numerojoueur;
	Droite = false;
	Gauche = false;
	Tir = false;
	Timer = 0;
	Position = _position;
}

SI_Joueur::~SI_Joueur()
{
}

int SI_Joueur::Get_Numero()
{
	return Numero_Joueur;
}

bool SI_Joueur::Get_Droite()
{
	return Droite;
}

bool SI_Joueur::Get_Gauche()
{
	return Gauche;
}

bool SI_Joueur::Get_Tir()
{
	return Tir;
}

void SI_Joueur::Set_Numero(int _numero)
{
	Numero_Joueur = _numero;
}

void SI_Joueur::Set_Droite(bool _bool)
{
	Droite = _bool;
}

void SI_Joueur::Set_Gauche(bool _bool)
{
	Gauche = _bool;
}

void SI_Joueur::Set_Tir(bool _bool)
{
	Tir = _bool;
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
	}

	if (Droite)
		Position.x += 200 * MainTime.GetTimeDeltaF();
	if (Gauche)
		Position.x -= 200 * MainTime.GetTimeDeltaF();
}

void SI_Joueur::Draw()
{
	string Sprite_Name = "Perso";

	Sprite_Name += to_string(Numero_Joueur);
	getSprite(Sprite_Name).setOrigin(getSprite(Sprite_Name).getGlobalBounds().width / 2, getSprite(Sprite_Name).getGlobalBounds().height / 2);
	getSprite(Sprite_Name).setPosition(Position);
	App.draw(getSprite(Sprite_Name));
	
}