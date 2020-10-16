#pragma once
#include "tools.hpp"

enum class gamepadPS4
{
	// Buttons
	A,
	B,
	X,
	Y,
	L1,
	R1,
	Select,
	Start,
	BSTICKL,
	BSTICKR,
	PS,
	BTOUCHPAD,
	L2,
	R2,
	NOTUSED,

	// Axis
	StickLX,
	StickLY,
	CROSSX,
	CROSSY,
	StickRX,
	StickRY,
	TriggerR2,
	TriggerL2
};

//////////////////////
// Enumes Joysticks //
//////////////////////
enum PadButton
{
	JoystickButtonA,
	JoystickButtonB,
	JoystickButtonX,
	JoystickButtonY,

	JoystickButtonLB,
	JoystickButtonRB,

	JoystickButtonSelect,
	JoystickButtonStart
};

enum PadAxis
{
	JoystickGaucheHori,
	JoystickGaucheVert,

	JoystickGachettes,

	JoystickDroitVert,
	JoystickDroitHori,

	JoystickCroixHori = 6,
	JoystickCroixVert
};


struct gamepad
{
	sf::Vector2f stickL;
	sf::Vector2f stickR;
	sf::Vector2f cross;
	float TriggerL;
	float TriggerR;
	int Bouton[14];
};
extern gamepad Gamepad[8];

////////////////////////////////////////////////////////////
//\brief | Detection des manettes
////////////////////////////////////////////////////////////
//void GamepadDetection();

////////////////////////////////////////////////////////////
//\brief | Register GamePad Inputs 
//\param _joystickId | joystick id.
//\param event | Window events.
////////////////////////////////////////////////////////////
void GamepadManager(int _joystickId, sf::Event event);
////////////////////////////////////////////////////////////
//\brief | Recupere si une action sur une touche et faite. 
//\param _joystickId | GamePad concerner.
//\param _button | Bonton concerner.
//\return int | 1 = pressed / 0 = don't pressed.
////////////////////////////////////////////////////////////
int Gamepad_isButtonPressed(unsigned int _joystickId, gamepadPS4 _button);
////////////////////////////////////////////////////////////
//\brief | Recupere si une action sur un axis et faite. 
//\param _joystickId | GamePad concerner.
//\param _Axis | Axis concerner.
//\return float | > 30 = Moving return position / 0 = don't Moving.
////////////////////////////////////////////////////////////
float Gamepad_isJoystickMoved(unsigned int _joystickId, gamepadPS4 _Axis);

