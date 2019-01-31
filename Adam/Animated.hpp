#pragma once
// ==========================================================================
//
// File      : Animated.hpp
//
// ==========================================================================

// this file contains Doxygen lines
///file Animated.hpp
/// \brief Animateable interfact - defines an interface for animateable objects and contains their animations which consist of textures.
/// \details
/// This class serves as an interface to objects having animations. 
/// The animations are stored in a map with a key which points to an animation


#include "pch.h"
#include "Animation.h"

class Animateable {
protected:
	/// \brief Container for the animations
	/// \detail
	/// Access the animations by their key, which is the name of the animation, in example: "WALKright" will give you the corresponding animation.
	std::shared_ptr<std::map<std::string, Animation>> animations;
public:

	/// \brief
	/// Animation states
	/// \details
	/// These are used to check animation state, not to interfere with the animation actually playing.
	enum states {
		IDLE = 1,
		WALKING,
		SLASHING,
		DEAD,
		JUMPING
	};

	/// \brief
	/// Current animation state.
	states state;

	/// \brief The current animation of the animateable object.
	/// \detail
	/// This is the animation on which the functions are being executed.
	Animation currentAnimation;
	/// \brief The interval at which the frames of the animation should change. 
	/// \detail
	/// This value can be gotten from Animation::intervals, which only holds integer values. 
	/// This field is the interval in miliseconds between two animation frames for the current animation.
	int animation_interval = 0;
	/// \brief The clock used for the interval between animation frames
	sf::Clock timer;

	/// \brief Sets the current animation to the desired animation by name and sets the interval needed for that animation (see animation_interval)
	void setAnimation(std::string animation, int interval);

	/// \brief Changes the animation map of the animateable object.
	/// \detail
	/// This will change the animation set of the child class to a new one. This is used for example for class selection since different classes have different animations.
	void setAnimationMap(std::map<std::string, Animation> &newAnimations);

	/// \brief Default constructor - doesn't do anything
	Animateable() {}
	/// \brife Default destructor - doesn't do anything
	~Animateable() {}
	/// \brief Constructor which also sets the animation map for the object instance.
	Animateable(std::map<std::string, Animation> &animations);
	
	/// \brief returns the animation within the map by name.
	Animation getAnimation(std::string animation);

	/// \brief returns a string containing the name for the current animation
	/// \detail
	/// this is used to check whether the current animation is a certain one, which is a lot less expensive than comparing two animation objects.
	std::string getCurrentAnimation();

	/// \brief Updates the animation to it's next frame
	/// \detail
	/// This function will check if the frame time of the current animation has elapsed, and if so, will update the animation to get the next frame.
	/// Returns true if the animation has a new frame, false otherwise.
	bool updateAnimation();

	/// \brief returns whether the currently playing animation is done playing, aka if all the frames have been used.
	bool currentAnimationIsDone() { return currentAnimation.isDone(); }
};

