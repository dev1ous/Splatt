#pragma once
#include "Lunar_GroundContainer.h"
#include "Lunar_player.h"

#include "Tools.hpp"

class Lunar_manager
{
private:
	Image mMyImage;
	Texture mMyTexture;
	Sprite mMySprite;

	Vector2f mPosition;

	Text mVelocityXText;
	Text mVelocityYText;
	Text mScoreText;
	Text mLifeText;
	Text mFuelText;
	Text mEscText;
	Font mMyFont;

	bool mIsMenuOn;
	bool mPause;

public:
	Lunar_manager(RenderWindow &_window);
	void TextInit(RenderWindow &_window) ;
	void Lunar_update(RenderWindow& _window);
	void Lunar_display(RenderWindow &_window);
	void TextUpdate();
	bool PlayerHasNoFuel();
	void DisplayPauseMenu();
	void IsOnPause();
	~Lunar_manager();

};