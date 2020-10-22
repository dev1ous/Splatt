#pragma once
#include "Tools.hpp"

#include "pch.h"


class GroundContainer
{
	Image mMyImage;
	Texture mMyTexture;
	Sprite mMySprite;

	Vector2f mPosition;

	int mNbLvl;

public:
	GroundContainer();
	GroundContainer(RenderWindow& _window);
	void Update(RenderWindow& _window);
	void Start(RenderWindow& _window);
	void ChangeLevel(RenderWindow& _window);
	void Display(RenderWindow& _window);

	Image& GetImage();
	int GetLvl();

	~GroundContainer();

private:

};
