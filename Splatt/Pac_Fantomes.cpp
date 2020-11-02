#include "Pac_Fantomes.h"


Pac_Fantomes::Pac_Fantomes()
{

}

Pac_Fantomes::Pac_Fantomes(int _type)
{
	type = _type;
	rand = 1;
	Direction_Fantome = RIEN;

	NextPosOnMap.x = 0;
	NextPosOnMap.y = 0;

	Anim_Fantome = { 0,0,60,60 };

	passage = false;

	if (type == 0)
	{
		PosX = 990;
		PosY = 510;
		demarrage = true;
		changement = false;

	}
	if (type == 1)
	{
		PosX = 990;
		PosY = 450;
		demarrage = true;
		changement = false;

	}
	if (type == 2)
	{
		PosX = 990;
		PosY = 390;
		demarrage = true;
		changement = true;

	}
	if (type == 3)
	{
		PosX = 990;
		PosY = 570;
		demarrage = true;
		changement = true;
	}
}

Pac_Fantomes::~Pac_Fantomes()
{
}

void Pac_Fantomes::Mort()
{
	rand = 1;
	Direction_Fantome = RIEN;

	NextPosOnMap.x = 0;
	NextPosOnMap.y = 0;

	passage = false;

	timer = 0;

	if (type == 0)
	{
		PosX = 990;
		PosY = 510;
		demarrage = true;
		changement = false;

	}
	if (type == 1)
	{
		PosX = 990;
		PosY = 450;
		demarrage = true;
		changement = false;

	}
	if (type == 2)
	{
		PosX = 990;
		PosY = 390;
		demarrage = true;
		changement = true;

	}
	if (type == 3)
	{
		PosX = 990;
		PosY = 570;
		demarrage = true;
		changement = true;
	}

}

void Pac_Fantomes::Deplacement()
{

	timer += MainTime.GetTimeDeltaF();

	if (type == 0)
	{
		if (demarrage == true)
		{
			if (PosY <= 510 && PosX < 1170)
			{
				Direction_Fantome = DROITE;
			}
			else
			{
				int rand = irandom(1, 3);
				if (rand == 1)
				{
					Direction_Fantome = HAUT;
				}
				else
				{
					Direction_Fantome = BAS;
				}

				demarrage = false;
			}
		}
		_Fantome = getSprite("Fantome0").getGlobalBounds();
	}
	else if (type == 1)
	{
		if (demarrage == true)
		{
			if (PosY >= 450 && PosX < 1170)
			{
				Direction_Fantome = DROITE;
			}
			else
			{
				int rand = irandom(1, 3);
				if (rand == 1)
				{
					Direction_Fantome = HAUT;
				}
				else
				{
					Direction_Fantome = BAS;
				}

				demarrage = false;
			}
		}
		_Fantome = getSprite("Fantome1").getGlobalBounds();
	}
	else if (type == 2)
	{
		if (demarrage == true)
		{

			if (PosY < 450)
			{
				Direction_Fantome = BAS;
			}
			else if (PosX < 1170)
			{
				Direction_Fantome = DROITE;
			}
			else if (PosX >= 1170)
			{
				int rand = irandom(1, 3);
				if (rand == 1)
				{
					Direction_Fantome = HAUT;
				}
				else
				{
					Direction_Fantome = BAS;
				}
				demarrage = false;
				timer = 0;

			}
		}
		_Fantome = getSprite("Fantome2").getGlobalBounds();
	}
	else if (type == 3)
	{
		if (demarrage == true)
		{

			if (PosY > 510)
			{
				Direction_Fantome = HAUT;
			}
			else if (PosX < 1170)
			{
				Direction_Fantome = DROITE;
			}
			else if (PosX >= 1170)
			{

				int rand = irandom(1, 3);
				if (rand == 1)
				{
					Direction_Fantome = HAUT;
				}
				else
				{
					Direction_Fantome = BAS;
				}
				demarrage = false;
				timer = 0;

			}

		}
		_Fantome = getSprite("Fantome3").getGlobalBounds();
	}




}

void Pac_Fantomes::Update()
{
	Deplacement();
	switch (Direction_Fantome)
	{

	case DROITE:

		PosX += 210 * MainTime.GetTimeDeltaF();

		break;
	case GAUCHE:

		PosX -= 210 * MainTime.GetTimeDeltaF();

		break;
	case HAUT:

		PosY -= 210 * MainTime.GetTimeDeltaF();

		break;
	case BAS:

		PosY += 210 * MainTime.GetTimeDeltaF();

		break;
	default:
		break;
	}

	if (demarrage == false)
	{

		Path(Image_Masque);

	}
}

void Pac_Fantomes::Display()
{

	string Sprite_Name = "Fantome";

	Sprite_Name += to_string(type);
	getSprite(Sprite_Name).setOrigin(getSprite(Sprite_Name).getGlobalBounds().width / 2, getSprite(Sprite_Name).getGlobalBounds().height / 2);
	getSprite(Sprite_Name).setTextureRect(Anim_Fantome);
	getSprite(Sprite_Name).setOrigin(getSprite(Sprite_Name).getGlobalBounds().width / 2, getSprite(Sprite_Name).getGlobalBounds().height / 2);
	getSprite(Sprite_Name).setPosition(PosX, PosY);
	App.draw(getSprite(Sprite_Name));

}

void Pac_Fantomes::Path(Image _Image)
{

	Masque = _Image.getPixel(PosX, PosY);


	NextPosOnMap.y = PosY;
	NextPosOnMap.x = (PosX - 30 - (210 * MainTime.GetTimeDeltaF()));
	MasqueGAUCHE = _Image.getPixel(NextPosOnMap.x - 15, NextPosOnMap.y);

	NextPosOnMap.x = PosX;
	NextPosOnMap.y = (PosY + 30 + (210 * MainTime.GetTimeDeltaF()));
	MasqueBAS = _Image.getPixel(NextPosOnMap.x, NextPosOnMap.y + 15);

	NextPosOnMap.y = PosY;
	NextPosOnMap.x = (PosX + 30 + (210 * MainTime.GetTimeDeltaF()));
	MasqueDROITE = _Image.getPixel(NextPosOnMap.x + 15, NextPosOnMap.y);

	NextPosOnMap.x = PosX;
	NextPosOnMap.y = (PosY - 30 - (210 * MainTime.GetTimeDeltaF()));
	MasqueHAUT = _Image.getPixel(NextPosOnMap.x, NextPosOnMap.y - 15);

	if (Masque == Color::Red && timer > 0.1f)
	{
		passage = true;


		while (passage == true)
		{
			rand = irandom(1, 5);
			if (rand == 1)
			{
				if (MasqueGAUCHE == Color::White && Direction_Fantome != DROITE)
				{
					Direction_Fantome = GAUCHE;
					timer = 0;
					passage = false;
				}

			}
			if (rand == 2)
			{

				if (MasqueBAS == Color::White && Direction_Fantome != HAUT)
				{
					Direction_Fantome = BAS;
					timer = 0;
					passage = false;
				}

			}
			if (rand == 3)
			{
				if (MasqueDROITE == Color::White && Direction_Fantome != GAUCHE)
				{
					Direction_Fantome = DROITE;
					timer = 0;
					passage = false;
				}

			}
			if (rand == 4)
			{

				if (MasqueHAUT == Color::White && Direction_Fantome != BAS)
				{
					Direction_Fantome = HAUT;
					timer = 0;
					passage = false;
				}

			}
		}

	}
}

FloatRect Pac_Fantomes::Get_Rect()
{
	return _Fantome;
}

void Pac_Fantomes::Set_Anim(int _rec)
{
	Anim_Fantome.left = _rec;
}



