#include "ColoredCharacter.hpp"

ColoredCharacter::ColoredCharacter()
{
   bg = Black;
   fg = White;
   c = ' ';
}

ColoredCharacter::ColoredCharacter(char ch)
{
   bg = Black;
   fg = White;
   c = ch;
}

ColoredCharacter::ColoredCharacter(color inputbg, color inputfg, char ch)
{
   c = ch;
   bg = inputbg;
   fg = inputfg;
}

bool ColoredCharacter::operator==(ColoredCharacter CCcompare)
{
   if ((bg == CCcompare.getBG()) && (fg == CCcompare.getFG()) && (c = CCcompare.getChar()))
      return true;
   else
      return false;
}

char ColoredCharacter::getChar()
{
   return c;
}

color ColoredCharacter::getBG()
{
   return bg;
}

color ColoredCharacter::getFG()
{
   return fg;
}
