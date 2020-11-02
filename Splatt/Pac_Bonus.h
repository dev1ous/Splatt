#pragma once
#include "Pac_Manager.h"
class Pac_Bonus
{
public:

	Pac_Bonus();
	Pac_Bonus(int _type);
	~Pac_Bonus();

	void Display();
	void Update();

	FloatRect Get_Rect();

	void Reset();
	void Set_PosX();
private:

	FloatRect _Bonus;
	int type;
	float PosX;
	float PosY;


};

