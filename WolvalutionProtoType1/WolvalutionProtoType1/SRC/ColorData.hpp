/**
 * @file
 * @author Elizabeth Harasymiw <Elizabeth.Harasymiw@gmail.com>
 *
 * @section DESCRIPTION
 * This file holds data about ColorCodes that the windows.
 */

#ifndef __COLORDATA_HPP_INCLUDED__  
#define __COLORDATA_HPP_INCLUDED__  

/*
 * Calculates the number needed for correct color in txtCC and CCC
 */
#define ColorCode(bg, fg) ((int(bg) * 0x10) + int(fg)) 

enum color
{
	Black       =0x0,
	DarkBlue    =0x1,
	DarkGreen   =0x2,
	DarkCyan    =0x3,
	DarkRed     =0x4,
	DarkPurple  =0x5,
	DarkYellow  =0x6,
	LightGray   =0x7,
	Gray        =0x8,
	Blue        =0x9,
	Green       =0xA,
	Cyan        =0xB,
	Red         =0xC,
	Purple      =0xD,
	Yellow      =0xE,
	White       =0xF};
#endif 
