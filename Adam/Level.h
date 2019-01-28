#pragma once
#include "pch.h"
#include "vector"
#include "Enemy.hpp"
#include "npc.hpp"

class Level
{
private:
	std::string name;
	std::vector<Enemy> ennemies;
	std::vector<npc> npcs;
	int level;
	int bounce_velocity = 1;
	sf::Vector2f player_spawn_point = {};
	std::map<std::string, std::pair<sf::Sprite, sf::Texture>> sprites;
public:
	Level();
	~Level();
	void draw(sf::RenderTarget &w);
	void addSprite(const std::string & name, const std::string & location);


	

};

