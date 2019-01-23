#include "pch.h"
#include "npc.hpp"

npc::npc(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, statistic health_c) :
	Animateable(animations),
	movable(position, scale, animations["IDLEright"].textures[0], velocity),
	originPosition(position)
{
	health = health_c;
	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		std::cout << "error loading font" << std::endl;
	}
	text.setFont(font);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(1.0f);
	text.setScale(sf::Vector2f(0.1, 0.1));
	text.setCharacterSize(200);
}


npc::~npc()
{
}

void npc::updateState() {
	int chance = rand();
	if (chance % 1000 < 5) {
		if (state == STATE::IDLE) {
			state = STATE::WALKING;
			walkTheOtherWay();
		} else if (state == STATE::WALKING) {
			state = STATE::IDLE;
		}
	}
}

void npc::setText(std::string str) {
	text.setString(str);
}
void npc::updateText(Character &p) {
	sf::Vector2f plPos = p.getPosition();
	if (plPos.x - position.x < 50 && plPos.x - position.x > -50) {
		std::cout << "talk ";
		setText("no munnie?");
	}
	else {
		setText("");
	}
}

bool npc::isWalking() {
	return state != STATE::IDLE;
}

void npc::walkTheOtherWay() {
	if (current_direction == direction::LEFT) {
		current_direction = direction::RIGHT;
	//	std::cout << "moving the other way, right \n";
		setScale(sf::Vector2f(0.2, 0.2));

	}
	else if (current_direction == direction::LEFT) {
		current_direction = direction::RIGHT;
		setScale(sf::Vector2f(-0.2, 0.2));

	}
}

int npc::getDirection() {
	if (current_direction == direction::LEFT) {
		return -1;
	} else if (current_direction == direction::RIGHT) {
		return 1;
	}
	return 0;
}

void npc::draw(sf::RenderTarget & w) {
	drawable::draw(w);
	text.setPosition(sf::Vector2f(getPosition().x, getPosition().y - 10));
	w.draw(text);
}
