#include "pch.h"
#include "Animation.h"
#include <iostream>
Animation::~Animation()
{
}

void Animation::addFrame(const std::string & location)
{
	textures.emplace_back(sf::Texture());
	textures.back().setSmooth(true);
	Collision::CreateTextureAndBitmask(textures.back(), location);
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
	if (animation_done && name == "DYINGright") {
		return textures.back();
	}
	return textures[++current_frame];
}

sf::Texture & Animation::getCurrentFrame()
{
	if (current_frame == textures.size()) {
		return textures.back();
	}
	else {
		return textures[(current_frame == -1 ) ? 0 : current_frame];
	}
}


void Animation::reset_animation()
{
	animation_done = false;
	current_frame = -1;
}
void Animation::print() {
	std::cout << name << " ";
}

bool Animation::operator==(Animation &rhs) {
	return this->name == rhs.name;
}

bool Animation::operator!=(Animation &rhs) {
	return this->name != rhs.name;
}

bool Animation::operator!=(Animation rhs) {
	return this->name != rhs.name;
}