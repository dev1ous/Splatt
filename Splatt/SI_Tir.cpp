#include "SI_Tir.h"

SI_Tir::SI_Tir()
{
	Position.x = 0;
	Position.y = 0;
}

SI_Tir::SI_Tir(Color _color, Vector2f _position, int _type)
{
	Type = _type;
	Radius = 10;

	CircleShape intermediaire(Radius);
	Ball = intermediaire;
	Ball.setOrigin(Vector2f(Radius, Radius));
	Ball.setFillColor(_color);

	Position.x = _position.x;
	Position.y = _position.y;
	Delta.x = 20 * sin(0);
	Delta.y = 20 * cos(0);
	destruction = false;
	Activation = false;
	timer = 0;
}

SI_Tir::SI_Tir(Vector2f _position, int _type, float _randtir)
{
	Type = _type;
	Radius = 10;
	Position.x = _position.x;
	Position.y = _position.y;

	Delta.x = 20.f * sin(_randtir);
	Delta.y = 20.f * cos(_randtir);
	
	destruction = false;
	Activation = false;
	timer = 0;

	CircleShape intermediaire(Radius);
	Ball = intermediaire;
	Ball.setOrigin(Vector2f(Radius, Radius));
	Ball.setFillColor(Color::Black);
}

SI_Tir::~SI_Tir()
{
}

void SI_Tir::Update_Joueur()
{
	if (Type == 1)
	{
		Position.x -= 40 * Delta.x * MainTime.GetTimeDeltaF();
		Position.y -= 40 * Delta.y * MainTime.GetTimeDeltaF();
	}
	else if (Type < 6)
	{
		if (Activation == false)
		{
			Position.x -= 40 * Delta.x * MainTime.GetTimeDeltaF();
			Position.y -= 40 * Delta.y * MainTime.GetTimeDeltaF();
		}
		else
		{
			if (Type == 2)
			{
				Position.x -= 40 * Delta.y * MainTime.GetTimeDeltaF();
				Position.y -= 40 * Delta.x * MainTime.GetTimeDeltaF();
			}
			if (Type == 3)
			{
				Position.x += 40 * Delta.y * MainTime.GetTimeDeltaF();
				Position.y -= 40 * Delta.x * MainTime.GetTimeDeltaF();
			}
			if (Type == 4)
			{
				Position.x -= 40 * Delta.x * MainTime.GetTimeDeltaF();
				Position.y -= 40 * Delta.y * MainTime.GetTimeDeltaF();
			}
			if (Type == 5)
			{
				timer += MainTime.GetTimeDeltaF();
				Set_Radius(200);
				if (timer > 0.05f)
					destruction = true;
			}
		}
	}

	if (Position.x < 0 || Position.x > 1920 || Position.y < 0 || Position.y > 1080)
		destruction = true;

	Ball.setPosition(Position);
}

void SI_Tir::Update_Ennemi()
{
	if (Type == 4 || Type == 1)
	{
		Position.x += 40 * Delta.y * MainTime.GetTimeDeltaF();
		Position.y += 40 * Delta.x * MainTime.GetTimeDeltaF();
	}
	else
	{
		Position.x += 40 * Delta.x * MainTime.GetTimeDeltaF();
		Position.y += 40 * Delta.y * MainTime.GetTimeDeltaF();
	}

	if (Position.x < 0 || Position.x > 1920 || Position.y < 0 || Position.y > 1080)
		destruction = true;

	Ball.setPosition(Position);

}

void SI_Tir::Draw()
{
	App.draw(Ball);
}