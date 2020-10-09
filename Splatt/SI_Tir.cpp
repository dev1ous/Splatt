#include "SI_Tir.h"

SI_Tir::SI_Tir()
{
	Position.x = 0;
	Position.y = 0;
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
