#include "pch.h"
#include "levelManager.h"
#include "Collision.h"

levelManager::levelManager()
{
	std::string line;
	std::ifstream lvls_file("assets/backgrounds/lvls.txt");
	if (lvls_file.is_open())
	{
		std::string name, bg, fg, fg_dmg, spawnpoint = "";
		while (lvls_file >> name >> bg >> fg >> fg_dmg >> spawnpoint)
		{
			lvls[name]["background"] = bg;
			lvls[name]["foreground"] = fg;
			lvls[name]["foreground_dmg"] = fg_dmg;
			lvls[name]["spawnpoints_p "] = spawnpoint;
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

	ground.setTexture(tex);
	background.setTexture(tex2);
	damage_background.setTexture(tex3);
}


levelManager::~levelManager()
{
}
