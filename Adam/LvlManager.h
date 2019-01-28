#pragma once
#include "Level.h"
class LvlManager
{
	AnimationManager & ani;
	std::map<std::string, Level> levels;
public:
	LvlManager(AnimationManager & ani);
	~LvlManager();

	std::string current_level;

	void make_lvl(std::string lvl_name);

	sf::Vector2f to_vector(const std::string & vec);
};

