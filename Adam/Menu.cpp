#include "pch.h"
#include "Menu.hpp"

void Menu::draw(sf::RenderWindow & window, LvlManager & lvls, std::shared_ptr<Enemy> & enemy, sf::View & main_camera, sf::Sprite & bgMain, Character & player) {
	if (menu_states == menu_states::INGAME) {
		draw(window, lvls, enemy);
	}
	else {
		draw(window, main_camera, bgMain, player);
	}
}