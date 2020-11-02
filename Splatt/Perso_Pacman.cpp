#include "Perso_Pacman.h"



Perso_Pacman::Perso_Pacman()
{

	PosX = 90;
	PosY = 90;
	Direction_Pac = RIEN;
	Power_up = false;
	vie = 3;
}

Perso_Pacman::~Perso_Pacman()
{
}

void Perso_Pacman::Mort()
{

	PosX = 90;
	PosY = 90;
	Direction_Pac = RIEN;
	Power_up = false;
	vie--;


}

void Perso_Pacman::Reset()
{
	PosX = 90;
	PosY = 90;
	Direction_Pac = RIEN;
	Power_up = false;
	vie = 3;
}

void Perso_Pacman::Deplacement()
{
	if (PosX > 0 && PosX < 1920 && PosY > 0 && PosY < 1080)
	{
		if ((Keyboard::isKeyPressed(Keyboard::Q)))
		{
			if (Collision(Image_Masque, GAUCHE) == false)
			{
				Direction_Pac = GAUCHE;
			}
		}

		if ((Keyboard::isKeyPressed(Keyboard::D)))
		{
			if (Collision(Image_Masque, DROITE) == false)
			{
				Direction_Pac = DROITE;
			}
		}
		if ((Keyboard::isKeyPressed(Keyboard::Z)))
		{
			if (Collision(Image_Masque, HAUT) == false)
			{
				Direction_Pac = HAUT;
			}
		}
		if ((Keyboard::isKeyPressed(Keyboard::S)))
		{
			if (Collision(Image_Masque, BAS) == false)
			{
				Direction_Pac = BAS;
			}
		}
	}

	if (PosY < -30)
	{
		PosY = 1110;
	}
	if (PosY > 1110)
	{
		PosY = -30;
	}

	if (PosX < -30)
	{
		PosX = 1950;
	}
	if (PosX > 1950)
	{
		PosX = -30;
	}
}

void Perso_Pacman::Update()
{

	_Pac = getSprite("Pac").getGlobalBounds();

	Deplacement();



	switch (Direction_Pac)
	{
	case DROITE:

		rotate = 0;
		if (Collision(Image_Masque, DROITE) == false)
		{
			PosX += 200 * MainTime.GetTimeDeltaF();

		}
		break;
	case GAUCHE:

		rotate = 180;
		if (Collision(Image_Masque, GAUCHE) == false)
		{
			PosX -= 200 * MainTime.GetTimeDeltaF();

		}
		break;
	case HAUT:

		rotate = 270;
		if (Collision(Image_Masque, HAUT) == false)
		{
			PosY -= 200 * MainTime.GetTimeDeltaF();

		}
		break;
	case BAS:

		rotate = 90;
		if (Collision(Image_Masque, BAS) == false)
		{
			PosY += 200 * MainTime.GetTimeDeltaF();


		}
		break;
	default:
		break;
	}

}

void Perso_Pacman::Display()
{
	//anim

	static IntRect Anim_Pac = { 0,0,59,59 };
	static float timer = 0;
	timer += MainTime.GetTimeDeltaF();

	if (timer > 0.1f)
	{
		if (Anim_Pac.left == 177)
		{
			Anim_Pac.left = -59;
		}
		Anim_Pac.left += 59;
		timer = 0;

	}


	//draw
	getSprite("Pac").setOrigin(getSprite("Pac").getGlobalBounds().width / 2, getSprite("Pac").getGlobalBounds().height / 2);
	getSprite("Pac").setTextureRect(Anim_Pac);
	getSprite("Pac").setPosition(PosX, PosY);
	getSprite("Pac").setRotation(rotate);
	App.draw(getSprite("Pac"));


	getSprite("Vie").setPosition(100, 1030);
	App.draw(getSprite("Vie"));
	if (vie >= 2)
	{
		getSprite("Vie").setPosition(150, 1030);
		App.draw(getSprite("Vie"));
	}
	if (vie == 3)
	{
		getSprite("Vie").setPosition(200, 1030);
		App.draw(getSprite("Vie"));
	}


}

int Perso_Pacman::Get_Vie()
{
	return vie;
}

FloatRect Perso_Pacman::Get_Rect()
{
	return _Pac;
}

bool Perso_Pacman::Get_Power_up()
{
	return Power_up;
}

void Perso_Pacman::Set_vie()
{
	vie = vie - 1;
}

void Perso_Pacman::Set_Power_up(bool _type)
{
	Power_up = _type;
}

bool Perso_Pacman::Collision(Image _Image, Direction _direction)
{
	Vector2f NextPosOnMap;

	FloatRect _player;

	Color Masque;
	Color Masque2;


	_player = getSprite("Pac").getGlobalBounds();

	switch (_direction)
	{
	case DROITE:
		NextPosOnMap.y = PosY;
		NextPosOnMap.x = (PosX + _player.width / 2 + (200 * MainTime.GetTimeDeltaF()));
		if (NextPosOnMap.y > 0 && NextPosOnMap.y < 1080)
		{
			Masque = _Image.getPixel(NextPosOnMap.x, (NextPosOnMap.y - _player.height / 2) + 4);
			Masque2 = _Image.getPixel(NextPosOnMap.x, (NextPosOnMap.y + _player.height / 2) - 4);
		}
		else
		{
			return false;
		}

		break;
	case GAUCHE:

		NextPosOnMap.y = PosY;
		NextPosOnMap.x = (PosX - _player.width / 2 - (200 * MainTime.GetTimeDeltaF()));
		if (NextPosOnMap.y > 0 && NextPosOnMap.y < 1080)
		{
			Masque = _Image.getPixel(NextPosOnMap.x, (NextPosOnMap.y - _player.height / 2) + 4);
			Masque2 = _Image.getPixel(NextPosOnMap.x, (NextPosOnMap.y + _player.height / 2) - 4);
		}
		else
		{
			return false;
		}

		break;
	case HAUT:

		NextPosOnMap.x = PosX;
		NextPosOnMap.y = (PosY - _player.height / 2 - (200 * MainTime.GetTimeDeltaF()));
		if (NextPosOnMap.y > 0 && NextPosOnMap.y < 1080)
		{
			Masque = _Image.getPixel((NextPosOnMap.x - _player.width / 2) + 4, NextPosOnMap.y);
			Masque2 = _Image.getPixel((NextPosOnMap.x + _player.width / 2) - 4, NextPosOnMap.y);
		}
		else
		{
			return false;
		}

		break;
	case BAS:

		NextPosOnMap.x = PosX;
		NextPosOnMap.y = (PosY + _player.height / 2 + (200 * MainTime.GetTimeDeltaF()));
		if (NextPosOnMap.y > 0 && NextPosOnMap.y < 1080)
		{
			Masque = _Image.getPixel((NextPosOnMap.x - _player.width / 2) + 4, NextPosOnMap.y);
			Masque2 = _Image.getPixel((NextPosOnMap.x + _player.width / 2) - 4, NextPosOnMap.y);
		}
		else
		{
			return false;
		}
		break;
	default:
		break;
	}

	if (Masque == Color::White && Masque2 == Color::White)
	{
		return false;
	}
	else if (Masque == Color::Black || Masque2 == Color::Black)
	{
		return true;
	}

}




