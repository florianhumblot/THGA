#pragma once
#include "Collision.h"

//sf::Texture AABB.load);
//AABB.loadFromFile("assets/AABB.png")

///@file

/// \brief
/// drawable class
/// \details
/// Provides an inheritable interface for the game entities to be drawn to the game window.
/// Since the games' collision is pixel perfect overlap, we treat complex pixel shapes as boxes by using getBox().
class drawable {
protected:
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

	/// \brief
	/// constructs an drawable
	/// \details
	/// class constructor that sets the position, scale and texture.
	drawable(sf::Vector2f &position, sf::Vector2f &scale, sf::Texture &texture);

	~drawable() {}

	/// \brief
	/// returns the position
	/// \details
	/// Get current sprite position.
	sf::Vector2f getPosition();

	/// \brief
	/// set the Position
	/// \details
	/// Sets the position and moves the sprite.
	void setPosition(sf::Vector2f newPos);

	/// \brief
	/// Set a texture for the drawable
	/// \details
	/// Takes a string that represents the file path of texture image you want to load on the sprite.
	void setTexture(const std::string & textureFile);

	/// \brief 
	/// sets the Texture of the drawable
	/// \details
	/// Takes an lvalue texture and loads it on the sprite.
	void setTexture(sf::Texture & texture);

	/// \brief
	/// Draws the sprite
	/// \details
	/// Draws the sprite onto a render target (e.g sf::RenderWindow)
	void draw(sf::RenderTarget &w);

	/// \brief
	/// Returns the hitbox of the drawable
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

	/// \brief
	/// returns a drawables hitbox
	/// \details
	/// returns an sprite and applies flips it around if neded
	virtual sf::Sprite getHitbox()
	{
		auto tmp = sf::Sprite();
		tmp.setTexture(HB);
		if (sprite.getScale().x < 0) 
			tmp.setPosition(sf::Vector2f(position.x - (texture.getSize().x * sprite.getScale().x), position.y));
		else
			tmp.setPosition(position);
		tmp.setScale(sprite.getScale());
		return tmp;
	}
	/// \brief
	/// cast a drawable's sprite
	/// \details
	/// Used to cast/get the drawable's sprite.
	operator sf::Sprite() { 
		return sprite; 
	}

	/// \brief
	/// setOrigin sets the origin of a drawable
	/// \details
	/// setOrigin is used to flip an sprite
	void setOrigin(const sf::Vector2f && origin)
	{
		sprite.setOrigin(origin);
	}

	/// \brief
	/// return the size of a drawable
	/// \deatails
	/// return the size of a drawable witch is actualy the size of the texture
	sf::Vector2u getSize()
	{
		return texture.getSize();
	}

	/// \brief
	/// Rotates a drawable
	/// \details
	/// Used to rotate a drawable by rotating the sprite.
	void setRotation(float angle)
	{
		sprite.setRotation(angle);
	}

};