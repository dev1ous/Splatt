#include "TronControles.h"
#include "TronJoueurs.h"
#include "Controles.h"

void TronControlesClavierJ1()
{
	if (isButtonPressed(Action::TronJ1_Gauche))
		if (joueur1.getDir() != 2)
		{
			joueur1.setDir(1);
			joueur1.getSprite().setRotation(180);
		}
	if (isButtonPressed(Action::TronJ1_Droite))
		if (joueur1.getDir() != 1)
		{
			joueur1.setDir(2);
			joueur1.getSprite().setRotation(0);
		}
	if (isButtonPressed(Action::TronJ1_Haut))
		if (joueur1.getDir() != 0)
		{
			joueur1.setDir(3);
			joueur1.getSprite().setRotation(270);
		}
	if (isButtonPressed(Action::TronJ1_Bas))
		if (joueur1.getDir() != 3)
		{
			joueur1.setDir(0);
			joueur1.getSprite().setRotation(90);
		}
}
void TronControlesClavierJ2()
{
	if (isButtonPressed(Action::TronJ2_Gauche))
		if (joueur2.getDir() != 2)
		{
			joueur2.setDir(1);
			joueur2.getSprite().setRotation(180);
		}
	if (isButtonPressed(Action::TronJ2_Droite))
		if (joueur2.getDir() != 1)
		{
			joueur2.setDir(2);
			joueur2.getSprite().setRotation(0);
		}
	if (isButtonPressed(Action::TronJ2_Haut))
		if (joueur2.getDir() != 0)
		{
			joueur2.setDir(3);
			joueur2.getSprite().setRotation(270);
		}
	if (isButtonPressed(Action::TronJ2_Bas))
		if (joueur2.getDir() != 3)
		{
			joueur2.setDir(0);
			joueur2.getSprite().setRotation(90);
		}
}