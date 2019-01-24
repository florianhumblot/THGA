#include "pch.h"
#include "levelManager.h"
#include "Collision.h"
#include "algorithm"

levelManager::levelManager()
{
	std::string prev = "";
	std::string line;
	std::ifstream lvls_file("assets/backgrounds/lvls.txt");
	if (lvls_file.is_open())
	{
		std::string item, name, lvl = "";
		int count = 0;
		while (lvls_file >> lvl >> name >> item)
		{
			if (name == "background")
			{
				lvls[lvl]["background"] = item;
			}
			else if (name == "foreground")
			{
				lvls[lvl]["foreground"] = item;
			}
			else if (name == "foreground_dmg")
			{
				lvls[lvl]["foreground_dmg"] = item;
			}
			else if (name == "foreground_bounce")
			{
				lvls[lvl]["foreground_bounce"] = item;
			}
			else if (name == "lvl_end")
			{
				lvls[lvl]["lvl_end"] = item;
			}
			else if (name == "spawnpoint_player")
			{
				lvls[lvl]["spawnpoint_player"] = item;
			}
			else if (name == "spawnpoint_enemy")
			{
				spawnpoints_enemys[lvl][count++] = item;
			}
			if (prev != lvl)
			{
				prev = lvl;
				maps.push_back(lvl);
			}
			
		}
	}
	//print();
	
}

void levelManager::print()
{
	for (auto & lvl : lvls)
	{
		std::cout << lvl.first << ":\n";
		for (auto & info : lvl.second)
		{
			std::cout << info.first << " = " << info.second << '\n';
		}

		for (auto & s : spawnpoints_enemys)
		{
			std::cout << s.first << " enemys spawnpoints: \n";
			for (auto & in : s.second)
			{
				std::cout << in.first << " = " << in.second << '\n';
			}
		}

	}

}

void levelManager::make_lvl(std::string lvl_name)
{
	Collision::removeBitmask(&tex);
	Collision::removeBitmask(&tex3);
	Collision::removeBitmask(&tex4);
	Collision::removeBitmask(&tex5);
	tex.loadFromFile(lvls[lvl_name]["foreground"]);
	tex2.loadFromFile(lvls[lvl_name]["background"]);
	tex3.loadFromFile(lvls[lvl_name]["foreground_dmg"]);
	tex4.loadFromFile(lvls[lvl_name]["foreground_bounce"]);
	tex5.loadFromFile(lvls[lvl_name]["lvl_end"]);

	ground.setTexture(tex);
	background.setTexture(tex2);
	damage_background.setTexture(tex3);
	foreground_bounce.setTexture(tex4);
	end.setTexture(tex5);
	bool seen = false;
	for (char & c : lvls[lvl_name]["spawnpoint_player"])
	{
		if (c != ',')
		{
			if (seen)
			{
				playerSpawn.y += c;
			}
			else
			{
				playerSpawn.x += c;
			}
		}
		
	}
}

void levelManager::next_lvl(Character & player)
{

	make_lvl(maps[current_lvl]);
	player.respawn();
	current_lvl--;
	if (current_lvl <0)
	{
		current_lvl = maps.size()+1;
	}

}

void levelManager::check_interaction(Character & player)
{
	if (Collision::PixelPerfectTest(damage_background, player))
	{
		player.health.sub(1);

	}

	if (Collision::PixelPerfectTest(end, player))
	{
		next_lvl(player);

	}
	if (Collision::PixelPerfectTest(foreground_bounce, player))
	{
		player.setVelocity(sf::Vector2f(player.getVelocity().x, -2 * bounce_velocity));

		if (bounce_velocity < 9)
		{
			bounce_velocity += 2;
		}
	}
	else {
		if (player.getVelocity().y == 0 && bounce_velocity > 1)
		{
			bounce_velocity--;
		}
	}
}

levelManager::~levelManager()
{
}
