#include "Lunar_GroundContainer.h"

Ground myGround;

GroundContainer::GroundContainer(RenderWindow &_window)
{
	for (int i = 0; i <= _window.getSize().x / 45; i++)
		mContainer.push_back(myGround);

	Display(_window);
}

void GroundContainer::Display(RenderWindow& _window)
{
	for (int i = 0; i <= _window.getSize().x / 45; i++)
		_window.draw(mContainer.at(i));
}

GroundContainer::~GroundContainer()
{
}
