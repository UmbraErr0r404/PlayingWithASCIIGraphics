/**
 * @file
 * @author Elizabeth Harasymiw <Elizabeth.Harasymiw@gmail.com>
 *
 * @section DESCRIPTION
 * This class represents a map object which has an array of MapSquares
 */
#ifndef __MAP_HPP_INCLUDED__
#define __MAP_HPP_INCLUDED__
#include <deque>
#include "MapSquare.hpp"
#include "Player.hpp"
#include "BaseTypes.hpp"

/*
 * File local TODO list
 * ====================
 *
 * * move WIDTH and HEIGHT to wherever they should be. (Id est, not here.)
 */

class Map{
private:
	std::deque<std::deque<MapSquare> > myMapSquares;
	const int WIDTH = 114; //constant map width
	const int HEIGHT = 24; //constant map height
	Player myPlayer;

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
	MapSquare getPlayerMapSquare() const;

	/**
	 * returns the maps height
	 */
	int getHeight() const;

	/**
	 * returns the maps width
	 */
	int getWidth() const;

	/**
   *
   */
	unsigned int getMyPlayerXLocation() const;

	/**
   *
   */
	unsigned int getMyPlayerYLocation() const;

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
	int getPlayerMAXHEALTH() const;

	/**
   *
   */
	int getPlayerCurrentHealth() const;

	/**
   *
   */
	int getPlayerCurrentStamina() const;

	/**
   *
   */
	int getPlayerMAXSTAMINA() const;

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
