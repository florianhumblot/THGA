#include "pch.h"
#include "Level.h"


Level::Level()
{
}



Level::~Level()
{
}

void Level::draw(sf::RenderTarget & w)
{
}

void Level::addSprite(const std::string & name, const std::string & location)
{
	std::cout << "Loading sprite: " << name << " at: " << location << std::endl;
	auto pos = sprites.find(name);
	if (pos == sprites.end()) {
		sprites[name] = std::make_pair(sf::Sprite(), sf::Texture());
	}
	sprites[name].second.loadFromFile(location);
	sprites[name].first.setTexture(sprites[name].second);
}

void Level::enemy_factory(std::string s)
{
	std::ifstream lvls_file(s);
	if (lvls_file.is_open())
	{
		std::string png, health, posx , posy = "";

		while (lvls_file >> png >> posx >> posy >> health)
		{
			enemies.push_back(Enemy(sf::Vector2f(stoi(posx),stoi(posy)), sf::Vector2f(0.2, 0.2), ani.animations[png], sf::Vector2f(0, 0), statistic(std::stoi(health), std::stoi(health))));
		}

	}
}

void Level::npc_factory(std::string s)
{
	std::ifstream lvls_file(s);
	if (lvls_file.is_open())
	{
		std::string png, posx, posy = "";

		while (lvls_file >> png >> posx >> posy)
		{
			npcs.push_back(npc(sf::Vector2f(stoi(posx), stoi(posy)), sf::Vector2f(0.2, 0.2), ani.animations[png], sf::Vector2f(0, 0), statistic(200, 200)));
		}

	}
}