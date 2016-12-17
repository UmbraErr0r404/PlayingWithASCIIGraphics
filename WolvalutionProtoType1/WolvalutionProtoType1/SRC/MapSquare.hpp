/**
 * @file
 * @author Savannah Evans <evanssav@uwplatt.edu>
 *
 * @section DESCRIPTION
 * This class reprepresents a MapSqaure and all data about that location.
 */

#ifndef __MAPSQUARE_HPP_INCLUDED__ 
#define __MAPSQUARE_HPP_INCLUDED__  

#include "ColoredCharacter.hpp"
#include "Scenario.hpp"

class MapSquare{
private:
	bool walkable;
	Scenario myScenario;
	ColoredCharacter myChar;
	std::string myDescription;

public:
	/**
	 * Default construtor
	 */
	MapSquare();

	/**
	 * A constructor for fully setting up a MapSqaure.
	 * @param aEvent is the scenario assigned to the MapSquare.
	 * @param c is the printable character assigned to the MapSquare.
	 * @param canWalk For checking if the player can be at this location.
	 * @param mfDif The description of this MapSquares scene.
	 */
	MapSquare(Scenario aEvent, ColoredCharacter c, bool canWalk, std::string myDif);

	/**
	 * Returns true if Player can occupy the MapSquare.
	 */
	bool isWalkable();

	/**
	 * Returns the printable character.
	 */
	ColoredCharacter getChar();

	/**
	 *
	 */
	std::string getDescription();

	/**
	 * Returns the scenario at the MapSquare.
	 */
	Scenario getScenario();

	/**
   *
   */
	bool getScenarioActive();

	/**
   *
   */
	ColoredCharacter getColoredCharacter();

	/**
   *
   */
	void DeActiveScenario();
};

#endif 
