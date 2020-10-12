#include "Lunar_manager.h"
#include "Lunar_GroundContainer.h"

Lander* player;
GroundContainer *myContainer;

Lunar_manager::Lunar_manager()
{
	player = new Lander(App);
	myContainer = new GroundContainer(App);
}

void Lunar_manager::Lunar_update()
{
	player->Update();
	myContainer->Update(*player);
}

void Lunar_manager::Lunar_display(RenderWindow& _window)
{
	player->Display(App);
	myContainer->Display(App);
}

Lunar_manager::~Lunar_manager()
{
}
