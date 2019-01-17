#ifndef  _ENEMY_HPP
#define _ENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "statistic.h"
#include "Movable.h"

class Enemy : public movable
{

	sf::Font font;
	sf::Text text[4];
	std::string t[4];
public:
	int lvl = 1;
	statistic health;

	enum class direction { LEFT, RIGHT };
	direction current_direction = direction::RIGHT;
	void update_info();
	void update_info_pos(sf::RenderWindow & windwo, sf::Vector2f character_pos);
	Enemy() {}
	Enemy(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity, statistic health_c = statistic(100, 100));

	~Enemy();
	//	operator sf::Sprite() { return sprite; }
};

#endif

