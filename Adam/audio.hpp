#ifndef AUDIO_HPP
#define AUDIO_HPP

#include "pch.h"

class Audio
{
private:
	sf::SoundBuffer buffer;
	sf::Music music;
	sf::Sound sound;
	std::string pathName;
public:
	Audio(std::string &pathName, sf::SoundBuffer &buffer, sf::Sound &sound);

	Audio(std::string &pathName, sf::SoundBuffer &buffer,sf::Music &music);

	void playShortSound(std::string &pathName);
};


#endif //AUDIO_HPP