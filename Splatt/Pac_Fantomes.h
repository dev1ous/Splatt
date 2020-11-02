#pragma once
#include "Pac_Personnage.h"

class Pac_Fantomes : public Pac_Personnage
{

public:

	Pac_Fantomes();
	Pac_Fantomes(int _type);
	~Pac_Fantomes();

	void Mort();
	void Deplacement();
	void Update();
	void Display();
	void Path(Image& _Image);

	FloatRect Get_Rect();
	void Set_Anim(int _rec);
private:

	int vie;
	float PosX;
	float PosY;
	int rand;
	Vector2f NextPosOnMap;
	IntRect Anim_Fantome;
	FloatRect _Fantome;
	Color Masque;
	Color MasqueGAUCHE;
	Color MasqueBAS;
	Color MasqueDROITE;
	Color MasqueHAUT;
	bool passage;
	bool changement;
	bool demarrage;
	int type;
	float timer;
	Direction Direction_Fantome;



};

