#include "SI_Perso.h"

SI_Perso::SI_Perso()
{
    Position.x = 0;
    Position.y = 0;
    Origine.x = 0;
    Origine.y = 0;
    Timer = 0;
    life = 0;
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
