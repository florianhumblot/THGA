#include "pch.h"
#include "Animated.hpp"

Animateable::Animateable(std::map<std::string, Animation> & animations):
	animations(animations)
{
	currentAnimation = animations.begin()->second;
}

Animation Animateable::getAnimation(std::string animation) {
	return animations[animation];
}

std::string Animateable::getCurrentAnimation() {
	return currentAnimation.name;
}

void Animateable::setAnimation(std::string animation) {
	currentAnimation = animations[animation];
}

void Animateable::setAnimationMap(std::map<std::string, Animation> newAnimations)
{
	animations = newAnimations;
}
