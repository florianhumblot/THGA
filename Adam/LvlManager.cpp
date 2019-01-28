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
			levels[level_name].addSprite(level_part, location);
		}

	}
}


LvlManager::~LvlManager()
{
}
