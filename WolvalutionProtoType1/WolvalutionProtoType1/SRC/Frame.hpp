/**
 * @file
 * @author Elizabeth Harasymiw <Elizabeth.Harasymiw@gmail.com>
 *
 * @section DESCRIPTION
 * This class represents a double array like code sturture that holds Characters with there
 * printing informastion for a coloredable termail.
 */

#ifndef __FRAME_H_INCLUDED__   
#define __FRAME_H_INCLUDED__  
#include "Map.hpp"
#include <string>
#include <deque>

class Frame{
private:
	int x;
	int y;
	unsigned int height;
	unsigned int width;
	std::deque<std::deque<ColoredCharacter> > frame;
	std::string name;

	/**
	 * Clears all frame data and then remakes the frame to the given height and width
	 * @param Iwidth Width that the frame will be changed too.
	 * @param Iheight Height that the frame will be changed too.
	 */
	void ResizeFrame(int Iwidth, int Iheight);

public:
	/**
	 * Default construtor
	 */
	Frame(); 

	/**
	 * Make new empty frame for target location
	 * @param Iname The name of the new frame.
	 * @param Ix X Locatiion where the frame thinks it will be drawn on the screen.
	 * @param Iy Y Locatiion where the frame thinks it will be drawn on the screen.
	 * @param Iheight The set height of the frame.
	 * @param Iwidth The set width of the frame.
	 */
	Frame(std::string Iname, int Ix, int Iy, int Iheight, int Iwidth); 

	/**
	 * Makes a frame coorspanding to the data of the map given to this function.
	 * @param Iname The name of the new frame.
	 * @param Ix X Locatiion where the frame thinks it will be drawn on the screen.
	 * @param Iy Y Locatiion where the frame thinks it will be drawn on the screen.
	 * @param AMap Any given map that will have its ColoredCharacter data transfered over.
	 */
	Frame(std::string Iname, int Ix, int Iy, Map AMap); 

	/**
	 * Turns the frame that called this function into a copy of the called file.
	 * @param Ix The x postion where the frames thinks it will be printed.
	 * @param Iy The y postion where the frames thinks it will be printed.
	 * @param fileName Name of the file this function is getting data from.
	 * @param newFrameName Name of the copied frame.
	 */
	void ImportFrame(int Ix, int Iy, std::string fileName, std::string newFrameName);

	/**
	 * Takes the data of the frame this function is being called from, and
	 * exports that data to the given fileName.
	 * @param fileName The file name that the data is being exported too.
	 */
	void ExportFrame(std::string fileName);

	/**
	 * Overloads the [] operators
	 * @param index
	 */
	std::deque<ColoredCharacter>& operator[] (const int index);

	/**
	 * Gets this frame's name and returns it.
	 */
	std::string getName() const;

	/**
	 * Gets this frame's X print location and returns it.
	 */
	unsigned int getX() const;

	/**
	 * Gets this frame's Y print location and returns it.
	 */
	unsigned int getY() const;

	/**
	 * Gets this frame's height and returns it.
	 */
	unsigned int getHeight() const;

	/**
	 * Gets this frame's width and returns it.
	 */
	unsigned int getWidth() const;

	/**
	 * Places the ColoredCharacters from the given frame onto
	 * this frame using X Y potion of the upper left corner
	 * as a refference point.
	 * @param Ix X postion of refference point within the frame
	 * @param Iy Y postion of refference point within the frame
	 * @param toPlaceFrame Frame being placed.
	 */
	void PlaceFrame(int Ix, int Iy, Frame toPlaceFrame);

	/**
	 * Places a line of characters started at the given X Y postion, and ending
	 * after a given length is reached. The line is drawn in spesfied colors.
	 * @param Ix X postion of refference point.
	 * @param Iy Y postion of refference point.
	 * @param length Number of characters drawn.
	 * @param bgcolor Background color of the line characters. 
	 * @param fgcolor Foreground color of the line characters. 
	 */
	void PlaceHLine(int Ix, int Iy, int length, color bgcolor, color fgcolor);

	/**
	 * Places a line of characters started at the given X Y postion, and ending
	 * after a given length is reached. The line is drawn in spesfied colors.
	 * @param Ix X postion of refference point.
	 * @param Iy Y postion of refference point.
	 * @param length Number of characters drawn.
	 * @param bgcolor Background color of the line characters.
	 * @param fgcolor Foreground color of the line characters.
	 */
	void PlaceVLine(int Ix, int Iy, int length, color bgcolor, color fgcolor);

	/**
	 * Places a spasfic ColoredCharacter at the given X Y postion.
	 * @param Ix X postion where the ColoredCharacter will be placed.
	 * @param Iy Y postion where the ColoredCharacter will be placed.
	 * @param c The character being placed.
	 * @param bgcolor Background color of the character being placed.
	 * @param fgcolor Foreground color of the character being placed.
	 */
	void PlaceChar(int Ix, int Iy, char c, color bgcolor, color fgcolor);

	/**
	 * Draws a box onto the current frame using the upper left, and lower right points
	 * of a rectangle in the spesfided colors.
	 * @param Ix1 X postion for upper left refference point.
	 * @param Iy1 Y postion for upper left refference point.
	 * @param Ix2 X postion for lower right refference point.
	 * @param Iy2 Y postion for lower right refference point.
	 * @param bgcolor Background color of the characters being drawn to make the box.
	 * @param fgcolor Foreground color of the characters being drawn to make the box.
	 */
	void PlaceBox(int Ix1, int Iy1, int Ix2, int Iy2, color bgcolor, color fgcolor);

	/**
	 * Places a string of characters in a line in the spesficed color.
	 * @param Ix X postion of reffernce point.
	 * @param Iy Y postion of reffernce point.
	 * @param text The string of characters being placed.
	 * @param bgcolor Background color of the characters being drawn.
	 * @param fgcolor Foreground color of the characters being drawn.
	 */
	void PlaceGenTxt(int Ix, int Iy, std::string text, color bgcolor, color fgcolor);

	/**
	 * ASCII ART 
	 * @param Ix
	 * @param Iy
	 * @param bgcolor
	 * @param fgcolor
	 */
	void PlaceLogo(int Ix, int Iy, color bgcolor, color fgcolor); 

	/**
	 * ASCII ART 
	 * @param Ix
	 * @param Iy
	 * @param bgcolor
	 * @param fgcolor
	 */
	void PlaceWindowSceneArt(int Ix, int Iy, color bgcolor, color fgcolor);

	/**
   * ASCII ART
   * @param Ix
   * @param Iy
   * @param bgcolor
   * @param fgcolor
   */
	void PlaceWindowMoonArt(int Ix, int Iy, color bgcolor, color fgcolor);

	/**
   * ASCII ART
   * @param Ix
   * @param Iy
   * @param bgcolor
   * @param fgcolor
   */
	void PlaceWhoAreYou(int Ix, int Iy, color bgcolor, color fgcolor);

	/**
   * ASCII ART
   * @param Ix
   * @param Iy
   * @param bgcolor
   * @param fgcolor
   */
	void YouWin(int Ix, int Iy, color bgcolor, color fgcolor);

	/**
   * ASCII ART
   * @param Ix
   * @param Iy
   * @param bgcolor
   * @param fgcolor
   */
	void YouDied(int Ix, int Iy, color bgcolor, color fgcolor);

	/**
   * ASCII ART
   * @param Ix
   * @param Iy
   */
	void PlaceExampleMap(int Ix1, int Iy1);

	/**
	 * This function is designed to find Coloredcharacters with equivilant displays
	 * and replacement with a known constantent replacement. This function affects
	 * the frame it was called from.
	 */
	void CleanUpFrame();
};

#endif 
