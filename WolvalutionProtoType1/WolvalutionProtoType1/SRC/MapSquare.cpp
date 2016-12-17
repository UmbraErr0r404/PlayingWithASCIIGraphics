#include "MapSquare.hpp"

MapSquare::MapSquare(){
	 walkable = true;
   myScenario = Scenario();
   myChar = ColoredCharacter(Black, DarkGreen, char(177));
   myDescription = "A small grassy area.";
}

MapSquare::MapSquare(Scenario aEvent, ColoredCharacter c, bool canWalk, std::string myDif){
   walkable = canWalk;
   myChar = c;
   myScenario = aEvent;
   myDescription = myDif;
}

bool MapSquare::isWalkable(){
   return walkable;
}

ColoredCharacter MapSquare::getChar(){
   return myChar;
}

std::string MapSquare::getDescription(){
   return myDescription;
}


Scenario MapSquare::getScenario(){
   return myScenario;
}

bool MapSquare::getScenarioActive(){
   return myScenario.getIsActive();
}

ColoredCharacter MapSquare::getColoredCharacter(){
   return myChar.getChar();
}

void MapSquare::DeActiveScenario(){
   myScenario.DeActiveScenario();
}
