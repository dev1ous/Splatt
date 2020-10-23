#include "TronTools.h"
#include "TronJoueurs.h"
#include "TronControles.h"

Joueurs joueur1(sf::Color::Red);
Joueurs joueur2(sf::Color::Green);

bool col[WIDTH][HEIGHT] = { 0 };
bool Game;
sf::RenderTexture t;
sf::Sprite s;
sf::Font Tronfont;
sf::Text Trontext("Vous avez eradiquez le programme adverse, bien joue", Tronfont, 35);
bool player1isAI = true;
bool player2isAI = true;
int AIrandomTurns = 120;
float velocity = 3.f;
sf::Shader* shader;
sf::RenderStates states;

void TronInit()
{
	
	joueur1.setOrigin(joueur1.getOrigin());
	joueur1.setTexture("../Ressources/Tron/MotoBleu.png");
	joueur1.setSprite(joueur1.getTexture());
	joueur2.setOrigin(joueur2.getOrigin());
	joueur2.setTexture("../Ressources/Tron/MotoJaune.png");
	joueur2.setSprite(joueur2.getTexture());

	sf::Texture texture;
	texture.loadFromFile("../Ressources/Tron/Grille3.png");
	sf::Sprite grille(texture);
	t.create(WIDTH, HEIGHT);
	t.setSmooth(true);
	s.setTexture(t.getTexture());
	t.clear();
	t.draw(grille);
	Tronfont.loadFromFile("../Ressources/Tron/TRON.ttf");
	Trontext.setPosition(80, HEIGHT / 2);

	shader = new sf::Shader;
	shader->loadFromFile("../Ressources/Tron/shader.frag", sf::Shader::Fragment);
	shader->setUniform("frag_Reso", sf::Vector2f(WIDTH, HEIGHT));
	shader->setUniform("frag_Attenuation_lumiere", 100.f);
	states.shader = shader;

	Game = 1;
}
void TronDisplay()
{
	static bool onepass = false;
	App.setFramerateLimit(60);
	if (!onepass)
	{
		TronInit();
		onepass = true;
	}

	/*if (!Game)
	{
		App.draw(Trontext);
		return;
	}*/

	/*	if (!joueur1.isAI)*/
	TronControlesClavierJ1();
		/*if (!joueur2.isAI)*/
	TronControlesClavierJ2();


	for (int i = 0; i < velocity; i++)
	{
		joueur1.Zuse();
		joueur2.Zuse();

		if (col[joueur1.getX()][joueur1.getY()] == 1)
		{
			Game = 0;
			Trontext.setFillColor(sf::Color::Black);
			Trontext.setOutlineColor(joueur1.getColor());
			Trontext.setOutlineThickness(5);
		}
		if (col[joueur2.getX()][joueur2.getY()] == 1)
		{
			Game = 0;
			Trontext.setFillColor(sf::Color::Black);
			Trontext.setOutlineColor(joueur2.getColor());
			Trontext.setOutlineThickness(5);
		}
		col[joueur1.getX()][joueur1.getY()] = 1;
		col[joueur2.getX()][joueur2.getY()] = 1;

		joueur1.setPosition(joueur1.getX(), joueur1.getY());
		joueur2.setPosition(joueur2.getX(), joueur2.getY());


	}

	t.display();

	shader->setUniform("frag_LightOrigin", sf::Vector2f(joueur1.getX(), joueur1.getY()));
	shader->setUniform("frag_LightColor", joueur1.getVecColor());
	t.draw(s, states);

	App.draw(s);

	shader->setUniform("frag_LightOrigin", sf::Vector2f(joueur2.getX(), joueur2.getY()));
	shader->setUniform("frag_LightColor", joueur2.getVecColor());
	t.draw(s, states);

	App.draw(s);

	App.draw(joueur1.getSprite());
    App.draw(joueur2.getSprite());
}