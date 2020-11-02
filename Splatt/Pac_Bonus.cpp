#include "Pac_Bonus.h"

Pac_Bonus::Pac_Bonus()
{

}

Pac_Bonus::Pac_Bonus(int _type)
{
	type = _type;

	if (type == 1)
	{
		PosX = 80;
		PosY = 980;

	}
	else if (type == 2)
	{
		PosX = 1820;
		PosY = 980;
	}
	else if (type == 3)
	{
		PosX = 1400;
		PosY = 80;
	}
	else if (type == 4)
	{
		PosX = 1340;
		PosY = 560;
	}
	else if (type == 5)
	{
		PosX = 860;
		PosY = 260;
	}
	else if (type == 6)
	{
		PosX = 620;
		PosY = 680;
	}

}

Pac_Bonus::~Pac_Bonus()
{
}

void Pac_Bonus::Display()
{
	getSprite("Bonus").setPosition(PosX, PosY);
	_Bonus = getSprite("Bonus").getGlobalBounds();
	App.draw(getSprite("Bonus"));
}

void Pac_Bonus::Update()
{
}

FloatRect Pac_Bonus::Get_Rect()
{
	return _Bonus;
}

void Pac_Bonus::Reset()
{

	if (type == 1)
	{
		PosX = 80;
		PosY = 980;

	}
	else if (type == 2)
	{
		PosX = 1820;
		PosY = 980;
	}
	else if (type == 3)
	{
		PosX = 1400;
		PosY = 80;
	}
	else if (type == 4)
	{
		PosX = 1340;
		PosY = 560;
	}
	else if (type == 5)
	{
		PosX = 860;
		PosY = 260;
	}
	else if (type == 6)
	{
		PosX = 620;
		PosY = 680;
	}

}

void Pac_Bonus::Set_PosX()
{
	PosX = -1000;
}
