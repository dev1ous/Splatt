#pragma once
#include "Tools.hpp"
#include "StateManager.hpp"

enum class RessourceType
{
	UNKNOWN,
	TEXTURE,
	SOUNDFX,
	MUSIC,
	LANG,
};

struct Ressources
{
	State state;
	RessourceType type;
	std::string name;
	std::string path;
	float soundmultiplier;
};

extern std::list<Ressources> RessourcesList;

void RessourcesLoad(std::string path);