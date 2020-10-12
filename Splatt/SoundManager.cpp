#include "SoundManager.hpp"

std::list<SSound> SoundList;
std::list<Musics*> MusicList;
int MusicMultip = 50;
int SoundMultip = 30;
 
void LoadSounds(State _state)
{
	for (Ressources& ActualRessource : RessourcesList)
	{
		if (ActualRessource.state == _state)
		{
			if (ActualRessource.type == RessourceType::SOUNDFX)
			{
				SoundList.push_back(SSound(ActualRessource.name, ActualRessource.state, ActualRessource.path, ActualRessource.soundmultiplier));
			}
			else if (ActualRessource.type == RessourceType::MUSIC)
			{
				Musics* ConstructMusic = new Musics;
				ConstructMusic->Construct(ActualRessource.name, ActualRessource.state, ActualRessource.path, ActualRessource.soundmultiplier);

				MusicList.push_back(ConstructMusic);
			}
		}
	}
}

sf::Sound& getSound(std::string Name)
{
	for (SSound& ActualSound : SoundList)
	{
		if (ActualSound.getName() == Name)
		{
			return ActualSound.getSound();
		}
	}
}

sf::Music& getMusic(std::string Name)
{
	for (Musics* ActualMusic : MusicList)
	{
		if (ActualMusic->getName() == Name)
		{
			return ActualMusic->getMusic();
		}
	}
}

void RemoveStateSounds(State _state)
{
	bool Removed = true;
	while (Removed)
	{
		Removed = false;
		for (SSound& ActualSound : SoundList)
		{
			if (ActualSound.getState() == _state && _state != State::ALL)
			{
				SoundList.remove(ActualSound);
				Removed = true;
				break;
			}
		}

		for (Musics* ActualMusic : MusicList)
		{
			if (ActualMusic->getState() == _state && _state != State::ALL)
			{
				delete ActualMusic;
				MusicList.remove(ActualMusic);
				Removed = true;
				break;
			}
		}
	}
}


void RemoveAllSounds()
{
	bool Removed = true;
	while (Removed)
	{
		Removed = false;
		for (SSound& ActualSound : SoundList)
		{
			if (ActualSound.getState() != State::ALL)
			{
				SoundList.remove(ActualSound);
				Removed = true;
				break;
			}
		}

		for (Musics* ActualMusic : MusicList)
		{
			if (ActualMusic->getState() != State::ALL)
			{
				delete ActualMusic;
				MusicList.remove(ActualMusic);
				Removed = true;
				break;
			}
		}
	}
}


void MusicPlayManager()
{
	
}