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
