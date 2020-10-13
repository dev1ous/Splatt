#include "Aste_Lights.h"

std::vector<Aste_Lights> LightList;

Aste_Lights::Aste_Lights()
{
}

Aste_Lights::Aste_Lights(sf::Vector3f pos, sf::Vector3f color, float radius, float FallOff) : m_position(pos), m_color(color), m_radius(radius), m_falloff(FallOff)
{
}

Aste_Lights::~Aste_Lights()
{
}
