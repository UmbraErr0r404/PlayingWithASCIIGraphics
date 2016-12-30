#include "Player.hpp"

Player::Player():
	myHealth(MAX_HEALTH), myStamina(MAX_STAMINA),
	myXLocation(4), myYLocation(4){

	std::string myName = "Joe";
}

void Player::modifyHealth(int num){
	myHealth = myHealth + num;
}

void Player::modifyStamina(int num){
	myStamina = myStamina + num;
}

int Player::getHealth() const{
	return myHealth;
}

int Player::getStamina() const{
	return myStamina;
}

int Player::getXLocation() const{
	return myXLocation;
}

int Player::getYLocation() const{
	return myYLocation;
}

std::string Player::getName() const{
	return myName;
}

int Player::searchItems(std::string item) const{
	for (uint i = 0; i < inventory.size(); i++)
		if (inventory[i] == item)
			return i;
		return -1;
}

void Player::givePlayerItem(std::string item){
	inventory.push_back(item);
}

std::string Player::removeItem(int index){
	std::string temp = inventory[index];
	inventory[index].erase();
	return temp;
}

void Player::movePlayerNorth(){
	myYLocation = myYLocation - 1;
}

void Player::movePlayerSouth(){
	myYLocation = myYLocation + 1;
}

void Player::movePlayerEast(){
	myXLocation = myXLocation + 1;
}

void Player::movePlayerWest(){
	myXLocation = myXLocation - 1;
}

int Player::getMAXHEALTH() const{
	return MAX_HEALTH;
}

int Player::getMAXSTAMINA() const{
	return MAX_STAMINA;
}
