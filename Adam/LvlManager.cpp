#include "pch.h"
#include "LvlManager.h"

LvlManager::LvlManager(std::shared_ptr<AnimationManager> ani) : ani(ani)
{

	std::ifstream lvls_file("assets/backgrounds/lvls.txt");
	if (lvls_file.is_open())
	{
		std::string level_name, level_part, location = "";
		while (lvls_file >> level_name >> level_part >> location) {
			std::cout << "Level name: " << level_name << std::endl; 
			auto level = levels.find(level_name);
			if (level == levels.end()) {
				Level L(ani);
				levels[level_name] = L;
			}
			if (level_part == std::string("npcs")) {
				levels[level_name].npc_factory(location);
			}
			else if (level_part == std::string("enemies")) {
				levels[level_name].enemy_factory(location);
			}
			else if (level_part == std::string("spawnpoint_player")) {
				sf::Vector2f temp = to_vector(location);
				levels[level_name].set_player_spawn_point(temp);
			}
			else if (level_part == std::string("next_level")) {
				levels[level_name].set_next_level(location);
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

Level * LvlManager::getLevel()
{
	return &levels[current_level];
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

void LvlManager::check_interaction(Character & player) {
	if (Collision::PixelPerfectTest(levels[current_level].getLayer("foreground_dmg"), player))
	{
		player.health.sub(((float)(player.health.max / 100) * 0.5f));

	}

	if (Collision::PixelPerfectTest(levels[current_level].getLayer("inifinity"), player))
	{
		player.respawn();

	}

	if (Collision::PixelPerfectTest(levels[current_level].getLayer("lvl_end"), player))
	{
		//next_lvl(player);
		current_level = levels[current_level].get_next_level();
		levels[current_level].setCharacterSpawn(player);
		player.respawn();
	}
	if (Collision::PixelPerfectTest(levels[current_level].getLayer("foreground_bounce"), player))
	{
		player.setVelocity(sf::Vector2f(player.getVelocity().x, -2 * levels[current_level].bounce_velocity));

		if (levels[current_level].bounce_velocity < 9)
		{
			levels[current_level].bounce_velocity += 2;
		}
	}
	else {
		if (player.getVelocity().y == 0 && levels[current_level].bounce_velocity > 1)
		{
			levels[current_level].bounce_velocity--;
		}
	}
}