#pragma once
#include "pch.h"
#include <list>

class GroundContainer
{
	Image mMyImage;
	Texture mMyTexture;
	Sprite mMySprite;

	list<Color> mMapColor;

	Vector2f mPosition;

public:
	GroundContainer();
	GroundContainer(RenderWindow& _window);
	void Display(RenderWindow& _window);

	Image GetImage();

	~GroundContainer();

private:

};
