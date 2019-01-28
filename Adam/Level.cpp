#include "pch.h"
#include "Level.h"


Level::Level(std::shared_ptr<AnimationManager>) : ani(ani)
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

	Collision::CreateTextureAndBitmask(sprites[name].second, location);
	sprites[name].second.setSmooth(true);
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
			enemies.push_back(Enemy(sf::Vector2f(stoi(posx),stoi(posy)), sf::Vector2f(0.2, 0.2), ani->animations[png], sf::Vector2f(0, 0), statistic(std::stoi(health), std::stoi(health))));
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
			npcs.push_back(npc(sf::Vector2f(stoi(posx), stoi(posy)), sf::Vector2f(0.2, 0.2), ani->animations[png], sf::Vector2f(0, 0), statistic(200, 200)));
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

void Level::check_interaction(Character & player) {
	if (Collision::PixelPerfectTest(sprites["foreground_dmg"].first, player))
	{
		player.health.sub(((float)(player.health.max / 100) * 0.5f));

	}

	if (Collision::PixelPerfectTest(sprites["inifinity"].first, player))
	{
		player.respawn();

	}

	if (Collision::PixelPerfectTest(sprites["lvl_end"].first, player))
	{
		next_lvl(player);
	}
	if (Collision::PixelPerfectTest(sprites["foreground_bounce"].first, player))
	{
		player.setVelocity(sf::Vector2f(player.getVelocity().x, -2 * bounce_velocity));

		if (bounce_velocity < 9)
		{
			bounce_velocity += 2;
		}
	}
	else {
		if (player.getVelocity().y == 0 && bounce_velocity > 1)
		{
			bounce_velocity--;
		}
	}
}