#include "SI_Collision.h"
#include "SI_Joueur.h"
#include "Si_Ennemi.h"
#include "SI_Tir.h"

SI_Joueur Incrementation_Tir_Special(SI_Ennemi _ennemi, SI_Tir _tir, SI_Joueur _joueur);

void Collision()
{
	for (SI_Ennemi& Actual_Ennemy : EnnemyList)
	{
		string Sprite_Name = "Ennemi";

		Sprite_Name += to_string(Actual_Ennemy.Get_Type());
		for (SI_Tir& Actual_Tir : Tir_Joueur)
		{
			if (Circle_Collision(Actual_Ennemy.Get_Position(), Actual_Tir.Get_Position(), getSprite(Sprite_Name).getGlobalBounds().width / 2, Actual_Tir.Get_Radius()))
			{
				Actual_Ennemy.Set_Life(0);
				Actual_Tir.Set_Destruct(true);

				for (SI_Joueur& Actual_Joueur : V_joueur)
				{
					Actual_Joueur = Incrementation_Tir_Special(Actual_Ennemy, Actual_Tir, Actual_Joueur);
				}
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
}

SI_Joueur Incrementation_Tir_Special(SI_Ennemi _ennemi, SI_Tir _tir, SI_Joueur _joueur)
{
	if (_tir.Ball.getFillColor() == _joueur.Get_Color())
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