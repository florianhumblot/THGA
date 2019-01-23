#pragma once
#include "Collision.h"

class drawable {
protected:
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Texture texture;
	sf::Vector2f scale;
	
public:
	sf::Texture AABB;
	drawable() {
		AABB.loadFromFile("assets/AABB.png");
	}
	drawable(sf::Vector2f &position, sf::Vector2f scale, sf::Texture texture);
	~drawable() {}
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f newPos);
	void setTexture(const std::string & textureFile);
	void setTexture(sf::Texture & texture);
	void draw(sf::RenderTarget &w);
	sf::Sprite getBox() {
		auto temp = sf::Sprite();
		temp.setPosition(position);
		temp.setTexture(AABB);
		temp.setScale(scale);
		return temp;
	}

	operator sf::Sprite() { 
		return sprite; 
	}

};