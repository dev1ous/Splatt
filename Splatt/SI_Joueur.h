#pragma once
#include "SI_Perso.h"

class SI_Joueur : public SI_Perso
{
private :
	int Numero_Joueur;
	int Limite_Tir;
	int Nombre_Tir;
	Color Couleur;
	bool Tir_Special;
	float Timer_col;

	RectangleShape PV;
	RectangleShape Encadré;

	int Special_Jaune;
	int Special_Bleu;
	int Special_Violet;
	int Special_Vert;

	int taille;

public :
	SI_Joueur();
	SI_Joueur(Vector2f _position, int _numerojoueur, int Nombre_tir, Color _color);
	~SI_Joueur();

	RectangleShape Special;
	string sTir_Special;
	Text tSpecial;
	bool ColiJ;

	inline int Get_Numero() { return Numero_Joueur; };
	inline int Get_NombreTir() { return Nombre_Tir; };
	inline int Get_Limit() { return Limite_Tir; };
	inline Color Get_Color() { return Couleur; };
	inline bool Get_Tir() { return Tir_Special; };

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
	inline void Set_TirSpecial(bool _bool) { Tir_Special = _bool; };
	
	void Update();
	void Draw();
};

extern vector <SI_Joueur> V_joueur;

extern int Nombre_Joueur;