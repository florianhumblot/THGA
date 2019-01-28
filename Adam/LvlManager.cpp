#include "pch.h"
#include "LvlManager.h"


LvlManager::LvlManager()
{
	std::ifstream lvls_file("assets/backgrounds/lvls.txt");
	if (lvls_file.is_open())
	{
		std::string level_name, level_part, location;
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
			else if (level_part == std::string("spawnpoint_player") || level_part == std::string("spawnpoint_npc") || level_part == std::string("spawnpoint_enemy")) {
				continue;
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
