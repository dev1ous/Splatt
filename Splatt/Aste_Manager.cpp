#include "Aste_Manager.h"
#include "StateManager.hpp"
#include "RessourcesManager.hpp"
#include "Texture_SpriteManager.hpp"
#include "SoundManager.hpp"
#include "Aste_Player.h"
#include "Aste_Shoot.h"
#include "Aste_Asteroid.h"
#include "Aste_SmallSaucer.h"
#include "Aste_BigSaucer.h"
#include "Aste_Lights.h"
#include "Aste_Explosion.h"
#include "Controles.h"

Aste_Player* aste_player = new Aste_Player();

int Round = 0;
bool RoundPass = true;
float saucerTimer = 0.f;
float ButtonTimer = 0.f;
int Choice = 1;

void Reset()
{
	// sauvegarde

	int Scores[5] = { 0,0,0,0,0 };
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
	ExplosionList.clear();

	Round = 0;
	RoundPass = true;
	saucerTimer = 0.f;
}

void Aste_Update()
{
	ButtonTimer += MainTime.GetTimeDeltaF();
	// + 2 asteroid every round (Done)
	// + 1 saucer every 10 sec ~ (Done)
	// reset saucer spawn timer when finish a round (Done)
	// saucer timer spawn don't increase when 1 is alive (Done)

	getMusic("Alone_Against_Enemy").setLoop(true);
	if (getMusic("Alone_Against_Enemy").getStatus() != sf::Music::Playing)
		getMusic("Alone_Against_Enemy").play();

	if (EnemiesList.size() == 0)
		RoundPass = true;

	if (RoundPass)
	{
		RoundPass = false;
		Round++;
		saucerTimer = 0.f;
		for (int i = 0; i < Round * 2 + 2; i++)
		{
			sf::Vector2f tmpPos(irandom(50, 1870), irandom(50, 1030));
			while (Circle_Collision(aste_player->getPosition(), tmpPos, 1.f, 350.f))
			{
				tmpPos = sf::Vector2f(irandom(50, 1870), irandom(50, 1030));
			}
			EnemiesList.push_back(new Aste_Asteroid(tmpPos, frandom(0, 360), 3));
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
		sf::Vector2f tmpPos(irandom(50, 1870), irandom(50, 1030));
		while (Circle_Collision(aste_player->getPosition(), tmpPos, 1.f, 350.f))
		{
			tmpPos = sf::Vector2f(irandom(50, 1870), irandom(50, 1030));
		}

		if (aste_player->getScore() < 40000)
		{
			if (rand() % 100 < 50)
				EnemiesList.push_back(new Aste_SmallSaucer(tmpPos, frandom(0, 360)));
			else
				EnemiesList.push_back(new Aste_BigSaucer(tmpPos, frandom(0, 360)));

		}
		else
			EnemiesList.push_back(new Aste_SmallSaucer(tmpPos, frandom(0, 360)));
	}

	aste_player->Update();

	for (Aste_Enemies* ActualEnemie : EnemiesList)
	{
		if (!ActualEnemie->Update())
			break;
	}

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

	if (isButtonPressed(Action::Aste_RotateRight))
		aste_player->RotateClockWise();

	if (isButtonPressed(Action::Aste_RotateLeft))
		aste_player->RotateConterClockWise();

	if (isButtonPressed(Action::Aste_Forward))
		aste_player->MoveForward();
	else
		aste_player->setFrame(0);

	if (isButtonPressed(Action::Aste_Fire))
		aste_player->Shoot();

	if (isButtonPressed(Action::Escape) && ButtonTimer >= 0.5)
	{
		ButtonTimer = 0.f;
		Pause = true;
	}
}

void Aste_Display()
{
	App.clear(sf::Color::Color(40, 40, 40));

	getSprite("Moon").setOrigin(getSprite("Moon").getGlobalBounds().width / 2, getSprite("Moon").getGlobalBounds().height / 2);
	getSprite("Moon").setPosition(1600, 200);
	App.draw(getSprite("Moon"));

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
	LightList.push_back(Aste_Lights(sf::Vector3f(aste_player->getPosition().x, 1080 - aste_player->getPosition().y, 100), sf::Vector3f(0.7, 0.7, 0.7), 75.f, 0.1));
	LightList.push_back(Aste_Lights(sf::Vector3f(1600, 1080 - 200, 100), sf::Vector3f(0.8, 0.8, 0.8), 175.f, 0.2));
	for (Aste_Enemies* ActualEnemie : EnemiesList)
	{
		if (ActualEnemie->getType() != EnemiesType::Asteroids)
			LightList.push_back(Aste_Lights(sf::Vector3f(ActualEnemie->getPosition().x, 1080 - ActualEnemie->getPosition().y, 60), sf::Vector3f(0.4f, 0.45, 0.f), 55.f, 0.5));
		else
			LightList.push_back(Aste_Lights(sf::Vector3f(ActualEnemie->getPosition().x, 1080 - ActualEnemie->getPosition().y, 60), sf::Vector3f(0.45, 0.45, 0.45), 55.f, 0.5));
	}

	for (Aste_Shoot Actualshoots : Aste_ShootList)
	{
		if (Actualshoots.isPlayer())
			LightList.push_back(Aste_Lights(sf::Vector3f(Actualshoots.getPosition().x, 1080 - Actualshoots.getPosition().y, 50), sf::Vector3f(0.5f, 0.4f, 0.f), 40.f, 0.1f));
		else
			LightList.push_back(Aste_Lights(sf::Vector3f(Actualshoots.getPosition().x, 1080 - Actualshoots.getPosition().y, 50), sf::Vector3f(0.5f, 0.f, 0.f), 40.f, 0.1f));
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

	sf::Vector3f Ambiant = { 0.2f ,0.2f ,0.2f };
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
	sf::Text Tscore("", font, 30);
	Tscore.setString(std::to_string(aste_player->getScore()));
	App.draw(Tscore);

	Tscore.setPosition(0, Tscore.getGlobalBounds().height + 10);
	Tscore.setString(std::to_string(aste_player->getLives() - 1));
	App.draw(Tscore);


	// debug infos
	//for (Aste_Enemies* ActualEnemie : EnemiesList)
		//ActualEnemie->DrawDebug();

	//aste_player->DrawDebug();
}

void Aste_UpdatePause()
{
	ButtonTimer += MainTime.GetTimeDeltaF();
	if (isButtonPressed(Action::Escape) && ButtonTimer >= 0.5)
	{
		ButtonTimer = 0.f;
		Pause = false;
	}

	if (isButtonPressed(Action::UP) && ButtonTimer >= 0.2)
	{
		ButtonTimer = 0.f;
		if (Choice > 1)
			Choice--;
	}

	if (isButtonPressed(Action::Down) && ButtonTimer >= 0.2)
	{
		ButtonTimer = 0.f;
		if (Choice < 2)
			Choice++;
	}

	if (isButtonPressed(Action::Interact))
	{
		switch (Choice)
		{
		case 1:
			Pause = false;
			break;

		case 2:
			Reset();
			Pause = false;
			ChangeState(State::MENU);
			break;

		default:
			break;
		}

		ButtonTimer = 0.f;
	}
}

void Aste_DisplayPause()
{
	sf::Text TResume("Resume", font, 50);
	sf::Text TQuit("Quit", font, 50);
	float height = (TResume.getLocalBounds().height + TQuit.getLocalBounds().height) * 1.5 + 20;

	sf::RectangleShape shape(sf::Vector2f(500, height));
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(2);

	TResume.setOrigin(getMidle(TResume));
	TQuit.setOrigin(getMidle(TQuit));
	shape.setOrigin(getMidle(shape));

	shape.setPosition(960, 540);
	TResume.setPosition(960, shape.getGlobalBounds().top + getMidle(TResume).y + 10);
	TQuit.setPosition(960, TResume.getPosition().y + getMidle(TQuit).y + 20);


	switch (Choice)
	{
	case 1:
		TResume.setFillColor(sf::Color::White);
		TQuit.setFillColor(sf::Color::Color(100, 100, 100));
		break;

	case 2:
		TResume.setFillColor(sf::Color::Color(100, 100, 100));
		TQuit.setFillColor(sf::Color::White);
		break;

	default:
		break;
	}


	App.draw(TResume);
	App.draw(TQuit);
	App.draw(shape);
}


void Aste_Infos(const int& x)
{

	static float rotate1 = 0.f;
	rotate1 += -75 * MainTime.GetTimeDeltaF();

	getSprite("astePlayer").setTextureRect(sf::IntRect(0, 0, 40, 60));
	getSprite("astePlayer").setRotation(0);
	getSprite("astePlayer").setOrigin(getSprite("astePlayer").getGlobalBounds().width / 2, getSprite("astePlayer").getGlobalBounds().height / 2);
	getSprite("astePlayer").setPosition(x + 125, 150);
	getSprite("astePlayer").setRotation(rotate1);

	App.draw(getSprite("astePlayer"));


	static float rotate2 = 0.f;
	rotate2 += 75 * MainTime.GetTimeDeltaF();

	getSprite("astePlayer").setTextureRect(sf::IntRect(0, 0, 40, 60));
	getSprite("astePlayer").setRotation(0);
	getSprite("astePlayer").setOrigin(getSprite("astePlayer").getGlobalBounds().width / 2, getSprite("astePlayer").getGlobalBounds().height / 2);
	getSprite("astePlayer").setPosition(x + 125, 210);
	getSprite("astePlayer").setRotation(rotate2);

	App.draw(getSprite("astePlayer"));


	static float yBall = 200.f;
	yBall -= 125 * MainTime.GetTimeDeltaF();
	if (yBall < 50.f)
		yBall = 200;


	sf::CircleShape CBall(3);
	CBall.setPosition(x + 563.5f, yBall);
	App.draw(CBall);


	getSprite("Aste_Infos").setPosition(x, 100);
	getSprite("Aste_Infos").setScale(1.2f,1.2f);
	App.draw(getSprite("Aste_Infos"));



	std::string Scores[5];
	std::ifstream ReadSave("../Ressources/Asteroid/Scores.txt");
	if (ReadSave.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
			std::getline(ReadSave, Scores[i]);
		}

		ReadSave.close();
	}

	sf::Text Tscores("Best Scores :", font, 40);
	Tscores.setPosition(x + 655, 450);
	App.draw(Tscores);
	for (int i = 0; i < 5; i++)
	{
		Tscores.setString(Scores[i]);
		Tscores.setPosition(x + 700, 500 + (50 * i));
		App.draw(Tscores);
	}
}