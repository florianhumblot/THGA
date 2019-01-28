#include "pch.h"
#include "LvlManager.h"


LvlManager::LvlManager()
{
	std::ifstream lvls_file("assets/backgrounds/lvls.txt");
	if (lvls_file.is_open())
	{
		std::string level_name, level_part, location = "";
		while (lvls_file >> level_name >> level_part >> location) {
			auto level = levels.find(level_name);
			if (level == levels.end()) {
				levels[level_name] = Level();
			}
			if (level_part == std::string("npcs")) {
				continue;
			}
			else if (level_part == std::string("enemies")) {
				continue;
			}
			else if (level_part == std::string("spawnpoint_npc") || level_part == std::string("spawnpoint_enemy")) {
				continue;
			}
			else if (level_part == std::string("spawnpoint_player")) {
				sf::Vector2f temp = to_vector(location);
				levels[level_name].set_player_spawn_point(temp);
			}
			else {
				levels[level_name].addSprite(level_part, location);
			}
		}

	}
}


LvlManager::~LvlManager()
{
}

void LvlManager::make_lvl(std::string lvl_name)
{
	current_level = lvl_name;

}

sf::Vector2f LvlManager::to_vector(const std::string & vec)
{
	{
		sf::Vector2f new_vec;
		std::string tmp = "";
		for (char c : vec)
		{
			if (c != ',')
			{
				tmp += c;
			}
			else
			{
				new_vec.x = std::stof(tmp);
				tmp = "";
			}

		}
		new_vec.y = std::stof(tmp);
		return new_vec;
	}
}
