#pragma once
#include "Lunar_GroundContainer.h"
#include "Lunar_player.h"
#include "Controles.h"
#include "StateManager.hpp"

#include "Tools.hpp"

class Lunar_manager
{
private:
	SoundBuffer mBuffer;

	Shader mShader;
	RenderStates Rstate;
	Texture mTextureLastPass;
	Texture mTextureDiffuse;
	Texture mTextureFond;
	Sprite mSpriteFond;

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
	Text mAngleText;
	Text mGoToMainMenu;
	Font mMyFont;

	bool mIsMenuOn;
	bool mPause;

public:
	Lunar_manager(RenderWindow &_window);
	void TextInit(RenderWindow &_window);
	void ShaderInit();
	void ShaderUpdate();
	void Lunar_update(RenderWindow& _window);
	void Lunar_display(RenderWindow &_window);
	void TextUpdate();
	bool PlayerHasNoFuel();
	void DisplayPauseMenu();
	void IsOnPause();
	void LunarMenuPause();
	~Lunar_manager();
};