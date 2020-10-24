#pragma once
#include "Tools.hpp"
#include "pch.h"
#include "Texture_SpriteManager.hpp"

enum class State_SI
{
	Intro,
	Menu,
	Niveau1,
	Niveau2,
	Niveau3,
};

extern bool app;

void SI_Update();
void SI_Display();
void Intro();
void Menu();
void Niveau1();
bool App_Ennemis(int _rangeX, int _rangeY, int _typeMin, int _typeMax);