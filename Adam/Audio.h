#pragma once
// ==========================================================================
//
// File      :Audio.h
//
// ==========================================================================

// this file contains Doxygen lines
///file Audio.h
/// \brief-Audio implementation - enables the use of sound effects and music ingame
/// \details
/// This class serves as way to easily add and make use of audio effects and music implementation.

#include "pch.h"

class Audio
{
private:
	/// \brief Foundation of audio
	/// \detail
	/// Acces the Buffers that will be bound to Sound in a later stage.
	std::map<std::string, std::vector<sf::SoundBuffer>>soundCollection;
	/// \brief Foundation of sound
	/// \detail
	/// a collection of sounds that are accesible through playSound functions.
	std::map<std::string, std::vector<sf::Sound>> themSounds;
	/// \brief buffer for the factory
	/// \detail
	/// repeatable buffer that gets placed in the soundCollection Map
	sf::SoundBuffer buffer;
	/// \brief variable told music
	/// \detail
	/// the variable that holds the music and is called upon to play music
	sf::Music music;
	/// \brief a sound for the themSounds Map
	/// \detail
	/// the variable that gets pushed into the sound Map
	sf::Sound sound;
public:
	/// \briefdefault constructor
	/// \detail
	/// constructor that calls upon a factory that read a txt file to put all the buffers in a std::map.
	/// takes a key to search for a buffer in the map, only to be passed along to a sound variable in the soundMaker function
	Audio(const std::string &filePath);
	/// \brief function to play single sounds
	/// \detail
	/// a function that can only play one single sound at the time, and can only play a new sound when the previous sound is finished
	/// takes a key to search for a sound in the map, value is a sound
	void playSound(const std::string &key, const float volume);
	/// \brief function that makes a map of sounds
	/// \detail
	/// a function that puts all the buffers from soundCollection into a map of sounds to increase performance
	void soundMaker();
	/// \brief a function to play simultaneous sounds
	/// \detail
	/// the function that should be called upon when you need to play multiple sounds at the same time at the same event
	void playSoundTwo(const std::string &key, const float volume);
	/// \brief function to play music
	/// \detail
	/// the function that can play music 
	void playMusic(const std::string & song,const float volume);
};
