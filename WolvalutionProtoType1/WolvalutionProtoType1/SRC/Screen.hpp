/**
 * @file
 * @author Elizabeth Harasymiw <Elizabeth.Harasymiw@gmail.com>
 *
 * @section DESCRIPTION
 * This is a containor class for Frame, it is an vecotor strture of frames;
 */

#ifndef __SCREEN_HPP_INCLUDED__   
#define __SCREEN_HPP_INCLUDED__   

#include "ColoredCharacter.hpp"
#include "Frame.hpp"
#include "Map.hpp"
#include <string>
#include <deque>

class Screen{
private:
	const static int HEIGHT = 50;
	const static int WIDTH = 120;
	std::deque< Frame > PrintOrder;
	int frameCount;

public:
	/**
	 * Default Construture to setup a Screen
	 */
	Screen();

	/**
	 * 
	 */
	void ClearPrintOrder();

	/**
	 *
	 */
	void PushFrameFront(Frame q);

	/**
	 *
	 */
	void PushFrameBack(Frame q);

	/**
   *
   */
	Frame PopFrameFront();

	/**
   *
   */
	Frame PopFrameBack();

	/**
	 * Returns postions in deque where the frame is, or -1 if not found.
	 */
	int SearchFrame(std::string searchName);

	/**
	 *
	 * @param Ix
	 * @param Iy
	 * @param Iq
	 */
	void UpdateMap(int Ix, int Iy, Map aMap);

	/**
	 * returns the current map for this screen, for the purposes of this game,
	 * each screen will only have one current map.
	 */
	Frame CurrentMap();

	/**
   * Returns the number of Frames in the PrintOrder
   */
	int printOrderLength();
      
};
#endif 
