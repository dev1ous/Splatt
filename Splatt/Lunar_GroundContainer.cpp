#include "Lunar_GroundContainer.h"
#include "Lunar_stone.h"

GroundContainer::GroundContainer()
{
}

GroundContainer::GroundContainer(RenderWindow& _window)
{
	Fill(_window);
}

void GroundContainer::Fill(RenderWindow& _window)
{
	Stone myStone;
	vector<int> tmp;

	for (int i = 0; i < _window.getSize().x / 45; i++)
		tmp.push_back(1);

	for (int x = 0; x < tmp.size(); x++)
	{
		if (tmp[x] == 1)
			mContainer.push_back(Stone(myStone.GetWidth() * x, _window.getSize().y - myStone.GetHeight()));
	}
}

void GroundContainer::Update(Lander& _myplayer)
{
	if (IsCollide(_myplayer))
	{
		//draw an explosion

		_myplayer.Explode();
	}
}

bool GroundContainer::IsCollide(Lander& _myplayer)
{
	for (int x = 0; x < mContainer.size(); x++)
	{
		if (mContainer.at(x).IsCollide(_myplayer))
			return true;
	}

	return false;
}

void GroundContainer::Display(RenderWindow& _window)
{
	for (int i = 0; i < mContainer.size(); i++)
		_window.draw(mContainer[i].GetSprite());
}

GroundContainer::~GroundContainer()
{
}
