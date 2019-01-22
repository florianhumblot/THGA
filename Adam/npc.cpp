#include "pch.h"
#include "npc.hpp"


npc::npc(sf::Vector2f position, sf::Vector2f scale, const std::string & textureFile, sf::Vector2f velocity,  statistic health_c ):
	movable(position, scale, textureFile, velocity),
	Animateable(std::map<std::string, Animation> { {"IDLEright", Animation()}}),
	originPosition(position)
{
	animations["IDLEright"].addFrame(textureFile);
	health = health_c;
}

npc::npc(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, statistic health_c) :
	Animateable(animations),
	movable(position, scale, animations["IDLEright"].textures[0], velocity),
	originPosition(position)
{
	health = health_c;
}


npc::~npc()
{
}

void npc::updateState() {
	int chance = rand();
	if (chance % 1000 < 5) {
		if (state == STATE::IDLE) {
			state = STATE::WALKINGLEFT;
		} else if (state == STATE::WALKINGLEFT || state == STATE::WALKINGLEFT) {
			state = STATE::IDLE;
		}
	}
}

bool npc::isWalking() {
	return state != STATE::IDLE;
}

void npc::walkTheOtherWay() {
	if (state == STATE::WALKINGLEFT) {
		state = STATE::WALKINGRIGHT;
	}
	else if (state == STATE::WALKINGRIGHT) {
		state = STATE::WALKINGLEFT;
	}
}

int npc::getDirection() {
	if (state == STATE::WALKINGLEFT) {
		return -1;
	} else if (state == STATE::WALKINGRIGHT) {
		return 1;
	}
	return 0;
}