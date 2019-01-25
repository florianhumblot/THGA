#ifndef AUDIO_HPP
#define AUDIO_HPP

#include "pch.h"
#include "Character.h"
#include "Enemy.hpp"

class Audio
{
private:
	std::map<std::string, std::vector<sf::Sound>>soundCollection;
	sf::SoundBuffer buffer;
	sf::Music music;
	sf::Sound sound;
public:
	Audio(const std::string &filePath);

	void playSound(std::string &key);

};
#endif //AUDIO_HPP