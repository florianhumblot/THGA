#pragma once
#include "projectile.hpp"

class shooter
{
protected:
	std::function<std::shared_ptr<projectile>(sf::Vector2f, sf::Vector2f, std::map<std::string, Animation> a)> shoot = [&](sf::Vector2f pos1, sf::Vector2f pos2, std::map<std::string, Animation> animations) {return std::make_shared<projectile>(projectile());};
	int size = 1;
	std::map<std::string, Animation> projectileAnimations;
public:
	std::vector<std::shared_ptr<projectile>> projectiles;

	/// \brief
	/// default constructor
	shooter();

	/// \brief
	/// constructs a shooter
	/// \details
	/// takes an size for the shared_ptr vector and animations for the projectile
	shooter(int &size, std::map<std::string, Animation> & projectileAnimations);

	/// \brief
	/// shoots a projectile
	/// \details
	/// actualy checks if there is an projectile that is death and revives it at the position, direction and angle of the player
	void shootProjectile(sf::Vector2f pos, sf::Vector2f direction, float angle);

	/// \brief
	/// sets a new projectile construct function
	/// \details
	/// it sets a new construction lambda in a very wierd way
	/// it creates a new projectile for every projectile in the vector
	void setProjectile(std::function<std::shared_ptr<projectile>(sf::Vector2f, sf::Vector2f, std::map<std::string, Animation>)> newS, std::map<std::string, Animation> & animations);

	/// \brief
	/// sets a new veloDeco
	/// \details
	/// sets a new veloDeco lambda for every projectile in the vector
	void setVeloDeco(std::function<void(sf::Vector2f&)> NveloDeco);

	/// \brief
	/// sets a new movDeco
	/// \details
	/// sets a new movDeco lambda for every projectile in the vector
	void setMovDeco(std::function<void(sf::Vector2f&)> NmovDeco);

	~shooter();
};

