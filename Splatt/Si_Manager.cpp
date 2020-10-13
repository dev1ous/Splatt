#include "SI_Manager.h"
#include "SI_Joueur.h"
#include "SI_Ennemi.h"
#include "SI_Tir.h"

vector <SI_Joueur> V_joueur;
vector <SI_Ennemi> EnnemyList;

SI_Joueur Incrementation_Tir_Special(SI_Ennemi _ennemi, SI_Tir _tir, SI_Joueur _joueur);

void SI_Update()
{
	static bool Load = false;
	if (!Load)
	{
		Color Couleur;
		for (int i = 0; i < Nombre_Joueur; i++)
		{
			if (i == 0)
				Couleur = Color::Red;
			if (i == 1)
				Couleur = Color::Blue;

			V_joueur.push_back(SI_Joueur(Vector2f(((1920 / (Nombre_Joueur + 1)) * (i + 1)), 1080 - 105), i + 1, Couleur));
		}
		
		App_Ennemis(10, 4, 2, 4);

		Load = true;
	}

	Collision();
	Suppression();

	for (SI_Joueur& Actual_Joueur : V_joueur)
		FullUpdate(Actual_Joueur);
	
	for (SI_Ennemi& Actual_Ennemy : EnnemyList)
		FullUpdate(Actual_Ennemy);

	for (SI_Tir& Actual_Tir : Tir_Joueur)
		Actual_Tir.Update();
}

void SI_Display()
{
	for (SI_Joueur& Actual_Joueur : V_joueur)
		FullDraw_Perso(Actual_Joueur);

	for (SI_Ennemi& Actual_Ennemy : EnnemyList)
		FullDraw_Perso(Actual_Ennemy);

	for (SI_Tir& Actual_Tir : Tir_Joueur)
		Actual_Tir.Draw();
}

void App_Ennemis(int _rangeX, int _rangeY, int _typeMin, int _typeMax)
{
	int Rand = 0;
	for (int y = 0; y < _rangeY; y++)
	{
		for (int x = 0; x < _rangeX; x++)
		{
			Rand = irandom(_typeMin, _typeMax);
			EnnemyList.push_back(SI_Ennemi(Vector2f((1920 / 11 * (x + 1)), 105 + (120 * y)), Rand));
		}
	}
}

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
			Nombre_Ennemis--;
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
				}
				_joueur.Set_Special_Jaune(_joueur.Get_Special_Jaune() + 1);
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
				}
				_joueur.Set_Special_Bleu(_joueur.Get_Special_Bleu() + 1);
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
				}
				_joueur.Set_Special_Violet(_joueur.Get_Special_Violet() + 1);
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
				}
				_joueur.Set_Special_Vert(_joueur.Get_Special_Vert() + 1);
			}
			break;
		default:
			break;
		}
	}
	return _joueur;
}