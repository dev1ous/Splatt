#include "Aste_Manager.h"
#include "RessourcesManager.hpp"
#include "Texture_SpriteManager.hpp"
#include "Aste_Player.h"
#include "Aste_Shoot.h"
#include "Aste_Asteroid.h"
#include "Aste_SmallSaucer.h"
#include "Aste_BigSaucer.h"
#include "Aste_Lights.h"
#include "Aste_Explosion.h"

Aste_Player* aste_player = new Aste_Player();

int Round = 0;
bool RoundPass = true;
float saucerTimer = 0.f;
void Reset()
{
	// sauvegarde

	int Scores[5] = {0,0,0,0,0};
	std::ifstream ReadSave("../Ressources/Asteroid/Scores.txt");
	if (ReadSave.is_open())
	{
		std::string Line;
		for (int i = 0; i < 5; i++)
		{
			std::getline(ReadSave, Line);
			Scores[i] = std::stoi(Line);
		}

		ReadSave.close();
	}

	for (int i = 0; i < 5; i++)
	{
		if (aste_player->getScore() > Scores[i])
		{
			for (int y = 4; y > i; y--)
			{
				if (y > 0)
					Scores[y] = Scores[y - 1];
			}
			Scores[i] = aste_player->getScore();
			break;
		}
	}

	std::ofstream SaveFile("../Ressources/Asteroid/Scores.txt");
	if (SaveFile.is_open())
	{
		for (int i = 0; i < 5; i++)
			SaveFile << std::to_string(Scores[i]) << std::endl;

		SaveFile.close();
	}

	// reset
	delete aste_player;
	aste_player = new Aste_Player();

	for (Aste_Enemies* ActualEnemie : EnemiesList)
		delete ActualEnemie;
	EnemiesList.clear();	

	LightList.clear();
	Aste_ShootList.clear();

	Round = 0;
	RoundPass = true;
	saucerTimer = 0.f;
}

void Aste_Update()
{
	// + 2 asteroid every round (Done)
	// + 1 saucer every 10 sec ~ (Done)
	// reset saucer spawn timer when finish a round (Done)
	// saucer timer spawn don't increase when 1 is alive (Done)
	
	if (EnemiesList.size() == 0)
		RoundPass = true;

	if (RoundPass)
	{
		RoundPass = false;
		Round++;
		saucerTimer = 0.f;
		for (int i = 0; i < Round * 2 + 2; i++)
		{
			EnemiesList.push_back(new Aste_Asteroid(sf::Vector2f(irandom(50, 1870), irandom(50, 1030)), frandom(0, 360), 3));
		}
	}

	bool saucer_exist = false;
	for (Aste_Enemies* ActualEnemie : EnemiesList)
	{
		if (ActualEnemie->getType() != EnemiesType::Asteroids)
			saucer_exist = true;
	}

	if (!saucer_exist)
		saucerTimer += MainTime.GetTimeDeltaF();
	if (saucerTimer >= 10.f)
	{
		saucerTimer = 0.f;
		if (aste_player->getScore() < 40000)
		{
			if (rand() % 100 < 50)
				EnemiesList.push_back(new Aste_SmallSaucer(sf::Vector2f(irandom(50, 1870), irandom(50, 1030)), frandom(0, 360)));
			else
				EnemiesList.push_back(new Aste_BigSaucer(sf::Vector2f(irandom(50, 1870), irandom(50, 1030)), frandom(0, 360)));

		}
		else
			EnemiesList.push_back(new Aste_SmallSaucer(sf::Vector2f(irandom(50, 1870), irandom(50, 1030)), frandom(0, 360)));
	}

	aste_player->Update();

	for (Aste_Enemies* ActualEnemie : EnemiesList)
		ActualEnemie->Update();	

	for (Aste_Explosion& ActualExplosion : ExplosionList)
		ActualExplosion.update();

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

	i = 0;
	for (Aste_Explosion& ActualExplosion : ExplosionList)
	{
		if (ActualExplosion.isDead())
		{
			ExplosionList.erase(ExplosionList.begin() + i);
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
	else
		aste_player->setFrame(0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		aste_player->Shoot();

}

void Aste_Display()
{
	App.clear(sf::Color::Color(40, 40, 40));


	static sf::Shader shader;

	// shoots
	sf::CircleShape CShoot(3);
	CShoot.setOrigin(CShoot.getRadius(), CShoot.getRadius());

	for (Aste_Shoot& ActualShoot : Aste_ShootList)
	{
		CShoot.setPosition(ActualShoot.getPosition());
		App.draw(CShoot);
	}

	// player
	aste_player->Draw();

	// explosions
	for (Aste_Explosion& ActualExplosion : ExplosionList)
		ActualExplosion.draw();

	// enemies
	for (Aste_Enemies* ActualEnemie : EnemiesList)
		ActualEnemie->Draw();

















	static sf::RenderStates Rstate;
	static sf::Texture _textureLastPass;
	static sf::Texture _textureDiffuse;
	static sf::Texture _textureFond;
	static sf::Sprite _spriteFond;

	static bool onepass = false;
	if (!onepass)
	{
		shader.loadFromFile("../Ressources/Asteroid/LightFading2.frag", sf::Shader::Type::Fragment);
		_textureLastPass.create(App.getSize().x, App.getSize().y);
		_textureDiffuse.create(App.getSize().x, App.getSize().y);
		_textureFond.create(App.getSize().x, App.getSize().y);
		_spriteFond.setTexture(_textureFond);

		onepass = true;
	}

	Rstate.shader = &shader;
	Rstate.blendMode = sf::BlendAlpha;
	Rstate.transform = sf::Transform::Identity;
	Rstate.texture = NULL;


	// light
	LightList.clear();
	LightList.push_back(Aste_Lights(sf::Vector3f(aste_player->getPosition().x, 1080 - aste_player->getPosition().y, 100), sf::Vector3f(0.7,0.7,0.7), 75.f, 0.1));
	for (Aste_Enemies* ActualEnemie : EnemiesList)
	{
		if (ActualEnemie->getType() != EnemiesType::Asteroids)
			LightList.push_back(Aste_Lights(sf::Vector3f(ActualEnemie->getPosition().x, 1080 - ActualEnemie->getPosition().y, 60), sf::Vector3f(0.4f,0.45,0.f), 55.f, 0.5));
		else
			LightList.push_back(Aste_Lights(sf::Vector3f(ActualEnemie->getPosition().x, 1080 - ActualEnemie->getPosition().y, 60), sf::Vector3f(0.45,0.45,0.45), 55.f, 0.5));
	}

	for (Aste_Shoot Actualshoots : Aste_ShootList)
	{
		if (Actualshoots.isPlayer())
			LightList.push_back(Aste_Lights(sf::Vector3f(Actualshoots.getPosition().x, 1080 - Actualshoots.getPosition().y, 50), sf::Vector3f(0.6f, 0.5f, 0.f), 40.f, 0.05f));
		else
			LightList.push_back(Aste_Lights(sf::Vector3f(Actualshoots.getPosition().x, 1080 - Actualshoots.getPosition().y, 50), sf::Vector3f(0.6f, 0.f, 0.f), 40.f, 0.05f));
	}
	for (Aste_Shoot Actualshoots : Aste_ShootList)
	{
		if (Actualshoots.isPlayer())
			LightList.push_back(Aste_Lights(sf::Vector3f(Actualshoots.getPosition().x, 1080 - Actualshoots.getPosition().y, 50), sf::Vector3f(0.6f, 0.5f, 0.f), 40.f, 0.05f));
		else
			LightList.push_back(Aste_Lights(sf::Vector3f(Actualshoots.getPosition().x, 1080 - Actualshoots.getPosition().y, 50), sf::Vector3f(0.6f, 0.f, 0.f), 40.f, 0.05f));
	}
	for (Aste_Explosion& ActualExplosion : ExplosionList)
	{
		float intencity = (ActualExplosion.getFrame() - 2.f) / 10.f;
		intencity = 1.f - intencity;
		
		LightList.push_back(Aste_Lights(sf::Vector3f(ActualExplosion.getPosition().x, 1080 - ActualExplosion.getPosition().y, 25), sf::Vector3f(0.8f * intencity, 0.4f * intencity, 0.f), 70.f, 0.07f));
	}

	// shader
	_spriteFond.setTexture(_textureFond);
	App.draw(_spriteFond);

	_textureLastPass.update(App);
	_textureDiffuse.update(App);

	sf::Vector3f Ambiant = { 0.1f ,0.1f ,0.1f };
	shader.setUniform("AmbientLight", Ambiant);

	int _pass = 1;
	int a = 0;
	for (Aste_Lights& actualLight : LightList)
	{
		shader.setUniform("DiffuseMap", _textureDiffuse);
		shader.setUniform("LastPass", _textureLastPass);
		shader.setUniform("PassNumber", _pass);
		shader.setUniform("LightCount", a + 1);

		std::string Lights;
		Lights = "Lights[" + std::to_string(a) + "].position";
		shader.setUniform(Lights, actualLight.getPosition());
		Lights = "Lights[" + std::to_string(a) + "].color";
		shader.setUniform(Lights, actualLight.getColor());
		Lights = "Lights[" + std::to_string(a) + "].radius";
		shader.setUniform(Lights, actualLight.getRadius());
		Lights = "Lights[" + std::to_string(a) + "].falloff";
		shader.setUniform(Lights, actualLight.getFallOff());


		a++;
		if (a >= 3)
		{
			_spriteFond.setTexture(_textureLastPass);
			App.draw(_spriteFond, &shader);
			_textureLastPass.update(App);
			_pass++;
			a = 0;
		}
		else
		{
			_spriteFond.setTexture(_textureDiffuse);
			App.draw(_spriteFond, &shader);
		}

	}


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