#pragma once
#include "Collision.h"
class Animation
{
private:
	bool animation_done;
	int current_frame;
public:
	std::string name = "default";
	std::vector<sf::Texture> textures;
	Animation() :animation_done(false), current_frame(0), textures()  {};
	Animation(std::string name) :name(name), animation_done(false), current_frame(0), textures() {};
	~Animation();
	void addFrame(const std::string & location);
	void addFrame(sf::Texture & texture);
	sf::Texture & nextFrame();
	void reset_animation();
	bool isDone() { return animation_done; }
	void print();
	bool operator==(Animation & rhs);
	bool operator!=(Animation & rhs);
	bool operator!=(Animation rhs);
};

