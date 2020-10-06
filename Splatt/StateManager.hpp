#pragma once
#include "Tools.hpp"

// pacman
// tetris
// asteroid
// tron
// lunar lander
// space invaders

// state enum
enum class State
{
	RTNULL,
	MENU,
	SPACE_INVADER,
	PACMAN,
	LUNAR_LANDER,
	ASTEROID,
	TETRIS,
	TRON

};
extern State state;

void EventsManager();

/////////////
/// \brief Managements of updates based on state
/// \param Windows
/// /////////////
void UpdateManager();

/////////////
/// \brief Managements of diplays based on state
/// \param Windows
/// /////////////
void DisplayManager();
