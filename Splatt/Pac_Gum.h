#pragma once
#include "Pac_Manager.h"

class Pac_Gum
{
public:

	Pac_Gum();
	~Pac_Gum();

	void Display();

	void Set_Mort();
	void Set_PosX(float _pos);
	void Set_PosY(float _pos);
	void Set_Rect(FloatRect _rec);
	void Reset();

	FloatRect Get_Rect();
	bool Get_Mort();
private:

	bool Mort;
	FloatRect _Gum;
	float PosX;
	float PosY;


};

