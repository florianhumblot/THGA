#include "Animated.hpp"

Animateable::Animateable(std::map<std::string, Animation> animations):
	animations(animations)
{
	currentAnimation = animations.begin()->second;
}

Animation Animateable::getAnimation(std::string animation) {
	return animations[animation];
}

Animation Animateable::getCurrentAnimation() {
	return currentAnimation;
}

void Animateable::setAnimation(std::string animation) {
	currentAnimation = animations[animation];
}