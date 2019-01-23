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
			//if (lvl == "lvl1")
			//{
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
				else if (name == "spawnpoint_player")
				{
					lvls[lvl]["spawnpoint_player"] = item;
				}
				else if (name == "spawnpoint_enemy")
				{
					spawnpoints_enemys[lvl][count++] = item;

				}
			//}
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
	Collision::CreateTextureAndBitmask(tex, lvls[lvl_name]["foreground"]);
	bg = sf::Sprite(tex);
	Collision::CreateTextureAndBitmask(tex2, lvls[lvl_name]["background"]);
	fg = sf::Sprite(tex2);
	Collision::CreateTextureAndBitmask(tex3, lvls[lvl_name]["foreground_dmg"]);
	fg_dmg = sf::Sprite(tex3);
	Collision::CreateTextureAndBitmask(tex4, lvls[lvl_name]["foreground_bounce"]);
	fg_bounce = sf::Sprite(tex4);

	//spawnpoint_player = sf::Vector2f(stof(lvls[lvl_name]["spawnpoint_X"]), stof(lvls[lvl_name]["spawnpoint_Y"]));

	ground.setTexture(tex);
	background.setTexture(tex2);
	damage_background.setTexture(tex3);
	foreground_bounce.setTexture(tex4);
}


levelManager::~levelManager()
{
}
