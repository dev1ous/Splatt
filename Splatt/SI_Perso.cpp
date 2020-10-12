#include "SI_Perso.h"

SI_Perso::SI_Perso()
{
    Position.x = 0;
    Position.y = 0;
    Origine.x = 0;
    Origine.y = 0;
    life = 1;
}

SI_Perso::~SI_Perso()
{
}

Vector2f SI_Perso::Get_Position()
{
    return Position;
}

Vector2f SI_Perso::Get_Origin()
{
    return Origine;
}

int SI_Perso::Get_Life()
{
    return life;
}

void SI_Perso::Set_Position(Vector2f _position)
{
    Position = _position;
}

void SI_Perso::Set_Origin(Vector2f _origine)
{
    Origine = _origine;
}

void SI_Perso::Set_Life(int _life)
{
    life = _life;
}