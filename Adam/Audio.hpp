#ifndef AUDIO_HPP
#define AUDIO_HPP

#include "pch.h"
#include "Character.h"
#include "Enemy.hpp"

class Audio
{
private:
	std::map<std::string, sf::SoundBuffer>soundCollection;
	sf::SoundBuffer buffer;
	sf::Music music;
	sf::Sound sound;
	std::string pathname;
public:
	Audio();

	void playSound(std::string &path);
	void playSoundRandom(std::string &path);

};
#endif //AUDIO_HPP