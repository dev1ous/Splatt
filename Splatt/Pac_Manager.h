#pragma once
#include "Tools.hpp"
#include "pch.h"
#include "Texture_SpriteManager.hpp"

void Pac_Update();
void Pac_Display();
void Niveau1_Pac();
void PacMenu();
void PacPause();
void Pac_Reset();
void Pac_GameOver();

enum Direction {

	RIEN,
	DROITE,
	GAUCHE,
	HAUT,
	BAS

};

extern Image Image_Masque;

enum class State_Pac
{
	Pause,
	Menu,
	Niveau1,
};
