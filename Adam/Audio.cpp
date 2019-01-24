#include "Audio.hpp"

Audio::Audio()
{

}

void Audio::playSound(std::string &path)
{
	if (!buffer.loadFromFile(path))
	{
		std::cout << "error" << std::endl;
	}
	sound.setBuffer(buffer);
	sound.play();
}


void Audio::playSoundRandom(std::string &path)
{
	int random = rand() % 10 + 1;
	std::string number = std::to_string(random);
	if (!buffer.loadFromFile(path + number))
	{
		std::cout << "error" << std::endl;
	}
	sound.setBuffer(buffer);
	sound.getStatus();
	sound.play();
}