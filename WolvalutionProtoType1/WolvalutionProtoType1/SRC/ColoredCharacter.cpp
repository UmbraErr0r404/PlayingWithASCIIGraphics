#include "ColoredCharacter.hpp"

ColoredCharacter::ColoredCharacter():
	bg(Black),fg(White),c(' '){
}

ColoredCharacter::ColoredCharacter(char c):
	bg(Black),fg(White),c(c){
}

ColoredCharacter::ColoredCharacter(color bg, color fg, char c):
   bg(bg),fg(fg), c(c){
}

//TODO: simplify code paths
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
