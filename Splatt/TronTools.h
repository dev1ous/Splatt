#pragma once
#include "Tools.hpp"


//constantes
const int WIDTH = 1920;
const int HEIGHT = 1080;

//Variables globales
extern bool col[WIDTH][HEIGHT];
extern bool Game;
extern sf::RenderTexture t;
extern sf::Sprite s;
extern sf::Text Trontext;
extern sf::Font Tronfont;
extern bool player1isAI;
extern bool player2isAI;
extern int AIrandomTurns;
extern float velocity;


//Prototypes de fonctions
//void aiCheck();
//void aiTurn(sf::Vector2f& _aiVelocity, bool _goLeft, Joueurs& _JoueursAI);
//void aiManager(Joueurs& _JoueursAI, Joueurs& _AutresJoueurs);
void TronDisplay();