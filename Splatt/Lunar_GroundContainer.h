#pragma once
#include <vector>
#include "pch.h"
#include "Lunar_Ground.h"
#include "Lunar_player.h"

class GroundContainer
{
	vector<Ground> mContainer;

public:
	GroundContainer();
	GroundContainer(RenderWindow& _window);
	void Fill(RenderWindow& _window);
	void Update(Lander &_myplayer);
	bool IsCollide(Lander &_myplayer, int _x);
	void Display(RenderWindow& _window);
	~GroundContainer();

private:

};
