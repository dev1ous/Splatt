#include "Aste_Explosion.h"
#include "Texture_SpriteManager.hpp"

std::vector<Aste_Explosion> ExplosionList;

Aste_Explosion::Aste_Explosion()
{
	m_frame = 0;
	m_timer = 0.f;
	m_dead = false;
	m_rect = sf::IntRect(0,0,96, 96);
}

Aste_Explosion::Aste_Explosion(sf::Vector2f pos) : m_position(pos)
{
	m_frame = 2; 
	m_timer = 0.f;
	m_dead = false;
	m_rect = sf::IntRect(2 * 96, 0, 96, 96);
}

Aste_Explosion::~Aste_Explosion()
{
}

void Aste_Explosion::update()
{
	m_timer += MainTime.GetTimeDeltaF();

	if (m_timer >= 0.1f)
	{
		m_timer -= 0.1f;

		if (m_frame == 12)
			m_dead = true;
		else
		{
			m_frame++;
			m_rect.left += m_rect.width;			
		}
	}
}

void Aste_Explosion::draw()
{
	getSprite("Aste_Explosion").setTextureRect(m_rect);
	getSprite("Aste_Explosion").setOrigin(getSprite("Aste_Explosion").getGlobalBounds().width / 2, getSprite("Aste_Explosion").getGlobalBounds().height / 2);
	getSprite("Aste_Explosion").setPosition(m_position);

	App.draw(getSprite("Aste_Explosion"));
}
