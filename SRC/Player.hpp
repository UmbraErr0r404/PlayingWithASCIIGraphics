/**
 * @file
 * @author Elizabeth Harasymiw <Elizabeth.Harasymiw@gmail.com>
 *
 * @section DESCRIPTION
 * This Class represents a Player and all data related to the Player, as they play the game.
 */

#ifndef __PLAYER_HPP_INCLUDED__
#define __PLAYER_HPP_INCLUDED__
#include <deque>
#include <string>

class Player{
private:
	static const int MAX_HEALTH = 48;
	static const int MAX_STAMINA = 47;
	int myHealth;
	int myStamina;
	int myXLocation;
	int myYLocation;
	std::string myName;
	std::deque <std::string > inventory;

public:
	/**
	 * Default construtor
	 */
	Player();

	/**
	 * Amount that health is changed by.
	 */
	void modifyHealth(int num);

	/**
	 * Amount that stamina is changed by.
	 */
	void modifyStamina(int num);

	/**
	 * Returns the player's current health.
	 */
	int getHealth() const;

	/**
	 * Returns the player's current stamina.
	 */
	int getStamina() const;

	/**
	 * Returns the player's current x location.
	 */
	int getXLocation() const;

	/**
	 * Returns the player's current y location.
	 */
	int getYLocation() const;

	/**
	 * Returns the player's name.
	 */
	std::string getName() const;

	/**
	 * Searchs the player's inventory for a spefic item then returns index if found
	 * else will give -1 if not found.
	 */
	int searchItems(std::string item) const;

	/**
	 * Adds an item to the player's inventory.
	 */
	void givePlayerItem(std::string item);

	/**
	 * Remove an item to the player's inventory.
	 */
	std::string removeItem(int index);

	/**
   * Sets the players coorniated to a location that represents moving one space north
   */
	void movePlayerNorth();

	/**
   * Sets the players coorniated to a location that represents moving one space south
   */
	void movePlayerSouth();

	/**
   * Sets the players coorniated to a location that represents moving one space east
   */
	void movePlayerEast();

	/**
   * Sets the players coorniated to a location that represents moving one space west
   */
	void movePlayerWest();

	int getMAXHEALTH() const;

	int getMAXSTAMINA() const;

};

#endif
