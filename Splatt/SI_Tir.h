#pragma once
#include "SI_Manager.h"

class SI_Tir
{
protected :
	Vector2f Position;
	Vector2f Delta;
	bool destruction;
	bool Activation;
	float Radius;
	int Type;
	float timer;

public :
	SI_Tir();
	SI_Tir(Color _color, Vector2f _position, int _type);
	SI_Tir(Vector2f _position, int _type, float _randtir);
	~SI_Tir();

	CircleShape Ball;

	inline Vector2f Get_Position() { return Position; };
	inline bool Get_Destruct() { return destruction; };
	inline float Get_Radius() { return Radius; };
	inline int Get_Type() { return Type; };
	inline bool Get_Activation() { return Activation; };

	inline void Set_Position(Vector2f _position) { Position = _position; };
	inline void Set_Radius(float _radius) { Radius = _radius; };
	inline void Set_Destruct(bool _bool) { destruction = _bool; };
	inline void Set_Activation(bool _bool) { Activation = _bool; };

	void Update_Joueur();
	void Update_Ennemi();
	void Draw();
};

extern vector <SI_Tir> Tir_Joueur;
extern vector <SI_Tir> Tir_Ennemi;