#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include <iostream>

class drawable {
protected:
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Texture texture;
	sf::Vector2f scale;

public:

	drawable() {}
	drawable(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile);
	~drawable() {}
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f newPos);
//	virtual void move(sf::Vector2f direction) = 0;
//	virtual void move() = 0;
	void setTexture(const std::string & textureFile);
	void setTexture(sf::Texture & texture);
	operator sf::Sprite() { 
	//	std::cout << texture.getSize().y << "\n"; 
		return sprite; 
	}

};