/**
 * @file
 * @author Sarah Higgens <higgenss@uwplatt.edu>
 *
 * @section DESCRIPTION
 * This Class represents a Player and all data related to the Player, as they play the game.
 */

#ifndef __PLAYER_H_INCLUDED__   
#define __PLAYER_H_INCLUDED__ 
#include <deque>
#include <string>

class Player
{
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
   int getHealth();

   /**
    * Returns the player's current stamina.
    */
   int getStamina();

   /**
    * Returns the player's current x location.
    * @pre Player is on the frame.
    */
   int getXLocation();
   
   /**
    * Returns the player's current y location.
    * @pre Player is on the frame.
    */
   int getYLocation();

   /**
    * Returns the player's name.
    * @pre Player is on the frame.
    */
   std::string getName();

   /**
    * Searchs the player's inventory for a spefic item then returns index if found
    * else will give -1 if not found.
    * @pre An inventory exists.
    */
   int searchItems(std::string item);

   /**
    * Adds an item to the player's inventory.
    * @pre An inventory exists.
    */
   void givePlayerItem(std::string item);

   /**
    * Remove an item to the player's inventory.
    * @pre An inventory exists.
    */
   std::string removeItem(int index);

   /**
   * Sets the players coorniated to a location that represents moving one space north.
   * @pre Player is set to a location on the map.
   */
   void movePlayerNorth();

   /**
   * Sets the players coorniated to a location that represents moving one space south.
   * @pre Player is set to a location on the map.
   */
   void movePlayerSouth();

   /**
   * Sets the players coorniated to a location that represents moving one space east.
   * @pre Player is set to a location on the map.
   */
   void movePlayerEast();

   /**
   * Sets the players coorniated to a location that represents moving one space west.
   * @pre Player is set to a location on the map.
   */
   void movePlayerWest();

   /**
   * Returns the max health.
   */
   int getMAXHEALTH();

   /**
   * Returns the max stamina.
   */
   int getMAXSTAMINA();
};

#endif 