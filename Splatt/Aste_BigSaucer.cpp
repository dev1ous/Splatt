#include "Aste_BigSaucer.h"
#include "Aste_Player.h"
#include "Aste_Shoot.h"

Aste_BigSaucer::Aste_BigSaucer()
{
	m_shoot_timer = 0;
}

Aste_BigSaucer::Aste_BigSaucer(sf::Vector2f position, float rotation) : Aste_Enemies(position, rotation, 2)
{
	m_shoot_timer = 0;
}

Aste_BigSaucer::~Aste_BigSaucer()
{
}

void Aste_BigSaucer::RemoveLife()
{
	aste_player->AddScore(300);
	Kill();
}

void Aste_BigSaucer::Update()
{
	setPosition(getPosition() + getVelocity() * MainTime.GetTimeDeltaF());

	if (getPosition().x < -15)
		setPosition(sf::Vector2f(1920 + 15, getPosition().y));
	else if (getPosition().x > 1920 + 15)
		setPosition(sf::Vector2f(-15, getPosition().y));

	if (getPosition().y < -15)
		setPosition(sf::Vector2f(getPosition().x, 1080 + 15));
	else if (getPosition().y > 1080 + 15)
		setPosition(sf::Vector2f(getPosition().x, -15));

	m_shoot_timer += MainTime.GetTimeDeltaF();
	if (m_shoot_timer >= 0.75f)
	{
		m_shoot_timer = 0;

		Aste_ShootList.push_back(Aste_Shoot(getPosition(), frandom(0, 360), false));
	}
}

void Aste_BigSaucer::Draw()
{
}

void Aste_BigSaucer::DrawDebug()
{
	sf::CircleShape Colision(getLife() * 10);
	Colision.setOrigin(Colision.getRadius(), Colision.getRadius());
	Colision.setPosition(getPosition());

	Colision.setFillColor(sf::Color::Transparent);
	Colision.setOutlineThickness(1);
	Colision.setOutlineColor(sf::Color::Red);
	App.draw(Colision);


	sf::RectangleShape Dir(sf::Vector2f(1, Colision.getRadius()));
	Dir.setPosition(getPosition());
	float angle = (double)Angle_calc(getPosition(), getPosition() + getVelocity()) * 180 / pi;
	Dir.setRotation(angle - 90);
	App.draw(Dir);
}
