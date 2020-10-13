#pragma once
#include "Pac_Manager.h"

class Pac_Personnage
{
public:
	Pac_Personnage();
	~Pac_Personnage();

	void Mort();


	void Update();
	void Draw();

	bool Get_vie();
	bool Get_gauche();
	bool Get_droite();
	bool Get_haut();
	bool Get_bas();

protected:

	bool vie;
	bool gauche;
	bool droite;
	bool haut;
	bool bas;
	float PosX;
	float PosY;


};

