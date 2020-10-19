#include "lunar_landingZone.h"

LandingZone::LandingZone()
{
	mId = 2;

	
}

LandingZone::LandingZone(float _posX, float _posY)
{
	mId = 2;

	mPosition.x = _posX;
	mPosition.y = _posY;

}

LandingZone::~LandingZone()
{
}
