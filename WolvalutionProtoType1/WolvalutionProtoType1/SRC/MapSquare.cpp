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

bool MapSquare::isWalkable() const{
	return walkable;
}

ColoredCharacter MapSquare::getChar() const{
	return myChar;
}

std::string MapSquare::getDescription() const{
	return myDescription;
}


Scenario MapSquare::getScenario() const{
	return myScenario;
}

bool MapSquare::getScenarioActive() const{
	return myScenario.getIsActive();
}

ColoredCharacter MapSquare::getColoredCharacter() const{
	return myChar.getChar();
}

void MapSquare::DeActiveScenario(){
	myScenario.DeActiveScenario();
}
