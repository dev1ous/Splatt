#pragma once
#include "Tools.hpp"

class Aste_Lights
{
	sf::Vector3f m_position;
	sf::Vector3f m_color;
	float m_radius;
	float m_falloff;

public:
	Aste_Lights();
	Aste_Lights(sf::Vector3f pos, sf::Vector3f color, float radius, float FallOff);
	~Aste_Lights();

	sf::Vector3f getPosition() const { return m_position; }
	sf::Vector3f getColor() const { return m_color; }
	float getRadius() const { return m_radius; }
	float getFallOff() const { return m_falloff; }
};

extern std::vector<Aste_Lights> LightList;