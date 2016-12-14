/**
 * @file
 * @author Elizabeth Harasymiw <harasymiwe@uwplatt.edu>
 *
 * @section DESCRIPTION
 * The WindowsConsole Class is all functions needed to properly print
 * the abstract GUI objects designed for this program.
 */
#ifndef __WINDOWSCONSOLE_HPP_INCLUDED__  
#define __WINDOWSCONSOLE_HPP_INCLUDED__  

 /*
  * The following line is necessary for the GetConsoleWindow() function to work!
  * it basically says that you are running this program on Windows 2000 or higher.
  */
#define _WIN32_WINNT 0x0500 

#include "ColorData.hpp"
#include "Frame.hpp"
#include "Screen.hpp"
#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <cstdlib> 
#include <stdio.h>
#include <time.h>
#include <stdlib.h> //for using the function sleep

class WindowsConsole
{
private:
   const static int HEIGHT = 50;
   const static int WIDTH = 120;
   bool CursorVisibility = true;
   Frame CurrentConsoleDisplay = Frame("CCD", 0, 0, HEIGHT, WIDTH);
   Frame BufferConsoleDisplay = Frame("BCD", 0, 0, HEIGHT, WIDTH);

public:
   /**
    * Default Construture to setup a Windows ColorEnabled Termail
    */
   WindowsConsole();

   /**
    * Takes some text and a colorCode and outputs it to the console
    * @param text The string that will be displayed
    * @param colorCode A number with the infomastion for forground and backcolor
    */
   void txtCC(std::string text, int colorCode);

   /**
    * Takes a character and a colorCode and outputs it to the console
    * @param text: The string that will be displayed
    * @param colorCode: a number with the infomastion for forground and backcolor
    */
   void CCC(char c, int colorCode);

   /**
    * This sets the Cursor to the give postion on the termail console
    * @param x: x distance from the upper left corner on the console by characters
    * @param y: y distance from the upper left corner on the console by characters
    */
   void SetCursor(int Ix, int Iy);

   /**
    * Changes the size of the consolewindow that the windows termail is displayed in.
    * @param height: new height counted in pixels
    * @param width: new height counted in pixels
    */
   void ResizeConsolePixel(int height, int width);

   /**
    * Changes the size of the windows termail buffer display.
    * @param height: new buffer height counted in characters
    * @param width: new buffer width counted in characters
    */
   void ResizeConsoleBufferSize(int height, int width);

   /**
    * Changes the Console color to the given colorcode.
    * @param colorcode The data int that reprents the forground and backgrounf color.
    */
   void ChangeConsoleFont(int colorcode); 

   /**
    * Clears all data from displayed console and resets to a generic default.
    */
   void ClearScreen();

   /**
    * Prints the given frame to the console at the given X Y postion.
    * @param Ix X postion the frame will printed at.
    * @param Iy Y postion the frame will printed at.
    * @param Iframe The frame being printed.
    */
   void PrintFrame(int Ix, int Iy, Frame Iframe);

   /**
    * Prints a ColoredCharacter at the given  X Y postion.
    * @param Ix
    * @param Iy
    * @param Ic
    */
   void PrintColoredCharacter(int Ix, int Iy, ColoredCharacter Ic);

   /**
    * Prints the given map from a given refference point of the upper left hand corner
    * @param Ix
    * @param Iy
    * @param aMap
    */
   void PrintMap(int Ix, int Iy, Map aMap);

};

#endif