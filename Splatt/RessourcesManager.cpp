#include "Tools.hpp"
#include "RessourcesManager.hpp"
#include <filesystem>

std::list<Ressources> RessourcesList;


void RessourcesLoad(std::string path)
{
	namespace fs = std::filesystem;

	for (const fs::directory_entry& entry : fs::directory_iterator(path))
	{
		std::string tmpExtension;
		// take Name of the element (ex : ../Ressources/Background.png)
		std::string tmp = entry.path().string();
		std::cout << tmp << std::endl;

		// erase the path (ex : Background.png)
		tmp.erase(0, path.size());

		// erase the extention (ex : Background)
		size_t position = tmp.find(".");
		if (position != -1)
		{
			tmpExtension = tmp.substr(position);
			tmp.erase(position);
		}


		Ressources tmpRessource;
		tmpRessource.type = RessourceType::UNKNOWN;
		tmpRessource.name = tmp;
		tmpRessource.path = path + tmp + tmpExtension;
		std::string InfoPath = "";

		if (tmpExtension == ".wav")
		{
			tmpRessource.type = RessourceType::SOUNDFX;
			InfoPath = "../Ressources/Infos/Sound.load";
		}
		else if (tmpExtension == ".ogg")
		{
			tmpRessource.type = RessourceType::MUSIC;
			InfoPath = "../Ressources/Infos/Music.load";
		}
		else if (tmpExtension == ".png")
		{
			tmpRessource.type = RessourceType::TEXTURE;
			InfoPath = "../Ressources/Infos/Textures.load";
		}
		else if (tmpExtension == ".jpg")
		{
			tmpRessource.type = RessourceType::TEXTURE;
			InfoPath = "../Ressources/Infos/Textures.load";
		}
		else if (tmpExtension == ".lang")
		{
			tmpRessource.type = RessourceType::LANG;
			InfoPath = "../Ressources/Infos/Langs.load";

		}


		if (InfoPath.size() != 0)
		{
			std::ifstream File(InfoPath);
			std::string Line;
			if (File.is_open())
			{
				while (std::getline(File, Line))
				{
					std::string FileName = "";
					FileName = Line.substr(0, Line.find(" "));

					if (FileName == tmp)
					{
						Line.erase(0, FileName.size() + 3);

						if (InfoPath == "../Ressources/Infos/Sound.load" || InfoPath == "../Ressources/Infos/Music.load")
						{
							tmpRessource.soundmultiplier = std::stof(Line.substr(0, Line.find(" ")));
							Line.erase(0, Line.substr(0, Line.find(" ")).size() + 3);
						}


						bool done = false;
						while (!done)
						{
							std::string ActiveStage = Line.substr(0, Line.find(" "));
							Line.erase(0, ActiveStage.size());

							if (ActiveStage == "All")
							{
								tmpRessource.state = State::ALL;
								RessourcesList.push_back(tmpRessource);
							}
							/*if (ActiveStage == "Intro")
							{
								tmpRessource.state = State::INTRO;
								RessourcesList.push_back(tmpRessource);
							}*/
							if (ActiveStage == "Menu")
							{
								tmpRessource.state = State::MENU;
								RessourcesList.push_back(tmpRessource);
							}
							if (ActiveStage == "Asteroid")
							{
								tmpRessource.state = State::ASTEROID;
								RessourcesList.push_back(tmpRessource);
							}

							if (Line.find("|") == -1)
								done = true;
							else
								Line.erase(0, 3);

						};
						break;

					}
				}

				File.close();
			}
			else
				std::cout << "Error Open File : " << InfoPath << std::endl;
		}
	}
}