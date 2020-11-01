#include "Controles.h"

std::list<Controle> controles;
std::list<sf::Keyboard::Key> PressedKey;

Controle::Controle(Action _name, sf::Keyboard::Key _baseTouche, bool _button, gamepadPS4 Button_or_Axis, int Axis_direction, int _speManette)
{
	name = _name;
	KeyBoard = _baseTouche;
	isButton = _button;
	
	PadKey = Button_or_Axis;
	AxisDirection = Axis_direction;

	speManette = _speManette;
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
						if (Actualcontrole.speManette == -1 || Actualcontrole.speManette == i)
						{
							if (Gamepad_isButtonPressed(i, Actualcontrole.PadKey))
								return true;
						}
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
							if (Actualcontrole.speManette == -1 || Actualcontrole.speManette == i)
							{
								if (Gamepad_isJoystickMoved(i, Actualcontrole.PadKey) < 0)
									return true;
							}
						}
					}
				}
				else if (Actualcontrole.AxisDirection > 0)
				{
					for (int i = 0; i < 8; i++)
					{
						if (Object_Number == -1 || Object_Number == i)
						{
							if (Actualcontrole.speManette == -1 || Actualcontrole.speManette == i)
							{
								if (Gamepad_isJoystickMoved(i, Actualcontrole.PadKey) > 0)
									return true;
							}
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
	controles.push_back(Controle(Action::Escape, sf::Keyboard::Escape, true, gamepadPS4::Start));
	controles.push_back(Controle(Action::Interact, sf::Keyboard::Enter, true, gamepadPS4::A));

	controles.push_back(Controle(Action::UP, sf::Keyboard::Z, false, gamepadPS4::StickLY, -1));
	controles.push_back(Controle(Action::UP, sf::Keyboard::Up, false, gamepadPS4::CROSSY, -1));
	controles.push_back(Controle(Action::Down, sf::Keyboard::S, false, gamepadPS4::StickLY, 1));
	controles.push_back(Controle(Action::Down, sf::Keyboard::Down, false, gamepadPS4::CROSSY, 1));
	controles.push_back(Controle(Action::Left, sf::Keyboard::Q, false, gamepadPS4::StickLX, -1));
	controles.push_back(Controle(Action::Left, sf::Keyboard::Left, false, gamepadPS4::CROSSX, -1));
	controles.push_back(Controle(Action::Right, sf::Keyboard::D, false, gamepadPS4::StickLX, 1));
	controles.push_back(Controle(Action::Right, sf::Keyboard::Right, false, gamepadPS4::CROSSX, 1));

	controles.push_back(Controle(Action::Aste_RotateLeft, sf::Keyboard::Q, false, gamepadPS4::StickLX, -1));
	controles.push_back(Controle(Action::Aste_RotateRight, sf::Keyboard::D, false, gamepadPS4::StickLX, 1));
	controles.push_back(Controle(Action::Aste_Forward, sf::Keyboard::Z, true, gamepadPS4::A));
	controles.push_back(Controle(Action::Aste_Fire, sf::Keyboard::Space, false, gamepadPS4::TriggerR2, 1));

	controles.push_back(Controle(Action::TronJ1_Bas, sf::Keyboard::S, false, gamepadPS4::StickLY, 1, 0));
	controles.push_back(Controle(Action::TronJ1_Droite, sf::Keyboard::D, false, gamepadPS4::StickLX, 1, 0));
	controles.push_back(Controle(Action::TronJ1_Gauche, sf::Keyboard::Q, false, gamepadPS4::StickLX, -1, 0));
	controles.push_back(Controle(Action::TronJ1_Haut, sf::Keyboard::Z, false, gamepadPS4::StickLY, -1, 0));

	controles.push_back(Controle(Action::TronJ2_Bas, sf::Keyboard::Down, false, gamepadPS4::StickLY, 1, 1));
	controles.push_back(Controle(Action::TronJ2_Droite, sf::Keyboard::Right, false, gamepadPS4::StickLX, 1, 1));
	controles.push_back(Controle(Action::TronJ2_Gauche, sf::Keyboard::Left, false, gamepadPS4::StickLX, -1, 1));
	controles.push_back(Controle(Action::TronJ2_Haut, sf::Keyboard::Up, false, gamepadPS4::StickLY, -1, 1));

	controles.push_back(Controle(Action::SIJ1_Droite, sf::Keyboard::D, false, gamepadPS4::StickLX, 1, 0));
	controles.push_back(Controle(Action::SIJ1_Gauche, sf::Keyboard::Q, false, gamepadPS4::StickLX, -1, 0));
	controles.push_back(Controle(Action::SIJ1_Tir, sf::Keyboard::Space, false, gamepadPS4::R1, 1, 0));
	controles.push_back(Controle(Action::SIJ1_TirSpe, sf::Keyboard::A, false, gamepadPS4::L1, -1, 0));

	controles.push_back(Controle(Action::SIJ2_Droite, sf::Keyboard::Right, false, gamepadPS4::StickLX, 1, 1));
	controles.push_back(Controle(Action::SIJ2_Gauche, sf::Keyboard::Left, false, gamepadPS4::StickLX, -1, 1));
	controles.push_back(Controle(Action::SIJ2_Tir, sf::Keyboard::Numpad0, false, gamepadPS4::R1, 1, 1));
	controles.push_back(Controle(Action::SIJ2_TirSpe, sf::Keyboard::Numpad1, false, gamepadPS4::L1, -1, 1));

	controles.push_back(Controle(Action::Lunar_Impulse, sf::Keyboard::Up, true, gamepadPS4::A));
	controles.push_back(Controle(Action::Lunar_Droite, sf::Keyboard::Right, false, gamepadPS4::StickLX, 1, 0));
	controles.push_back(Controle(Action::Lunar_Gauche, sf::Keyboard::Left, false, gamepadPS4::StickLX, -1, 0));
	controles.push_back(Controle(Action::Lunar_Reset, sf::Keyboard::R, true, gamepadPS4::Y));
	controles.push_back(Controle(Action::Lunar_Pause, sf::Keyboard::Escape, true, gamepadPS4::Start));
	controles.push_back(Controle(Action::Lunar_Select, sf::Keyboard::Space, true, gamepadPS4::Select));
	controles.push_back(Controle(Action::Lunar_ReturnMenu, sf::Keyboard::Q, true, gamepadPS4::B));
}