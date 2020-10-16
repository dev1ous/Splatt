#pragma once
#include "Pac_Personnage.h"

class Perso_Pacman : public Pac_Personnage
{

public:

	Perso_Pacman();
	~Perso_Pacman();

	void Mort();

	void Deplacement();
	void Update();
	void Display() ;

private:

	Direction Direction_Pac;
	int rotate;

};

