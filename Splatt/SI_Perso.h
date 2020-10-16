#pragma once
#include "SI_Manager.h"

class SI_Perso
{
protected :
	Vector2f Position;
	Vector2f Origine;
	float Timer;
	int life;

	bool Droite;
	bool Gauche;
	bool Tir;

public :
	SI_Perso();
	~SI_Perso();

	inline Vector2f Get_Position() { return Position; };
	inline Vector2f Get_Origin() { return Origine; };
	inline float Get_Timer() { return Timer; };
	inline int Get_Life() { return life; };

	inline bool Get_Droite() { return Droite; };
	inline bool Get_Gauche() { return Gauche; };
	inline bool Get_Tir() { return Tir; };

	inline void Set_Position(Vector2f _position) { Position = _position; };
	inline void Set_Origin(Vector2f _origine) { Origine = _origine; };
	inline void Set_Timer(float _timer) { Timer = _timer; };
	inline void Set_Life(int _life) { life = _life; };

	inline void Set_Droite(bool _bool) { Droite = _bool; };
	inline void Set_Gauche(bool _bool) { Gauche = _bool; };
	inline void Set_Tir(bool _bool) { Tir = _bool; };

	virtual void Update() = 0;
	virtual void Draw() = 0;
};

void FullDraw_Perso(SI_Perso& _p);
void FullUpdate(SI_Perso& _p);