#include "Lunar_manager.h"

Lander* player;

Lunar_manager::Lunar_manager()
{
	player = new Lander(App);
}

void Lunar_manager::Lunar_update()
{
	player->Update();
}

void Lunar_manager::Lunar_display(RenderWindow& _window)
{
	player->Display(App);
}

Lunar_manager::~Lunar_manager()
{
}
