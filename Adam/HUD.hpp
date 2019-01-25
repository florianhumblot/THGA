#ifndef HUD_HPP
#define HUD_HPP

#include "Character.h"
///@file

/// \brief
/// HUD
/// \details
/// The HUD shows the status of the player: health, mana, experience, lvl.
class HUD
{
private:
	sf::Font font;
	sf::Texture bar;
	sf::Text text[4];
	sf::Texture texture_bar[4];
	sf::Sprite sprite_bar[4];
	std::string bar_location[4] = { "assets/Health.png","assets/Mana.png","assets/exp.png","assets/lvl.png" };
	Character & character;
	int bar_length[4] = {100,100,100,60};
public:

	/// \brief
	/// constructor
	/// \details
	/// The constructor initialize a Character(player).
	/// The standard values of the character are set.
	HUD(Character & character);

	/// \brief
	/// updates HUD info
	/// \details
	/// Updates the current & max value of each stat on the HUD.
	/// Calls bar_satus function for each stat on the HUD.
	void update();

	/// \brief
	/// bar length
	/// \details
	/// Sets the scale, texture and position of the bar of a stat based on the max & current value.
	void bar_status(int index);

	/// \brief
	/// show info on HUD
	/// \details
	/// Draws for each stat the text & bar.
	void draw(sf::RenderWindow & window);
};
#endif // !HUD_HPP

