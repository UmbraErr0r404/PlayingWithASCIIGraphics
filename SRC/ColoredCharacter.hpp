/**
 * @file
 * @author Elizabeth Harasymiw <Elizabeth.Harasymiw@gmail.com>
 *
 * @section DESCRIPTION
 * This class represents a character with data about its printing properites
 * for colored capaible termails
 */

#ifndef __COLOREDCHARACTER_HPP_INCLUDED__
#define __COLOREDCHARACTER_HPP_INCLUDED__

#include "ColorData.hpp"
#include "BaseTypes.hpp"

//TODO: move operators to be defined at end of class

class ColoredCharacter{
private:
	char c;
	color bg, fg; //background and forgound color

public:
	/**
	 * Creates a default ColoredCharacter with default charcter, and colors;
	 */
	ColoredCharacter();

	/**
	 * Creates a default ColoredCharacter with a given charcter, and  default colors;
	 * @param ch A char that will be set to the default colors
	 */
	explicit ColoredCharacter(char c);

	/**
	 * Creates a default ColoredCharacter with a given charcter, and colors;
	 * @param inputbg Color the background will be set to.
	 * @param inputfg Color the foreground will be set to.
	 * @param ch A char that will be set to the given colors
	 */
	ColoredCharacter(color bg, color fg, char c);

	/**
	 * Overloads the == operator for ColoredCharcter
	 * @param CCcompare The ColorCharacter being compared too.
	 */
	bool operator== (const ColoredCharacter& CCcompare) const;

	/**
	 * Gets the character for this ColoredCharacter.
	 */
	char getChar() const;

	/**
	 * Gets the background color for this ColoredCharacter.
	 */
	color getBG() const;

	/**
	 * Gets the foreground color for this ColoredCharacter.
	 */
	color getFG() const;
};
#endif
