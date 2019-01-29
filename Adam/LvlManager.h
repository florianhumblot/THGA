#pragma once
#include "pch.h"
#include "Level.h"
#include "collision_handler.h"
#include "physics.h"
#include "Audio.hpp"

class LvlManager
{
	std::shared_ptr<AnimationManager> ani;
	std::map<std::string, Level> levels;
public:
	LvlManager(std::shared_ptr<AnimationManager> ani);
	~LvlManager();

	std::string current_level = "lvl1";

	void make_lvl(std::string lvl_name);
	Level * getLevel();
	sf::Vector2f to_vector(const std::string & vec);
	bool check_interaction(Character & player, Audio & sound);
};

