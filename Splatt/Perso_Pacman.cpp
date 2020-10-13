#include "Perso_Pacman.h"

Perso_Pacman::Perso_Pacman()
{
	PosX = 300;
	PosY = 300;
}

Perso_Pacman::~Perso_Pacman()
{
}

void Perso_Pacman::Display()
{
	static IntRect Anim_Pac = { 0,0,134,132 };
	static float timer = 0;
	timer += MainTime.GetTimeDeltaF();

	if (timer > 0.1f)
	{
		if (Anim_Pac.left == 402)
		{
			Anim_Pac.left = -134;
		}
		Anim_Pac.left += 134;
		timer = 0;

	}
	getSprite("Pac").setOrigin(getSprite("Pac").getGlobalBounds().width / 2, getSprite("Pac").getGlobalBounds().height / 2);
	getSprite("Pac").setScale(0.5f, 0.5f);
	getSprite("Pac").setPosition(PosX, PosY);
	getSprite("Pac").setTextureRect(Anim_Pac);
	App.draw(getSprite("Pac"));

}
