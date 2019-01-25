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
		if (!b.loadFromFile(path))
		{
			std::cout << path << "Audio File Buffer error" << std::endl;
		}
		s.setBuffer(b);
		if (soundCollection.count(factorySound))
		{
			soundCollection[factorySound].push_back(b);
			std::cout << " pushing back sound into vector" << path << std::endl;
		}
		else
		{
			std::cout << " adding sound into vector manually" << path << std::endl;
			soundCollection[factorySound] = { b };
		}

	}

	sound.setBuffer(soundCollection["Fireball"][1]);
}

void Audio::playSound(const std::string &key)
{

	std::cout << "in function playSound " << std::endl;
	if (sound.getStatus()!=sf::SoundSource::Status::Playing)
	{
	
		int random = rand() %  (soundCollection[key].size()-1);
		sound.setBuffer(soundCollection[key][random]);
		std::cout << key << ' ' << random << ' '  << std::endl;
		sound.play();
	}
	
}
