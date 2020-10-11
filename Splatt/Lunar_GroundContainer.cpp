#include "Lunar_GroundContainer.h"

GroundContainer::GroundContainer(RenderWindow &_window)
{
	for (int i = 0; i <= _window.getSize().x / 45; i++)
		mContainer.push_back(1);
}

void GroundContainer::Display(RenderWindow& _window)
{
	Ground myGround;

	for (int i = 0; i <= _window.getSize().x / 45; i++)
	{
		if (mContainer[i] == 1)
			_window.draw(myGround.GetSprite());
	}
}

GroundContainer::~GroundContainer()
{
}
