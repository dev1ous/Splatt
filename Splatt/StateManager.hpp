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
	ALL,
	MENU,
	SPACE_INVADER,
	PACMAN,
	LUNAR_LANDER,
	ASTEROID,
	TETRIS,
	TRON

};
extern State state;
extern bool Pause;

void EventsManager();

void ChangeState(State NextState);

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
