#include "pch.h"
#include "levelManager.h"
#include "Collision.h"
#include "algorithm"

levelManager::levelManager()
{
	loading.loadFromFile("assets/loading.png");
	loading_screen.setTexture(loading);
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
			else if (name == "infinity")
			{
				lvls[lvl]["infinity"] = item;
			}
			else if (name == "spawnpoint_player")
			{
				lvls[lvl]["spawnpoint_player"] = item;
			}
			else if (name == "spawnpoint_enemy")
			{
				spawnpoints_enemys[lvl][count++] = to_vector(item);
			}
			else if (name == "spawnpoint_npc")
			{
				spawnpoints_npcs[lvl][count++] = to_vector(item);
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
/*
		for (auto & s : spawnpoints_enemys)
		{
			std::cout << s.first << " enemys spawnpoints: \n";
			for (auto & in : s.second)
			{
				std::cout << in.first << " = " << in.second << '\n';
			}
		}*/

	}

}

sf::Vector2f levelManager::to_vector(std::string vec) {
	bool seen = false;
	sf::Vector2f new_vec;
	std::string tmp = "";
	for (char & c : vec)
	{
		if (c != ',')
		{
			if (seen)
			{
				tmp += c;
			}
			else
			{
				tmp += c;
			}
		}
		else
		{
			seen = true;
			new_vec.x = std::stof(tmp);
			tmp = "";
		}

	}
	new_vec.y = std::stof(tmp);
	return new_vec;
}

void levelManager::make_lvl(std::string lvl_name)
{
	Collision::removeBitmask(&tex);
	Collision::removeBitmask(&tex2);
	Collision::removeBitmask(&tex3);
	Collision::removeBitmask(&tex4);
	Collision::removeBitmask(&tex5);
	Collision::removeBitmask(&tex6);
	tex.loadFromFile(lvls[lvl_name]["foreground"]);
	tex2.loadFromFile(lvls[lvl_name]["background"]);
	tex3.loadFromFile(lvls[lvl_name]["foreground_dmg"]);
	tex4.loadFromFile(lvls[lvl_name]["foreground_bounce"]);
	tex5.loadFromFile(lvls[lvl_name]["lvl_end"]);
	tex6.loadFromFile(lvls[lvl_name]["infinity"]);

	ground.setTexture(tex, 1);
	background.setTexture(tex2, 1);
	damage_background.setTexture(tex3, 1);
	foreground_bounce.setTexture(tex4, 1);
	end.setTexture(tex5, 1);
	infinity.setTexture(tex6, 1);
	for ( int i = 0; i < spawnpoints_enemys[lvl_name].size(); i++)
	{
		current_lvl_enemys.push_back(spawnpoints_enemys[lvl_name][i]);
	}

	for (int i = 0; i < spawnpoints_npcs[lvl_name].size(); i++)
	{
		current_lvl_npcs.push_back(spawnpoints_npcs[lvl_name][i]);
	}

	playerSpawn = to_vector(lvls[lvl_name]["spawnpoint_player"]);
}

void levelManager::next_lvl(Character & player)
{

	make_lvl(maps[current_lvl]);
	player.set_spawn(playerSpawn);
	player.respawn();
	current_lvl--;
	if (current_lvl < 0)
	{
		current_lvl = maps.size()-1;
	}

}

void levelManager::check_interaction(Character & player, sf::RenderWindow & window)
{
	if (Collision::PixelPerfectTest(damage_background, player))
	{
		player.health.sub(((float)(player.health.max / 100) * 0.5f));

	}

	if (Collision::PixelPerfectTest(infinity, player))
	{
		player.respawn();

	}

	if (Collision::PixelPerfectTest(end, player))
	{
		/*window.clear();
		window.setView(hud);
		window.draw(loading_screen);
		window.display();*/
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

