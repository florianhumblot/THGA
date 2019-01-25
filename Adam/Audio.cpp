#include "pch.h"

#include "Audio.hpp"
//
Audio::Audio(const std::string &filePath)
{
	std::ifstream soundFile(filePath, std::ios::in | std::ios::binary);
	if(!soundFile)
	{
		std::cout << "ERROR: SoundFile couldn't be opened!" << std::endl;
	}
	std::string factorySound, path = "";
	while (soundFile >> factorySound >> path)
	{
		sf::SoundBuffer b;
		sf::Sound s;
		if (b.loadFromFile(path))
		{
			std::cout << "Audio File Buffer error" << std::endl;
		}
		s.setBuffer(b);
		if (soundCollection.count(factorySound))
		{
			soundCollection[factorySound].push_back(s);

		}
		else
		{
			soundCollection[factorySound] = { s };
		}

	}
}

void Audio::playSound(std::string &key)
{

	if (!sound.getStatus()==3)
	{
		int random = rand() % soundCollection[key].size() + 1;
		sound = soundCollection[key][random];
		sound.play();
	}
	
}
