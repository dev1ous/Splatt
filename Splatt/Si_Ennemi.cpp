#include "SI_Ennemi.h"

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
	life = 1;
	Type = _type;
	Droite = false;
	Gauche = true;
	Descente = false;
	Tir = false;
	life = 1;
	Timer = 0;
	Position = _position;
}

SI_Ennemi::~SI_Ennemi()
{
	
}

void SI_Ennemi::Update()
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
			Position.y += Vitesse * MainTime.GetTimeDeltaF();
			if (Timer > 0.5f)
			{
				Descente = false;
				Timer = 0;
			}
		}
		else
			Position.x -= Vitesse * MainTime.GetTimeDeltaF();
	}

	if (Droite)
	{
		if (Descente)
		{
			Timer += MainTime.GetTimeDeltaF();
			Position.y += Vitesse * MainTime.GetTimeDeltaF();
			if (Timer > 0.5f)
			{
				Descente = false;
				Timer = 0;
			}
		}
		else
			Position.x += Vitesse * MainTime.GetTimeDeltaF();
	}

	if (Keyboard::isKeyPressed(Keyboard::Numpad1))
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
}