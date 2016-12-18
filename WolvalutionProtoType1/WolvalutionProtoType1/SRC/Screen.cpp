#include "Screen.hpp"

Screen::Screen(){
	frameCount = 0;
}

void Screen::ClearPrintOrder(){
	PrintOrder.clear();
	frameCount = 0;
}

void Screen::PushFrameFront(Frame q){
	PrintOrder.push_front(q);
	frameCount++;
}
void Screen::PushFrameBack(Frame q){
	PrintOrder.push_back(q);
	frameCount++;
}

Frame Screen::PopFrameFront(){
	Frame temp(PrintOrder[0]);
	PrintOrder.pop_front();
	frameCount--;
	return temp;
}

Frame Screen::PopFrameBack(){
	Frame temp(PrintOrder[frameCount - 1]);
	PrintOrder.pop_back();
	frameCount--;
	return temp;
}

int Screen::SearchFrame(std::string searchName) const{
	for (unsigned int i = 0; i < PrintOrder.size(); i++)
		if (PrintOrder[i].getName() == searchName)
			return i;
	return -1;
}

/*
 * checks if there is a map, then either makes a frame or replaces old frame
 */
void Screen::UpdateMap(int Ix, int Iy, Map aMap){
	Frame map("CurrentScreenMap", Ix, Iy, aMap);
	if (SearchFrame("CurrentScreenMap") == -1){
		PrintOrder.push_back(map);
		frameCount++;
	}
	else{
		PrintOrder.erase(PrintOrder.begin() + SearchFrame("CurrentScreenMap"));
		PrintOrder.push_back(map);
	}
}

//TODO: I'm sure you ever check if that happened on a higher level
Frame Screen::CurrentMap() const{
	if (SearchFrame("CurrentScreenMap") == -1){
		Frame Error("Error", 0, 0, 0, 0);
		return Error;
	}
	else{
		return PrintOrder[SearchFrame("CurrentScreenMap")];
	}
}

int Screen::printOrderLength() const{
	return frameCount;
}
