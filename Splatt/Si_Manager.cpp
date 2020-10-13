#include "SI_Manager.h"
#include "SI_Perso.h"
#include "SI_Joueur.h"
#include "SI_Ennemi.h"
#include "SI_Tir.h"

vector <SI_Joueur*> V_joueur;
vector <SI_Ennemi*> EnnemyList;

void SI_Update()
{
	static bool Load = false;
	if (!Load)
	{
		for (int i = 0; i < Nombre_Joueur; i++)
			V_joueur.push_back(new SI_Joueur(Vector2f(((1920 / (Nombre_Joueur + 1)) * (i + 1)), 1080 - 105), i + 1));
		
		App_Ennemis(10, 4, 1, 5);

		Load = true;
	}

	for (SI_Joueur* Actual_Joueur : V_joueur)
		FullUpdate(*Actual_Joueur);
	
	for (SI_Ennemi* Actual_Ennemy : EnnemyList)
		FullUpdate(*Actual_Ennemy);

	for (SI_Tir* Actual_Tir : Tir_Joueur)
		Actual_Tir->Update();
}

void SI_Display()
{
	for (SI_Joueur* Actual_Joueur : V_joueur)
		FullDraw_Perso(*Actual_Joueur);

	for (SI_Ennemi* Actual_Ennemy : EnnemyList)
		FullDraw_Perso(*Actual_Ennemy);

	for (SI_Tir* Actual_Tir : Tir_Joueur)
		Actual_Tir->Draw();
}

void App_Ennemis(int _rangeX, int _rangeY, int _typeMin, int _typeMax)
{
	int Rand = 0;
	for (int y = 0; y < _rangeY; y++)
	{
		for (int x = 0; x < _rangeX; x++)
		{
			Rand = irandom(_typeMin, _typeMax);
			EnnemyList.push_back(new SI_Ennemi(Vector2f((1920 / 11 * (x + 1)), 105 + (120 * y)), Rand));
		}
	}
}