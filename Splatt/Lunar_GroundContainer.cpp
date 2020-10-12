#include "Lunar_GroundContainer.h"

GroundContainer::GroundContainer(RenderWindow &_window)
{
	
}

void GroundContainer::Fill(RenderWindow& _window)
{
	for (int i = 0; i <= _window.getSize().x / 45; i++)
		mContainer.push_back(1);
}

void GroundContainer::Display(RenderWindow& _window)
{
	
}

GroundContainer::~GroundContainer()
{
}
