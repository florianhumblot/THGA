#pragma once
// ==========================================================================
//
// File      : AnimationManager.h
//
// ==========================================================================

// this file contains Doxygen lines
///file AnimationManager.hpp
/// \brief Factory for animations
/// \detail
/// This class serves as a factory and container for all animations of the game project.
#include "Animation.h"
class AnimationManager
{
public:
	/// \brief container of animations
	/// \detail
	/// You can access the animation map by first using the name of the object (such as "Knight" or "Projectile")
	/// And then by using the action (such as "IDLEright" or "HURTright")
	/// i.e.: animations["mage"]["IDLEright"] which will return the actual idle animation for the mage object
	/// or i.e.: animations["mage"] which will return the map of all animation for that object.
	std::map<std::string, std::map<std::string, Animation>> animations;
	/// \brief Factory constructor
	/// \detail
	/// Gets the path to a text file as inout (s) and will then use the factory pattern to construct the map of animations.
	AnimationManager(const std::string & s);
	/// \brief default constructor - doesn't do anything.
	AnimationManager() {}
	/// \brief prints the animation object's name, the animation name and the amount of frames for that animation (debugging)
	void print();
	/// \brief default destructor - doesn't do anything.
	~AnimationManager();
};