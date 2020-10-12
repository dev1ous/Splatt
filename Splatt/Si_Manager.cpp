#include "SI_Manager.h"
#include "SI_Perso.h"
#include "SI_Joueur.h"
#include "SI_Ennemi.h"

vector <SI_Joueur*> V_joueur;
vector <SI_Ennemi*> EnnemyList;

void SI_Update()
{
	static bool one_pass = false;
	if (!one_pass)
	{
		for (int i = 0; i < Nombre_Joueur; i++)
			V_joueur.push_back(new SI_Joueur(Vector2f(((1920 / (Nombre_Joueur + 1)) * (i + 1)), 1080 - 105), i + 1));
		
		for (int y = 0; y < 10; y++)
		{
			EnnemyList.push_back(new SI_Ennemi(Vector2f(((1920 / (10 + 1)) * (y + 1)), 105), 1));
		}

		one_pass = true;
	}

	for (SI_Joueur* Actual_Joueur : V_joueur)
		Actual_Joueur->Update();
}

void SI_Display()
{
	for (SI_Joueur* Actual_Joueur : V_joueur)
		FullDraw_Perso(*Actual_Joueur);

	for (SI_Ennemi* Actual_Ennemy : EnnemyList)
		FullDraw_Perso(*Actual_Ennemy);
}