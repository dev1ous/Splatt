#pragma once
#include "Pac_Manager.h"

class Pac_Personnage
{
public:
	Pac_Personnage();
	~Pac_Personnage();

	virtual void Mort() = 0;

	virtual void Deplacement() = 0;
	virtual void Update() = 0;
	virtual	void Display() = 0;

	bool Get_vie();


protected:

	
	bool vie;
	float PosX;
	float PosY;


};

