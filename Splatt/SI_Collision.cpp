#include "SI_Collision.h"
#include "SI_Joueur.h"
#include "Si_Ennemi.h"
#include "SI_Tir.h"

SI_Joueur Incrementation_Tir_Special(SI_Ennemi _ennemi, SI_Tir _tir, SI_Joueur _joueur);

void Collision()
{
	for (SI_Ennemi& Actual_Ennemy : EnnemyList)
	{
		Actual_Ennemy.Timer_degat += MainTime.GetTimeDeltaF();
		string Sprite_Name = "Ennemi";

		Sprite_Name += to_string(Actual_Ennemy.Get_Type());
		for (SI_Tir& Actual_Tir : Tir_Joueur)
		{
			if (Actual_Ennemy.Timer_degat > 0.5f && Circle_Collision(Actual_Ennemy.Get_Position(), Actual_Tir.Get_Position(), getSprite(Sprite_Name).getGlobalBounds().width / 2, Actual_Tir.Get_Radius()))
			{
				Actual_Ennemy.Set_Life(Actual_Ennemy.Get_Life() - 1);

				if (Actual_Tir.Get_Type() == 1)
					Actual_Tir.Set_Destruct(true);
				else if (Actual_Tir.Get_Activation() == false)
					Actual_Tir.Set_Activation(true);

				for (SI_Joueur& Actual_Joueur : V_joueur)
				{
					Actual_Joueur = Incrementation_Tir_Special(Actual_Ennemy, Actual_Tir, Actual_Joueur);
				}

				Actual_Ennemy.Timer_degat = 0;
				break;
			}
		}

		for (SI_Joueur& Actual_Joueur : V_joueur)
		{
			string Sprite_Name2 = "Perso";
			Sprite_Name2 += to_string(Actual_Joueur.Get_Numero());
			if (Circle_Collision(Actual_Ennemy.Get_Position(), Actual_Joueur.Get_Position(), getSprite(Sprite_Name).getGlobalBounds().width / 2, getSprite(Sprite_Name2).getGlobalBounds().width / 2) && Actual_Joueur.ColiJ == false)
			{
				Actual_Joueur.ColiJ = true;
				Actual_Joueur.Set_Life(0);
				Actual_Ennemy.Set_Life(0);
				break;
			}
		}
	}

	for (SI_Joueur& Actual_Joueur : V_joueur)
	{
		string Sprite_Name2 = "Perso";
		Sprite_Name2 += to_string(Actual_Joueur.Get_Numero());
		for (SI_Tir& Actual_Tir : Tir_Ennemi)
		{
			if (Circle_Collision(Actual_Tir.Get_Position(), Actual_Joueur.Get_Position(), Actual_Tir.Get_Radius(), getSprite(Sprite_Name2).getGlobalBounds().width / 2) && Actual_Joueur.ColiJ == false)
			{
				Actual_Tir.Set_Destruct(true);
				Actual_Joueur.Set_Life(Actual_Joueur.Get_Life() - 1);
				if (Actual_Joueur.Get_Life() > 0)
					Actual_Joueur.ColiJ = true;
				break;
			}
		}
	}
}

void Suppression()
{
	int i = 0;
	for (SI_Ennemi& Actual_Ennemy : EnnemyList)
	{
		if (Actual_Ennemy.Get_Life() == 0)
		{
			EnnemyList.erase(EnnemyList.begin() + i);
			break;
		}
		i++;
	}

	i = 0;
	for (SI_Tir& Actual_Tir : Tir_Ennemi)
	{
		if (Actual_Tir.Get_Destruct() == true)
		{
			Tir_Ennemi.erase(Tir_Ennemi.begin() + i);
			break;
		}
		i++;
	}

	i = 0;
	for (SI_Tir& Actual_Tir : Tir_Joueur)
	{
		if (Actual_Tir.Get_Destruct() == true)
		{
			for (SI_Joueur& Actual_Joueur : V_joueur)
			{
				if (Actual_Tir.Ball.getFillColor() == Color::Red && Actual_Joueur.Get_Numero() == 1)
					Actual_Joueur.Set_NombreTir(Actual_Joueur.Get_NombreTir() - 1);

				if (Actual_Tir.Ball.getFillColor() == Color::Blue && Actual_Joueur.Get_Numero() == 2)
					Actual_Joueur.Set_NombreTir(Actual_Joueur.Get_NombreTir() - 1);
			}

			Tir_Joueur.erase(Tir_Joueur.begin() + i);
			break;
		}
		i++;
	}

	i = 0;
	for (SI_Joueur& Actual_Joueur : V_joueur)
	{
		if (Actual_Joueur.Get_Life() == 0)
		{
			V_joueur.erase(V_joueur.begin() + i);
			break;
		}
		i++;
	}
}

SI_Joueur Incrementation_Tir_Special(SI_Ennemi _ennemi, SI_Tir _tir, SI_Joueur _joueur)
{
	if (_tir.Ball.getFillColor() == _joueur.Get_Color() && _tir.Get_Type() == 1)
	{
		switch (_ennemi.Get_Type())
		{
		case 1:
			if (_joueur.Get_Special_Jaune() < 4)
			{
				if (_joueur.Get_Special_Jaune() == 0)
				{
					_joueur.Set_Special_Jaune(0);
					_joueur.Set_Special_Bleu(0);
					_joueur.Set_Special_Violet(0);
					_joueur.Set_Special_Vert(0);
					_joueur.Special.setFillColor(Color::Yellow);
				}
				_joueur.Set_Special_Jaune(_joueur.Get_Special_Jaune() + 1);
				_joueur.sTir_Special = "Tu as " + to_string(_joueur.Get_Special_Jaune()) + "/4";
			}
			break;
		case 2:
			if (_joueur.Get_Special_Bleu() < 4)
			{
				if (_joueur.Get_Special_Bleu() == 0)
				{
					_joueur.Set_Special_Jaune(0);
					_joueur.Set_Special_Bleu(0);
					_joueur.Set_Special_Violet(0);
					_joueur.Set_Special_Vert(0);
					_joueur.Special.setFillColor(Color::Blue);
				}
				_joueur.Set_Special_Bleu(_joueur.Get_Special_Bleu() + 1);
				_joueur.sTir_Special = "Tu as " + to_string(_joueur.Get_Special_Bleu()) + "/4";
			}
			break;
		case 3:
			if (_joueur.Get_Special_Violet() < 4)
			{
				if (_joueur.Get_Special_Violet() == 0)
				{
					_joueur.Set_Special_Jaune(0);
					_joueur.Set_Special_Bleu(0);
					_joueur.Set_Special_Violet(0);
					_joueur.Set_Special_Vert(0);
					_joueur.Special.setFillColor(Color::Magenta);
				}
				_joueur.Set_Special_Violet(_joueur.Get_Special_Violet() + 1);
				_joueur.sTir_Special = "Tu as " + to_string(_joueur.Get_Special_Violet()) + "/4";
			}
			break;
		case 4:
			if (_joueur.Get_Special_Vert() < 4)
			{
				if (_joueur.Get_Special_Vert() == 0)
				{
					_joueur.Set_Special_Jaune(0);
					_joueur.Set_Special_Bleu(0);
					_joueur.Set_Special_Violet(0);
					_joueur.Set_Special_Vert(0);
					_joueur.Special.setFillColor(Color::Green);
				}
				_joueur.Set_Special_Vert(_joueur.Get_Special_Vert() + 1);
				_joueur.sTir_Special = "Tu as " + to_string(_joueur.Get_Special_Vert()) + "/4";
			}
			break;
		default:
			break;
		}
	}
	return _joueur;
}