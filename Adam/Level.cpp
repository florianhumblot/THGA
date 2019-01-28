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
	w.draw(sprites["background"].first);
	w.draw(sprites["foreground"].first);
	w.draw(sprites["foreground_dmg"].first);
	w.draw(sprites["foreground_bounce"].first);
	w.draw(sprites["lvl_end"].first);
	w.draw(sprites["infinity"].first);
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
void Level::setCharacterSpawn(Character & player)
{
	player.set_spawn(player_spawn_point);
	player.respawn();
}

void Level::set_player_spawn_point(sf::Vector2f & spawn_point)
{
	player_spawn_point = spawn_point;
}
