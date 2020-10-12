#pragma once
#include <vector>
#include "pch.h"
#include "Lunar_Ground.h"

class GroundContainer
{
	vector<int> mContainer;

public:
	GroundContainer(RenderWindow& _window);
	void Fill(RenderWindow& _window);
	void Display(RenderWindow& _window);
	~GroundContainer();

private:

};
