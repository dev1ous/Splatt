#pragma once
#include "SI_Perso.h"

class SI_Joueur : public SI_Perso
{
private :
	int Numero_Joueur;
	bool Droite;
	bool Gauche;
	bool Tir;

public :
	SI_Joueur();
	SI_Joueur(Vector2f _position, int _numerojoueur);
	~SI_Joueur();

	int Get_Numero();
	bool Get_Droite();
	bool Get_Gauche();
	bool Get_Tir();

	void Set_Numero(int _numero);
	void Set_Droite(bool _bool);
	void Set_Gauche(bool _bool);
	void Set_Tir(bool _bool);
	
	void Update();
	void Draw();
};

extern vector <SI_Joueur*> V_joueur;

static int Nombre_Joueur = 2;