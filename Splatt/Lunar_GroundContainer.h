#pragma once
#include <vector>
#include "pch.h"
#include "Lunar_Ground.h"

class GroundContainer
{
	vector<Ground> mContainer;

public:
	GroundContainer(RenderWindow& _window);
	void Display(RenderWindow& _window);
	~GroundContainer();

private:

};
