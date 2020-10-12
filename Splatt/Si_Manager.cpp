#include "SI_Manager.h"
#include "SI_Perso.h"
#include "SI_Joueur.h"

void SI_Update()
{
	static bool one_pass = false;
	if (!one_pass)
	{
		for (int i = 0; i < Nombre_Joueur; i++)
			V_joueur.push_back(new SI_Joueur(Vector2f(0, 0), i + 1));
	}
}

void SI_Display()
{
	FullDraw_Perso(V_joueur);
}