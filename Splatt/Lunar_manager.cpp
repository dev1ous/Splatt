#include "Lunar_manager.h"

Lander* player;
GroundContainer* myContainer;

Lunar_manager::Lunar_manager()
{
	myContainer = new GroundContainer(App);
}

void Lunar_manager::Lunar_update(RenderWindow& _window)
{
	myContainer->Update(_window);

	if (myContainer->GetLvl() >= 1)
	{
		player = new Lander(_window);
		player->Update(*myContainer);
	}
}

void Lunar_manager::Lunar_display(RenderWindow& _window)
{
	myContainer->Display(_window);

	if (myContainer->GetLvl() >= 1)
		player->Display(_window);
}

Lunar_manager::~Lunar_manager()
{
}
