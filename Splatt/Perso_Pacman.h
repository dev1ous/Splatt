#pragma once
#include "Pac_Personnage.h"

class Perso_Pacman : public Pac_Personnage
{

public:

	Perso_Pacman();
	~Perso_Pacman();

	void Mort();
	void Reset();
	void Deplacement();
	void Update();
	void Display();

	int Get_Vie();
	FloatRect Get_Rect();
	bool Get_Power_up();

	void Set_vie();
	void Set_Power_up(bool _type);
private:


	bool Power_up;
	int vie;
	float timer;
	FloatRect _Pac;
	Direction Direction_Pac;
	bool Collision(Image _Image, Direction _direction);
	int rotate;


};

