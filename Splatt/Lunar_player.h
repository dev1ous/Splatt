#pragma once
#include "Lunar_GroundContainer.h"
#include "pch.h"
#include "Tools.hpp"

class Lander
{
protected:

	Texture mTexture;
	Sprite mSprite;
	Vector2f mPosition;
	Vector2f mVelocity;
	float mAngle;
	bool mEngineOn;

	FloatRect mCollideBox;


public:
	Lander(RenderWindow &_window);

#pragma region "Lander_update"

	void Update(GroundContainer& _myContainer);
	void MoveRight();
	void MoveLeft();
	void Inpulse();
	void Landing();
	bool IsCollide(GroundContainer& _myContainer);

#pragma endregion

	void Display(RenderWindow& _window);

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

#pragma endregion
	
};


