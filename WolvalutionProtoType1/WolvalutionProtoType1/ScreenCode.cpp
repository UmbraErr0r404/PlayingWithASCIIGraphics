/*
Frame HomeBase("HomeBase", 0, 0, HEIGHT, WIDTH);
HomeBase.PlaceHLine(1, 13, 118, Black, DarkYellow);
HomeBase.PlaceBox(0, 0, WIDTH - 1, HEIGHT - 1, Black, DarkYellow);
HomeBase.PlaceGenTxt(27, 10, "Created by UW-Platteville Group: Software Wolves, in Class SE2730", Black, DarkBlue); //27, 10
HomeBase.PlaceWindowSceneArt(1, 14, Black, DarkYellow);
HomeBase.PlaceLogo(16, 3, Black, Green);
HomeBase.PlaceWindowMoonArt(1, 14, Black, Gray);
HomeBase.PlaceGenTxt(83, 48, "*Hint: Use space-bar and arrow keys", Black, Gray);
HomeBase.ExportFrame("HomeScreen.txt");
*/

/*
Frame PlaySelected("PlaySelected", 27, 21, 2, 6);
PlaySelected.PlaceGenTxt(0, 0, " Play ", Yellow, Black);
PlaySelected.PlaceGenTxt(0, 1, " Quit ", Black, Green);
PlaySelected.ExportFrame("PlaySelected.txt");
*/

/*
Frame QuitSelected("QuitSelected", 27, 21, 2, 6);
QuitSelected.PlaceGenTxt(0, 0, " Play ", Black, Green);
QuitSelected.PlaceGenTxt(0, 1, " Quit ", Yellow, Black);
QuitSelected.ExportFrame("QuitSelected.txt");
*/

/*
Frame IntroBase("IntroBase", 0, 0, HEIGHT, WIDTH);
IntroBase.PlaceBox(0, 0, 119, 48, Black, DarkYellow);
IntroBase.PlaceHLine(1, 11, 118, Black, DarkYellow);
IntroBase.PlaceHLine(1, 15, 118, Black, DarkYellow);
IntroBase.PlaceWhoAreYou(16, 2, Black, Green);
IntroBase.PlaceGenTxt(5, 13, ":> What is your name: ", Black, Green);
IntroBase.PlaceGenTxt(50, 17, "How to Play ", Black, Green);
IntroBase.PlaceExampleMap(80, 26);
IntroBase.PlaceGenTxt(78, 20, "You are the \"@\" character on the map.", Black, Green);
IntroBase.PlaceGenTxt(91, 20, "@", Black, Yellow);
IntroBase.PlaceGenTxt(78, 21, "Use either Arrow keys or WASD keys", Black, Green);
IntroBase.PlaceGenTxt(78, 22, "to move in-game.", Black, Green);
IntroBase.PlaceGenTxt(91, 25, "Example Map", Black, Green);
IntroBase.PlaceBox(3, 43, 71, 46, Black, DarkYellow);
IntroBase.PlaceGenTxt(5, 44, "After typing in your name, press the enter key to confirm it.", Black, Green);
IntroBase.PlaceGenTxt(5, 45, "Once you have entered your name press space-bar to start playing.", Black, Green);
IntroBase.PlaceGenTxt(8, 23, "In-Game HotKeys:", Black, Green);
IntroBase.PlaceGenTxt(5, 25, "\"I\": Inventory", Black, Green);
IntroBase.PlaceGenTxt(5, 26, "\"H\": Help Menu", Black, Green);
IntroBase.PlaceGenTxt(5, 27, "\"Q\": Quit Menu", Black, Green);
IntroBase.PlaceGenTxt(8, 31, "Character Stats:", Black, Green);
IntroBase.PlaceGenTxt(5, 33, "You have two main stats:", Black, Green);
IntroBase.PlaceGenTxt(5, 34, "Health and Laziness.", Black, Green);
IntroBase.PlaceGenTxt(5, 35, "If Health reaches zero", Black, Green);
IntroBase.PlaceGenTxt(5, 36, "or Laziness reaches max,", Black, Green);
IntroBase.PlaceGenTxt(5, 37, "you lose.", Black, Green);
IntroBase.PlaceGenTxt(44, 23, "In-Game Decision:", Black, Green);
IntroBase.PlaceGenTxt(38, 25, "While traveling in the map, you", Black, Green);
IntroBase.PlaceGenTxt(38, 26, "will occasionally be stopped.", Black, Green);
IntroBase.PlaceGenTxt(38, 28, "When this happens, you will have", Black, Green);
IntroBase.PlaceGenTxt(38, 29, "to pick from a list of options.", Black, Green);
IntroBase.PlaceGenTxt(38, 31, "The option you pick can effect", Black, Green);
IntroBase.PlaceGenTxt(38, 32, "your characters stats and/or ", Black, Green);
IntroBase.PlaceGenTxt(38, 33, "progress the game.", Black, Green);
IntroBase.PlaceGenTxt(38, 35, "Press the space-bar or enter key", Black, Green);
IntroBase.PlaceGenTxt(38, 36, "to confirm a selected option.", Black, Green);
IntroBase.ExportFrame("IntroScreen.txt");
*/

/*
Frame PlayGameBase("PlayGameBase", 0, 0, HEIGHT, WIDTH);
PlayGameBase.PlaceBox(0, 0, 119, 49, Black, DarkGreen);
PlayGameBase.PlaceGenTxt(50, 1, "Game State:", Black, Green);
PlayGameBase.PlaceHLine(1, 2, 118, Black, DarkGreen);
PlayGameBase.PlaceGenTxt(3, 33, "Area Text:", Black, Green);
PlayGameBase.PlaceGenTxt(3, 37, "Scenario Text:", Black, Green);
PlayGameBase.PlaceGenTxt(3, 41, ">:", Black, Green);
PlayGameBase.PlaceGenTxt(3, 43, ">:", Black, Green);
PlayGameBase.PlaceGenTxt(3, 45, ">:", Black, Green);
PlayGameBase.PlaceGenTxt(3, 47, ">:", Black, Green);
PlayGameBase.PlaceGenTxt(3, 30, "Heath: ", Black, DarkRed);
PlayGameBase.PlaceVLine(1, 30, 9, Black, DarkBlue);
PlayGameBase.PlaceVLine(57, 30, 1, Black, DarkBlue);
PlayGameBase.PlaceVLine(58, 30, 1, Black, DarkBlue);
PlayGameBase.PlaceVLine(59, 30, 1, Black, DarkBlue);
PlayGameBase.PlaceVLine(60, 30, 1, Black, DarkBlue);
PlayGameBase.PlaceGenTxt(62, 30, "Laziness: ", Black, DarkGreen);
PlayGameBase.PlaceVLine(118, 30, 9, Black, DarkBlue);
PlayGameBase.PlaceHLine(1, 29, 118, Black, DarkBlue);
PlayGameBase.PlaceHLine(1, 31, 118, Black, DarkBlue);
PlayGameBase.PlaceHLine(1, 35, 118, Black, DarkBlue);
PlayGameBase.PlaceHLine(1, 39, 118, Black, DarkBlue);
PlayGameBase.ExportFrame("PlayGameScreen.txt");
*/

/*
Frame WinFrame("WinFrame", 0, 0, HEIGHT, WIDTH);
WinFrame.PlaceBox(0, 0, 119, 49, Black, Green);
WinFrame.YouWin(32, 15, Black, Green);
WinFrame.ExportFrame("WinScreen.txt");
*/

/*
Frame LossBase("LossBase", 0, 0, HEIGHT, WIDTH);
LossBase.PlaceBox(0, 0, 119, 49, Black, Red);
LossBase.YouDied(28, 15, Black, Red);
LossBase.ExportFrame("LossScreen.txt");
*/

/*
Frame QuitMenuYes("QuitMenuYes", 45, 10, 8, 30);
QuitMenuYes.PlaceBox(0, 0, 29, 7, Black, DarkRed);
QuitMenuYes.PlaceGenTxt(9, 0, " Quit Menu ", Black, Red);
QuitMenuYes.PlaceGenTxt(3, 2, "Would you like to Quit?", Black, Red);
QuitMenuYes.PlaceGenTxt(6, 4, " Yes ", Yellow, Black);
QuitMenuYes.PlaceGenTxt(20, 4, "No", Black, DarkRed);
QuitMenuYes.ExportFrame("QuitMenuYes.txt");
*/

/*
Frame QuitMenuNo("QuitMenuNo", 45, 10, 8, 30);
QuitMenuNo.PlaceBox(0, 0, 29, 7, Black, DarkRed);
QuitMenuNo.PlaceGenTxt(9, 0, " Quit Menu ", Black, Red);
QuitMenuNo.PlaceGenTxt(3, 2, "Would you like to Quit?", Black, Red);
QuitMenuNo.PlaceGenTxt(6, 4, " Yes ", Black, DarkRed);
QuitMenuNo.PlaceGenTxt(19, 4, " No ", Yellow, Black);
QuitMenuNo.ExportFrame("QuitMenuNo.txt");
*/

/*
Frame HelpMenu("HelpMenu", 45, 10, 18, 30);
HelpMenu.PlaceBox(0, 0, 29, 17, Black, DarkCyan);
HelpMenu.PlaceGenTxt(9, 0, " Help Menu ", Black, Cyan);
HelpMenu.PlaceGenTxt(3, 2, "Game State: Walking", Black, Cyan);
HelpMenu.PlaceGenTxt(3, 3, "Use arrow keys or WASD", Black, DarkCyan);
HelpMenu.PlaceGenTxt(3, 4, "keys to move on the map.", Black, DarkCyan);
HelpMenu.PlaceGenTxt(3, 6, "Game State: Scenario", Black, Cyan);
HelpMenu.PlaceGenTxt(3, 7, "Use arrow keys or WASD", Black, DarkCyan);
HelpMenu.PlaceGenTxt(3, 8, "to change option.", Black, DarkCyan);
HelpMenu.PlaceGenTxt(3, 9, "Use space-bar or enter", Black, DarkCyan);
HelpMenu.PlaceGenTxt(3, 10, "to confirm selection.", Black, DarkCyan);
HelpMenu.PlaceGenTxt(3, 12, "In-Game HotKeys:", Black, Cyan);
HelpMenu.PlaceGenTxt(3, 13, "H: Close This Window", Black, DarkCyan);
HelpMenu.PlaceGenTxt(3, 14, "I: Inventory", Black, DarkCyan);
HelpMenu.PlaceGenTxt(3, 15, "Q: Quit", Black, DarkCyan);
HelpMenu.ExportFrame("HelpMenu.txt");
*/

/*
Frame Inventory("Inventory", 45, 10, 14, 30);
Inventory.PlaceBox(0, 0, 29, 13, Black, Yellow);
Inventory.PlaceGenTxt(9, 0, " Inventory ", Black, Yellow);
Inventory.PlaceGenTxt(3, 2, "1:", Black, Yellow);
Inventory.PlaceGenTxt(3, 3, "2:", Black, Yellow);
Inventory.PlaceGenTxt(3, 4, "3:", Black, Yellow);
Inventory.PlaceGenTxt(3, 5, "4:", Black, Yellow);
Inventory.PlaceGenTxt(3, 6, "5:", Black, Yellow);
Inventory.PlaceGenTxt(3, 7, "6:", Black, Yellow);
Inventory.PlaceGenTxt(3, 8, "7:", Black, Yellow);
Inventory.PlaceGenTxt(3, 9, "8:", Black, Yellow);
Inventory.PlaceGenTxt(3, 10, "9:", Black, Yellow);
Inventory.PlaceGenTxt(2, 11, "10:", Black, Yellow);
Inventory.ExportFrame("Inventory.txt");
*/

//----------------------------------------------------------------------------------------------------------------


for (int h = 0; h < CHealth; h++)
CCC(IC(219), Red); //heart is 3
SetCursor(72, 4);
for (int s = 0; s < (MaxStamina - CStamina); s++)
CCC(IC(219), Green); //diamond is 4



bool det = false;
char key = ' '; //called for storing char key presses
bool QuitSelect = false;
bool PlaySelect = true;

while (det == false)
{
key = getch();

if (key == 'w' || key == 'W') //w key
{
if (QuitSelect)
{
Console.PrintFrame(QuitSelected.getX(), QuitSelected.getY(), QuitSelected);
QuitSelect = false;
PlaySelect = true;
}
else if (PlaySelect)
{
Console.PrintFrame(PlaySelected.getX(), PlaySelected.getY(), PlaySelected);
QuitSelect = true;
PlaySelect = false;
}
}
if (key == 's' || key == 'S') //s key
{
if (QuitSelect)
{
Console.PrintFrame(QuitSelected.getX(), QuitSelected.getY(), QuitSelected);
QuitSelect = false;
PlaySelect = true;
}
else if (PlaySelect)
{
Console.PrintFrame(PlaySelected.getX(), PlaySelected.getY(), PlaySelected);
QuitSelect = true;
PlaySelect = false;
}
}
if (key == 32 || key == 13) //space-bar or enter
{
if (QuitSelect)
{
Console.PrintColoredCharacter(WIDTH - 1, HEIGHT - 1, ColoredCharacter(Red, Black, 'E'));
exit(0);
}
else if (PlaySelect)
{
det = true;
}
}
}
*/


/*
bool HomeScreenSelection = true;
bool Intro = true;
bool Play = true;

bool QuitSelect = false;
bool PlaySelect = true;



if (HomeScreenSelection)
{
PrintLogo(16, 3);
PrintTeamDip(27, 10);
PrintBox(0, 0, 119, 48, ColorCode(Black, DarkYellow));
PrintHLine(1, 13, 118, ColorCode(Black, DarkYellow));
PrintWindowSceneArt(1, 14, ColorCode(Black, DarkYellow));
PrintWindowMoonArt(1, 14, ColorCode(Black, White));
PrintTxtPlaySelect(27, 21);
PrintTxtQuit(27, 22);
while (HomeScreenSelection)
{
x = getch();

if (x == 'w' || x == 'W') //w key
{
if (QuitSelect)
{
PrintTxtPlaySelect(27, 21);
PrintTxtQuit(27, 22);
QuitSelect = false;
PlaySelect = true;
}
else if (PlaySelect)
{
PrintTxtPlay(27, 21);
PrintTxtQuitSelect(27, 22);
QuitSelect = true;
PlaySelect = false;
}
}
if (x == 's' || x == 'S') //s key
{
if (QuitSelect)
{
PrintTxtPlaySelect(27, 21);
PrintTxtQuit(27, 22);
QuitSelect = false;
PlaySelect = true;
}
else if (PlaySelect)
{
PrintTxtPlay(27, 21);
PrintTxtQuitSelect(27, 22);
QuitSelect = true;
PlaySelect = false;
}
}
if (x == 32) //space-bar
{
if (QuitSelect)
{
Intro = false;
Play = false;
HomeScreenSelection = false;
ClearScreen(50, 120);
SetCursor(0, 0);
}
else if (PlaySelect)
{
HomeScreenSelection = false;
}
}
if (x == 13) //buggy enter key
{
if (QuitSelect)
{
Intro = false;
Play = false;
HomeScreenSelection = false;
ClearScreen(50, 120);
SetCursor(0, 0);
}
else if (PlaySelect)
{
HomeScreenSelection = false;
}
}

if (x == -32) //arrow keys intro
{
switch (_getch())
{
case 72: //up key
if (QuitSelect)
{
PrintTxtPlaySelect(27, 21);
PrintTxtQuit(27, 22);
QuitSelect = false;
PlaySelect = true;
}
else if (PlaySelect)
{
PrintTxtPlay(27, 21);
PrintTxtQuitSelect(27, 22);
QuitSelect = true;
PlaySelect = false;
}
break;
case 80: //down key
if (QuitSelect)
{
PrintTxtPlaySelect(27, 21);
PrintTxtQuit(27, 22);
QuitSelect = false;
PlaySelect = true;
}
else if (PlaySelect)
{
PrintTxtPlay(27, 21);
PrintTxtQuitSelect(27, 22);
QuitSelect = true;
PlaySelect = false;
}
break;
}
}
}
}


if (Intro == true)
{
ClearScreen(50, 120);
std::string name = " ";

PrintBox(0, 0, 119, 48, ColorCode(Black, DarkYellow));
PrintHLine(1, 11, 118, ColorCode(Black, DarkYellow));
PrintHLine(1, 15, 118, ColorCode(Black, DarkYellow));
PrintWhoAreYou(16, 2, ColorCode(Black, Green));
PrintGenTxt(5, 13, ":> What is your name: ", ColorCode(Black, Green));
PrintGenTxt(50, 17, "How to Play ", ColorCode(Black, Green));

PrintExampleMap(80, 26);

PrintGenTxt(78, 20, "You are the \"@\" character on the map", ColorCode(Black, Green));
PrintGenTxt(91, 20, "@", ColorCode(Black, Yellow));
PrintGenTxt(78, 21, "Use either Arrow keys or WASD keys", ColorCode(Black, Green));
PrintGenTxt(78, 22, "to move in Game.", ColorCode(Black, Green));

PrintGenTxt(91, 25, "Example Map", ColorCode(Black, Green));


PrintBox(3, 43, 71, 46, ColorCode(Black, DarkYellow));
PrintGenTxt(5, 44, "After typing in your name, press: \"enter\", to confirm it.", ColorCode(Black, Green));
PrintGenTxt(5, 45, "Once you have entered your name press space-bar to start playing.", ColorCode(Black, Green));



PrintGenTxt(8, 23, "In Game HotKeys:", ColorCode(Black, Green));
PrintGenTxt(5, 25, "\"I\": Inventory", ColorCode(Black, Green));
PrintGenTxt(5, 26, "\"H\": Help Menu", ColorCode(Black, Green));
PrintGenTxt(5, 27, "\"Q\": Quit Menu", ColorCode(Black, Green));

PrintGenTxt(8, 31, "Character Stats:", ColorCode(Black, Green));
PrintGenTxt(5, 33, "You have two main stats", ColorCode(Black, Green));
PrintGenTxt(5, 34, "Health and Laziness", ColorCode(Black, Green));
PrintGenTxt(5, 35, "If Health reaches zero", ColorCode(Black, Green));
PrintGenTxt(5, 36, "or Laziness reaches max", ColorCode(Black, Green));
PrintGenTxt(5, 37, "you loss.", ColorCode(Black, Green));

PrintGenTxt(44, 23, "In Game Decision:", ColorCode(Black, Green));

PrintGenTxt(38, 25, "While traveling in the map, you", ColorCode(Black, Green));
PrintGenTxt(38, 26, "will occasionally be stopped.", ColorCode(Black, Green));
PrintGenTxt(38, 27, "When this happens you will have", ColorCode(Black, Green));
PrintGenTxt(38, 28, "to pick from a list of options.", ColorCode(Black, Green));

PrintGenTxt(38, 30, "The option you pick can effect", ColorCode(Black, Green));
PrintGenTxt(38, 31, "your characters state or ", ColorCode(Black, Green));
PrintGenTxt(38, 32, "Progress the game", ColorCode(Black, Green));

PrintGenTxt(38, 34, "Press the space-bar or enter to", ColorCode(Black, Green));
PrintGenTxt(38, 35, "confirm a selected option", ColorCode(Black, Green));

SetCursor(27, 13);
std::cin >> name;
SetCursor(70, 45);

while (Intro)
{
x = getch();

if (x == 32) //space-bar
{
Intro = false;
}
}

ClearScreen(50, 120);


}
if (Play)
{
int MaxHealth = 45;
int MaxStamina = 45;
int CHealth = 45;
int CStamina = 40;
bool GameStatechocie = false;
bool GameStateWalking = true;
bool Op1Select = true;
bool Op2Select = false;
bool Op3Select = false;

DisplayableChar Testdirt(DarkYellow, Black, IC(176));
DisplayableChar Testbush(DarkGreen, Green, IC(5));
DisplayableChar Testwater(DarkBlue, Blue, IC(247));
DisplayableChar bridgeFloor(Black, Gray, IC(177));
DisplayableChar bridgeWall(Gray, DarkYellow, IC(205));
//std::string Pname, std::string Pdip, DisplayableChar PChar,
//bool walkable, bool IsEvent, std::string EDip, std::string Op1,
//std::string Op2, std::string Op3)

MapSquare GenEvent("Guess", "You find a old man in a bush", Testbush, true,
true, "Old Man: I swear, nothing will happen", "Stare", "Do nothing", "Leave");

Map PlayTestMap(39, 37);

PlayTestMap.PlaceMapSquare(25, 25, GenEvent);
PlayTestMap.PlaceMapSquare(3, 5, GenEvent);
PlayTestMap.PlaceMapSquare(10, 19, GenEvent);

PrintBox(0, 0, 119, 48, ColorCode(Black, DarkGreen));
PrintGenTxt(50, 1, "Game State:", ColorCode(Black, Green));
PrintHLine(1, 2, 118, ColorCode(Black, DarkGreen));
PrintBox(2, 3, 58, 5, ColorCode(Black, DarkYellow)); //Health bar
PrintBox(61, 3, 117, 5, ColorCode(Black, DarkYellow)); //Lazy bar
PrintGenTxt(3, 4, "   Heath: ", ColorCode(Black, DarkRed));
PrintGenTxt(62, 4, "Laziness: ", ColorCode(Black, DarkGreen));
SetCursor(13, 4);
for (int h = 0; h < CHealth; h++)
CCC(IC(219), Red); //heart is 3
SetCursor(72, 4);
for (int s = 0; s < (MaxStamina - CStamina); s++)
CCC(IC(219), Green); //diamond is 4
PrintHLine(1, 6, 118, ColorCode(Black, DarkBlue));
PrintHLine(1, 8, 118, ColorCode(Black, DarkBlue));
PrintVLine(27, 7, 41, ColorCode(Black, DarkBlue));
PrintGenTxt(9, 7, "Commands:", ColorCode(Black, Green));
PrintVLine(77, 7, 41, ColorCode(Black, DarkBlue));
PrintGenTxt(42, 7, "Description Text:", ColorCode(Black, Green));
PrintGenTxt(96, 7, "Map:", ColorCode(Black, Green));
PlayTestMap.SetPlayerLocation(19, 20);
PlayTestMap.PrintMap(79, 10);

PrintGenTxt(3, 10, ">:", ColorCode(Black, Green));
PrintGenTxt(3, 12, ">:", ColorCode(Black, Green));
PrintGenTxt(3, 14, ">:", ColorCode(Black, Green));

//PrintGenTxt(3, 10, PlayTestMap.CurrentPlaceDip()  , ColorCode(Black, Green));
//MapSquare GenEvent("Guess", " You find a old man in a bush", Testbush, true,
//true, "Old Man: I swear, nothing will happen", "Stare", "Do nothing", "Leave");
while (Play)
{
MapSquare temp(PlayTestMap.CurrentSquare());
PrintGenTxt(30, 9, temp.ThisPlaceDip, ColorCode(Black, Green));

if (GameStateWalking)
{
Op1Select = true;
Op2Select = false;
Op3Select = false;
PrintGenTxt(62, 1, "Walking       ", ColorCode(Black, Green));
x = getch();

if (x == 'w' || x == 'W') //w key
PlayTestMap.MovePlayerUp();
if (x == 's' || x == 'S') //s key
PlayTestMap.MovePlayerDown();
if (x == 'a' || x == 'A') //s key
PlayTestMap.MovePlayerLeft();
if (x == 'd' || x == 'D') //s key
PlayTestMap.MovePlayerRight();
if (x == 'h' || x == 'H') //s key
{
bool helpmenu = true;
PrintBox(45, 30, 65, 35, ColorCode(Black, Blue));
PrintGenTxt(49, 33, "Help Menu", ColorCode(Black, Blue));
while (helpmenu)
{
x = getch();
if (x == 'h' || x == 'H')
helpmenu = false;
}
PrintGenTxt(45, 30, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 31, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 32, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 33, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 34, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 35, "                     ", ColorCode(Black, DarkBlue));
}
if (x == 'i' || x == 'I') //s key
{
bool InventoryMenu = true;
PrintBox(45, 30, 65, 35, ColorCode(Black, Yellow));
PrintGenTxt(49, 33, "Empty Inventory", ColorCode(Black, Yellow));
while (InventoryMenu)
{
x = getch();
if (x == 'i' || x == 'I')
InventoryMenu = false;
}
PrintGenTxt(45, 30, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 31, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 32, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 33, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 34, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 35, "                     ", ColorCode(Black, DarkBlue));
}
if (x == 'q' || x == 'Q') //s key
{
bool QuitMenu = true;
PrintBox(45, 30, 65, 35, ColorCode(Black, Red));
PrintGenTxt(49, 33, "Quit", ColorCode(Black, Red));
while (QuitMenu)
{
x = getch();
if (x == 'q' || x == 'Q')
QuitMenu = false;
}
PrintGenTxt(45, 30, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 31, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 32, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 33, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 34, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 35, "                     ", ColorCode(Black, DarkBlue));
}
if (x == -32) //arrow keys intro
{
x = _getch();
if (x = 72) //up arrow
PlayTestMap.MovePlayerUp();
if (x = 80) //down arrow
PlayTestMap.MovePlayerDown();
}
PlayTestMap.PrintMap(79, 10);
if (PlayTestMap.IsEventActive())
{
GameStateWalking = false;
GameStatechocie = true;
}
}
else if (GameStatechocie)
{
PrintGenTxt(62, 1, "Pick an Option", ColorCode(Black, Green));
MapSquare temp(PlayTestMap.CurrentSquare());
PrintGenTxt(30, 11, temp.eventDip, ColorCode(Black, Green));

if (Op1Select)
PrintGenTxt(6, 10, " " + temp.Option1 + " ", ColorCode(Yellow, Black));
else
PrintGenTxt(6, 10, " " + temp.Option1 + " ", ColorCode(Black, Green));

if (Op2Select)
PrintGenTxt(6, 12, " " + temp.Option2 + " ", ColorCode(Yellow, Black));
else
PrintGenTxt(6, 12, " " + temp.Option2 + " ", ColorCode(Black, Green));

if (Op3Select)
PrintGenTxt(6, 14, " " + temp.Option3 + " ", ColorCode(Yellow, Black));
else
PrintGenTxt(6, 14, " " + temp.Option3 + " ", ColorCode(Black, Green));

x = getch();

if (x == 'w' || x == 'W') //w key
{
if (Op1Select)
{
Op1Select = false;
Op2Select = false;
Op3Select = true;
}
else if (Op2Select)
{
Op1Select = true;
Op2Select = false;
Op3Select = false;
}
else if (Op3Select)
{
Op1Select = false;
Op2Select = true;
Op3Select = false;
}
}
if (x == 's' || x == 'S') //s key
{
if (Op1Select)
{
Op1Select = false;
Op2Select = true;
Op3Select = false;
}
else if (Op2Select)
{
Op1Select = false;
Op2Select = false;
Op3Select = true;
}
else if (Op3Select)
{
Op1Select = true;
Op2Select = false;
Op3Select = false;
}
}
if (x == 'h' || x == 'H') //s key
{
bool helpmenu = true;
PrintBox(45, 30, 65, 35, ColorCode(Black, Blue));
PrintGenTxt(49, 33, "Help Menu", ColorCode(Black, Blue));
while (helpmenu)
{
x = getch();
if (x == 'h' || x == 'H')
helpmenu = false;
}
PrintGenTxt(45, 30, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 31, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 32, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 33, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 34, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 35, "                     ", ColorCode(Black, DarkBlue));
}
if (x == 'i' || x == 'I') //s key
{
bool InventoryMenu = true;
PrintBox(45, 30, 65, 35, ColorCode(Black, Yellow));
PrintGenTxt(49, 33, "Empty Inventory", ColorCode(Black, Yellow));
while (InventoryMenu)
{
x = getch();
if (x == 'i' || x == 'I')
InventoryMenu = false;
}
PrintGenTxt(45, 30, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 31, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 32, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 33, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 34, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 35, "                     ", ColorCode(Black, DarkBlue));
}
if (x == 'q' || x == 'Q') //s key
{
bool QuitMenu = true;
PrintBox(45, 30, 65, 35, ColorCode(Black, Red));
PrintGenTxt(49, 33, "Quit", ColorCode(Black, Red));
while (QuitMenu)
{
x = getch();
if (x == 'q' || x == 'Q')
QuitMenu = false;
}
PrintGenTxt(45, 30, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 31, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 32, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 33, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 34, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 35, "                     ", ColorCode(Black, DarkBlue));
}
if (x == 32) //space-bar
{
if (Op1Select);
else if (Op2Select);
else if (Op3Select)
{
GameStatechocie = false;
GameStateWalking = true;
temp.Event = false;
PlayTestMap.PlaceMapSquare(PlayTestMap.XLocal(), PlayTestMap.YLocal(), temp);
}
}
if (x == 13) //enter key
{
if (Op1Select);
else if (Op2Select);
else if (Op3Select)
{
GameStatechocie = false;
GameStateWalking = true;
temp.Event = false;
PlayTestMap.PlaceMapSquare(PlayTestMap.XLocal(), PlayTestMap.YLocal(), temp);
}
}
}

PrintGenTxt(30, 9, "                                             ", ColorCode(Black, Green));
PrintGenTxt(30, 11, "                                             ", ColorCode(Black, Green));
PrintGenTxt(6, 10, "                ", ColorCode(Black, Black));
PrintGenTxt(6, 12, "                ", ColorCode(Black, Black));
PrintGenTxt(6, 14, "                ", ColorCode(Black, Black));

}
}
SetCursor(0, 0);
*/




//----------------------------------------------------------------------------------------------------------------
bool KeyListenerActionIntro()
{
x = getch();

if (x == 32) //space-bar
{
return true;
}
return false;
}

//Used to run Play Screen State Walking
bool KeyListenerActionWalk()
{
x = getch();

if (x == 'w' || x == 'W') //w key
PlayTestMap.MovePlayerUp();
if (x == 's' || x == 'S') //s key
PlayTestMap.MovePlayerDown();
if (x == 'a' || x == 'A') //s key
PlayTestMap.MovePlayerLeft();
if (x == 'd' || x == 'D') //s key
PlayTestMap.MovePlayerRight();
if (x == 'h' || x == 'H') //s key
{
helpCode();
}
if (x == 'i' || x == 'I') //s key
{
inventoryCode();
}
if (x == 'q' || x == 'Q') //s key
{
quitCode();
}


PlayTestMap.PrintMap(79, 10);
if (PlayTestMap.IsEventActive())
{
return false;
}
return true;
}


//Used to run Play Screen State Scenario
bool KeyListenerActionScenario()
{
x = getch();

if (x == 'w' || x == 'W') //w key
{
if (Op1Select)
{
Op1Select = false;
Op2Select = false;
Op3Select = true;
}
else if (Op2Select)
{
Op1Select = true;
Op2Select = false;
Op3Select = false;
}
else if (Op3Select)
{
Op1Select = false;
Op2Select = true;
Op3Select = false;
}
}
if (x == 's' || x == 'S') //s key
{
if (Op1Select)
{
Op1Select = false;
Op2Select = true;
Op3Select = false;
}
else if (Op2Select)
{
Op1Select = false;
Op2Select = false;
Op3Select = true;
}
else if (Op3Select)
{
Op1Select = true;
Op2Select = false;
Op3Select = false;
}
}
if (x == 'h' || x == 'H') //s key
{
helpCode();
}
if (x == 'i' || x == 'I') //s key
{
inventoryCode();
}
if (x == 'q' || x == 'Q') //s key
{
quitCode();
}
if (x == 32 || x == 13) //space-bar or enter
{
if (Op1Select);
else if (Op2Select);
else if (Op3Select)
{
GameStatechocie = false;
GameStateWalking = true;
temp.Event = false;
PlayTestMap.PlaceMapSquare(PlayTestMap.XLocal(), PlayTestMap.YLocal(), temp);
}
}
}




void quitCode()
{
bool QuitMenu = true;
PrintBox(45, 30, 65, 35, ColorCode(Black, Red));
PrintGenTxt(49, 33, "Quit", ColorCode(Black, Red));
while (QuitMenu)
{
x = getch();
if (x == 'q' || x == 'Q')
QuitMenu = false;
}
PrintGenTxt(45, 30, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 31, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 32, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 33, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 34, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 35, "                     ", ColorCode(Black, DarkBlue));
}

void inventoryCode()
{
bool InventoryMenu = true;
PrintBox(45, 30, 65, 35, ColorCode(Black, Yellow));
PrintGenTxt(49, 33, "Empty Inventory", ColorCode(Black, Yellow));
while (InventoryMenu)
{
x = getch();
if (x == 'i' || x == 'I')
InventoryMenu = false;
}
PrintGenTxt(45, 30, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 31, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 32, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 33, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 34, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 35, "                     ", ColorCode(Black, DarkBlue));
}

void helpCode()
{
bool helpmenu = true;
PrintBox(45, 30, 65, 35, ColorCode(Black, Blue));
PrintGenTxt(49, 33, "Help Menu", ColorCode(Black, Blue));
while (helpmenu)
{
x = getch();
if (x == 'h' || x == 'H')
helpmenu = false;
}
PrintGenTxt(45, 30, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 31, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 32, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 33, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 34, "                     ", ColorCode(Black, DarkBlue));
PrintGenTxt(45, 35, "                     ", ColorCode(Black, DarkBlue));
}
