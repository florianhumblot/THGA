#include "audio.hpp"

Audio::Audio(const std::string &pathName)
{
	if (!buffer.loadFromFile(pathName))
	{
		std::cout << "Error loading sound from memory." << std::endl;
	}
	sound.setBuffer(buffer);
}

Audio::Audio(const std::string &pathName)
{
	if (!buffer.loadFromFile(pathName))
	{
		std::cout << "Error loading sound from stream." << std::endl;
	}
	music.
}
