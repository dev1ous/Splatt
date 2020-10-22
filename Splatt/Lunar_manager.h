#pragma once
#include "Lunar_GroundContainer.h"
#include "Lunar_player.h"

#include "Tools.hpp"

class Lunar_manager
{
private:

public:
	Lunar_manager();
	void Lunar_update(RenderWindow& _window);
	void Lunar_display(RenderWindow &_window);

	~Lunar_manager();

};