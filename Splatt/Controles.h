//#pragma once
//#include "Tools.hpp"
//#include "GamePad.h"
//
//
//
//enum Action
//{
//	Forward,
//	RotateLeft,
//	RotateRight,
//	Fire,
//};
//
//
//struct Controle
//{
//	Controle(int _name, sf::Keyboard::Key _baseTouche, bool _button, gamepadPS4 Button_or_Axis, int Axis_direction = 0);
//
//	int name;
//
//	sf::Keyboard::Key KeyBoard;
//	
//	gamepadPS4 PadKey;
//	bool isButton;
//	int AxisDirection;
//};
//
//////////////////////////////////////////////////////////////
//// \brief Check if an action is done
//// \param The name of the action checked
//// \param Check a specifique pad :
//// \param                    0 - 7 Pad Number
//// \param                    8 = keyboard 
//// \param                    -1 = CheckAll
//// \return True / False
//////////////////////////////////////////////////////////////
//bool isButtonPressed(int Name, int Object_Number = -1);
//
//
//void ResetButtonsPressed();
//
//extern std::list<Controle> controles;
//extern std::list<sf::Keyboard::Key> PressedKey;