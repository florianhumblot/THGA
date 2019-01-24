#pragma once

#include "Character.h"

class levelManager
{
private:
	std::vector<std::string> maps = {};
	int current_lvl = maps.size()+1;
	int bounce_velocity = 1;
	sf::Texture tex;
	sf::Texture tex2;
	sf::Texture tex3;
	sf::Texture tex4;
	sf::Texture tex5;
public:
	sf::Vector2f playerSpawn = {};
	sf::Sprite background;
	sf::Sprite damage_background;
	sf::Sprite ground;
	sf::Sprite foreground_bounce;
	sf::Sprite end;

	std::map<std::string, std::map<int, std::string> > spawnpoints_enemys;

	std::map<std::string, std::map<std::string, std::string> > lvls;
	levelManager();
	void print();
	void make_lvl(std::string lvl_name);
	void next_lvl(Character & player);
	void check_interaction(Character & player);
	~levelManager();
};

