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

	Vector2f Get_Position();
	bool Get_Destruct();
	float Get_Radius();

	void Set_Position(Vector2f _position);
	void Set_Destruct(bool _bool);

	void Update();
	void Draw();
};

extern vector <SI_Tir> Tir_Joueur;
extern vector <SI_Tir> Tir_Ennemi;