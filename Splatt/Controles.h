#pragma once
#include "Tools.hpp"
#include "GamePad.h"



enum class Action
{
	Escape,
	Aste_Forward,
	Aste_RotateLeft,
	Aste_RotateRight,
	Aste_Fire,
};


struct Controle
{
	Controle(Action _name, sf::Keyboard::Key _baseTouche, bool _button, gamepadPS4 Button_or_Axis, int Axis_direction = 0);

	Action name;

	sf::Keyboard::Key KeyBoard;
	
	gamepadPS4 PadKey;
	bool isButton;
	int AxisDirection;
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