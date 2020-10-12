#pragma once
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


public:
	Lander(RenderWindow &_window);

#pragma region "Lander_update"

	void Update();
	void MoveRight();
	void MoveLeft();
	void Inpulse();
	bool IsLanding();

#pragma endregion

	void Display(RenderWindow& _window);

	void Explode();
	~Lander();
	
};


