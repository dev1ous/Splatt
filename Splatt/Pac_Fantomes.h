#pragma once
#include "Pac_Personnage.h"

class Pac_Fantomes : public Pac_Personnage
{

public:

	Pac_Fantomes();
	~Pac_Fantomes();

	void Mort();

	void Deplacement();
	void Update();
	void Display();

private:


	
};

