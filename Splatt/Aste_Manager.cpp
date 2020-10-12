#include "Aste_Manager.h"
#include "RessourcesManager.hpp"
#include "Texture_SpriteManager.hpp"
#include "Aste_Player.h"
#include "Aste_Shoot.h"
#include "Aste_Asteroid.h"
#include "Aste_SmallSaucer.h"
#include "Aste_BigSaucer.h"

Aste_Player* aste_player = new Aste_Player();

int Round = 0;
bool RoundPass = true;


void Aste_Update()
{
	// + 2 asteroid every round (Done)
	// + 1 saucer every 10 sec ~
	// reset saucer spawn timer when finish a round
	// saucer timer spawn don't increase when 1 is alive
	
	if (EnemiesList.size() == 0)
		RoundPass = true;

	if (RoundPass)
	{
		RoundPass = false;
		Round++;
		for (int i = 0; i < Round * 2 + 2; i++)
		{
			EnemiesList.push_back(new Aste_Asteroid(sf::Vector2f(irandom(50, 1870), irandom(50, 1030)), frandom(0, 360), 3));
		}
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
			break;
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