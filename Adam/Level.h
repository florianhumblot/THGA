#pragma once
#include "pch.h"
#include "vector"
#include "Enemy.hpp"
#include "npc.hpp"
#include "AnimationManager.h"

class Level
{
private:
	std::shared_ptr<AnimationManager> ani;
	std::string name;
	std::vector<Enemy> enemies;
	std::vector<npc> npcs;
	int level;
	int bounce_velocity = 1;
	sf::Vector2f player_spawn_point = {};
	std::map<std::string, std::pair<sf::Sprite, sf::Texture>> sprites;
public:
	explicit Level(std::shared_ptr<AnimationManager>);
	Level() {};
	~Level();
	void draw(sf::RenderTarget &w);
	void addSprite(const std::string & name, const std::string & location);
	void enemy_factory(std::string s);
	void npc_factory(std::string s);
	
	void setCharacterSpawn(Character & player);
	void set_player_spawn_point(sf::Vector2f & spawn_point);

};

