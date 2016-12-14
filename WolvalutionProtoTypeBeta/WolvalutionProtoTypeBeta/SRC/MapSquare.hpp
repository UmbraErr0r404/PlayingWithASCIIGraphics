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

class MapSquare
{
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
    * @pre a player exists and map exists
    */
   bool isWalkable();

   /**
    * Returns the printable character.
    * @pre a frame exists
    */
   ColoredCharacter getChar();

   /**
    * Returns the description of a particular event.
    * @pre Player is at a location of a scenrio. 
    */
   std::string getDescription();

   /**
    * Returns the scenario at the MapSquare.
    * @pre Map Square exists.
    */
   Scenario getScenario();

   /**
   * Returns to see if a scenario has been completed.
   * @pre Player is on a scernario.
   */
   bool getScenarioActive();

   /**
   * Returns the color and character for a location on the Frame.
   * @pre A Frame exists. 
   */
   ColoredCharacter getColoredCharacter();

   /**
   * Changes is active to false. 
   * @pre Active is set to true.
   */
   void DeActiveScenario();
};

#endif 