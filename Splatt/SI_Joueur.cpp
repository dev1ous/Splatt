#include "SI_Joueur.h"

SI_Joueur::SI_Joueur()
{
	life = 1;
	Numero_Joueur = 1;
	Droite = false;
	Gauche = false;
	Tir = false;
	Timer = 0;
}

SI_Joueur::SI_Joueur(Vector2f _position, int _numerojoueur)
{
	life = 1;
	Numero_Joueur = _numerojoueur;
	Droite = false;
	Gauche = false;
	Tir = false;
	Timer = 0;
	Position = _position;
}

SI_Joueur::~SI_Joueur()
{
}

int SI_Joueur::Get_Numero()
{
	return Numero_Joueur;
}

float SI_Joueur::Get_Timer()
{
	return Timer;
}

bool SI_Joueur::Get_Droite()
{
	return Droite;
}

bool SI_Joueur::Get_Gauche()
{
	return Gauche;
}

bool SI_Joueur::Get_Tir()
{
	return Tir;
}

void SI_Joueur::Set_Numero(int _numero)
{
	Numero_Joueur = _numero;
}

void SI_Joueur::Set_Timer(float _timer)
{
	Timer = _timer;
}

void SI_Joueur::Set_Droite(bool _bool)
{
	Droite = _bool;
}

void SI_Joueur::Set_Gauche(bool _bool)
{
	Gauche = _bool;
}

void SI_Joueur::Set_Tir(bool _bool)
{
	Tir = _bool;
}

void SI_Joueur::Draw()
{
	if (Numero_Joueur == 1)
	{
		getSprite("Perso1").setOrigin(getSprite("Perso1").getGlobalBounds().width / 2, getSprite("Perso1").getGlobalBounds().height / 2);
		getSprite("Perso1").setPosition(Position);
		App.draw(getSprite("Perso1"));
	}
	if (Numero_Joueur == 2)
	{
		getSprite("Perso2").setOrigin(getSprite("Perso2").getGlobalBounds().width / 2, getSprite("Perso2").getGlobalBounds().height / 2);
		getSprite("Perso2").setPosition(Position);
		App.draw(getSprite("Perso2"));
	}
}
