#include "TronJoueurs.h"

Joueurs::Joueurs(sf::Color _color)
{
	color = _color;
	x = rand() % WIDTH;
	y = rand() % HEIGHT;
	direction = rand() % 4;
	origin.x = 79.5f;
	origin.y = 29.5f;
	texture;
	sprite;
	TronNBdeVies = 5;
}

Joueurs::~Joueurs()
{
}

int Joueurs::getDir()
{
	return direction;
}

void Joueurs::setDir(int _direction)
{
	direction = _direction;
}

int Joueurs::getX()
{
	return x;
}

int Joueurs::getY()
{
	return y;
}

void Joueurs::setX(int _x)
{
	x = _x;
	sprite.setPosition(x, y);
}

void Joueurs::setY(int _y)
{
	y = _y;
	sprite.setPosition(x, y);
}

void Joueurs::setPosition(float _x, float _y)
{
	sprite.setPosition(_x, _y);
}

void Joueurs::setSprite(sf::Texture _texture)
{
	texture = _texture;
	sprite.setTexture(texture, true);
}

void Joueurs::setTexture(std::string _path)
{
	texture.loadFromFile(_path);
}

void Joueurs::setOrigin(sf::Vector2f _origin)
{
	origin.x = _origin.x;
	origin.y = _origin.y;
	sprite.setOrigin(origin);
}

sf::Vector3f Joueurs::getVecColor()
{
	return sf::Vector3f(color.r, color.g, color.b);
}

sf::Color Joueurs::getColor()
{
	return color;
}
sf::Sprite& Joueurs::getSprite()
{
	return sprite;
}

sf::Texture Joueurs::getTexture()
{
	return texture;
}

sf::Vector2f Joueurs::getOrigin()
{
	return origin;
}

void Joueurs::Zuse()
{
	if (direction == 0)
		y += 1;

	if (direction == 1)
		x -= 1;

	if (direction == 2)
		x += 1;

	if (direction == 3)
		y -= 1;

	if (x >= WIDTH)
		x = 0;
	if (y >= HEIGHT)
		y = 0;
	if (x < 0)
		x = WIDTH -1;
	if (y < 0)
		y = HEIGHT -1;
}
unsigned short Joueurs::getNbdeVies()
{
	return TronNBdeVies;
}

void Joueurs::setNbdeVies()
{
	TronNBdeVies -= 1;
}

void Joueurs::setAddVies()
{
	TronNBdeVies = 5;
}

