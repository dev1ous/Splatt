#pragma once
#include "Tools.hpp"
#include "GamePad.h"



enum class Action
{
	Escape,
	Interact,
	UP,
	Down,
	Left,
	Right,

	Aste_Forward,
	Aste_RotateLeft,
	Aste_RotateRight,
	Aste_Fire,
	TronJ1_Gauche,
	TronJ1_Droite,
	TronJ1_Haut,
	TronJ1_Bas,
	TronJ2_Gauche,
	TronJ2_Droite,
	TronJ2_Haut,
	TronJ2_Bas,

	SIJ1_Gauche,
	SIJ1_Droite,
	SIJ1_Tir,
	SIJ1_TirSpe,

	SIJ2_Gauche,
	SIJ2_Droite,
	SIJ2_Tir,
	SIJ2_TirSpe,
};


struct Controle
{
	Controle(Action _name, sf::Keyboard::Key _baseTouche, bool _button, gamepadPS4 Button_or_Axis, int Axis_direction = 0, int _speManette = -1);

	Action name;

	sf::Keyboard::Key KeyBoard;
	
	gamepadPS4 PadKey;
	bool isButton;
	int AxisDirection;
	int speManette;
};

////////////////////////////////////////////////////////////
// \brief Check if an action is done
// \param The name of the action checked
// \param Check a specifique pad :
// \param                    0 - 7 Pad Number
// \param                    8 = keyboard 
// \param                    -1 = CheckAll
// \return True / False
////////////////////////////////////////////////////////////
bool isButtonPressed(Action Name, int Object_Number = -1);

void ResetButtonsPressed();

void InitControles();

extern std::list<Controle> controles;
extern std::list<sf::Keyboard::Key> PressedKey;