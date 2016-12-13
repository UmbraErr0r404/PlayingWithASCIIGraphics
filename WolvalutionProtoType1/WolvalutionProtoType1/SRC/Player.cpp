#include "Player.hpp"

Player::Player()
{
   myHealth = MAX_HEALTH;
   myStamina = MAX_STAMINA;
   myXLocation = 4;
   myYLocation = 4;
   std::string myName = "Joe";
}

void Player::modifyHealth(int num)
{
   myHealth = myHealth + num;
}

void Player::modifyStamina(int num)
{
   myStamina = myStamina + num;
}

int Player::getHealth()
{
   return myHealth;
}

int Player::getStamina()
{
   return myStamina;
}

int Player::getXLocation()
{
   return myXLocation;
}

int Player::getYLocation()
{
   return myYLocation;
}

std::string Player::getName()
{
   return myName;
}

int Player::searchItems(std::string item)
{
   for (int i = 0; i < inventory.size(); i++)
   {
      if (inventory[i] == item)
         return i;
      else
         return -1;
   }
}

void Player::givePlayerItem(std::string item)
{
   inventory.push_back(item);
}

std::string Player::removeItem(int index)
{
   std::string temp = inventory[index];
   inventory[index].erase();
   return temp;
}

void Player::movePlayerNorth()
{
   myYLocation = myYLocation - 1;
}

void Player::movePlayerSouth()
{
   myYLocation = myYLocation + 1;
}

void Player::movePlayerEast()
{
   myXLocation = myXLocation + 1;
}

void Player::movePlayerWest()
{
   myXLocation = myXLocation - 1;
}

int Player::getMAXHEALTH()
{
   return MAX_HEALTH;
}

int Player::getMAXSTAMINA()
{
   return MAX_STAMINA;
}


