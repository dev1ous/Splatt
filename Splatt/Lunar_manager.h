#pragma once
#include "Lunar_GroundContainer.h"
#include "Lunar_player.h"

#include "Tools.hpp"

class Lunar_manager
{
private:

	Text mVelocityXText;
	Text mVelocityYText;
	Text mScoreText;
	Text mLifeText;
	Text mFuelText;
	Font mMyFont;

public:
	Lunar_manager(RenderWindow &_window);
	void TextInit(RenderWindow &_window) ;
	void Lunar_update(RenderWindow& _window);
	void Lunar_display(RenderWindow &_window);
	void TextUpdate();
	bool PlayerHasNoFuel();

	~Lunar_manager();

};