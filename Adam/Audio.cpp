#include "pch.h"

#include "Audio.hpp"
//
Audio::Audio()
{}

void Audio::playSound(std::string &path)
{
	if (!buffer.loadFromFile(path))
	{
		std::cout << "error" << std::endl;
	}
	sound.setBuffer(buffer);
	if (!sound.getStatus()==3)
	{
		sound.play();
	}
}


void Audio::playSoundRandom(std::string &path)
{
	int random = rand() % 10 + 1;
	std::string number = std::to_string(random);
	if (!buffer.loadFromFile(path + number))
	{
		std::cout << "error playing random sound" << std::endl;
	}
	sound.setBuffer(buffer);
	if (!sound.getStatus()==3)
	{
		sound.play();
	}
}