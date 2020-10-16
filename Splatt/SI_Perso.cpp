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

void FullDraw_Perso(SI_Perso& _p)
{
    _p.Draw();
}

void FullUpdate(SI_Perso& _p)
{
    _p.Update();
}