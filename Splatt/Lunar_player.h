#pragma once
#include "Lunar_GroundContainer.h"
#include "Tools.hpp"

#include "pch.h"

class Lander
{
protected:

	Texture mTexture;
	Sprite mSprite;
	Vector2f mPosition;
	Vector2f mVelocity;
	float mAngle;
	bool mEngineOn;
	bool mIsAlive;

public:
	Lander(RenderWindow &_window);

#pragma region "Lander_update"

	void Update(RenderWindow& _window, GroundContainer &_myContainer);
	void MoveRight();
	void MoveLeft();
	void Inpulse();
	void Landing(RenderWindow& _window, GroundContainer& _myContainer);
	void Collide(RenderWindow& _window, GroundContainer &_myContainer);

#pragma endregion

	void Display(RenderWindow &_window);

	void Explode();
	~Lander();

#pragma region "Get/Set"

	float GetPosX();
	float GetPosY();
	Vector2f GetPos();
	float GetVelocityX();
	float GetVelocityY();
	float GetHeight();
	float GetWidth();
	Sprite GetSprite();
	FloatRect GetBound();
	bool GetIsAlive();

#pragma endregion
	
};


