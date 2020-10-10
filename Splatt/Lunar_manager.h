#pragma once
#include "Tools.hpp"
#include "Lunar_player.h"
#include "lunar_landingZone.h"

class Lunar_manager
{
public:
	Lunar_manager();
	void Lunar_update();
	void Lunar_display(RenderWindow& _window);
	~Lunar_manager();

};




