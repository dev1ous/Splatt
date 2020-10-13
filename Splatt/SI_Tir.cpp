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
}

SI_Tir::~SI_Tir()
{
}

Vector2f SI_Tir::Get_Position()
{
	return Position;
}

void SI_Tir::Set_Position(Vector2f _position)
{
	Position = _position;
}

void SI_Tir::Update()
{
	Position.y -= 350 * MainTime.GetTimeDeltaF();
	Ball.setPosition(Position);
}

void SI_Tir::Draw()
{
	App.draw(Ball);
}

