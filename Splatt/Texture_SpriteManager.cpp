#include "Texture_SpriteManager.hpp"

std::list<Sprite*> SpriteList;

void LoadSprite(State _state)
{
	for (Ressources& ActualRessource : RessourcesList)
	{
		if (ActualRessource.state == _state)
		{
			if (ActualRessource.type == RessourceType::TEXTURE)
			{
		
				Sprite* tmp = new Sprite;
				tmp->init(ActualRessource.name, ActualRessource.state, ActualRessource.path);

				SpriteList.push_back(tmp);
			
			
			}
		}
	}
}

sf::Sprite& getSprite(std::string Name)
{
	for (Sprite* ActualSprite : SpriteList)
	{
		if (ActualSprite->getName() == Name)
		{
			ActualSprite->getSprite().setTexture(ActualSprite->getTexture());
			return ActualSprite->getSprite();
		}
	}
	std::cout << "Error Loading Sprite : " << Name << std::endl;
}

sf::Texture& getTexture(std::string Name)
{	
	for (Sprite* ActualSprite : SpriteList)
	{
		if (ActualSprite->getName() == Name)
		{
			return ActualSprite->getTexture();
		}
	}
	std::cout << "Error Loading Texture : " << Name << std::endl;
}

void RemoveStateSprites(State _state)
{
	bool Removed = true;
	while (Removed)
	{
		Removed = false;
		for (Sprite* ActualSprite : SpriteList)
		{
			if (ActualSprite->getState() == _state && _state != State::ALL)
			{
				delete ActualSprite;
				SpriteList.remove(ActualSprite);
				Removed = true;
				break;
			}
		}
	}
}

void RemoveAllSprites()
{
	bool Removed = true;
	while (Removed)
	{
		Removed = false;
		for (Sprite* ActualSprite : SpriteList)
		{
			if (ActualSprite->getState() != State::ALL)
			{
				delete ActualSprite;
				SpriteList.remove(ActualSprite);
				Removed = true;
				break;
			}
		}
	}
}