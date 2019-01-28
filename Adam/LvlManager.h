#pragma once
#include "Level.h"
class LvlManager
{
	std::shared_ptr<AnimationManager> ani;
	std::map<std::string, Level> levels;
public:
	LvlManager(std::shared_ptr<AnimationManager> ani);
	~LvlManager();

	std::string current_level;

	void make_lvl(std::string lvl_name);
	std::shared_ptr<Level> getLevel();
	sf::Vector2f to_vector(const std::string & vec);
};

