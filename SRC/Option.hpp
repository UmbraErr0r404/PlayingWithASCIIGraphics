/**
 * @file
 * @author Elizabeth Harasymiw <Elizabeth.Harasymiw@gmail.com>
 *
 * @section DESCRIPTION
 * This class holds all the data that will be needed to both display an option and
 * all the data related to what happens in game when this option is chosen
 * by the Player.
 */

#ifndef __OPTION_HPP_INCLUDED__   
#define __OPTION_HPP_INCLUDED__ 

#include <string>

class Option{
private:
	int myHealthChange;
	int myStaminaChange;
	std::string myText;
	std::string myItem;
	bool isSeletced;

public:
	/**
	 * Default construtor
	 */
	Option();

	/**
	 * Construtor that fully sets up a Option.
	 * @param HC When picked the health change effect it has on player.
	 * @param SC When picked the stamina change effect it has on player.
	 * @param item The item that would be gained from picking this Option.
	 * @param def Text that tells the player what the Option might do if picked.
	 * @param selected Wether or not this Option is currently selected.
	 */
	Option(int HC, int SC, std::string item, std::string def, bool selected);

	/**
	 * Returns the health change this option does.
	 */
	int getHealthChange() const;

	/**
	 * Returns the stamina change this option does.
	 */
	int getStaminaChange() const;

	/**
	 * Returns the item the player gets from picking this option.
	 */
	std::string getMyItem() const;

	/**
	 * Return the text that tells the player what this option might do.
	 */
	std::string getMyText() const;
};

#endif 
