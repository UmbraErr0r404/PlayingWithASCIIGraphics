#include "Map.hpp"
#include "Scenario.hpp"         //for input and export map
#include "ColoredCharacter.hpp" //for input and export map
#include "Option.hpp"           //for input and export map

Map::Map(){
	for (int lcv = 0; lcv < WIDTH; lcv++){
		myMapSquares.push_back(std::deque<MapSquare>());
		for (int lcv2 = 0; lcv2 < HEIGHT; lcv2++)
			myMapSquares.back().push_back(MapSquare());
	}
}

void Map::PlaceMapSquare(const int x, const int y, MapSquare aMapSquare){
	myMapSquares[x][y] = aMapSquare;
}

std::deque<MapSquare>& Map::operator[] (const int index){
	return myMapSquares[index];
}

MapSquare Map::getPlayerMapSquare() const{
	return myMapSquares[myPlayer.getXLocation()][myPlayer.getYLocation()];
}

int Map::getHeight() const{
	return HEIGHT;
}

int Map::getWidth() const{
	return WIDTH;
}

unsigned int Map::getMyPlayerXLocation() const{
	return myPlayer.getXLocation();
}

unsigned int Map::getMyPlayerYLocation() const{
	return myPlayer.getYLocation();
}

void Map::MovePlayerNorth(){
	if (getMyPlayerYLocation() <= 0)
		; //do nothing
	else if (myMapSquares[getMyPlayerXLocation()][getMyPlayerYLocation() - 1].isWalkable())
		myPlayer.movePlayerNorth();
	else
		;//do nothing
}

void Map::MovePlayerSouth(){
	if (getMyPlayerYLocation() >= HEIGHT -1)
		; //do nothing
	else if (myMapSquares[getMyPlayerXLocation()][getMyPlayerYLocation() + 1].isWalkable())
		myPlayer.movePlayerSouth();
	else
		;//do nothing
}

void Map::MovePlayerWest(){
	if (getMyPlayerXLocation() <= 0)
		; //do nothing
	else if (myMapSquares[getMyPlayerXLocation() - 1][getMyPlayerYLocation()].isWalkable())
		myPlayer.movePlayerWest();
	else
		;//do nothing
}

void Map::MovePlayerEast(){
	if (getMyPlayerXLocation() >= WIDTH - 1)
		; //do nothing
	else if (myMapSquares[getMyPlayerXLocation() + 1][getMyPlayerYLocation()].isWalkable())
		myPlayer.movePlayerEast();
	else
		;//do nothing
}

int Map::getPlayerMAXHEALTH(){
	return myPlayer.getMAXHEALTH();
}

int Map::getPlayerCurrentHealth(){
	return myPlayer.getHealth();
}

int Map::getPlayerCurrentStamina(){
	return myPlayer.getStamina();
}

int Map::getPlayerMAXSTAMINA(){
	return myPlayer.getMAXSTAMINA();
}

void Map::modifyPlayerHealth(int num){
	myPlayer.modifyHealth(num);
}

void Map::modifyPlayerStamina(int num){
	myPlayer.modifyStamina(num);
}
