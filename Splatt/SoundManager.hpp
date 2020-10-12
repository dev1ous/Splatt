#pragma once
#include "Tools.hpp"
#include "StateManager.hpp"
#include "RessourcesManager.hpp"

extern int MusicMultip;
extern int SoundMultip;

class SSound
{
public:
	SSound(std::string Name, State _state, std::string Path, float VolumeMultiplier)
	{
		m_name = Name;
		m_state = _state;
		m_volume_multi = VolumeMultiplier;

		if (m_Buffer.loadFromFile(Path))
		{
			m_sound.setBuffer(m_Buffer);	// need to redo it beacause the address is moved when pushback
		}
		else
		{
			std::cout << "ERROR: sounds : " << m_name << " didn't load" << std::endl;
		}
	};
	~SSound() {};

	std::string getName() const { return m_name; };
	State getState() const { return m_state; };
	sf::Sound& getSound() { return m_sound; };
	sf::SoundBuffer& getSoundBuffer() { return m_Buffer; };
	void update()
	{
		m_sound.setVolume(SoundMultip * m_volume_multi);
		if (m_sound.getStatus() != sf::Sound::Playing)
			m_sound.setBuffer(m_Buffer);
	};

	bool operator == (const SSound& s) const { return m_name == s.m_name && m_state == s.m_state; };
	bool operator != (const SSound& s) const { return !operator==(s); };

private:
	std::string m_name;
	//RessourceType m_type;
	State m_state;
	sf::SoundBuffer m_Buffer;
	sf::Sound m_sound;
	float m_volume_multi;

};


extern std::list<SSound> SoundList;


void LoadSounds(State _state);
sf::Sound& getSound(std::string Name);
void RemoveAllSounds();
void RemoveStateSounds(State _state);


class Musics
{
public:
	Musics() { m_state = State::RTNULL; m_volume_multi = 0; };
	~Musics() {};

	std::string getName() const { return m_name; };
	State getState() const { return m_state; };
	sf::Music& getMusic() { return m_Music; };
	void update() { m_Music.setVolume(MusicMultip * m_volume_multi); };

	void Construct(std::string Name, State _state, std::string Path, float VolumeMultiplier)
	{
		m_name = Name;
		m_state = _state;
		m_volume_multi = VolumeMultiplier;

		if (m_Music.openFromFile(Path))
		{
		}
		else
		{
			std::cout << "ERROR: Music : " << m_name << " didn't load" << std::endl;
		}
	};

	bool operator == (const Musics& s) const { return m_name == s.m_name && m_state == s.m_state; };
	bool operator != (const Musics& s) const { return !operator==(s); };

private:
	std::string m_name;
	//RessourceType m_type;
	State m_state;
	sf::Music m_Music;
	float m_volume_multi;
};


extern std::list<Musics*> MusicList;
sf::Music& getMusic(std::string Name);
void MusicPlayManager();
