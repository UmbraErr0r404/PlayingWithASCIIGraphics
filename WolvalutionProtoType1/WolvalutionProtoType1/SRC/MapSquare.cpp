#include "MapSquare.hpp"

MapSquare::MapSquare(){
	walkable = true;
	myScenario = Scenario();
	tile = ColoredCharacter(Black, DarkGreen, char(177));
	myDescription = "A small grassy area.";
}

MapSquare::MapSquare(Scenario aEvent, ColoredCharacter c, bool canWalk, std::string myDis){
	walkable = canWalk;
	tile = c;
	myScenario = aEvent;
	myDescription = myDis;
}

bool MapSquare::isWalkable() const{
	return walkable;
}

ColoredCharacter MapSquare::getChar() const{
	return tile;
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
	return tile.getChar();
}

void MapSquare::DeActiveScenario(){
	myScenario.DeActiveScenario();
}
