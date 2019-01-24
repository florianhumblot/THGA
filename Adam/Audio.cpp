#include "pch.h"
#include "audio.hpp"

Audio::Audio()
{};


void Audio::playFireBall()
{
	if (!buffer.loadFromFile("audio/fireBall.wav"))
	{
		std::cout << "Error loading Sound" << std::endl;
	}
	sound.setBuffer(buffer);
	sound.play();
}


