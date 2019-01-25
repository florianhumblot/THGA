#pragma once
#include "pch.h"
#include "Animation.h"
class Animateable {
protected:
	std::map<std::string, Animation> animations;
public:
	Animation currentAnimation;
	int animation_interval = 0;
	sf::Clock timer;

	void setAnimation(std::string animation, int interval);
	void setAnimationMap(std::map<std::string, Animation> newAnimations);

	Animateable() {}
	~Animateable() {}
	Animateable(std::map<std::string, Animation> & animations);
	
	Animation getAnimation(std::string animation);
	std::string getCurrentAnimation();
	bool updateAnimation();
	bool currentAnimationIsDone() { return currentAnimation.isDone(); }
};

