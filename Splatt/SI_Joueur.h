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

	inline int Get_Numero() { return Numero_Joueur; };
	inline int Get_NombreTir() { return Nombre_Tir; };
	inline int Get_Limit() { return Limite_Tir; };
	inline Color Get_Color() { return Couleur; };

	inline int Get_Special_Jaune() { return Special_Jaune; };
	inline int Get_Special_Bleu() { return Special_Bleu; };
	inline int Get_Special_Violet() { return Special_Violet; };
	inline int Get_Special_Vert() { return Special_Vert; };

	inline void Set_Numero(int _numero) { Numero_Joueur = _numero; };
	void Set_NombreTir(int _NbTir);
	inline void Set_Limit(int _limit) { Limite_Tir = _limit; };

	inline void Set_Special_Jaune(int _special) { Special_Jaune = _special; };
	inline void Set_Special_Bleu(int _special) { Special_Bleu = _special; };
	inline void Set_Special_Violet(int _special) { Special_Violet = _special; };
	inline void Set_Special_Vert(int _special) { Special_Vert = _special; };
	
	void Update();
	void Draw();
};

extern vector <SI_Joueur> V_joueur;

static int Nombre_Joueur = 2;