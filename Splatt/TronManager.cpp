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
sf::Text Trontext("Vous avez gagne une manche mais ce n'est pas fini !", Tronfont, 50);
sf::Text TrontextFin("Vous avez eradiquez le programme adverse, bien joue", Tronfont, 50);
sf::RenderStates states;
sf::Shader* TronShader;
sf::RectangleShape TronShape;
sf::Text TronTextVies1;
sf::Text TronTextVies2;

void TronInit()
{
	joueur1.setOrigin(joueur1.getOrigin());
	joueur1.setTexture("../Ressources/Tron/MotoBleuRe.png");
	joueur1.setSprite(joueur1.getTexture());
	joueur2.setOrigin(joueur2.getOrigin());
	joueur2.setTexture("../Ressources/Tron/MotoJauneRe.png");
	joueur2.setSprite(joueur2.getTexture());

	sf::Vector2f TronSize(WIDTH, HEIGHT);
	TronShape.setSize(TronSize);
	TronShape.setFillColor(sf::Color::Black);
	sf::Texture Trontexture;
	Trontexture.loadFromFile("../Ressources/Tron/GrilleFinale.png");
	sf::Sprite Trongrille(Trontexture);
	t.create(WIDTH, HEIGHT);
	t.setSmooth(true);
	s.setTexture(t.getTexture());
	t.clear();
	t.draw(Trongrille);
	Trontext.setPosition(140, HEIGHT / 2);
	TrontextFin.setPosition(140, HEIGHT / 2);

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
}
void TronDisplay()
{
	static float TronVelocity = 3.f;
	static float TronTimerReset = 0.f;
	static float TronTimerFinGame = 0.f;
	static bool onepass = false;
	App.setFramerateLimit(60);

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
			if(getSound("BikeSound").getStatus() != sf::Sound::Playing)
				getSound("BikeSound").play();
			for (int i = 0; i < TronVelocity; i++)
			{
				joueur1.Zuse();
				joueur2.Zuse();

				if (col[joueur1.getX()][joueur1.getY()] == 1)
				{
					joueur1.setNbdeVies();
					if (joueur1.getNbdeVies() < 1)
					{
						TronGame = 0;
						TrontextFin.setFillColor(joueur2.getColor());
						TrontextFin.setOutlineThickness(2);
					}
					TronRound = 0;
					Trontext.setFillColor(joueur2.getColor());
					Trontext.setOutlineThickness(2);
					break;
				}
				else if (col[joueur2.getX()][joueur2.getY()] == 1)
				{
					joueur2.setNbdeVies();
					if (joueur1.getNbdeVies() < 1)
					{
						TronGame = 0;
						TrontextFin.setFillColor(joueur1.getColor());
						TrontextFin.setOutlineThickness(2);
					}
					TronRound = 0;
					Trontext.setFillColor(joueur1.getColor());
					Trontext.setOutlineThickness(2);
					break;
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
				App.draw(TronShape);
				App.draw(Trontext);
			}
		}
		if (TronPause == 1)
		{
			getSound("BikeSound").stop();
			TronVelocity -= 3;
			TronMenuControlIG();
			TronMenuDisplayIG();
		}
		else
		{
			TronVelocity = 3;
			TronControlesClavierJ1();
			TronControlesClavierJ2();
		}
	}
	if (!TronGame)
	{
		getSound("BikeSound").stop();
		if (TronTimerFinGame < 2.f)
		{
			App.draw(TronShape);
			App.draw(TrontextFin);
		}
	}
}