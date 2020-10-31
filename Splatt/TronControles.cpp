#include "TronControles.h"
#include "TronJoueurs.h"
#include "Controles.h"
#include "TronMenu.h"

extern bool isJ2_ia;
extern bool isJ1_ia;

void TronControlesClavierJ1()
{
	if (isButtonPressed(Action::TronJ1_Gauche))
		if (joueur1.getDir() != 2)
		{
			joueur1.setDir(1);
			joueur1.getSprite().setRotation(180);
			isJ1_ia = false;
		}
	if (isButtonPressed(Action::TronJ1_Droite))
		if (joueur1.getDir() != 1)
		{
			joueur1.setDir(2);
			joueur1.getSprite().setRotation(0);
			isJ1_ia = false;
		}
	if (isButtonPressed(Action::TronJ1_Haut))
		if (joueur1.getDir() != 0)
		{
			joueur1.setDir(3);
			joueur1.getSprite().setRotation(270);
			isJ1_ia = false;
		}
	if (isButtonPressed(Action::TronJ1_Bas))
		if (joueur1.getDir() != 3)
		{
			joueur1.setDir(0);
			joueur1.getSprite().setRotation(90);
			isJ1_ia = false;
		}
}
void TronControlesClavierJ2()
{
	if (isButtonPressed(Action::TronJ2_Gauche))
		if (joueur2.getDir() != 2)
		{
			joueur2.setDir(1);
			joueur2.getSprite().setRotation(180);
			isJ2_ia = false;
		}
	if (isButtonPressed(Action::TronJ2_Droite))
		if (joueur2.getDir() != 1)
		{
			joueur2.setDir(2);
			joueur2.getSprite().setRotation(0);
			isJ2_ia = false;
		}
	if (isButtonPressed(Action::TronJ2_Haut))
		if (joueur2.getDir() != 0)
		{
			joueur2.setDir(3);
			joueur2.getSprite().setRotation(270);
			isJ2_ia = false;
		}
	if (isButtonPressed(Action::TronJ2_Bas))
		if (joueur2.getDir() != 3)
		{
			joueur2.setDir(0);
			joueur2.getSprite().setRotation(90);
			isJ2_ia = false;
		}
}
void GoMenuIG()
{
	static float TimerTronControle = 0.f;
	TimerTronControle += MainTime.GetTimeDeltaF();
	if (isButtonPressed(Action::Escape) && TimerTronControle > 0.5f)
	{
		TronPause = 1;
		TimerTronControle = 0.f;
	}
}