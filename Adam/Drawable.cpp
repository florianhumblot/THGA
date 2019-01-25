#include "pch.h"
#include "Drawable.h"

drawable::drawable(sf::Vector2f &position, sf::Vector2f scale, sf::Texture texture):
	position(position),
	scale(scale),
	texture(texture)
{
	sprite.setPosition(position);
	sprite.setTexture(texture);
	sprite.setScale(scale);
	AABB.loadFromFile("assets/AABB.png");
}

drawable::drawable(sf::Vector2f &position, sf::Vector2f scale, const std::string &textureFile) :
	position(position),
	scale(scale)
	//texture(texture)
{
	Collision::CreateTextureAndBitmask(texture, textureFile);
	sprite.setPosition(position);
	sprite.setTexture(texture);
	sprite.setScale(scale);
	AABB.loadFromFile("assets/AABB.png");
}

sf::Vector2f drawable::getPosition() {
	return position;
}

void drawable::setPosition(sf::Vector2f newPos) {
	position = newPos;
	sprite.setPosition(position);
}

void drawable::setTexture(const std::string & textureFile) {
	Collision::CreateTextureAndBitmask(texture, textureFile);
	sprite.setTexture(texture);
}

void drawable::setTexture(sf::Texture & texture) {
	sprite.setTexture(texture);
	texture = texture;
}

void drawable::draw(sf::RenderTarget &w) {
	w.draw(sprite);
}

