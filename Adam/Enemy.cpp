#include "pch.h"
#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> & animations, sf::Vector2f velocity, statistic health_c):
	fighter(health_c, 1),
	Animateable(animations),
	movable(position, scale, animations["IDLEright"].textures[0], velocity)
{
	health = health_c;
	texture = animations["IDLEright"].textures[0];
	setAnimation("IDLEright", Animation::intervals::idle);
	if (!font.loadFromFile("fonts/stranger.ttf"))
	{
		std::cout << "error loading font" << std::endl;
	}
	update_info();

	for (auto & tex: text)
	{
		tex = sf::Text();
		tex.setFont(font);
		tex.setOutlineColor(sf::Color::Black);
		tex.setOutlineThickness(2.0f);
		tex.setScale(sf::Vector2f(0.1, 0.1));
		tex.setCharacterSize(100);
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
	
	if (getCurrentAnimation() == std::string("SLASHINGright")) return false;

	if (!checkDead()) {
		if (fighter::fight(opponent)) {
			if (getCurrentAnimation() != std::string("SLASHINGright")) {
				setAnimation("SLASHINGright", Animation::intervals::attack);
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

sf::Sprite Enemy::makeFightBox() {
	auto temp = sf::Sprite();
	temp.setPosition(position);
	temp.setTexture(AABB_H);
	temp.setScale(scale);
	return temp;
}

sf::Sprite Enemy::getBox() {
	if (state != STATE::DEAD) {
		return drawable::getBox();
	}
	else {
		return sf::Sprite();
	}
		
}

void Enemy::setVelocity(sf::Vector2f newVel) {
	if (state != STATE::DEAD) {
		movable::setVelocity(newVel);
	}
	else {
		movable::setVelocity(sf::Vector2f(0,0));
	}
}


void Enemy::die()
{
	state = STATE::DEAD;
	if (getCurrentAnimation() != std::string("DYINGright")) {
		setAnimation("DYINGright", Animation::intervals::dying);
		setTexture(currentAnimation.nextFrame());
	}
	else {
		if (currentAnimationIsDone()) {
			setTexture(currentAnimation.textures.back());
		}
	}
	health.zero();
	update_info();
	sound.playSoundTwo("monsterDeath", 60);
}

void Enemy::draw(sf::RenderTarget &w) {
	drawable::draw(w);
	int j = -2;
	for (auto & txt: text) {
		txt.setPosition(sf::Vector2f(getPosition().x, getPosition().y + j * 10));
		txt.setFont(font);
		w.draw(txt);
		j++;
	}
}

sf::Sprite Enemy::getHitbox()
{
	return drawable::getHitbox();
}

