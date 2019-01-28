#pragma once

#include "Character.h"
///@file

/// \brief
/// levelManager
/// \details
/// Managed the info of lvls (lvl map ,spawnpoints)
class levelManager 
{
private:
	std::vector<std::string> maps = {};
	std::map<std::string, std::map<int, sf::Vector2f> > spawnpoints_enemys;
	std::map<std::string, std::map<int, sf::Vector2f> > spawnpoints_npcs;
	int current_lvl;
	int bounce_velocity = 1;
	sf::Texture foregroundTexture, backgroundTexture, dmgTexture, bounceTexture, lvlEndTexture, infinityTexture;
public:
	sf::Vector2f playerSpawn = {};
	sf::Sprite background, damage_background, ground, foreground_bounce, end, infinity;
	std::vector<sf::Vector2f> current_lvl_enemys;
	std::vector<sf::Vector2f> current_lvl_npcs;
	std::map<std::string, std::map<std::string, std::string> > lvls;

	/// \brief
	/// contructor
	/// \details
	/// Reads the lvl.txt file for all lvl attributes & puts it in a map.
	levelManager();

	/// \brief
	/// prints map
	/// \details
	/// Prints the map(attributes of each lvl).
	void print();

	/// \brief
	/// convert vector in string to vector
	/// \details
	/// Reads string & splits is on ','.
	/// returns sf::Vector2f.
	sf::Vector2f to_vector(std::string vec);

	/// \brief
	/// make new lvl
	/// \details
	/// Sets textures of next lvl.
	/// Sets new spawnpoint of player
	void make_lvl(std::string lvl_name);

	/// \brief
	/// next lvl
	/// \details
	/// Checks if there is a next lvl.
	/// Calls make_lvl function.
	/// Respawns player.
	void next_lvl(Character & player);

	/// \brief
	/// checks interaction
	/// details
	/// Checks interaction between player and certain layers of lvl.
	void check_interaction(Character & player, sf::RenderWindow & window);
};

