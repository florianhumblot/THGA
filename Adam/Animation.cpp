#include "Animation.h"

Animation::~Animation()
{
}

void Animation::addFrame(const std::string & location)
{
	sf::Texture t;
	Collision::CreateTextureAndBitmask(t, location);
	textures.emplace_back(t);
}

void Animation::addFrame(sf::Texture & texture)
{
	textures.emplace_back(texture);
}

sf::Texture & Animation::nextFrame()
{
	if (current_frame == textures.size() -1) {
		current_frame = -1;
		animation_done = true;
	}
	return textures[++current_frame];
}

void Animation::reset_animation()
{
	animation_done = false;
	current_frame = -1;
}
