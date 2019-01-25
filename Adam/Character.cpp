#include "pch.h"
#include "Character.h"

void Character::respawn()
{
	setPosition(spawn);
	health.current = health.max;
}

void Character::set_spawn(sf::Vector2f new_spawn)
{
	spawn = new_spawn;
}

Character::Character(sf::Vector2f position, sf::Vector2f scale, std::map<std::string, Animation> animations, sf::Vector2f velocity, statistic mana_c, statistic health_c, statistic exp_c):
	Animateable(animations),
	fighter(health_c, 1),
	movable(position, scale, animations["IDLEright"].textures[0], velocity)
{
	setAnimation("IDLEright", Animation::intervals::idle);
	setTexture(currentAnimation.nextFrame());
	mana = mana_c;
	exp = exp_c;
}

bool Character::fight(fighter * opponent) {
	if (getCurrentAnimation() != "SLASHINGright") {
		setAnimation("SLASHINGright", Animation::intervals::attack);
		setTexture(currentAnimation.nextFrame());
	}
	if (fighter::fight(opponent)) {

		if (fighter::checkDead()) {
			setPosition(sf::Vector2f(890, 690));
			health.current = health.max;
		}
		else if (opponent->checkDead()) {
			update_exp(40);
		}
		return true;
	}
	return false;
}

sf::Sprite Character::makeFightBox() {
	auto temp = sf::Sprite();
	temp.setPosition(position);
	temp.setTexture(AABB_H);
	temp.setScale(scale);
	return temp;
}

void Character::die()
{
	if (getCurrentAnimation() != std::string("DYINGright")) {
		setAnimation("DYINGright", Animation::intervals::dying);
		setTexture(currentAnimation.nextFrame());
	}
	else {
		if (currentAnimationIsDone()) {
			respawn();
			setAnimation("IDLEright", Animation::intervals::idle);
			setTexture(currentAnimation.nextFrame());
		}
	}
}

sf::Sprite Character::getBox() {
	return drawable::getBox();
}


Character::~Character()
{
}

void Character::update_exp(int amount)
{
	exp.add(amount);
	if (exp.is_max()) {
		lvl++;
		exp.set_max(exp.max + 20);
		exp.zero();
	}
}