#include "MapSquare.hpp"

MapSquare::MapSquare():
	walkable(true), myScenario(Scenario()), 
	tile(ColoredCharacter(Black, DarkGreen, char(177))),
	myDescription("A small grassy area."){
}

MapSquare::MapSquare(Scenario aEvent, ColoredCharacter c, bool canWalk, std::string myDif):
	walkable(canWalk), tile(c), myScenario(aEvent),
	myDescription(myDif){
}

bool MapSquare::isWalkable() const{
	return walkable;
}

char MapSquare::getChar() const{
	return tile.getChar();
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
   return tile;
}

void MapSquare::DeActiveScenario(){
	myScenario.DeActiveScenario();
}
