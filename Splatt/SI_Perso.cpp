#include "SI_Perso.h"

SI_Perso::SI_Perso()
{
    Position.x = 0;
    Position.y = 0;
    Origine.x = 0;
    Origine.y = 0;
    life = 1;
    Timer = 0;
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

float SI_Perso::Get_Timer()
{
    return Timer;
}

int SI_Perso::Get_Life()
{
    return life;
}

bool SI_Perso::Get_Droite()
{
    return Droite;
}

bool SI_Perso::Get_Gauche()
{
    return Gauche;
}

bool SI_Perso::Get_Tir()
{
    return Tir;
}

void SI_Perso::Set_Position(Vector2f _position)
{
    Position = _position;
}

void SI_Perso::Set_Origin(Vector2f _origine)
{
    Origine = _origine;
}

void SI_Perso::Set_Timer(float _timer)
{
    Timer = _timer;
}

void SI_Perso::Set_Life(int _life)
{
    life = _life;
}

void SI_Perso::Set_Droite(bool _bool)
{
    Droite = _bool;
}

void SI_Perso::Set_Gauche(bool _bool)
{
    Gauche = _bool;
}

void SI_Perso::Set_Tir(bool _bool)
{
    Tir = _bool;
}

void FullDraw_Perso(SI_Perso& _p)
{
    _p.Draw();
}

void FullUpdate(SI_Perso& _p)
{
    _p.Update();
}