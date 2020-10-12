#include "Lunar_GroundContainer.h"

GroundContainer::GroundContainer()
{
}

GroundContainer::GroundContainer(RenderWindow &_window)
{
	Fill(_window);
}

void GroundContainer::Fill(RenderWindow& _window)
{
	vector<int> tmp;
	Ground myGround;

	for (int i = 0; i <= _window.getSize().x / 45; i++)
		tmp.push_back(1);

	for (int i = 0; i <= _window.getSize().x / 45; i++)
	{
		if (tmp[i] == 1)
			mContainer.push_back(Ground(myGround.GetWidth() * i + 1, _window.getSize().y - myGround.GetHeight()));

	}
}

void GroundContainer::Display(RenderWindow& _window)
{
	for (int i = 0; i <= mContainer.size() - 1; i++)
		_window.draw(mContainer[i].GetSprite());
}

GroundContainer::~GroundContainer()
{
}
