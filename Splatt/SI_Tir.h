#pragma once
#include "SI_Manager.h"

class SI_Tir
{
protected :
	Vector2f Position;
	float Radius;

public :
	SI_Tir();
	SI_Tir(Color _color, Vector2f _position);
	~SI_Tir();

	CircleShape Ball;

	Vector2f Get_Position();
	void Set_Position(Vector2f _position);

	void Update();
	void Draw();
};

extern vector <SI_Tir*> Tir_Joueur;
extern vector <SI_Tir*> Tir_Ennemi;