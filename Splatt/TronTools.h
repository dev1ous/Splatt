#pragma once
#include "Tools.hpp"


//constantes
const int WIDTH = 1920;
const int HEIGHT = 1080;

//Variables globales
extern bool col[WIDTH][HEIGHT];
extern bool TronGame;
extern bool TronRound;
extern bool TronPause;
extern sf::RenderTexture t;
extern sf::Sprite s;
extern sf::Text Trontext;
extern sf::Font Tronfont;
extern sf::RenderStates states;
extern sf::Text TronTextVies1;
extern sf::Text TronTextVies2;
extern sf::Font Tronfont;


//Prototypes de fonctions
//void aiCheck();
//void aiTurn(sf::Vector2f& _aiVelocity, bool _goLeft, Joueurs& _JoueursAI);
//void aiManager(Joueurs& _JoueursAI, Joueurs& _AutresJoueurs);

void TronDisplay();
void TronInit();