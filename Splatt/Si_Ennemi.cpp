#include "SI_Ennemi.h"

SI_Ennemi::SI_Ennemi()
{
	life = 1;
	Type = 1;
	Nombre_Ennemis++;
	Droite = false;
	Gauche = false;
	Tir = false;
	life = 1;
	Timer = 0;
}

SI_Ennemi::SI_Ennemi(Vector2f _position, int _type)
{
	life = 1;
	Type = _type;
	Nombre_Ennemis++;
	Droite = false;
	Gauche = false;
	Tir = false;
	life = 1;
	Timer = 0;
	Position = _position;
}

SI_Ennemi::~SI_Ennemi()
{
}

bool SI_Ennemi::Get_Droite()
{
	return Droite;
}

bool SI_Ennemi::Get_Gauche()
{
	return Gauche;
}

bool SI_Ennemi::Get_Tir()
{
	return Tir;
}

void SI_Ennemi::Set_Droite(bool _bool)
{
	Droite = _bool;
}

void SI_Ennemi::Set_Gauche(bool _bool)
{
	Gauche = _bool;
}

void SI_Ennemi::Set_Tir(bool _bool)
{
	Tir = _bool;
}

void SI_Ennemi::Update()
{
	string Sprite_Name = "Ennemy";

	Sprite_Name += to_string(Type);
	if (Position.x - getSprite(Sprite_Name).getGlobalBounds().width / 2 < 0)
		for (SI_Ennemi* Actual_Ennemy : EnnemyList)
		{
			Droite = true;
			Gauche = false;
		}

	if (Position.x + getSprite(Sprite_Name).getGlobalBounds().width / 2 > 1920)
		for (SI_Ennemi* Actual_Ennemy : EnnemyList)
		{
			Droite = false;
			Gauche = true;
		}

}

void SI_Ennemi::Draw()
{
	string Sprite_Name = "Ennemi";

	Sprite_Name += to_string(Type);
	getSprite(Sprite_Name).setOrigin(getSprite(Sprite_Name).getGlobalBounds().width / 2, getSprite(Sprite_Name).getGlobalBounds().height / 2);
	getSprite(Sprite_Name).setPosition(Position);
	App.draw(getSprite(Sprite_Name));
}