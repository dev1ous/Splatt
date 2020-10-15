#include "Lunar_GroundContainer.h"
#include "Lunar_stone.h"
#include "Lunar_landingZone.h"

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
	LandingZone myLandingZone;

	vector<int> tmp;

	for (int x = 0; x < _window.getSize().x / myStone.GetWidth() - 1; x++)
		tmp.push_back(2);

	for (int x = 0; x < tmp.size(); x++)
	{
		if (tmp[x] == 1)
			mContainer.push_back(Stone(myStone.GetWidth() * x, _window.getSize().y - myStone.GetHeight()));
		else if (tmp[x] == 2)
			mContainer.push_back(LandingZone(myLandingZone.GetWidth() * x, _window.getSize().y - myLandingZone.GetHeight()));
	}
}

void GroundContainer::Update(Lander& _myPlayer)
{
	for (int x = 0; x < mContainer.size(); x++)
	{
		if (IsCollide(_myPlayer, x))
		{
			if (mContainer[x].GetID() == 1)
				_myPlayer.Explode();
			else if (mContainer[x].GetID() == 2 && _myPlayer.GetVelocityY() > .5f)
				_myPlayer.Explode();
			else if (mContainer[x].GetID() == 2 && _myPlayer.GetVelocityY() <= .5f)
				_myPlayer.Landing();
		}
	}
}

bool GroundContainer::IsCollide(Lander& _myplayer, int _x)
{
	Ground myGround;

	if (mContainer.at(_x).GetClass() == myGround.GetClass() && mContainer.at(_x).IsCollide(_myplayer))
		return true;


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
