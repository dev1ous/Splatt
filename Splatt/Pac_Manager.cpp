#include "Pac_Manager.h"
#include "Perso_Pacman.h"

Perso_Pacman Pac;

void Pac_Update()
{
	Pac.Update();

}

void Pac_Display()
{

	string Sprite_Map = "PacMap";
	App.draw(getSprite(Sprite_Map));
	Pac.Display();

}