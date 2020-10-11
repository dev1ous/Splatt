#include "Aste_Manager.h"
#include "RessourcesManager.hpp"
#include "Texture_SpriteManager.hpp"
#include "Aste_Player.h"
#include "Aste_Shoot.h"
#include "Aste_Asteroid.h"
#include "Aste_SmallSaucer.h"

Aste_Player* aste_player;

void Aste_Update()
{
	static bool one = false;
	if (!one)
	{
		RessourcesLoad("../Ressources/Asteroid/");
		LoadSprite(State::ASTEROID);
		aste_player = new Aste_Player();
		EnemiesList.push_back(new Aste_Asteroid(sf::Vector2f(10, 10), 0, 3));
		EnemiesList.push_back(new Aste_Asteroid(sf::Vector2f(1800, 1000), 42, 1));
		EnemiesList.push_back(new Aste_Asteroid(sf::Vector2f(1800, 10), 173, 2));
		EnemiesList.push_back(new Aste_Asteroid(sf::Vector2f(10, 1000), 260, 3));

		EnemiesList.push_back(new Aste_SmallSaucer(sf::Vector2f(200, 500), 200, 2));
		one = true;
	} 


	aste_player->Update();

	for (Aste_Enemies* ActualEnemie : EnemiesList)
	{
		ActualEnemie->Update();
	}

	int i = 0;
	for (Aste_Shoot& ActualShoot : Aste_ShootList)
	{
		ActualShoot.Update();
		if (ActualShoot.isDead())
			Aste_ShootList.erase(Aste_ShootList.begin() + i);		
		else
			i++;
	}

	i = 0;
	for (Aste_Enemies* ActualEnemie : EnemiesList)
	{
		if (ActualEnemie->getLife() <= 0)
		{
			delete ActualEnemie;
			EnemiesList.erase(EnemiesList.begin() + i);
		}
		else
			i++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		aste_player->RotateClockWise();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		aste_player->RotateConterClockWise();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		aste_player->MoveForward();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		aste_player->Shoot();
}

void Aste_Display()
{
	aste_player->Draw();

	// shoots
	sf::CircleShape CShoot(3);
	CShoot.setOrigin(CShoot.getRadius(), CShoot.getRadius());

	for (Aste_Shoot& ActualShoot : Aste_ShootList)
	{
		CShoot.setPosition(ActualShoot.getPosition());
		App.draw(CShoot);
	}

	// enemies
	for (Aste_Enemies* ActualEnemie : EnemiesList)
		ActualEnemie->Draw();
	

	// Hud
	sf::Text Tscore("", Font, 30);
	Tscore.setString(std::to_string(aste_player->getScore()));
	App.draw(Tscore);

	Tscore.setPosition(0, Tscore.getGlobalBounds().height + 10);
	Tscore.setString(std::to_string(aste_player->getLives() - 1));
	App.draw(Tscore);


	// debug infos
	for (Aste_Enemies* ActualEnemie : EnemiesList)
		ActualEnemie->DrawDebug();

	aste_player->DrawDebug();
}