#pragma once
#include "Level.h"
class LvlManager
{
	std::map<std::string, Level> levels;
public:
	LvlManager();
	~LvlManager();

	std::string current_level;

	void make_lvl(std::string lvl_name);

	sf::Vector2f to_vector(const std::string & vec);
};

