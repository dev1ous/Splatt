//#include "Gamepad.h"
//#include "Controles.h"
//
//gamepad Gamepad[8];
//extern bool changingkey;
//extern Controle* ChangingControle;
//
//
////void GamepadDetection()
////{
////	sf::Joystick::update();
////
////	int playernber = 0;
////	for (unsigned int i = 0; i < 8; i++)
////	{
////		if (playernber >= MAX_PLAYER) break;
////		if (sfJoystick_isConnected(i) == sfTrue)
////		{
////			sfJoystickIdentification joyid = sfJoystick_getIdentification(i);
////			if (joyid.vendorId == 1118)
////			{
////				playernber++;
////			}
////			sf::Joystick::getIdentification()
////		}
////	}
////}
//
//void GamepadManager(int _joystickId, sf::Event event)
//{
//	if (event.type == sf::Event::JoystickConnected)
//	{
//		printf("Gamepad is Connected id %d\n", event.joystickConnect.joystickId);
//		//GamepadDetection();
//	}
//	if (event.type == sf::Event::JoystickDisconnected)
//	{
//		printf("Gamepad is Disconnected id %d\n", event.joystickConnect.joystickId);
//		// TODO : Mettre en pause pour indiquer qu'un (ou plusieurs) Gamepad est déconnecté
//	}
//	if (event.joystickButton.joystickId == _joystickId)
//	{
//		if (event.type == sf::Event::JoystickMoved)
//		{
//			if (changingkey)
//			{
//
//				if (event.joystickMove.axis == PadAxis::JoystickGaucheHori)
//				{
//					if (event.joystickMove.position > 30.0f || event.joystickMove.position < -30.0f)
//					{
//						ChangingControle->PadKey = gamepadPS4::StickLX;
//					}
//				}
//				if (event.joystickMove.axis == PadAxis::JoystickGaucheVert)
//				{
//					if (event.joystickMove.position > 30.0f || event.joystickMove.position < -30.0f)
//					{
//						ChangingControle->PadKey = gamepadPS4::StickLY;
//					}
//				}
//				if (event.joystickMove.axis == PadAxis::JoystickDroitHori)
//				{
//					if (event.joystickMove.position > 30.0f || event.joystickMove.position < -30.0f)
//					{
//						ChangingControle->PadKey = gamepadPS4::StickRX;
//					}
//				}
//				if (event.joystickMove.axis == PadAxis::JoystickDroitVert)
//				{
//					if (event.joystickMove.position > 30.0f || event.joystickMove.position < -30.0f)
//					{
//						ChangingControle->PadKey = gamepadPS4::StickRY;
//					}
//				}
//				if (event.joystickMove.axis == PadAxis::JoystickCroixHori)
//				{
//					if (event.joystickMove.position > 30.0f || event.joystickMove.position < -30.0f)
//					{
//						ChangingControle->PadKey = gamepadPS4::CROSSX;
//					}
//				}
//				if (event.joystickMove.axis == PadAxis::JoystickCroixVert)
//				{
//					if (event.joystickMove.position > 30.0f || event.joystickMove.position < -30.0f)
//					{
//						ChangingControle->PadKey = gamepadPS4::CROSSY;
//					}
//				}
//
//				if (event.joystickMove.axis == PadAxis::JoystickGachettes) // L2 et R2
//				{
//					if (event.joystickMove.position < -30.0f)
//					{
//						ChangingControle->PadKey = gamepadPS4::TriggerR2;
//					}
//					else if (event.joystickMove.position > 30.0f)
//					{
//						ChangingControle->PadKey = gamepadPS4::TriggerL2;
//					}
//				}
//
//
//
//				ChangingControle->AxisDirection = 0;
//				if (event.joystickMove.position < -30.0f)
//					ChangingControle->AxisDirection = -1;
//				if (event.joystickMove.position > 30.0f)
//					ChangingControle->AxisDirection = 1;
//
//				if (ChangingControle->PadKey == gamepadPS4::TriggerR2)
//					ChangingControle->AxisDirection = 1;
//
//				if (ChangingControle->AxisDirection != 0)
//				{
//					ChangingControle->isButton = false;
//					changingkey = false;
//					ChangingControle = 0;
//				}
//			}
//			if (event.joystickMove.axis == PadAxis::JoystickGaucheHori)
//			{
//				if (event.joystickMove.position > 30.0f || event.joystickMove.position < -30.0f)
//				{
//					Gamepad[_joystickId].stickL.x = event.joystickMove.position;
//				}
//				else
//				{
//					Gamepad[_joystickId].stickL.x = 0.0f;
//				}
//			}
//			if (event.joystickMove.axis == PadAxis::JoystickGaucheVert)
//			{
//				if (event.joystickMove.position > 30.0f || event.joystickMove.position < -30.0f)
//				{
//					Gamepad[_joystickId].stickL.y = event.joystickMove.position;
//				}
//				else
//				{
//					Gamepad[_joystickId].stickL.y = 0.0f;
//				}
//			}
//			if (event.joystickMove.axis == PadAxis::JoystickDroitHori)
//			{
//				if (event.joystickMove.position > 30.0f || event.joystickMove.position < -30.0f)
//				{
//					Gamepad[_joystickId].stickR.x = event.joystickMove.position;
//				}
//				else
//				{
//					Gamepad[_joystickId].stickR.x = 0.0f;
//				}
//			}
//			if (event.joystickMove.axis == PadAxis::JoystickDroitVert)
//			{
//				if (event.joystickMove.position > 30.0f || event.joystickMove.position < -30.0f)
//				{
//					Gamepad[_joystickId].stickR.y = event.joystickMove.position;
//				}
//				else
//				{
//					Gamepad[_joystickId].stickR.y = 0.0f;
//				}
//			}
//			if (event.joystickMove.axis == PadAxis::JoystickCroixHori)
//			{
//				if (event.joystickMove.position > 30.0f || event.joystickMove.position < -30.0f)
//				{
//					Gamepad[_joystickId].cross.x = event.joystickMove.position;
//				}
//				else
//				{
//					Gamepad[_joystickId].cross.x = 0.0f;
//				}
//			}
//			if (event.joystickMove.axis == PadAxis::JoystickCroixVert)
//			{
//				if (event.joystickMove.position > 30.0f || event.joystickMove.position < -30.0f)
//				{
//					Gamepad[_joystickId].cross.y = event.joystickMove.position;
//				}
//				else
//				{
//					Gamepad[_joystickId].cross.y = 0.0f;
//				}
//			}
//
//			if (event.joystickMove.axis == PadAxis::JoystickGachettes) // L2 et R2
//			{
//				if (event.joystickMove.position > 10.0f)
//				{
//					Gamepad[_joystickId].TriggerL = event.joystickMove.position;
//				}
//				else
//				{
//					Gamepad[_joystickId].TriggerL = 0.0f;
//				}
//				if (event.joystickMove.position < -10.0f)
//				{
//					Gamepad[_joystickId].TriggerR = -event.joystickMove.position;
//				}
//				else
//				{
//					Gamepad[_joystickId].TriggerR = 0.0f;
//				}
//			}
//		}
//
//		if (event.type == sf::Event::JoystickButtonPressed)
//		{
//
//			if (changingkey)
//			{
//				ChangingControle->isButton = true;
//				ChangingControle->PadKey = (gamepadPS4)event.joystickButton.button;
//				changingkey = false;
//				ChangingControle = 0;
//			}
//
//			for (int i = 0; i < 14; i++)
//			{
//
//				if (event.joystickButton.button == i)
//				{
//					Gamepad[_joystickId].Bouton[i] = 1;
//				}
//			}
//		}
//
//		if (event.type == sf::Event::JoystickButtonReleased)
//		{
//			for (int i = 0; i < 14; i++)
//			{
//				if (event.joystickButton.button == i)
//				{
//					Gamepad[_joystickId].Bouton[i] = 0;
//				}
//			}
//		}
//	}
//}
//
//int Gamepad_isButtonPressed(unsigned int _joystickId, gamepadPS4 _button)
//{
//	return Gamepad[_joystickId].Bouton[(int)_button];
//}
//
//float Gamepad_isJoystickMoved(unsigned int _joystickId, gamepadPS4 _Axis)
//{
//	switch (_Axis)
//	{
//	case gamepadPS4::StickLX:
//		return Gamepad[_joystickId].stickL.x;
//		break;
//	case gamepadPS4::StickLY:
//		return Gamepad[_joystickId].stickL.y;
//		break;
//	case gamepadPS4::CROSSX:
//		return Gamepad[_joystickId].cross.x;
//		break;
//	case gamepadPS4::CROSSY:
//		return Gamepad[_joystickId].cross.y;
//		break;
//	case gamepadPS4::StickRX:
//		return Gamepad[_joystickId].stickR.x;
//		break;
//	case gamepadPS4::StickRY:
//		return Gamepad[_joystickId].stickR.y;
//		break;
//	case gamepadPS4::TriggerR2:
//		return Gamepad[_joystickId].TriggerR;
//		break;
//	case gamepadPS4::TriggerL2:
//		return Gamepad[_joystickId].TriggerL;
//		break;
//	default:
//		return 0.0f;
//		break;
//	}
//}