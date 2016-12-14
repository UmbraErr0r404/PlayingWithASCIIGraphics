/**
 * @file
 * @author Savannah Evans <evanssav@uwplatt.edu>
 *
 * @section DESCRIPTION
 * This class represents a map object which has an array of MapSquares
 */

#ifndef __MAP_HPP_INCLUDED__  
#define __MAP_HPP_INCLUDED__  
#include <deque>
#include "MapSquare.hpp"
#include "Player.hpp"

class Map
{
private:
   std::deque<std::deque<MapSquare>> myMapSquares;
   const int WIDTH = 114; //constant map width
   const int HEIGHT = 24; //constant map height
   Player myPlayer = Player();

public:
   /**
    * Default construtor
    */
   Map();

   /**
    * Changes the MapSquare in the array at the specified x and y locations.
    */
   void PlaceMapSquare(const int x, const int y, MapSquare aMapSquare);

   /**
    * overloads the [] operator for this class.
    */
   std::deque<MapSquare>& operator[] (const int index);

   /**
    * returns the mapsqaure that corsponse to the players current potion on the map.
    * @pre A mapSquare is created.
    */
   MapSquare getPlayerMapSquare();

   /**
    * returns the maps height.
    * @pre A map is created.
    */
   int getHeight();

   /**
    * returns the maps width.
    * @pre A map is created.
    */
   int getWidth();

   /**
   * returns the X Location of Player.
   * @pre Player has been created
   */
   int getMyPlayerXLocation();

   /**
   * returns the Y Location of Player.
   * @pre Player has been created
   */
   int getMyPlayerYLocation();

   /**
   * Modifies where player is placed on screen by editing y coordinate up by 1.
   * Moves player North
   * @pre Player has been created
   */
   void MovePlayerNorth();

   /**
   * Modifies where player is placed on screen by editing y coordinate down by 1.
   * Moves the player South
   * @pre Player has been created
   */
   void MovePlayerSouth();

   /**
   * Modifies where player is placed on screen by editing x coordinate up by 1.
   * Moves the player West
   * @pre Player has been created
   */
   void MovePlayerWest();

   /**
   * Modifies where player is placed on screen by editing x coordinate down by 1.
   * Moves the player East
   * @pre Player has been created
   */
   void MovePlayerEast();

   /** 
   * returns players max health.
   * @pre a player has been created
   */
   int getPlayerMAXHEALTH();

   /**
   * returns players max stamina.
   * @pre a player has been created
   */

   int getPlayerMAXSTAMINA();
   /**
   * returns players current health.
   * @pre a player has been created
   */
   int getPlayerCurrentHealth();

   /**
   * returns players current stamina.
   * @pre a player has been created
   */
   int getPlayerCurrentStamina();

   /**
   * Modifies players health value by the value of num.
   * @pre player has been created
   * @param num value that the players health is to be
   * modified by
   */
   void modifyPlayerHealth(int num);

   /**
   * Modifies players stamina value by the value of num.
   * @pre player has been created
   * @param num value that the players stamina is to be
   * modified by
   */
   void modifyPlayerStamina(int num);
};

#endif 