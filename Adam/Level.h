#pragma once
#include "pch.h"
#include "vector"
#include "Enemy.hpp"
#include "npc.hpp"
class invalid_position : public std::exception {
	std::string name;
public:
	explicit invalid_position(char __arg) : name(std::string("Invalid position for character found")) {}

	const char *what() const throw() override {
		return name.c_str();
	}

};
class invalid_value : public std::exception {
	std::string name;
public:
	explicit invalid_value(char __arg) : name(std::string("Invalid value entered")) {}

	const char *what() const throw() override {
		return name.c_str();
	}
}; 
class unexpected_eof_exception : public std::exception {
public:
	explicit unexpected_eof_exception(const std::string &__arg = "Unexpected end of file") {}

	const char *what() const throw() override {
		return "Unexpected end of file";
	}
};
std::ifstream &operator>>(std::ifstream &input, sf::Vector2f &rhs) {
	char c;
	if (!(input >> rhs.x)) { throw invalid_value(c); }
	if (!(input >> c)) { throw unexpected_eof_exception(); }
	if (c != ',') { throw invalid_position(c); }
	if (!(input >> rhs.y)) { throw invalid_value(c); }
	return input;
}

class Level
{
private:
	std::string name;
	std::vector<Enemy> ennemies;
	std::vector<npc> npcs;
	int level;
	int bounce_velocity = 1;
	sf::Vector2f player_spawn_point = {};
	std::map<std::string, std::tuple<sf::Sprite, sf::Texture>> sprites;
public:
	Level();
	Level(const std::string & input);
	~Level();
	void draw(sf::RenderTarget &w);
	void addSprite(const std::string & name, const std::string & location);


	

};

