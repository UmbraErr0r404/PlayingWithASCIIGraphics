/**
 * @file
 * @author Zachary Pollard <example@gmail.com>
 *
 * @section DESCRIPTION
 * This class holds all the data related to a Scenario within a given MapSqaure on Map.
 * A Scernario has data related to all the options it will give the user as well
 * as a description on how this event has affected the evoirment around it.
 */

#ifndef __SCENARIO_H_INCLUDED__   
#define __SCENARIO_H_INCLUDED__  
#include <string>
#include "Option.hpp"

class Scenario
{
private:
   std::string myDescription;
   Option myOption1, myOption2, myOption3, myOption4;
   bool isActive;

public:
   /**
    * Default construtor
    */
   Scenario();

   /**
    * Construtor that fully sets up a Scenario.
    * @param O1 All dated needed by the player and game for option 1.
    * @param O2 All dated needed by the player and game for option 2.
    * @param O3 All dated needed by the player and game for option 3.
    * @param O4 All dated needed by the player and game for option 4.
    * @param Description
    * @param active
    */
   Scenario(Option O1, Option O2, Option O3, Option O4, std::string Description, bool active);

   /**
    * Returns the Description of this Scenario.
    */
   std::string getMyDescription();

   /**
    * Returns option 1;
    */
   Option getMyOption1();

   /**
    * Returns option 2;
    */
   Option getMyOption2();

   /**
    * Returns option 3;
    */
   Option getMyOption3();

   /**
   * Returns option 4;
   */
   Option getMyOption4();

   /**
    * Returns if this Scenario is active or not.
    */
   bool getIsActive();

   /**
   * Returns if this Scenario is active or not.
   */
   void DeActiveScenario();
};

#endif 