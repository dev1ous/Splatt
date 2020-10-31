#include "TronTools.h"
#include "TronJoueurs.h"
#include "TronControles.h"
#include "TronMenu.h"
#include "StateManager.hpp"
#include "SoundManager.hpp"

namespace InutileMaisJeFaisLeBeauAvecUnTemplate
{
	template < typename TronType > std::string to_stringTron(const TronType& _Trontype)//crée un type générique avec la fonction to_string
	{
		std::ostringstream StringTronTmp; //Création d'un tmp contenant des caractères
		StringTronTmp << _Trontype;
		return StringTronTmp.str(); //retourne mon string avec la copie du tmp
	}
}//Tous ça pour dire que tout ceci est inutile et que le std::to_string de base fonctionne mais je voulais faire le malin avec un template

Joueurs joueur1(sf::Color::Cyan);
Joueurs joueur2(sf::Color(255, 165, 0, 255));

bool col[WIDTH][HEIGHT] = { 0 };
bool TronGame;
bool TronRound;
bool TronPause;
sf::RenderTexture t;
sf::Sprite s;
sf::Text Trontext("Ce miserable concepteur ne fait pas le poids\n          contre un genie comme vous!", Tronfont, 50);
sf::Text TrontextFin("Cette vermine de concepteur n'avait aucune chance ! ", Tronfont, 50);
sf::RenderStates states;
sf::Shader* TronShader;
sf::Text TronTextVies1;
sf::Text TronTextVies2;
bool isJ2_ia = true;
bool isJ1_ia = true;

void TronInit()
{
	getSound("MenuSound").stop();
	joueur1.setOrigin(joueur1.getOrigin());
	joueur1.setTexture("../Ressources/Tron/MotoBleuRe.png");
	joueur1.setSprite(joueur1.getTexture());
	joueur2.setOrigin(joueur2.getOrigin());
	joueur2.setTexture("../Ressources/Tron/MotoJauneRe.png");
	joueur2.setSprite(joueur2.getTexture());

	sf::Texture Trontexture;
	Trontexture.loadFromFile("../Ressources/Tron/GrilleFinale.png");
	sf::Sprite Trongrille(Trontexture);
	t.create(WIDTH, HEIGHT);
	t.setSmooth(true);
	s.setTexture(t.getTexture());
	t.clear();
	t.draw(Trongrille);
	Trontext.setPosition(240, 400);
	TrontextFin.setPosition(140, 400);

	TronTextVies1.setFillColor(joueur1.getColor());
	TronTextVies2.setFillColor(joueur2.getColor());
	TronTextVies1.setOutlineThickness(2);
	TronTextVies2.setOutlineThickness(2);
	TronTextVies1.setPosition(sf::Vector2f(20, 20));
	TronTextVies2.setPosition(sf::Vector2f(1140, 20));
	TronTextVies1.setFont(Tronfont);
	TronTextVies2.setFont(Tronfont);
	TronTextVies1.setCharacterSize(40);
	TronTextVies2.setCharacterSize(40);

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			col[i][j] = 0;
		}
	}

	TronShader = new sf::Shader;
	TronShader->loadFromFile("../Ressources/Tron/shader.frag", sf::Shader::Fragment);
	TronShader->setUniform("frag_Reso", sf::Vector2f(WIDTH, HEIGHT));
	TronShader->setUniform("frag_Attenuation_lumiere", 100.f);
	states.shader = TronShader;

	joueur1.setX(100); joueur1.setY(100); joueur1.setDir(2); joueur1.getSprite().setRotation(0);
	joueur2.setX(100); joueur2.setY(800); joueur2.setDir(2); joueur2.getSprite().setRotation(0);

	TronRound = 1;
	TronGame = 1;
	TronPause = 0;
	joueur1.TronVerif = false;
	joueur2.TronVerif = false;
}
void TronDisplay()
{

	static float TronTimerReset = 0.f;
	static float TronTimerFinGame = 0.f;
	static bool onepass = false;
	App.setFramerateLimit(180);

	if (!onepass)
	{
		TronInit();
		onepass = true;
	}

	GoMenuIG();

	if (!TronGame)
	{
		TronTimerFinGame += MainTime.GetTimeDeltaF();
		if (TronTimerFinGame > 2.f)
		{
			Pause = 1;
			TronTimerFinGame = 0.f;
		}
	}
	else
	{
		if (!TronRound)
		{
			TronTimerReset += MainTime.GetTimeDeltaF();
			if (TronTimerReset > 5.f)
			{
				TronInit();
				TronTimerReset = 0.f;
			}
		}
		else
		{
			if (!TronPause)
			{
				if (getSound("BikeSound").getStatus() != sf::Sound::Playing)
					getSound("BikeSound").play();

				joueur1.Zuse();
				joueur2.Zuse();

				// ia part start
				if (isJ1_ia)
				{
					if (joueur1.getDir() == 0) // v
					{
						int nextY = joueur1.getY() + 50;
						if (nextY < 0)
							nextY += HEIGHT;

						if (nextY < HEIGHT && nextY >= 0)
						{
							if (col[joueur1.getX()][nextY] == 1)
							{
								int iRand = irandom(0, 2);
								if (iRand == 0)
									joueur1.setDir(1);
								if (iRand == 1)
									joueur1.setDir(2);
							}
						}
					}
					else if (joueur1.getDir() == 1) // <-
					{
						int nextX = joueur1.getX() - 50;
						if (nextX < 0)
							nextX += WIDTH;

						if (nextX < WIDTH && nextX >= 0)
						{
							if (col[nextX][joueur1.getY()] == 1)
							{
								int iRand = irandom(0, 2);
								if (iRand == 0)
									joueur1.setDir(0);
								if (iRand == 1)
									joueur1.setDir(3);
							}
						}
					}
					else if (joueur1.getDir() == 2) // ->
					{
						int nextX = joueur1.getX() + 50;
						if (nextX > WIDTH)
							nextX -= WIDTH;

						if (nextX < WIDTH && nextX >= 0)
						{
							if (col[nextX][joueur1.getY()] == 1)
							{
								int iRand = irandom(0, 2);
								if (iRand == 0)
									joueur1.setDir(0);
								if (iRand == 1)
									joueur1.setDir(3);
							}
						}
					}
					else if (joueur1.getDir() == 3) // ^
					{
						int nextY = joueur1.getY() - 50;
						if (nextY < 0)
							nextY -= HEIGHT;

						if (nextY < HEIGHT && nextY >= 0)
						{
							if (col[joueur1.getX()][nextY] == 1)
							{
								int iRand = irandom(0, 2);
								if (iRand == 0)
									joueur1.setDir(1);
								if (iRand == 1)
									joueur1.setDir(2);
							}
						}
					}
				}
				if (isJ2_ia)
				{
					if (joueur2.getDir() == 0) // v
					{
						int nextY = joueur2.getY() + 50;
						if (nextY < 0)
							nextY += HEIGHT;

						if (nextY < HEIGHT && nextY >= 0)
						{
							if (col[joueur2.getX()][nextY] == 1)
							{
								int iRand = irandom(0, 2);
								if (iRand == 0)
									joueur2.setDir(1);
								if (iRand == 1)
									joueur2.setDir(2);
							}
						}
					}
					else if (joueur2.getDir() == 1) // <-
					{
						int nextX = joueur2.getX() - 50;
						if (nextX < 0)
							nextX += WIDTH;

						if (nextX < WIDTH && nextX >= 0)
						{
							if (col[nextX][joueur2.getY()] == 1)
							{
								int iRand = irandom(0, 2);
								if (iRand == 0)
									joueur2.setDir(0);
								if (iRand == 1)
									joueur2.setDir(3);
							}
						}
					}
					else if (joueur2.getDir() == 2) // ->
					{
						int nextX = joueur2.getX() + 50;
						if (nextX > WIDTH)
							nextX -= WIDTH;

						if (nextX < WIDTH && nextX >= 0)
						{
							if (col[nextX][joueur2.getY()] == 1)
							{
								int iRand = irandom(0, 2);
								if (iRand == 0)
									joueur2.setDir(0);
								if (iRand == 1)
									joueur2.setDir(3);
							}
						}
					}
					else if (joueur2.getDir() == 3) // ^
					{
						int nextY = joueur2.getY() - 50;
						if (nextY < 0)
							nextY -= HEIGHT;

						if (nextY < HEIGHT && nextY >= 0)
						{
							if (col[joueur2.getX()][nextY] == 1)
							{
								int iRand = irandom(0, 2);
								if (iRand == 0)
									joueur2.setDir(1);
								if (iRand == 1)
									joueur2.setDir(2);
							}
						}
					}
				}
				// ia part end

				if (col[joueur1.getX()][joueur1.getY()] == 1)
				{
					getSound("ExplosionTron").play();
					joueur1.setNbdeVies();
					joueur1.TronVerif = true;
					if (joueur1.getNbdeVies() < 1)
					{
						TronGame = 0;
						TrontextFin.setFillColor(joueur2.getColor());
						TrontextFin.setOutlineThickness(2);
					}
					TronRound = 0;
					Trontext.setFillColor(joueur2.getColor());
					Trontext.setOutlineThickness(2);
				}
				else if (col[joueur2.getX()][joueur2.getY()] == 1)
				{
					getSound("ExplosionTron").play();
					joueur2.setNbdeVies();
					joueur2.TronVerif = true;
					if (joueur2.getNbdeVies() < 1)
					{
						TronGame = 0;
						TrontextFin.setFillColor(joueur1.getColor());
						TrontextFin.setOutlineThickness(2);
					}
					TronRound = 0;
					Trontext.setFillColor(joueur1.getColor());
					Trontext.setOutlineThickness(2);
				}
				col[joueur1.getX()][joueur1.getY()] = 1;
				col[joueur2.getX()][joueur2.getY()] = 1;

				joueur1.setPosition(joueur1.getX(), joueur1.getY());
				joueur2.setPosition(joueur2.getX(), joueur2.getY());
			}
		}
		t.display();

		TronShader->setUniform("frag_LightOrigin", sf::Vector2f(joueur1.getX(), joueur1.getY()));
		TronShader->setUniform("frag_LightColor", joueur1.getVecColor());
		t.draw(s, states);

		App.draw(s);

		TronShader->setUniform("frag_LightOrigin", sf::Vector2f(joueur2.getX() , joueur2.getY() ));
		TronShader->setUniform("frag_LightColor", joueur2.getVecColor());
		t.draw(s, states);

		App.draw(s);

		App.draw(joueur1.getSprite());
		App.draw(joueur2.getSprite());

		TronTextVies1.setString("Nombre de vies du Joueur 1 : " + InutileMaisJeFaisLeBeauAvecUnTemplate::to_stringTron(joueur1.getNbdeVies()));
		TronTextVies2.setString("Nombre de vies du Joueur 2 : " + InutileMaisJeFaisLeBeauAvecUnTemplate::to_stringTron(joueur2.getNbdeVies()));
		App.draw(TronTextVies1);
		App.draw(TronTextVies2);


		if (!TronRound)
		{
			getSound("BikeSound").stop();
			if (TronTimerReset < 5.f)
			{
				if (joueur1.TronVerif==true)
				{
					sf::Texture TronRoundJ2T;
					TronRoundJ2T.loadFromFile("../Ressources/Tron/RoundGagneJoueur2.png");
					sf::Sprite TronRoundJ2(TronRoundJ2T);
					App.draw(TronRoundJ2);
				}
				else if (joueur2.TronVerif==true)
				{
					sf::Texture TronRoundJ1T;
					TronRoundJ1T.loadFromFile("../Ressources/Tron/RoundGagneJoueur1.png");
					sf::Sprite TronRoundJ1(TronRoundJ1T);
					App.draw(TronRoundJ1);
				}
				App.draw(Trontext);
			}
		}
		else if (TronPause == 1)
		{
			getSound("BikeSound").stop();
			TronMenuControlIG();
			TronMenuDisplayIG();
		}
		else
		{
			TronControlesClavierJ1();
			TronControlesClavierJ2();
		}
	}
	if (!TronGame)
	{
		getSound("BikeSound").stop();
		if (TronTimerFinGame < 2.f)
		{
			if (joueur1.getNbdeVies() < 1)
			{
				sf::Texture TronVictoireJ1T;
				TronVictoireJ1T.loadFromFile("../Ressources/Tron/VictoireJoueur2.png");
				sf::Sprite TronVictoireJ1(TronVictoireJ1T);
				App.draw(TronVictoireJ1);
			}
		    else if (joueur2.getNbdeVies() < 1)
			{
				sf::Texture TronVictoireJ2T;
				TronVictoireJ2T.loadFromFile("../Ressources/Tron/VictoireJoueur1.png");
				sf::Sprite TronVictoireJ2(TronVictoireJ2T);
				App.draw(TronVictoireJ2);
			}
			App.draw(TrontextFin);
		}
	}
}