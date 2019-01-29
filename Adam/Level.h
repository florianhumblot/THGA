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
	sf::Vector2f player_spawn_point = {};
	std::unordered_map<std::string, std::pair<sf::Sprite, sf::Texture>> sprites;
	std::string next_level_name;
public:
	int bounce_velocity = 1;
	
	explicit Level(std::shared_ptr<AnimationManager>);
	Level() {};
	~Level();
	void draw(sf::RenderTarget &w);
	void addSprite(const std::string & name, const std::string & location);
	void enemy_factory(std::string s);
	void npc_factory(std::string s);
	sf::Sprite & getLayer(const std::string & name);
	void setCharacterSpawn(Character & player);
	void set_player_spawn_point(sf::Vector2f & spawn_point);
	void set_next_level(const std::string & next_level_name);
	std::string get_next_level();
	std::vector<npc> & getNPCs();
	std::vector<Enemy> & getEnemies();
};

