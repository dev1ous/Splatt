#pragma once
#include "Tools.hpp"
#include "pch.h"
#include "Texture_SpriteManager.hpp"
#include "Controles.h"

enum class State_SI
{
	Menu,
	Niveau1,
	Niveau2,
	Niveau3,
};

extern bool app;
extern bool Debut_Niveau;
extern bool Load;

void reset();
void reset_Joueur(int Nombre_tirJ1, int Nombre_tirJ2);
void SI_Update();
void SI_Display();
void Menu();
void Pause_update();
void Niveau1();
void Niveau2();
void Niveau3();
bool App_Ennemis(int _rangeX, int _rangeY, int _typeMin, int _typeMax);
void Display_Controle(const int& x);