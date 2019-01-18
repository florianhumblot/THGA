#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <tuple>
#include "Animation.h"
#include "fstream"
#include <iostream>
class AnimationManager
{
public:
	std::map<std::string, std::map<std::string, Animation>> animations;
	AnimationManager(const std::string & s);
	AnimationManager() {}
	void print();
	~AnimationManager();
};