#pragma once
#include "pch.h"
#include "Animation.h"
#include <iostream>
class Animateable {
protected:
	std::map<std::string, Animation> animations;
	//Animation currentAnimation;
public:
	Animation currentAnimation;
	Animateable(std::map<std::string, Animation> animations);
	Animateable() {}
	Animation getAnimation(std::string animation);
	std::string getCurrentAnimation();
	void setAnimation(std::string animation);
	~Animateable() {}
};

