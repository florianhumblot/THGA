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
	std::vector<Audio> audioGroup;
public:
	Audio();

	void playFireBall();


};

#endif //AUDIO_HPP