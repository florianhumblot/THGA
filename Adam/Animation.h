#pragma once
// ==========================================================================
//
// File      : Animation.h
//
// ==========================================================================

// this file contains Doxygen lines
///file Animation.h
/// \brief Animation object - contains an animation
/// \detail
/// This class is a container for an animation consisting of multiple frames stored as textures in a vector.
#include "Collision.h"
class Animation
{
private:
	/// \brief Stores whether this animation is over or not - aka if all frames have been used.
	bool animation_done;
	/// \brief Stores the index of the current animation frame we need to return when prompted to.
	int current_frame;
public:
	/// \brief Milisecond interval possibilities between frames for an animation.
	enum intervals
	{
		idle = 50,
		walk = 10,
		attack = 50,
		dying = 50,
	};

	/// \brief the name of the animation
	std::string name = "default";
	/// \brief the textures or frames of the animation
	std::vector<sf::Texture> textures;
	/// \brief Default constructor, creates an empty animation without name.
	Animation() :animation_done(false), current_frame(0), textures()  {};
	/// \brief Constructor which takes a name and creates an empty animation
	Animation(std::string name) :name(name), animation_done(false), current_frame(0), textures() {};
	/// \brief default destructor
	~Animation();
	/// \brief Adds a frame by loading a texture from the disk at the specified path
	/// \detail
	/// This is the quickest addFrame variant.
	void addFrame(const std::string & location);
	/// \brief Adds a frame to an animation.
	void addFrame(sf::Texture & texture);
	/// \brief return the next frame of the animation by reference.
	/// \detail
	/// increments the index of the animation and returns the frame stored at that new index.
	/// if the animation is over (the end of the vector is reached) this will set a flag signaling that the animation is done, but will wrap around to the start of the vector and continure functioning for animation loops.
	sf::Texture & nextFrame();
	/// \brief returns the current frame of the animation.
	sf::Texture & getCurrentFrame();
	/// \brief resets the animation to it's starting point.
	/// \detail
	/// Sets the done flag to false and resets the index to the start of the vector.
	void reset_animation();

	/// \brief Returns whether or not the animation is done - aka all frames have been used.
	bool isDone() { return animation_done; }

	/// \brief prints the name of the animation
	void print();

	/// \brief checks for equality between Animations by their name.
	bool operator==(Animation & rhs);
	/// \brief checks for inequality between Animations by their name.
	bool operator!=(Animation & rhs);
	/// \brief checks for inequality between Animations by their name.
	bool operator!=(Animation rhs);
};

