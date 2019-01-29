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
			std::cout << " pushing back buffer into vector " << path << std::endl;
		}
		else
		{
			std::cout << " adding buffer into vector manually" << path << std::endl;
			soundCollection[factorySound] = { b };
		}

	}

	sound.setBuffer(soundCollection["Fireball"][1]);
	soundMaker();
}

void Audio::playSound(const std::string &key, const float volume)
{

	std::cout << "in function playSound " << std::endl;
	if (sound.getStatus()!=sf::SoundSource::Status::Playing)
	{
	
		
		if (soundCollection[key].size() == 1)
		{
			sound.setBuffer(soundCollection[key][0]);
		}
		else
		{
		int random = rand() % (soundCollection[key].size() - 1);
		sound.setBuffer(soundCollection[key][random]);
		std::cout << key << ' ' << random << ' ' << std::endl;
		}
		sound.setVolume(volume);
		sound.play();
	}
	
}

void Audio::soundMaker()
{
	for (auto &string : soundCollection)
	{

		std::cout << "soundmake First Loop-- " << string.first << std::endl;
		for (auto &buffers : string.second)
		{
			std::cout << "soundmake SECOND Loop-- " << std::endl;

			sound.setBuffer(buffers);
			if (themSounds.count(string.first))
			{
				std::cout << "in IF ---" << std::endl;
				themSounds[string.first].push_back(sound);

			}
			else
			{
				std::cout << "in ELSE-- " << std::endl;
				themSounds[string.first] = { sound };
			}

		}
	}
}

void Audio::playSoundTwo(const std::string &key, const float volume)
{
	if (sound.getStatus() != sf::SoundSource::Status::Playing)
	{
		int random = rand() % (themSounds[key].size() - 1);
		themSounds[key][random].setVolume(volume);
		themSounds[key][random].play();
	}
	
}

void Audio::playMusic(const std::string& song, float volume)
{

	if (!music.openFromFile(song))
	{
		std::cout<< "song not LOADED ERROR" << std::endl;
	}
	if (music.getStatus() != sf::SoundSource::Status::Playing)
	{
		music.setLoop(true);
		music.setVolume(volume);
		music.play();
	}

}


