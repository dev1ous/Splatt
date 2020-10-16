#pragma once
#include "SI_Manager.h"

class SI_Tir
{
protected :
	Vector2f Position;
	bool destruction;
	float Radius;

public :
	SI_Tir();
	SI_Tir(Color _color, Vector2f _position);
	~SI_Tir();

	CircleShape Ball;

	inline Vector2f Get_Position() { return Position; };
	inline bool Get_Destruct() { return destruction; };
	inline float Get_Radius() { return Radius; };

	inline void Set_Position(Vector2f _position) { Position = _position; };
	inline void Set_Destruct(bool _bool) { destruction = _bool; };

	void Update();
	void Draw();
};

extern vector <SI_Tir> Tir_Joueur;
extern vector <SI_Tir> Tir_Ennemi;