#include "pch.h"

#include "Audio.h"
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
		}
		else
		{
			soundCollection[factorySound] = { b };
		}
	}
	sound.setBuffer(soundCollection["Fireball"][1]);
	soundMaker();
}

void Audio::playSound(const std::string &key, const float volume)
{
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
		for (auto &buffers : string.second)
		{
			sound.setBuffer(buffers);
			if (themSounds.count(string.first))
			{
				themSounds[string.first].push_back(sound);
			}
			else
			{
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

void Audio::playMusic(const std::string& song,const float volume)
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

bool Audio::anySound()
{
	if (sound.getStatus() == sf::SoundSource::Status::Playing)
	{
		return true;
	}
}


