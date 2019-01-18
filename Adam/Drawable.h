#pragma once
#include "Collision.h"

class drawable {
protected:
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Texture texture;
	sf::Vector2f scale;

public:

	drawable() {}
	drawable(sf::Vector2f &position, sf::Vector2f scale, const std::string & textureFile);
	drawable(sf::Vector2f &position, sf::Vector2f scale, sf::Texture texture);
	~drawable() {}
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f newPos);
	void setTexture(const std::string & textureFile);
	void setTexture(sf::Texture & texture);
	operator sf::Sprite() { 
	//	std::cout << texture.getSize().y << "\n"; 
		return sprite; 
	}

};