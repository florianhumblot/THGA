#pragma once
// ==========================================================================
//
// File      : LvlManager.h
//
// ==========================================================================

// this file contains Doxygen lines
///file LvlManager.h
/// \brief Manager for the different game levels
/// \detail
/// This class serves as a factory and a container for all game levels and handles the interaction of the player with the different levels.
#include "pch.h"
#include "Level.h"
#include "collision_handler.h"
#include "physics.h"
#include "Audio.h"

class LvlManager
{
	/// \brief shared pointer to the animation manager to be able to construct levels correctly.
	std::shared_ptr<AnimationManager> ani;
	/// \brief container of the levels, indexed by name
	std::map<std::string, Level> levels;
public:
	/// \brief constructor of the level manager. Takes a pointer to the animation manager to be able to construct levels later on.
	/// \detail
	/// Factory constructor which will read the lvls.txt file containing all the levels of this game and construct them.
	LvlManager(std::shared_ptr<AnimationManager> ani);
	~LvlManager();

	/// \brief keeps track of the current level
	std::string current_level = "lvl0";

	/// \brief sets the current level to the one specified by it's name in the parameter.
	void make_lvl(std::string lvl_name);
	/// \brief Get a pointer to the current level
	Level * getLevel();
	/// \brief string to vector function.
	sf::Vector2f to_vector(const std::string & vec);

	/// \brief checks the interaction of the player with the level
	/// \detail
	/// returns true if the end of the level has been reached and false otherwise.
	/// also changes the level when the end has been reached and respawns the player to the new spawnpoint/
	bool check_interaction(Character & player, Audio & sound);
};

