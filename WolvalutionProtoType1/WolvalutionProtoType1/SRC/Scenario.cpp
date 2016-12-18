#include "Scenario.hpp"

Scenario::Scenario(){
	myDescription = "There is nothing here.";
	myOption1 = Option();
	myOption2 = Option();
	myOption3 = Option();
	myOption4 = Option();
	isActive = false;
}

Scenario::Scenario(Option O1, Option O2, Option O3, Option O4, std::string Description, bool active){
	myDescription = Description;
	myOption1 = O1;
	myOption2 = O2;
	myOption3 = O3;
	myOption3 = O4;
	isActive = active;
}

std::string Scenario::getMyDescription() const{
	return myDescription;
}

Option Scenario::getMyOption1() const{
	return myOption1;
}

Option Scenario::getMyOption2() const{
	return myOption2;
}

Option Scenario::getMyOption3() const{
	return myOption3;
}

Option Scenario::getMyOption4() const{
	return myOption4;
}

bool Scenario::getIsActive() const{
	return isActive;
}

void Scenario::DeActiveScenario(){
	isActive = false;
}
