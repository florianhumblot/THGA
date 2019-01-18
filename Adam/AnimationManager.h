#pragma once
#include "Animation.h"
class AnimationManager
{
public:
	std::map<std::string, std::map<std::string, Animation>> animations;
	AnimationManager(const std::string & s);
	void print();
	~AnimationManager();
};