#include "Aste_Explosion.h"
#include "Texture_SpriteManager.hpp"

std::vector<Aste_Explosion> ExplosionList;

Aste_Explosion::Aste_Explosion()
{
	m_timer = 0.f;
	m_dead = false;
	m_rect = sf::IntRect(0,0,80,80);
}

Aste_Explosion::Aste_Explosion(sf::Vector2f pos) : m_position(pos)
{
	m_timer = 0.f;
	m_dead = false;
	m_rect = sf::IntRect(0,0,80,80);
}

Aste_Explosion::~Aste_Explosion()
{
}

void Aste_Explosion::update()
{
	m_timer += MainTime.GetTimeDeltaF();

	if (m_timer >= 0.05f)
	{
		m_timer -= 0.05f;

		if (m_rect.left == m_rect.width * 23)
			m_dead = true;
		else
			m_rect.left += m_rect.width;
	}
}

void Aste_Explosion::draw()
{
	getSprite("Aste_Explosion").setTextureRect(m_rect);
	getSprite("Aste_Explosion").setOrigin(getSprite("Aste_Explosion").getGlobalBounds().width / 2, getSprite("Aste_Explosion").getGlobalBounds().height / 2);
	getSprite("Aste_Explosion").setPosition(m_position);

	App.draw(getSprite("Aste_Explosion"));
}
