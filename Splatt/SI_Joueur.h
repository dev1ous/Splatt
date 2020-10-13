#pragma once
#include "SI_Perso.h"

class SI_Joueur : public SI_Perso
{
private :
	int Numero_Joueur;
	int Limite_Tir;
	int Nombre_Tir;
	Color Couleur;

	int Special_Jaune;
	int Special_Bleu;
	int Special_Violet;
	int Special_Vert;

	RectangleShape Special;
	int taille;

public :
	SI_Joueur();
	SI_Joueur(Vector2f _position, int _numerojoueur, Color _color);
	~SI_Joueur();

	int Get_Numero();
	int Get_NombreTir();
	int Get_Limit();
	Color Get_Color();

	int Get_Special_Jaune();
	int Get_Special_Bleu();
	int Get_Special_Violet();
	int Get_Special_Vert();

	void Set_Numero(int _numero);
	void Set_NombreTir(int _NbTir);
	void Set_Limit(int _limit);

	void Set_Special_Jaune(int _special);
	void Set_Special_Bleu(int _special);
	void Set_Special_Violet(int _special);
	void Set_Special_Vert(int _special);
	
	void Update();
	void Draw();
};

extern vector <SI_Joueur> V_joueur;

static int Nombre_Joueur = 2;