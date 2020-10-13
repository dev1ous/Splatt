#include "SI_Tir.h"

SI_Tir::SI_Tir()
{
	Position.x = 0;
	Position.y = 0;
}

SI_Tir::SI_Tir(Color _color, Vector2f _position)
{
	Radius = 10;
	CircleShape intermediaire(Radius);
	Ball = intermediaire;
	Ball.setOrigin(Vector2f(Radius, Radius));
	Ball.setFillColor(_color);
	Position.x = _position.x;
	Position.y = _position.y;
	destruction = false;
}

SI_Tir::~SI_Tir()
{
}

Vector2f SI_Tir::Get_Position()
{
	return Position;
}

bool SI_Tir::Get_Destruct()
{
	return destruction;
}

float SI_Tir::Get_Radius()
{
	return Radius;
}

void SI_Tir::Set_Position(Vector2f _position)
{
	Position = _position;
}

void SI_Tir::Set_Destruct(bool _bool)
{
	destruction = _bool;
}

void SI_Tir::Update()
{
	Position.y -= 500 * MainTime.GetTimeDeltaF();
	if (Position.x < 0 || Position.x > 1920 || Position.y < 0 || Position.y > 1080)
		destruction = true;

	Ball.setPosition(Position);
}

void SI_Tir::Draw()
{
	App.draw(Ball);
}