#include "Drawable.h"
#include <iostream>

drawable::drawable(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile) {
	position = position;
	scale = scale;
	Collision::CreateTextureAndBitmask(texture, textureFile);
	sprite.setPosition(position);
	sprite.setTexture(texture);
	sprite.setScale(scale);
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
