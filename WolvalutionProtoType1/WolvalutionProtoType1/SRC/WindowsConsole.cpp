#include "WindowsConsole.hpp"
#include <iomanip>
#include <deque>
#include "ColoredCharacter.hpp"

WindowsConsole::WindowsConsole(){
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	AllocConsole();
	std::wstring strW = L"Wolvalution";
	SetConsoleTitle(strW.c_str());
	DrawMenuBar(GetConsoleWindow());
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);

	ChangeConsoleFont(ColorCode(Black, Green));
	ResizeConsoleBufferSize(HEIGHT + 1, WIDTH);
	ResizeConsolePixel(1000, 2000);
};

void WindowsConsole::txtCC(std::string text, int colorCode = White){
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD   index = 0;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	SetConsoleTextAttribute(hstdout, colorCode);
	std::cout << text;
	FlushConsoleInputBuffer(hstdin);
	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
}

void WindowsConsole::CCC(char c, int colorCode = White){
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD   index = 0;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	SetConsoleTextAttribute(hstdout, colorCode);
	std::cout << c;
	FlushConsoleInputBuffer(hstdin);
	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
}

void WindowsConsole::SetCursor(int Ix, int Iy){
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD homeCoords = { Ix, Iy };
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void WindowsConsole::ChangeCursorVisibility(bool visibility) //could just be a toggle function?{
	CursorVisibility = visibility;
//https://msdn.microsoft.com/en-us/library/windows/desktop/ms686019(v=vs.85).aspx
}

void WindowsConsole::GetConsoleData(){
	HWND console = GetConsoleWindow();
	RECT r;
	//stores the console's current dimensions
	//store the data outside the fuction later, to make work
	GetWindowRect(console, &r);
}

void WindowsConsole::ResizeConsolePixel(int height, int width){
	HWND console = GetConsoleWindow();
	MoveWindow(console, 0, 0, width, height, true);
}

void WindowsConsole::ResizeConsoleBufferSize(int height, int width){
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD ScreenSize = { width, height };
	SetConsoleScreenBufferSize(hStdOut, ScreenSize);
}

void WindowsConsole::ChangeConsoleFont(int colorcode){
	//changes color
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hstdout, colorcode);

	//attempts to change font
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);//you don't have to call this function every time
	CONSOLE_FONT_INFOEX font;//CONSOLE_FONT_INFOEX is defined in some windows header
	GetCurrentConsoleFontEx(outcon, false, &font);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
	font.dwFontSize.X = 12;
	font.dwFontSize.Y = 6;
	mbstowcs(font.FaceName,"Consolas", LF_FACESIZE);
	SetCurrentConsoleFontEx(outcon, false, &font);
	SetConsoleTextAttribute(outcon, colorcode);
}

void WindowsConsole::ChangeConsoleTextSize(){
	//GetConsoleMode?
	//SetConsoleCursorInfo
	//get function?
	//SetConsoleWindowInfo();
}

void WindowsConsole::ReturnConsole(){
	//returns postions back to the way it way before game started
	//MoveWindow(console, r.left, r.top, r.right - r.left, r.bottom - r.top, TRUE);
}

void WindowsConsole::ClearScreen(){
	for (int bx = 0; bx < WIDTH; bx++)
		for (int by = 0; by < HEIGHT; by++){
			CurrentConsoleDisplay[bx][by] = ColoredCharacter(Black, Black, ' ');
			BufferConsoleDisplay[bx][by] = ColoredCharacter(Black, Black, ' ');
		}
	std::string blank = "";
	for (int x = 0; x < WIDTH; x++)
		blank = blank + " ";

	for (int y = 0; y < HEIGHT; y++){
		SetCursor(0, 0 + y);
		std::cout << blank;
	}
}

void WindowsConsole::PrintCurrentMap(int Ix, int Iy, Screen IScreen) //check later{
	if (IScreen.CurrentMap().getName() == "Error")
		;//do nothing
	else
		PrintFrame(Ix, Iy, IScreen.CurrentMap());
}

void WindowsConsole::PrintFrame(int Ix, int Iy, Frame Iframe){
	for (int by = 0; by < Iframe.getHeight(); by++)
		for (int bx = 0; bx < Iframe.getWidth(); bx++)
			PrintColoredCharacter(Ix + bx, Iy + by, Iframe[bx][by]);
}

void WindowsConsole::PrintColoredCharacter(int Ix, int Iy, ColoredCharacter Ic){
	BufferConsoleDisplay[Ix][Iy] = Ic;

	if (CurrentConsoleDisplay[Ix][Iy] == BufferConsoleDisplay[Ix][Iy])
		;//do nothing
	else{
		SetCursor(Ix, Iy);
		CCC(Ic.getChar(), ColorCode(Ic.getBG(), Ic.getFG()));
		CurrentConsoleDisplay[Ix][Iy] = Ic;
	}

}

void WindowsConsole::PrintScreen(Screen aScreen){
	for (int i = 0; i < aScreen.printOrderLength(); i++){
		Frame Temp(aScreen.PopFrameFront());
		PrintFrame(Temp.getX(), Temp.getY(), Temp);
		aScreen.PushFrameBack(Temp);
	}
}

void WindowsConsole::PrintMap(int Ix, int Iy, Map aMap){
	Frame tempM("aMap", Ix, Iy, aMap);
	PrintFrame(Ix, Iy, tempM);
}
