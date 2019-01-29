#pragma once
#include "Collision.h"

///@file

/// \brief
/// drawable class
/// \details
/// Provides an inheritable interface for the game entities to be drawn to the game window.
/// Since the games' collision is pixel perfect overlap, we treat complex pixel shapes as boxes by using getBox().
class drawable {
public:
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Texture texture;
	sf::Vector2f scale;
	
public:
	sf::Texture AABB;
	sf::Texture HB;

	/// \details
	/// default class constructor, only loads the AABB hitbox texture from disk.
	drawable() {
		AABB.loadFromFile("assets/AABB.png");
		HB.loadFromFile("assets/AABB_H.png");
	}

	/// \details
	/// class constructor that sets the position, scale and texture.
	drawable(sf::Vector2f &position, sf::Vector2f scale, sf::Texture texture);
	drawable(sf::Vector2f &position, sf::Vector2f scale, const std::string &textureFile);
	~drawable() {}

	/// \details
	/// Get current sprite position.
	sf::Vector2f getPosition();

	/// \details
	/// Sets the position and moves the sprite.
	void setPosition(sf::Vector2f newPos);

	/// \details
	/// Takes a string that represents the file path of texture image you want to load on the sprite.
	void setTexture(const std::string & textureFile);

	/// \details
	/// Takes an lvalue texture and loads it on the sprite.
	void setTexture(sf::Texture & texture);

	/// \details
	/// Draws the sprite onto a render target (e.g sf::RenderWindow)
	void draw(sf::RenderTarget &w);

	/// \details
	/// Helper function to get the "hitbox" of a drawable, the texture loaded is a fixed size rectangle,
	/// slightly smaller than the original sprite.
	virtual sf::Sprite getBox() {
		auto temp = sf::Sprite();
		temp.setPosition(position);
		temp.setTexture(AABB);
		temp.setScale(scale);
		return temp;
	}

	sf::Sprite getHitbox()
	{
		auto temp = sf::Sprite();
		temp.setTexture(HB);

		if (sprite.getScale().x < 0) temp.setPosition(sf::Vector2f(position.x - (texture.getSize().x * sprite.getScale().x), position.y));
		else temp.setPosition(position);

		temp.setScale(sprite.getScale());
		return temp;
	}

	/// \details
	/// Used to cast/get the drawable's sprite.
	operator sf::Sprite() { 
		return sprite; 
	}

	void setOrigin(const sf::Vector2f && origin)
	{
		sprite.setOrigin(origin);
	}

	sf::Vector2u getSize()
	{
		return texture.getSize();
	}

	void setRotation(float angle)
	{
		sprite.setRotation(angle);
	}

};