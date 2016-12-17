#include "ColoredCharacter.hpp"

ColoredCharacter::ColoredCharacter(){
	bg = Black;
	fg = White;
	c = ' ';
}

ColoredCharacter::ColoredCharacter(char ch){
	bg = Black;
	fg = White;
	c = ch;
}

ColoredCharacter::ColoredCharacter(color inputbg, color inputfg, char ch){
	c = ch;
	bg = inputbg;
	fg = inputfg;
}

bool ColoredCharacter::operator==(const ColoredCharacter& CCcompare) const{
	if ((bg == CCcompare.getBG()) && (fg == CCcompare.getFG()) && (c == CCcompare.getChar()))
		return true;
	else
		return false;
}

char ColoredCharacter::getChar() const{
	return c;
}

color ColoredCharacter::getBG() const{
	return bg;
}

color ColoredCharacter::getFG() const{
	return fg;
}
