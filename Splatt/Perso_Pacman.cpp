#include "Perso_Pacman.h"

Perso_Pacman::Perso_Pacman()
{

	PosX = 300;
	PosY = 300;
	Direction_Pac = RIEN;
	
}

Perso_Pacman::~Perso_Pacman()
{
}

void Perso_Pacman::Mort()
{

}

void Perso_Pacman::Deplacement()
{
	if ((Keyboard::isKeyPressed(Keyboard::Q)))
	{
		Direction_Pac = GAUCHE;
	}
	if ((Keyboard::isKeyPressed(Keyboard::D)))
	{
		Direction_Pac = DROITE;
	}
	if ((Keyboard::isKeyPressed(Keyboard::Z)))
	{
		Direction_Pac = HAUT;
	}
	if ((Keyboard::isKeyPressed(Keyboard::S)))
	{
		Direction_Pac = BAS;
	}
}

void Perso_Pacman::Update()
{
	Deplacement();

	switch (Direction_Pac)
	{
	case DROITE:

		PosX += 200 * MainTime.GetTimeDeltaF();
		rotate = 0;
	
		break;
	case GAUCHE:

		PosX -= 200 * MainTime.GetTimeDeltaF();
		rotate = 180;


		break;
	case HAUT:

		PosY -= 200 * MainTime.GetTimeDeltaF();
		rotate = 270;


		break;
	case BAS:

		PosY += 200 * MainTime.GetTimeDeltaF();
		rotate = 90;
		

		break;
	default:
		break;
	}

}

void Perso_Pacman::Display()
{
	//anim
	static bool one_pass = true;
	static IntRect Anim_Pac = { 0,0,60,59 };
	static float timer = 0;
	timer += MainTime.GetTimeDeltaF();

	if (timer > 0.1f)
	{
		if (Anim_Pac.left == 180)
		{
			Anim_Pac.left = -60;
		}
		Anim_Pac.left += 60;
		timer = 0;

	}
	//draw

	//getSprite("Pac").setScale(0.5f, 0.5f);
	getSprite("Pac").setOrigin(getSprite("Pac").getGlobalBounds().width / 2, getSprite("Pac").getGlobalBounds().height / 2);
	getSprite("Pac").setTextureRect(Anim_Pac);
	getSprite("Pac").setPosition(PosX, PosY);
	getSprite("Pac").setRotation(rotate);
	App.draw(getSprite("Pac"));

}
