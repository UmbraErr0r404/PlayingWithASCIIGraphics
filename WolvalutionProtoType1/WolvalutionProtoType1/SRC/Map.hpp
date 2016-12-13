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
    * Changes the MapSquare in the array at the specified x and y locations
    */
   void PlaceMapSquare(const int x, const int y, MapSquare aMapSquare);

   /**
    * overloads the [] operator for this class
    */
   std::deque<MapSquare>& operator[] (const int index);

   /**
    * returns the mapsqaure that corsponse to the players current potion on the map
    */
   MapSquare getPlayerMapSquare();

   /**
    * returns the maps height
    */
   int getHeight();

   /**
    * returns the maps width
    */
   int getWidth();

   /**
   *
   */
   int getMyPlayerXLocation();

   /**
   *
   */
   int getMyPlayerYLocation();

   /**
   *
   */
   void MovePlayerNorth();

   /**
   *
   */
   void MovePlayerSouth();

   /**
   *
   */
   void MovePlayerWest();

   /**
   *
   */
   void MovePlayerEast();

   /**
   *
   */
   int getPlayerMAXHEALTH();

   /**
   *
   */
   int getPlayerCurrentHealth();

   /**
   *
   */
   int getPlayerCurrentStamina();

   /**
   *
   */
   int getPlayerMAXSTAMINA();

   /**
   *
   */
   void ImportMap(int Ix, int Iy, std::string fileName);

   /**
   *
   */
   void ExportMap(std::string fileName);

   /**
   *
   */
   void modifyPlayerHealth(int num);

   /**
   *
   */
   void modifyPlayerStamina(int num);
};

#endif 