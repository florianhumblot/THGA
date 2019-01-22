#include "audio.hpp"

Audio::Audio(std::string &pathName, sf::SoundBuffer &buffer, sf::Sound &sound)
{
	if (!buffer.loadFromFile(pathName))
	{
		std::cout << "Error loading sound from memory." << std::endl;
	}
	sound.setBuffer(buffer);
}

Audio::Audio(std::string &pathName, sf::SoundBuffer &buffer, sf::Music &music)
{
	if (!buffer.loadFromFile(pathName))
	{
		std::cout << "Error loading sound from stream." << std::endl;
	}
	music.
}

void playShortSound(std::string &pathName)
{

}