#pragma once
// ==========================================================================
//
// File      : Level.h
//
// ==========================================================================

// this file contains Doxygen lines
///file Level.hpp
/// \brief Container for a game level
/// \detail
/// This class serves as a container for a game level.
#include "pch.h"
#include "vector"
#include "Enemy.hpp"
#include "npc.hpp"
#include "AnimationManager.h"

class Level
{
private:
	/// \brief smart pointer to the animation manager to be able to correctly construct npc's and enemies.
	std::shared_ptr<AnimationManager> ani;
	/// \brief the name of the level
	std::string name;
	/// \brief container of the enemies of this level
	std::vector<Enemy> enemies;
	/// \brief container of the npcs of this level
	std::vector<npc> npcs;
	/// \brief 
	int level;
	/// \brief stores the spawn point for the player for this level
	sf::Vector2f player_spawn_point = {};
	/// \brief a map containing the different layers to be drawn/used for this level
	std::unordered_map<std::string, std::pair<sf::Sprite, sf::Texture>> sprites;
	/// \brief the name of the next level to be able to go there once this level is finished.
	std::string next_level_name;
public:
	/// \brief factor used for bouncing
	int bounce_velocity = 1;
	/// \brief create a level, needed to set the animation manager smart pointer
	explicit Level(std::shared_ptr<AnimationManager>);
	Level() {};
	~Level();
	/// \brief function to draw the level's layers
	void draw(sf::RenderTarget &w);
	/// \brief adds a sprite to the level's layers. 
	/// \detail
	/// Loads a sprite from disk using the location parameter and stores it in the map of sprites using the name parameter.
	void addSprite(const std::string & name, const std::string & location);
	/// \brief factory that creates the enemies of this level using the factory pattern.
	/// \detail
	/// Loads the text file located at a path (s) and initializes all the enemies and stores them in the enemies vector.
	void enemy_factory(std::string s);
	/// \brief factory that creates the npcs of this level using the factory pattern.
	/// \detail
	/// Loads the text file located at a path (s) and initializes all the npcs and stores them in the npcs vector.
	void npc_factory(std::string s);
	/// \brief get a specific sprite layer of the level by it's name.
	/// \detail
	/// In example: getLayer("background") to get the background of this level.
	sf::Sprite & getLayer(const std::string & name);
	/// \brief sets the player's spawn point
	void setCharacterSpawn(Character & player);
	/// \brief sets this level's spawn point
	void set_player_spawn_point(sf::Vector2f & spawn_point);
	/// \brief sets the next level's name
	void set_next_level(const std::string & next_level_name);
	/// \brief gets the next level's name
	std::string get_next_level();
	/// \brief returns the npc's of this level
	std::vector<npc>  getNPCs();
	/// \brief returns the enemies of this level.
	std::vector<Enemy>  getEnemies();
};

