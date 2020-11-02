#include "Pac_Gum.h"

Pac_Gum::Pac_Gum()
{
	PosX = 30;
	PosY = 30;
	Mort = false;
}

Pac_Gum::~Pac_Gum()
{

}


void Pac_Gum::Display()
{
	App.draw(getSprite("Gums"));
}


void Pac_Gum::Set_Mort()
{
	Mort = true;
}

void Pac_Gum::Set_PosX(float _pos)
{
	PosX = _pos;
}

void Pac_Gum::Set_PosY(float _pos)
{
	PosY = _pos;
}

void Pac_Gum::Set_Rect(FloatRect _rec)
{
	_Gum = _rec;
}

void Pac_Gum::Reset()
{
	PosX = 30;
	PosY = 30;
	Mort = false;
}

FloatRect Pac_Gum::Get_Rect()
{
	return _Gum;
}

bool Pac_Gum::Get_Mort()
{
	return Mort;
}
