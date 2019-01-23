#include "pch.h"
#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> & animations, sf::Vector2f velocity, statistic health_c):
	fighter(position, scale, animations["IDLEright"].textures[0], velocity, health_c, 1),
	Animateable(animations)
{
	health = health_c;
	texture = animations["IDLEright"].textures[0];
	setAnimation("IDLEright");
	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		std::cout << "error loading font" << std::endl;
	}
	update_info();

	for (int i = 0; i < 2; i++)
	{
		text[i].setFont(font);
		text[i].setOutlineColor(sf::Color::Black);
		text[i].setOutlineThickness(2.0f);
		text[i].setScale(sf::Vector2f(0.1, 0.1));
		text[i].setCharacterSize(100);
	}
	text[0].setFillColor(sf::Color::Red);
	text[1].setFillColor(sf::Color::White);
}


Enemy::~Enemy()
{
}

void Enemy::update_info()
{
	text[0].setString(std::to_string(health.current) + "/" + std::to_string(health.max) + '\n');
	text[1].setString("  lvl: " + std::to_string(lvl));
}

void Enemy::update_info_pos(sf::RenderWindow & window)
{
	text[0].setPosition(sf::Vector2f(position.x, position.y - 30));
	text[1].setPosition(sf::Vector2f(position.x, position.y - 30 + 12));
}

bool Enemy::fight(fighter * opponent) {
	
	if (!checkDead()) {
		if (fighter::fight(opponent)) {
			if (getCurrentAnimation() != std::string("SLASHINGright")) {
				setAnimation("SLASHINGright");
				std::cout << getCurrentAnimation() << std::endl;
				setTexture(currentAnimation.nextFrame());

			}
			if (fighter::checkDead()) {
				setPosition(sf::Vector2f(890, 690));
				health.current = health.max;
			}
			return true;
		}
	}
	return false;
}


void Enemy::updateFollowPosition(int x) {
	if (!checkDead()) {
		// make the enemy move (x is 0, 1, or -1)
		setVelocity(sf::Vector2f(4 * x, getVelocity().y));
	}
}

void Enemy::die()
{
	if (getCurrentAnimation() != std::string("DYINGright")) {
		setAnimation("DYINGright");
		setTexture(currentAnimation.nextFrame());
	}
	else {
		if (currentAnimationIsDone()) {
			setTexture(currentAnimation.textures.back());
		}
	}
}

void Enemy::draw(sf::RenderTarget &w) {
	drawable::draw(w);
	int j = -2;
	for (auto & txt: text) {
		txt.setPosition(sf::Vector2f(getPosition().x, getPosition().y + j * 10));
		w.draw(txt);
		j++;
	}
}

