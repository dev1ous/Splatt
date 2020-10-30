#pragma once
#include "Tools.hpp"
#include "StateManager.hpp"

#include "pch.h"


class GroundContainer
{
	Image mMyImage;
	Texture mMyTexture;
	Sprite mMySprite;

	Vector2f mPosition;

	int mNbLvl;
	bool mLvlCanChange;
	bool mIsOnDS;
	bool mStartNewGame;

public:
	GroundContainer(RenderWindow& _window);
	void Update(RenderWindow& _window);
	void Start();
	void GoToNextLvl(RenderWindow& _window);
	void ChangeLevel(RenderWindow& _window);
	void DeathScreen(RenderWindow& _window);
	void Display(RenderWindow& _window);

	Image& GetImage();
	int GetLvl();
	bool GetLvlChange();
	bool GetNewGame();
	bool GetIsOnDeathScreen();

	void SetNbLvl(int _nbLvl);
	void SetNewGame(bool _newGame);
	~GroundContainer();
};
