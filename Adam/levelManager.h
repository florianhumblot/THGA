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
	int current_lvl = maps.size()+1;
	int bounce_velocity = 1;
	sf::Texture tex;
	sf::Texture tex2;
	sf::Texture tex3;
	sf::Texture tex4;
	sf::Texture tex5;
	sf::Texture tex6;
public:
	sf::Vector2f playerSpawn = {};
	sf::Sprite background;
	sf::Sprite damage_background;
	sf::Sprite ground;
	sf::Sprite foreground_bounce;
	sf::Sprite end;
	sf::Sprite infinity;
	std::map<std::string, std::map<int, std::string> > spawnpoints_enemys;
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
	void check_interaction(Character & player);
};

