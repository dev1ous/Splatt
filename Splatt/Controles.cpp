#include "Controles.h"

std::list<Controle> controles;
std::list<sf::Keyboard::Key> PressedKey;

Controle::Controle(Action _name, sf::Keyboard::Key _baseTouche, bool _button, gamepadPS4 Button_or_Axis, int Axis_direction)
{
	name = _name;
	KeyBoard = _baseTouche;
	isButton = _button;
	
	PadKey = Button_or_Axis;
	AxisDirection = Axis_direction;
}

bool isButtonPressed(Action Name, int Object_Number)
{
	for (Controle& Actualcontrole : controles)
	{
		if (Actualcontrole.name == Name)
		{
			if (Object_Number == -1 || Object_Number == 8)
			{
				for (sf::Keyboard::Key& ActualKeyPressed : PressedKey)
				{
					if (Actualcontrole.KeyBoard == ActualKeyPressed)
						return true;
				}
			}

			if (Actualcontrole.isButton)
			{
				for (int i = 0; i < 8; i++)
				{
					if (Object_Number == -1 || Object_Number == i)
					{
						if (Gamepad_isButtonPressed(i, Actualcontrole.PadKey))
							return true;
					}
				}
			}
			else
			{
				if (Actualcontrole.AxisDirection < 0)
				{
					for (int i = 0; i < 8; i++)
					{
						if (Object_Number == -1 || Object_Number == i)
						{
							if (Gamepad_isJoystickMoved(i, Actualcontrole.PadKey) < 0)
								return true;
						}
					}
				}
				else if (Actualcontrole.AxisDirection > 0)
				{
					for (int i = 0; i < 8; i++)
					{
						if (Object_Number == -1 || Object_Number == i)
						{
							if (Gamepad_isJoystickMoved(i, Actualcontrole.PadKey) > 0)
								return true;
						}
					}
				}
			}
		}
	}
	return false;
}

void ResetButtonsPressed()
{
	// keyBoard key reset
	while (PressedKey.size() > 0)
		PressedKey.pop_back();
	
	for (int i = 0; i < 8; i++)
	{
		// GamePad buttons reset
		for (int x = 0; x < 14; x++)
		{
			Gamepad[i].Bouton[x] = 0;
		}

		// GamePad Joysitck reset
		Gamepad[i].cross = sf::Vector2f(0, 0);
		Gamepad[i].stickL = sf::Vector2f(0, 0);
		Gamepad[i].stickR = sf::Vector2f(0, 0);
		Gamepad[i].TriggerL = 0;
		Gamepad[i].TriggerR = 0;		
	}
}

void InitControles()
{
	controles.push_back(Controle(Action::Aste_RotateLeft, sf::Keyboard::Q, false, gamepadPS4::StickLX, -1));
	controles.push_back(Controle(Action::Aste_RotateRight, sf::Keyboard::D, false, gamepadPS4::StickLX, 1));
	controles.push_back(Controle(Action::Aste_Forward, sf::Keyboard::Z, true, gamepadPS4::A));
	controles.push_back(Controle(Action::Aste_Fire, sf::Keyboard::Space, false, gamepadPS4::TriggerR2, 1));
}