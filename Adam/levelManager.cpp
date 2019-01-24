#include "pch.h"
#include "levelManager.h"
#include "Collision.h"

levelManager::levelManager()
{
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
		}
	}
	print();
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
	tex.loadFromFile(lvls[lvl_name]["foreground"]);
	tex2.loadFromFile(lvls[lvl_name]["background"]);
	tex3.loadFromFile(lvls[lvl_name]["foreground_dmg"]);
	tex4.loadFromFile(lvls[lvl_name]["foreground_bounce"]);
	tex5.loadFromFile(lvls[lvl_name]["lvl_end"]);
	/*Collision::CreateTextureAndBitmask(tex, lvls[lvl_name]["foreground"]);
	Collision::CreateTextureAndBitmask(tex2, lvls[lvl_name]["background"]);
	Collision::CreateTextureAndBitmask(tex3, lvls[lvl_name]["foreground_dmg"]);
	Collision::CreateTextureAndBitmask(tex4, lvls[lvl_name]["foreground_bounce"]);
	Collision::CreateTextureAndBitmask(tex5, lvls[lvl_name]["lvl_end"]);*/

	ground.setTexture(tex);
	background.setTexture(tex2);
	damage_background.setTexture(tex3);
	foreground_bounce.setTexture(tex4);
	end.setTexture(tex5);
}

void levelManager::next_lvl(Character & player)
{
	
	make_lvl("lvl2");
	player.respawn();
}

levelManager::~levelManager()
{
}
