/**
 * @file
 * @author Elizabeth Harasymiw <Elizabeth.Harasymiw@gmail.com>
 *
 * @section DESCRIPTION
 * This is the file that contains the main and where all the 
 * classes do therr main interactions. A large part of this 
 * code might be changed into a game engine file or class.
 */

#include <string>	
#include "Screen.hpp"
#include "Frame.hpp"
#include "ColoredCharacter.hpp"
#include "WindowsConsole.hpp"
#include "Option.hpp"
#include "Scenario.hpp"
#include "MapSquare.hpp"
#include "Map.hpp"

int main(int argc, char * argv[]){ 
	WindowsConsole Console;
	Frame HomeBase;
        HomeBase.ImportFrame(0, 0, "HomeScreen.txt", "HomeBase");
  Frame PlaySelected;
        PlaySelected.ImportFrame(27, 21, "PlaySelected.txt", "PlaySelected");
  Frame QuitSelected;                                           
        QuitSelected.ImportFrame(27, 21, "QuitSelected.txt", "QuitSelected");
  Frame IntroBase;
        IntroBase.ImportFrame(0, 0, "IntroScreen.txt", "IntroBase");
  Frame PlayGameBase;
        PlayGameBase.ImportFrame(0, 0, "PlayGameScreen.txt", "PlayGameBase");
  Frame WinBase;
        WinBase.ImportFrame(0, 0, "WinScreen.txt", "WinBase");
  Frame LossBase;
        LossBase.ImportFrame(0, 0, "LossScreen.txt", "LossBase");
  Frame QuitMenuYes;
        QuitMenuYes.ImportFrame(45, 10, "QuitMenuYes.txt", "QuitMenuYes");
  Frame QuitMenuNo;
        QuitMenuNo.ImportFrame(45, 10, "QuitMenuNo.txt", "QuitMenuNo");
  Frame HelpMenu;
        HelpMenu.ImportFrame(45, 10, "HelpMenu.txt", "HelpMenu");      
  Frame Inventory;
        Inventory.ImportFrame(45, 10, "Inventory.txt", "Inventory");

  Map IAmMap;

	ColoredCharacter BackPack(Black, DarkYellow, char(254));
	Option Back1(-15, -7, "NA", "Pick the backpack up and open it. You are curious as to what it may contain.", false);
	Option Back2(0, 0, "NA", "Walk right past it. There is no way your touching that thing!", false);
	Option Back3(0, -3, "NA", "You are scared and freeze!", false);
	Option Back4(5, -1, "NA", "You start to scream at the sun. You don\'t know why, but it just feels right!", false);
	Scenario BackPackSc(Back1, Back2, Back3, Back4, "You leave your house and discover a backpack of possibly helpful or harmful items. What do you do?", true);
	IAmMap.PlaceMapSquare( 8, 5, MapSquare(BackPackSc, BackPack, true, "There is a backpack on the ground"));

	ColoredCharacter Water(DarkBlue, Blue, char(247));
	IAmMap.PlaceMapSquare(8, 4, MapSquare(Scenario(), Water, false, "It is wet here"));
	IAmMap.PlaceMapSquare(8, 6, MapSquare(Scenario(), Water, false, "It is wet here"));


	Console.PrintFrame(HomeBase.getX(), HomeBase.getY(), HomeBase);
	Console.PrintFrame(PlaySelected.getX(), PlaySelected.getY(), PlaySelected);

	char key = ' ';
	bool HomeSelecting = true;
	bool QuitSelect = false;
	bool PlaySelect = true;

	//TODO: use a switch statement
	while (HomeSelecting){
		key = getch();
		if (key == 'w' || key == 'W'){
			if (QuitSelect){
				Console.PrintFrame(PlaySelected.getX(), PlaySelected.getY(), PlaySelected);
				QuitSelect = false;
				PlaySelect = true;
			}else if (PlaySelect){
				Console.PrintFrame(QuitSelected.getX(), QuitSelected.getY(), QuitSelected);
				QuitSelect = true;
				PlaySelect = false;
			}
		}else if (key == 's' || key == 'S'){
			if (QuitSelect){
				Console.PrintFrame(PlaySelected.getX(), PlaySelected.getY(), PlaySelected);
				QuitSelect = false;
				PlaySelect = true;
			}else if (PlaySelect){
				Console.PrintFrame(QuitSelected.getX(), QuitSelected.getY(), QuitSelected);
				QuitSelect = true;
				PlaySelect = false;
			}
		}else if (key == ' ' || key == '\n' || key == '\r'){
			if (QuitSelect)
				return 0;
			else if (PlaySelect)
				HomeSelecting = false;
		}
	}

	Console.ClearScreen();

	Console.PrintFrame(IntroBase.getX(), IntroBase.getY(), IntroBase);
	std::string name;
	Console.SetCursor(27, 13);
	std::cin >> name;
	Console.SetCursor(70, 45);
	bool IntroWait = true;
	while (IntroWait){
		key = getch();
		if (key == ' ')
			IntroWait = false;
	}

	Console.ClearScreen();

	Console.PrintFrame(PlayGameBase.getX(), PlayGameBase.getY(), PlayGameBase);
	Console.PrintMap(3, 4, IAmMap);

	bool PlayGame = true;
	bool walking = true;
	bool wonGame = false;
	bool loseGame = false;
	bool MenuOpen = false;
	bool OptionMenu = false;

	while (PlayGame){
		Console.SetCursor(14, 33);
		Console.txtCC("                                                                                                     ", ColorCode(Black, Purple));
		Console.SetCursor(14, 33);
		Console.txtCC(IAmMap.getPlayerMapSquare().getDescription(), ColorCode(Black, Purple));

		Console.SetCursor(62, 1);
		Console.txtCC("Walking      ", ColorCode(Black, Purple));

		for (int mh = 0; mh < IAmMap.getPlayerMAXHEALTH(); mh++){
			Console.SetCursor(9 + mh, 30);
			Console.CCC(' ', ColorCode(Black, Red));
		}
		for (int h = 0; h < IAmMap.getPlayerCurrentHealth(); h++){
			Console.SetCursor(9 + h, 30);
			Console.CCC(char(219), ColorCode(Black, Red));
		}
		for (int ms = 0; ms < IAmMap.getPlayerMAXSTAMINA(); ms++){
			Console.SetCursor(71 + ms, 30);
			Console.CCC(' ', ColorCode(Black, Green));
		}
		for (int h = 0; h < IAmMap.getPlayerMAXSTAMINA() - IAmMap.getPlayerCurrentStamina(); h++){
			Console.SetCursor(71 + h, 30);
			Console.CCC(char(219), ColorCode(Black, Green));
		}

		//TODO: use a switch statement
		while (walking){
			key = getch();
			if (key == 'w' || key == 'W'){
				IAmMap.MovePlayerNorth();
				Console.PrintMap(3, 4, IAmMap);
			}
			if (key == 's' || key == 'S'){
				IAmMap.MovePlayerSouth();
				Console.PrintMap(3, 4, IAmMap);
			}
			if (key == 'a' || key == 'A'){
				IAmMap.MovePlayerWest();
				Console.PrintMap(3, 4, IAmMap);
			}
			if (key == 'd' || key == 'D'){
				IAmMap.MovePlayerEast();
				Console.PrintMap(3, 4, IAmMap);
			}
			if (key == 'h' || key == 'H'){
				Console.PrintFrame(HelpMenu.getX(), HelpMenu.getY(), HelpMenu);
				MenuOpen = true;
				while (MenuOpen){
					key = getch();
					if (key == 'h' || key == 'H')
						MenuOpen = false;
				}
				Console.PrintMap(3, 4, IAmMap);
			}
			if (key == 'i' || key == 'I'){
				//TODO: I presume the next line is correct but typed badly.
				//      Correct it either way.
				Console.PrintFrame(Inventory.getX(), Inventory.getY(), Inventory);bool MenuOpen = true;
				MenuOpen = true;
				while (MenuOpen){
					key = getch();
					if (key == 'i' || key == 'I')
						MenuOpen = false;
				}
				Console.PrintMap(3, 4, IAmMap);
			}
			if (key == 'q' || key == 'Q'){
				Console.PrintFrame(QuitMenuYes.getX(), QuitMenuYes.getY(), QuitMenuYes);     
				bool YesSelect = true;
				bool NoSelect = false;
				MenuOpen = true;
				while (MenuOpen){
					key = getch();
					if (key == 'A' || key == 'a' || key == 'D' || key == 'd'){
						YesSelect = !YesSelect;
						NoSelect = !NoSelect;
						if(YesSelect)
							Console.PrintFrame(QuitMenuYes.getX(), QuitMenuYes.getY(), QuitMenuYes);
						if (NoSelect)
							Console.PrintFrame(QuitMenuNo.getX(), QuitMenuNo.getY(), QuitMenuNo);
					}
					if (key == ' ' || key == '\r' || key == '\n')
						MenuOpen = false;                  
				}
				if (YesSelect)
					return 0;
				if (NoSelect)
					Console.PrintMap(3, 4, IAmMap);
			}
			Console.SetCursor(14, 33);
			Console.txtCC("                                                                                                     ", ColorCode(Black, Purple));
			Console.SetCursor(14, 33);
			Console.txtCC(IAmMap.getPlayerMapSquare().getDescription(), ColorCode(Black, Purple));

			walking = !IAmMap.getPlayerMapSquare().getScenario().getIsActive();

		}

		Console.SetCursor(62, 1);
		Console.txtCC("Scenario      ", ColorCode(Black, Purple));

		Console.SetCursor(18, 37);
		Console.txtCC(IAmMap.getPlayerMapSquare().getScenario().getMyDescription(), ColorCode(Black, Purple));

		OptionMenu = true;
		//TODO: OptionListB is just an int%4
		bool OptionListB[4]{ true, false, false, false };
		Option OptionListO[4]{ IAmMap.getPlayerMapSquare().getScenario().getMyOption1(),
				IAmMap.getPlayerMapSquare().getScenario().getMyOption2(),
				IAmMap.getPlayerMapSquare().getScenario().getMyOption3(),
				IAmMap.getPlayerMapSquare().getScenario().getMyOption4() };
		int currentOption = 0;

		//TODO: use a switch statement
		while(OptionMenu){
			for (int olist = 0; olist < 4; olist++){
				Console.SetCursor(6, 41 + (2 * olist));
				if (OptionListB[olist])
					Console.txtCC(OptionListO[olist].getMyText(), ColorCode(Yellow, Black));
				else
					Console.txtCC(OptionListO[olist].getMyText(), ColorCode(Black, Purple));
			}
			key = getch();
			if (key == 'W' || key == 'w'){
				OptionListB[currentOption] = false;
				if (currentOption == 0){
					currentOption = 3;
					OptionListB[currentOption] = true;
				}else{
					currentOption--;
					OptionListB[currentOption] = true;
				}
			}
			if (key == 'S' || key == 's'){
				OptionListB[currentOption] = false;
				if (currentOption == 3){
					currentOption = 0;
					OptionListB[currentOption] = true;
				}else{
					currentOption++;
					OptionListB[currentOption] = true;
				}
			}
			if (key == ' ' || key == '\n' || key == '\r')
				OptionMenu = false;
		}
		Console.SetCursor(18, 37);
		Console.txtCC("                                                                                                   ", ColorCode(Black, Purple));
		for (int olist = 0; olist < 4; olist++){
			Console.SetCursor(6, 41 + (2 * olist));
			Console.txtCC("                                                                                                             ", ColorCode(Black, Purple));
		}
		MapSquare temp(IAmMap.getPlayerMapSquare());
		temp.DeActiveScenario();
		IAmMap.PlaceMapSquare(IAmMap.getMyPlayerXLocation(), IAmMap.getMyPlayerYLocation(), temp);
		walking = true;

		for (int olist = 0; olist < 4; olist++)
			if (OptionListB[olist]){
				if (OptionListO[olist].getHealthChange() + IAmMap.getPlayerCurrentHealth() <= IAmMap.getPlayerMAXHEALTH())
					IAmMap.modifyPlayerHealth(OptionListO[olist].getHealthChange());
				else
					IAmMap.modifyPlayerHealth(IAmMap.getPlayerMAXHEALTH() - IAmMap.getPlayerCurrentHealth());

				if (OptionListO[olist].getStaminaChange() + IAmMap.getPlayerCurrentStamina() <= IAmMap.getPlayerMAXSTAMINA())
					IAmMap.modifyPlayerStamina(OptionListO[olist].getStaminaChange());
				else
					IAmMap.modifyPlayerHealth(IAmMap.getPlayerMAXSTAMINA() - IAmMap.getPlayerCurrentStamina());

				if (OptionListO[olist].getMyItem() == "Winning")
					wonGame = true;
				if (IAmMap.getPlayerCurrentHealth() <= 0)
					loseGame = true;
				if(IAmMap.getPlayerCurrentStamina() <= 0)
					loseGame = true;
			}

		//TODO: If this || holds true all of the time, should there only
		//      exist 2 bools to hold the value, not 3?
		if(wonGame || loseGame)
			PlayGame = false;     
	}

	Console.ClearScreen();

	if (wonGame)
		Console.PrintFrame(WinBase.getX(), WinBase.getY(), WinBase);
	else
		Console.PrintFrame(LossBase.getX(), LossBase.getY(), LossBase);

	//TODO: Make a slection to playagain or quit

	return 0; 
}
