#include "Option.hpp"

Option::Option(){
	myHealthChange = 0;
	myStaminaChange = 0;
	myItem = "NaI";
	myText = "Do Nothing";
	isSeletced = false;
}

Option::Option(int HC, int SC, std::string item, std::string def, bool selected){
	myHealthChange = HC;
	myStaminaChange = SC;
	myItem = item;
	myText = def;
	isSeletced = selected;
}

int Option::getHealthChange() const{
	return myHealthChange;
}

int Option::getStaminaChange() const{
	return myStaminaChange;
}

std::string Option::getMyItem() const{
	return myItem;
}

std::string Option::getMyText() const{
	return myText;
}
