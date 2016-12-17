#include "Frame.hpp"
#include "Scenario.hpp"
#include "ColoredCharacter.hpp"
#include <string>
#include <iostream>
#include <fstream>

void Frame::ResizeFrame(int Iwidth, int Iheight){ 
	frame.clear();
	for (int tx = 0; tx < Iwidth; tx++){
		frame.push_back(std::deque<ColoredCharacter>());
		for (int ty = 0; ty < Iheight; ty++){
			frame[tx].push_back(ColoredCharacter());
		}
	} 
}

Frame::Frame(){
	name = "DefaultFrame";  x = 0; y = 0; height = 0; width = 0;
	ResizeFrame(0, 0);
};

Frame::Frame(std::string Iname, int Ix, int Iy, int const Iheight, int const Iwidth){
	name = Iname;
	x = Ix;
	y = Iy;
	height = Iheight;
	width = Iwidth;
	ResizeFrame(Iwidth, Iheight);
}

Frame::Frame(std::string Iname, int Ix, int Iy, Map AMap){
	x = Ix;
	y = Iy;
	name = Iname;
	height = AMap.getHeight();
	width = AMap.getWidth();
	ResizeFrame(width, height);

	ColoredCharacter MSPlayer(Black, Yellow, '@');
	ColoredCharacter MUnknown(Black, Red, '?');

	for (int bx = 0; bx < width; bx++)
		for (int by = 0; by < height; by++){
			if (AMap.getMyPlayerXLocation() == bx && AMap.getMyPlayerYLocation() == by)
				frame[bx][by] = MSPlayer;
			else if (AMap[bx][by].getScenarioActive())
				frame[bx][by] = MUnknown;
			else
				frame[bx][by] = AMap[bx][by].getChar();
		}
};

void Frame::ImportFrame(int Ix, int Iy, const std::string fileName, std::string newFrameName){
	std::ifstream myfile;
	myfile.open(fileName);

	std::string nom, fName;
	int fHeight, fWidth, charNum, fFG, fBG;

	myfile >> nom >> fHeight >> nom >> fWidth >> nom >> fName;

	ResizeFrame(fWidth, fHeight);

	height = fHeight;
	width = fWidth;
	name = newFrameName;
	x = Ix;
	y = Iy;

	for (int bx = 0; bx < fWidth; bx++){
		for (int by = 0; by < fHeight; by++){
			myfile >> nom >> charNum >> nom >> fBG >> nom >> fFG;
			color nfFG = color(fFG);
			color nfBG = color(fBG);
			ColoredCharacter temp( nfBG, nfFG , char(charNum) );
			frame[bx][by] = temp;
		}
	}
	 
	myfile.close();
}

void Frame::ExportFrame(std::string fileName){
	std::ofstream myfile;

	myfile.open(fileName);
	myfile << "Height " << height << " Width " 
				 << width << " Name " << name << "\n";

	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			myfile << "Char " << int(frame[x][y].getChar())
						 << " BG " << frame[x][y].getBG() 
						 << " FG " << frame[x][y].getFG() 
						 << "\n";

	myfile.close();
}

std::deque<ColoredCharacter>& Frame::operator[](const int index){
	return frame[index];
}

std::string Frame::getName() const{
	return name;
}

int Frame::getX() const{
	return x;
}

int Frame::getY() const{
	return y;
}

int Frame::getHeight() const{
	return height;
}

int Frame::getWidth() const{
	return width;
}

void Frame::PlaceFrame(int Ix, int Iy, Frame toPlaceFrame){
	if (width > toPlaceFrame.getWidth())
		if (height > toPlaceFrame.getHeight())
			for (int bx = 0; bx < toPlaceFrame.getWidth(); bx++)
				for (int by = 0; by < toPlaceFrame.getHeight(); by++)
					frame[bx + Ix][by + Iy] = toPlaceFrame[bx][by];
		else
			for (int bx = 0; bx < toPlaceFrame.getWidth(); bx++)
				for (int by = 0; by < height - Iy; by++)
					frame[bx + Ix][by + Iy] = toPlaceFrame[bx][by];
	else
		if (height > toPlaceFrame.getHeight())
			for (int bx = 0; bx < width - Ix; bx++)
				for (int by = 0; by < toPlaceFrame.getHeight(); by++)
					frame[bx + Ix][by + Iy] = toPlaceFrame[bx][by];
		else
			for (int bx = 0; bx < width - Ix; bx++)
				for (int by = 0; by < height - Iy; by++)
					frame[bx + Ix][by + Iy] = toPlaceFrame[bx][by];
}

void Frame::PlaceHLine(int Ix, int Iy, int length, color bgcolor, color fgcolor){
	ColoredCharacter HBar(bgcolor, fgcolor, char(196));
	for (int i = 0; i < length; i++)
		frame[Ix + i][Iy] = HBar;
}

void Frame::PlaceVLine(int Ix, int Iy, int length, color bgcolor, color fgcolor){
	ColoredCharacter HBar(bgcolor, fgcolor, char(179));
	for (int i = 0; i < length; i++)
		frame[Ix][Iy + i] = HBar;
}

void Frame::PlaceChar(int Ix, int Iy, char c, color bgcolor, color fgcolor){
	ColoredCharacter HBar(bgcolor, fgcolor, c);
	frame[Ix][Iy] = HBar;
}

void Frame::PlaceBox(int Ix1, int Iy1, int Ix2, int Iy2, color bgcolor, color fgcolor){
	ColoredCharacter TopLeftCorner(bgcolor, fgcolor, char(218));
	ColoredCharacter TopRightCorner(bgcolor, fgcolor, char(191));
	ColoredCharacter BottomLeftCorner(bgcolor, fgcolor, char(192));
	ColoredCharacter BottomRightCorner(bgcolor, fgcolor, char(217));

	frame[Ix1][Iy1] = TopLeftCorner;
	frame[Ix2][Iy1] = TopRightCorner;
	frame[Ix1][Iy2] = BottomLeftCorner;
	frame[Ix2][Iy2] = BottomRightCorner;

	PlaceVLine(Ix1, Iy1 + 1, Iy2 - 1 - Iy1, bgcolor, fgcolor);
	PlaceVLine(Ix2, Iy1 + 1, Iy2 - 1 - Iy1, bgcolor, fgcolor);
	PlaceHLine(Ix1 + 1, Iy1, Ix2 - 1 - Ix1, bgcolor, fgcolor);
	PlaceHLine(Ix1 + 1, Iy2, Ix2 - 1 - Ix1, bgcolor, fgcolor);
}

void Frame::PlaceGenTxt(int Ix, int Iy, std::string text, color bgcolor, color fgcolor){
	if (width < text.size())
		for (int i = 0; i < width; i++)
			frame[Ix + i][Iy] = ColoredCharacter(bgcolor, fgcolor, text[i]);
	else
		for (int i = 0; i < text.size(); i++)
			frame[Ix + i][Iy] = ColoredCharacter(bgcolor, fgcolor, text[i]);
}

void Frame::PlaceLogo(int Ix, int Iy, color bgcolor, color fgcolor){
	std::deque<std::string> lines;
	lines.push_back(" _        _            _                      _              _                          ");
	lines.push_back("| |      | |          | |                    | |           _| |_                        ");
	lines.push_back("| |  __  | |   ____   | | __    __   ____ _  | |  _    _  |_   _| (+)   ____    _  ___  ");
	lines.push_back("| | /  \\ | |  / __ `  | | \\ \\  / /  / __ ` | | | | |  | |   | |    _   / __ `  | |'__ ` ");
	lines.push_back("| |/ /\\ \\| | | |__| | | |  \\ \\/ /  | |__|  | | | | |__| |   | |   | | | |__| | |  /  | |");
	lines.push_back("|___/  \\___|  \\____/  |_|   \\__/    \\____/_| |_|  \\____/    \\__|  |_|  \\____/  |__|  |_|");

	for (auto&line : lines)
		PlaceGenTxt(Ix, Iy++, line, bgcolor, fgcolor);
}

void Frame::PlaceWindowSceneArt(int Ix, int Iy, color bgcolor, color fgcolor){
	std::deque<std::string> lines;
	lines.push_back("                                                                                          | ");
	lines.push_back("                                                             _______________________      | ");
	lines.push_back("                                                            |  ________   ________  |     | ");
	lines.push_back("                                                            | |        | |        | |     | ");
	lines.push_back("                                                            | |        | |        | |     | ");
	lines.push_back("                                                            | |        | |        | |     | ");
	lines.push_back("                                                            | |        | |        | |     | ");
	lines.push_back("                                                            | |        | |        | |     | ");
	lines.push_back("                                                            | |________| |________| |     | ");
	lines.push_back("                                                            |  ________   ________  |     | ");
	lines.push_back("                                                            | |        | |        | |     | ");
	lines.push_back("                                                            | |        | |        | |     | ");
	lines.push_back("                                                            | |        | |        | |     | ");
	lines.push_back("                                                            | |        | |        | |     | ");
	lines.push_back("                                                            | |        | |        | |     | ");
	lines.push_back("                                                            | |________| |________| |     | ");
	lines.push_back("                                                            |_______________________|     | ");
	lines.push_back("                                                                                          | ");
	lines.push_back("                                                                                          | ");
	lines.push_back("                                                                                          | ");
	lines.push_back("   _     _    _   _  _  _  _  ____________________________________________________________| ");
	lines.push_back("                                                                                          `.  ");
	lines.push_back("                                                                                            `.  ");
	lines.push_back("                                                                                              `. ");
	lines.push_back("                                                                                                `.");
	lines.push_back("                                                                                                   .");
	lines.push_back("                                                                                                      ");
	lines.push_back("                                                                                                      ` ");
	lines.push_back("                                                                                                         .");

	for (auto&line : lines) 
		PlaceGenTxt(Ix, Iy++, line, bgcolor, fgcolor);
}

void Frame::PlaceWindowMoonArt(int Ix, int Iy, color bgcolor, color fgcolor){
	std::deque<std::string> moon;
	moon.push_back("   ___ ");
	moon.push_back(" ,',.(`");
	moon.push_back(":  `'  ");
	moon.push_back(":) _  (");
	moon.push_back(" `:_)_,");

	std::deque<std::string> wshadow;
	wshadow.push_back("                                                   .::.");
	wshadow.push_back("                                                .:::::::.");
	wshadow.push_back("                                             .:::::::::' .:.");
	wshadow.push_back("                                            ::::::::::' .::::.");
	wshadow.push_back("                                        .:.  `:::::::' .:::::::.");
	wshadow.push_back("                                     .::::::.  `::::' .::::::::::");
	wshadow.push_back("                                  .:::::::::::.  `:' .::::::::::'");
	wshadow.push_back("                               .::::::::::::::::.    :::::::::::");
	wshadow.push_back("                            .::::::::::::::::::::' .  `::::::::'");
	wshadow.push_back("                           :::::::::::::::::::::' .::.  `::::::");
	wshadow.push_back("                            `::::::::::::::::::' .:::::.  `:::'");
	wshadow.push_back("                              `:::::::::::::::' .::::::::.  `'");

	Iy += 3;
	for (auto&line : moon) 
		PlaceGenTxt(Ix + 75, Iy++, line, bgcolor, fgcolor);
	Iy += 15;
	for (auto&line : wshadow)
		PlaceGenTxt(Ix, Iy++, line, bgcolor, fgcolor);
}

void Frame::PlaceWhoAreYou(int Ix, int Iy, color bgcolor, color fgcolor){
	std::deque<std::string> lines;

	lines.push_back(" _        _   _                                                                   ___");
	lines.push_back("| |      | | | |                                                                 |__ \\  ");
	lines.push_back("| |  __  | | | | __     ___       ___  _   _ __    ___     _   _    ___    _   _    ) | ");
	lines.push_back("| | /  \\ | | | |'_ `   / _ `     / __`  | | '__\\  / _ \\   | | | |  / _ \\  | | | |  / / ");
	lines.push_back("| |/ /\\ \\| | |  / | | | |_| |   | |__|  | | |    |  __/   | |_| | | |_| | | |_| | |_| ");
	lines.push_back("|___/  \\___| |__| |_|  \\__ /     \\___ /_| |_|     \\___|   \\__,  |  \\___/   \\__,_| (_) ");
	lines.push_back("                                                           __/  |");
	lines.push_back("                                                          |___ /");

	for (auto&line : lines)
		PlaceGenTxt(Ix, Iy++, line, bgcolor, fgcolor);
}

void Frame::YouWin(int Ix, int Iy, color bgcolor, color fgcolor){
	std::deque<std::string> lines;

	lines.push_back(".%%..%%...%%%%...%%..%%..........%%...%%...%%%%...%%..%%.");
	lines.push_back("..%%%%...%%..%%..%%..%%..........%%...%%..%%..%%..%%%.%%.");
	lines.push_back("...%%....%%..%%..%%..%%..........%%.%.%%..%%..%%..%%.%%%.");
	lines.push_back("...%%....%%..%%..%%..%%..........%%%%%%%..%%..%%..%%..%%.");
	lines.push_back("...%%.....%%%%....%%%%............%%.%%....%%%%...%%..%%.");

	for (auto&line : lines)
		PlaceGenTxt(Ix, Iy++, line, bgcolor, fgcolor);
}



void Frame::YouDied(int Ix, int Iy, color bgcolor, color fgcolor){
	std::deque<std::string> lines;

	lines.push_back(".%%..%%...%%%%...%%..%%..........%%%%%...%%%%%%..%%%%%%..%%%%%..");
	lines.push_back("..%%%%...%%..%%..%%..%%..........%%..%%....%%....%%......%%..%%.");
	lines.push_back("...%%....%%..%%..%%..%%..........%%..%%....%%....%%%%....%%..%%.");
	lines.push_back("...%%....%%..%%..%%..%%..........%%..%%....%%....%%......%%..%%.");
	lines.push_back("...%%.....%%%%....%%%%...........%%%%%...%%%%%%..%%%%%%..%%%%%..");

	for (auto&line : lines)
		PlaceGenTxt(Ix, Iy++, line, bgcolor, fgcolor);
}

void Frame::PlaceExampleMap(int Ix1, int Iy1){
	int x2 = Ix1 + 34;
	int y2 = Iy1 + 20;
	PlaceBox(Ix1, Iy1, x2, y2, Black, DarkYellow);

	ColoredCharacter grass(Black, DarkGreen, char(177));
	ColoredCharacter dirt(Black, DarkYellow, char(177));
	ColoredCharacter bush(DarkGreen, Green, char(5));
	ColoredCharacter water(DarkBlue, Blue, char(247));
	ColoredCharacter Player(Black, Yellow, '@');
	ColoredCharacter MUnknown(Black, Red, '?');
   

	for (int bx = Ix1 + 1; bx < x2; bx++)
		for (int by = Iy1 + 1; by < y2; by++)
			frame[bx][by] = grass;

	frame[Ix1 +  4][Iy1 +  4] = dirt;
	frame[Ix1 + 14][Iy1 +  3] = dirt;
	frame[Ix1 +  8][Iy1 +  6] = dirt;
	frame[Ix1 + 15][Iy1 + 10] = dirt;
	frame[Ix1 + 11][Iy1 + 15] = dirt;
	frame[Ix1 + 30][Iy1 +  8] = dirt;
	frame[Ix1 + 25][Iy1 + 13] = dirt;
	frame[Ix1 + 17][Iy1 + 11] = bush;
	frame[Ix1 + 30][Iy1 +  8] = bush;
	frame[Ix1 + 20][Iy1 +  2] = bush;
	frame[Ix1 + 18][Iy1 +  1] = water;
	frame[Ix1 + 17][Iy1 +  2] = water;
	frame[Ix1 + 18][Iy1 +  2] = water;
	frame[Ix1 + 18][Iy1 +  3] = water;
	frame[Ix1 + 19][Iy1 +  3] = water;
	frame[Ix1 + 17][Iy1 +  4] = water;
	frame[Ix1 + 18][Iy1 +  4] = water;
	frame[Ix1 + 16][Iy1 +  5] = water;
	frame[Ix1 + 17][Iy1 +  5] = water;
	frame[Ix1 + 15][Iy1 +  6] = water;
	frame[Ix1 + 16][Iy1 +  6] = water;
	frame[Ix1 + 15][Iy1 +  7] = water;
	frame[Ix1 + 16][Iy1 +  7] = water;
	frame[Ix1 + 13][Iy1 +  8] = water;
	frame[Ix1 + 14][Iy1 +  8] = water;
	frame[Ix1 + 15][Iy1 +  8] = water;
	frame[Ix1 + 12][Iy1 +  9] = water;
	frame[Ix1 + 13][Iy1 +  9] = water;
	frame[Ix1 + 11][Iy1 + 10] = water;
	frame[Ix1 + 12][Iy1 + 10] = water;
	frame[Ix1 +  9][Iy1 + 11] = water;
	frame[Ix1 + 10][Iy1 + 11] = water;
	frame[Ix1 + 11][Iy1 + 11] = water;
	frame[Ix1 +  8][Iy1 + 12] = water;
	frame[Ix1 +  9][Iy1 + 12] = water;
	frame[Ix1 +  8][Iy1 + 13] = water;
	frame[Ix1 +  9][Iy1 + 13] = water;
	frame[Ix1 +  7][Iy1 + 14] = water;
	frame[Ix1 +  8][Iy1 + 14] = water;
	frame[Ix1 + 20][Iy1 +  9] = Player;
}
