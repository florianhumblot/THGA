#include "pch.h"
#include "Level.h"
#include <vector>
#include <string>


Level::Level(std::shared_ptr<AnimationManager> ani) : ani(ani)
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
	//sprites[name].second.setSmooth(true);
	Collision::CreateTextureAndBitmask(sprites[name].second, location);
	sprites[name].first.setTexture(sprites[name].second);

}

void Level::enemy_factory(std::string s)
{
	std::ifstream lvls_file(s);
	if (lvls_file.is_open())
	{
		std::string png, health, posx, posy = "";

		while (lvls_file >> png >> posx >> posy >> health)
		{
			enemies.push_back(Enemy(sf::Vector2f(stoi(posx), stoi(posy)), sf::Vector2f(0.2, 0.2), ani->animations[png], sf::Vector2f(0, 0), statistic(std::stoi(health), std::stoi(health))));
			enemies.back().setAnimation("IDLEright", Animation::intervals::idle);
			enemies.back().setTexture(enemies.back().currentAnimation.getCurrentFrame());
		}

	}
}

bool getVectorString(std::ifstream & input, std::vector<std::string> & npc_text) {
	char c;
	std::string tempString = "";
	if (!(input >> c)) {
		return false;
	}
	if (c != '{') {
		std::cout << "-------------------------" << c << "\n";
		return false;
	}
	while (c != '}') {
		while ((input >> c) && (c != ',' && c != '}') ){
			if (c == '#') {
				tempString += " ";
			}
			else {
				tempString += c;
			}
		}
		std::cout << "--------------------------------------" << tempString << "\n";
		
		npc_text.push_back(tempString);
		tempString = "";
	}
	return true;
}



void Level::npc_factory(std::string s)
{
	std::ifstream lvls_file(s);
	if (lvls_file.is_open())
	{
		std::string png, posx, posy = "";
		std::vector<std::string> npc_text = {};
		while (lvls_file >> png >> posx >> posy && getVectorString(lvls_file, npc_text))
		{
			npcs.push_back(npc(sf::Vector2f(stoi(posx), stoi(posy)), sf::Vector2f(0.2, 0.2), ani->animations[png], sf::Vector2f(0, 0), npc_text, statistic(200, 200)));
			npcs.back().setAnimation("IDLEright", Animation::intervals::idle);
			npcs.back().setTexture(npcs.back().currentAnimation.getCurrentFrame());
			npc_text.clear();
		}

	}
}
sf::Sprite & Level::getLayer(const std::string & name)
{
	return sprites[name].first;
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

void Level::set_next_level(const std::string & next_level)
{
	next_level_name = next_level;
}

std::string Level::get_next_level()
{
	return next_level_name;
}

std::vector<npc> & Level::getNPCs()
{
	return npcs;
}

std::vector<Enemy> & Level::getEnemies()
{
	return enemies;
}



