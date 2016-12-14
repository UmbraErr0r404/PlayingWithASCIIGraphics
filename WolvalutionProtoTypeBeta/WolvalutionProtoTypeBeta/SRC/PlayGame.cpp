#include <string>	
#include "Frame.hpp"
#include "ColoredCharacter.hpp"
#include "WindowsConsole.hpp"
#include "Option.hpp"
#include "Scenario.hpp"
#include "MapSquare.hpp"
#include "Map.hpp"

void HomeScreenMenu(WindowsConsole &Console, Frame PlaySelected, Frame QuitSelected);
void IntroScreenInput(WindowsConsole &Console);
bool PlayGame(WindowsConsole &Console, Map &aMap, Frame HelpMenu, Frame Inventory, Frame QuitMenuYes, Frame QuitMenuNo);
void UpdatePlayGameDisplay(WindowsConsole &Console, Map &aMap);
void MovePlayer(WindowsConsole &Console, Map &aMap, char key);
void Help(WindowsConsole &Console, Map &aMap, Frame HelpMenu, char key);
void InventoryMenu(WindowsConsole &Console, Map &aMap, Frame Inventory, char key);
void QuitMenu(WindowsConsole &Console, Map &aMap, Frame QuitMenuYes, Frame QuitMenuNo, char key);
void UpdateDescription(WindowsConsole &Console, Map &aMap);
void UpdateScenario(WindowsConsole &Console, Map &aMap);
int OptionMenu(WindowsConsole &Console, Map &aMap);
void ClearOptions(WindowsConsole &Console);

int main(int argc, char * argv[])
{ 
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

   ColoredCharacter Wall(Black, DarkYellow, char(219));
   IAmMap.PlaceMapSquare(1, 2, MapSquare(Scenario(), Wall, false, "Your in a Wall... 0.0"));
   IAmMap.PlaceMapSquare(1, 3, MapSquare(Scenario(), Wall, false, "Your in a Wall... 0.0"));
   IAmMap.PlaceMapSquare(1, 4, MapSquare(Scenario(), Wall, false, "Your in a Wall... 0.0"));
   IAmMap.PlaceMapSquare(1, 5, MapSquare(Scenario(), Wall, false, "Your in a Wall... 0.0"));   
   IAmMap.PlaceMapSquare(1, 6, MapSquare(Scenario(), Wall, false, "Your in a Wall... 0.0"));
   IAmMap.PlaceMapSquare(2, 2, MapSquare(Scenario(), Wall, false, "Your in a Wall... 0.0"));
   IAmMap.PlaceMapSquare(3, 2, MapSquare(Scenario(), Wall, false, "Your in a Wall... 0.0"));
   IAmMap.PlaceMapSquare(4, 2, MapSquare(Scenario(), Wall, false, "Your in a Wall... 0.0"));
   IAmMap.PlaceMapSquare(4, 3, MapSquare(Scenario(), Wall, false, "Your in a Wall... 0.0"));
   IAmMap.PlaceMapSquare(2, 6, MapSquare(Scenario(), Wall, false, "Your in a Wall... 0.0"));
   IAmMap.PlaceMapSquare(3, 6, MapSquare(Scenario(), Wall, false, "Your in a Wall... 0.0"));
   IAmMap.PlaceMapSquare(4, 6, MapSquare(Scenario(), Wall, false, "Your in a Wall... 0.0"));
   IAmMap.PlaceMapSquare(4, 5, MapSquare(Scenario(), Wall, false, "Your in a Wall... 0.0"));

   ColoredCharacter HouseFloor(Black, DarkYellow, char(206));
   IAmMap.PlaceMapSquare(2, 3, MapSquare(Scenario(), HouseFloor, true, "You are in your house."));
   IAmMap.PlaceMapSquare(2, 4, MapSquare(Scenario(), HouseFloor, true, "You are in your house."));
   IAmMap.PlaceMapSquare(2, 5, MapSquare(Scenario(), HouseFloor, true, "You are in your house."));
   IAmMap.PlaceMapSquare(3, 3, MapSquare(Scenario(), HouseFloor, true, "You are in your house."));
   IAmMap.PlaceMapSquare(3, 4, MapSquare(Scenario(), HouseFloor, true, "You are in your house."));
   IAmMap.PlaceMapSquare(3, 5, MapSquare(Scenario(), HouseFloor, true, "You are in your house."));

   ColoredCharacter Door(Black, DarkYellow, char(179));
   IAmMap.PlaceMapSquare(4, 4, MapSquare(Scenario(), Door, true, "You open the door, and stand in the doorway."));

   ColoredCharacter BackPack(Black, DarkYellow, '.');
   Option Back1(-15, -7, "NA", "Pick the backpack up and open it. You are curious as to what it may contain.", false);
   Option Back2(0, 0, "NA", "Walk right past it. There is no way your touching that thing!", false);
   Option Back3(0, -3, "NA", "You are scared and freeze!", false);
   Option Back4(5, -1, "NA", "You start to scream at the sun. You don\'t know why, but it just feels right!", false);
   Scenario BackPackSc(Back1, Back2, Back3, Back4, "You leave your house and discover a backpack of possibly helpful or harmful items. What do you do?", true);
   IAmMap.PlaceMapSquare(5, 4, MapSquare(BackPackSc, BackPack, true, "There is a backpack on the ground"));

   ColoredCharacter DirtPath(Black, DarkYellow, char(177));
   IAmMap.PlaceMapSquare(6, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(7, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(8, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(9, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(10, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(11, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(12, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(13, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(14, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(15, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(16, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));   
   IAmMap.PlaceMapSquare(17, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(18, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(19, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(20, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(21, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(22, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(23, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(24, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(25, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(26, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(27, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));
   IAmMap.PlaceMapSquare(28, 4, MapSquare(Scenario(), DirtPath, true, "You are on a dirt Path."));

   ColoredCharacter Doe(Black, DarkYellow, char(139));
   Option Doe1(-10, 0, "NA", "You ask, \"How does it feel to not have horns ? \"", false);
   Option Doe2(-10, 0, "NA", "Stranger Danger!!! Run away.", false);
   Option Doe3(0, -10, "NA", "You start to freak out. You think that you must be on some kind of drug!", false);
   Option Doe4(0, 0, "NA", "You listen to what she has to say.", false);
   Scenario DoeSc(Doe1, Doe2, Doe3, Doe4, "You are walking along a path and come upon a Doe named John. She approaches you and starts to talk.", true);
   IAmMap.PlaceMapSquare(13, 5, MapSquare(DoeSc, Doe, true, "There is a Doe on the path."));

   ColoredCharacter Harambre(Black, Blue, 'M');
   Option Harambre1(0, -10, "NA", "You stand there for a second and remember Harambre.", false);
   Option Harambre2(10, 0, "NA", "You hide your sadness", false);
   Option Harambre3(20, 0, "NA", "Your eyes slowly fill up with tears and you begin to weep.", false);
   Option Harambre4(0, -10, "NA", "You write a letter to President Trump for spending taxpayer money on silly things, like \"The Wall\".", false);
   Scenario HarambreSc(Harambre1, Harambre2, Harambre3, Harambre4, "You see a monument to Harambre. What do you do?", true);
   IAmMap.PlaceMapSquare(16, 3, MapSquare(HarambreSc, Harambre, true, "You are standing in front of a monument of Harambre."));

   ColoredCharacter Rae404(Black, DarkPurple, '#');
   Option Rae4041(0, 0, "NA", "You sing along to his famous song \"No Type\".", false);
   Option Rae4042(-20, 0, "NA", "You Dab.", false);
   Option Rae4043(-10, 0, "NA", "Walk away because you don't like rap music.", false);
   Option Rae4044(0, -10, "NA", "You wonder why a rapper would only dedicate his songs to coding problems and shake your head in disappointment.", false);
   Scenario Rae404Sc(Rae4041, Rae4042, Rae4043, Rae4044, "In the distance you hear loud rap music, Rae 404 Name Not Found is performing.", true);
   IAmMap.PlaceMapSquare(19, 5, MapSquare(Rae404Sc, Rae404, true, "You are standing on a music platform"));

   ColoredCharacter Bridge(Black, DarkCyan, '&');
   Option Bridge1(-100, -100, "NA", "I don't know that!", false);
   Option Bridge2(-100, -100, "NA", "Blue", false);
   Option Bridge3(0, 0, "NA", "What do you mean? An African or European swallow?", false);
   Option Bridge4(-40, -40, "NA", "You cry in the corner.", false);
   Scenario BridgeSc(Bridge1, Bridge2, Bridge3, Bridge4, "The keeper asks you: What is the air-speed velocity of an unladen swallow?", true);
   IAmMap.PlaceMapSquare(29, 4, MapSquare(BridgeSc, Bridge, true, "You stand before the Bridge of Death"));

   ColoredCharacter WereWolf(Black, DarkPurple, 'W');
   Option WereWolf1(-100, 0, "NA", "You say, \"give me the antidote.\"", false);
   Option WereWolf2(0, 0, "Winning", "You ask him, \"Do you want to hear a pun ? \"", false);
   Option WereWolf3(-100, 0, "NA", "You say, \"I see you.\"", false);
   Option WereWolf4(-100, 0, "NA", "You get scared and cry.", false);
   Scenario WereWolfSc(WereWolf1, WereWolf2, WereWolf3, WereWolf4, "You see the Software Wolf and you walk up to him.", true);
   IAmMap.PlaceMapSquare(34, 4, MapSquare(WereWolfSc, WereWolf, true, "You stand before a Software Wolf"));

   ColoredCharacter Water(DarkBlue, Blue, char(247));
   IAmMap.PlaceMapSquare(30, 0, MapSquare(Scenario(), Water, false, "It is wet here"));
   IAmMap.PlaceMapSquare(30, 1, MapSquare(Scenario(), Water, false, "It is wet here"));
   IAmMap.PlaceMapSquare(30, 2, MapSquare(Scenario(), Water, false, "It is wet here"));
   IAmMap.PlaceMapSquare(30, 3, MapSquare(Scenario(), Water, false, "It is wet here"));
   IAmMap.PlaceMapSquare(30, 5, MapSquare(Scenario(), Water, false, "It is wet here"));
   IAmMap.PlaceMapSquare(30, 6, MapSquare(Scenario(), Water, false, "It is wet here"));
   IAmMap.PlaceMapSquare(30, 7, MapSquare(Scenario(), Water, false, "It is wet here"));
   IAmMap.PlaceMapSquare(30, 8, MapSquare(Scenario(), Water, false, "It is wet here"));
   IAmMap.PlaceMapSquare(30, 9, MapSquare(Scenario(), Water, false, "It is wet here"));

   Console.PrintFrame(HomeBase.getX(), HomeBase.getY(), HomeBase);
   Console.PrintFrame(PlaySelected.getX(), PlaySelected.getY(), PlaySelected);
   HomeScreenMenu(Console, PlaySelected, QuitSelected);

   Console.ClearScreen();

   Console.PrintFrame(IntroBase.getX(), IntroBase.getY(), IntroBase);
   IntroScreenInput(Console);

   Console.ClearScreen();

   Console.PrintFrame(PlayGameBase.getX(), PlayGameBase.getY(), PlayGameBase);
   Console.PrintMap(3, 4, IAmMap);

   if (PlayGame(Console, IAmMap, HelpMenu, Inventory, QuitMenuYes, QuitMenuNo))
      Console.PrintFrame(WinBase.getX(), WinBase.getY(), WinBase);
   else
      Console.PrintFrame(LossBase.getX(), LossBase.getY(), LossBase);

   char key = ' ';
   key = getch(); //wait beforeing closing after won or lost

   return 0; 
}

void HomeScreenMenu(WindowsConsole &Console, Frame PlaySelected, Frame QuitSelected)
{
   char key = ' ';
   bool FrameListB[2]{ true, false };
   Frame FrameListS[2]{ PlaySelected, QuitSelected };
   int currentOption = 0;
   bool HomeSelecting = true;

   while (HomeSelecting)
   {
      for (int flist = 0; flist < 2; flist++)
         if (FrameListB[flist])
            Console.PrintFrame(FrameListS[flist].getX(), FrameListS[flist].getY(), FrameListS[flist]);
      key = getch();
      if (key == 'w' || key == 'W' || key == 's' || key == 'S')
      {
         FrameListB[currentOption] = false;
         if(currentOption == 0)
            currentOption = 1;
         else
            currentOption = 0;
         FrameListB[currentOption] = true;
      }
      if (key == 32 || key == 13) //space-bar or enter
         if (FrameListB[1])
            exit(0);
         else
            HomeSelecting = false;
   }
}

void IntroScreenInput(WindowsConsole &Console)
{
   char key = ' ';
   std::string name;
   Console.SetCursor(27, 13);
   std::cin >> name;
   Console.SetCursor(70, 45);
   bool IntroWait = true;

   while (IntroWait)
   {
      key = getch();
      if (key == 32) //space-bar
         IntroWait = false;
   }
}

bool PlayGame(WindowsConsole &Console, Map &aMap, Frame HelpMenu, Frame Inventory, Frame QuitMenuYes, Frame QuitMenuNo)
{
   char key = ' ';
   bool PlayGame = true, walking = true, MenuOpen = false;
   while (PlayGame)
   {
      while (walking)
      {
         Console.PrintMap(3, 4, aMap);
         key = getch();
         MovePlayer(Console, aMap, key);
         Help(Console, aMap, HelpMenu, key);
         InventoryMenu(Console, aMap, Inventory, key);
         QuitMenu(Console, aMap, QuitMenuYes, QuitMenuNo, key);
         UpdateDescription(Console, aMap);
         walking = !aMap.getPlayerMapSquare().getScenario().getIsActive();
      } 
      UpdateScenario(Console, aMap);
      int check = OptionMenu(Console, aMap);
      if (check == 1)
         return true;
      else if (check == -1)
         return false;
      else
         walking = true;  
   } 
}

void UpdatePlayGameDisplay(WindowsConsole &Console, Map &aMap)
{
   Console.SetCursor(14, 33);
   Console.txtCC("                                                                                                     ", ColorCode(Black, Purple));
   Console.SetCursor(14, 33);
   Console.txtCC(aMap.getPlayerMapSquare().getDescription(), ColorCode(Black, Purple));
   Console.SetCursor(62, 1);
   Console.txtCC("Walking      ", ColorCode(Black, Purple));

   for (int mh = 0; mh < aMap.getPlayerMAXHEALTH(); mh++)
   {
      Console.SetCursor(9 + mh, 30);
      Console.CCC(' ', ColorCode(Black, Red));
   }
   for (int h = 0; h < aMap.getPlayerCurrentHealth(); h++)
   {
      Console.SetCursor(9 + h, 30);
      Console.CCC(char(219), ColorCode(Black, Red));
   }
   for (int ms = 0; ms < aMap.getPlayerMAXSTAMINA(); ms++)
   {
      Console.SetCursor(71 + ms, 30);
      Console.CCC(' ', ColorCode(Black, Green));
   }
   for (int h = 0; h < aMap.getPlayerMAXSTAMINA() - aMap.getPlayerCurrentStamina(); h++)
   {
      Console.SetCursor(71 + h, 30);
      Console.CCC(char(219), ColorCode(Black, Green));
   }
}

void MovePlayer(WindowsConsole &Console, Map &aMap, char key)
{
   if (key == 'w' || key == 'W') //w key to move north
   {
      aMap.MovePlayerNorth();
      Console.PrintMap(3, 4, aMap);
   }
   if (key == 's' || key == 'S') //s key to move south
   {
      aMap.MovePlayerSouth();
      Console.PrintMap(3, 4, aMap);
   }
   if (key == 'a' || key == 'A') //a key to move west
   {
      aMap.MovePlayerWest();
      Console.PrintMap(3, 4, aMap);
   }
   if (key == 'd' || key == 'D') //d key to move east
   {
      aMap.MovePlayerEast();
      Console.PrintMap(3, 4, aMap);
   }
}

void Help(WindowsConsole &Console, Map &aMap, Frame HelpMenu, char key)
{
   bool MenuOpen = true;

   if (key == 'h' || key == 'H') //h key
   {
      Console.PrintFrame(HelpMenu.getX(), HelpMenu.getY(), HelpMenu);
      while (MenuOpen)
      {
         key = getch();
         if (key == 'h' || key == 'H') //h key
            MenuOpen = false;
      }
      Console.PrintMap(3, 4, aMap);
   }
}

void InventoryMenu(WindowsConsole &Console, Map &aMap, Frame Inventory, char key)
{
   bool MenuOpen = true;
   if (key == 'i' || key == 'I') //i key
   {
      Console.PrintFrame(Inventory.getX(), Inventory.getY(), Inventory); bool MenuOpen = true;
      while (MenuOpen)
      {
         key = getch();
         if (key == 'i' || key == 'I') //h key
            MenuOpen = false;
      }
      Console.PrintMap(3, 4, aMap);
   }
}

void QuitMenu(WindowsConsole &Console, Map &aMap, Frame QuitMenuYes, Frame QuitMenuNo, char key)
{
   bool MenuOpen = true;
   if (key == 'q' || key == 'Q') 
   {
      Console.PrintFrame(QuitMenuYes.getX(), QuitMenuYes.getY(), QuitMenuYes);
      bool YesSelect = true;
      bool NoSelect = false;
      while (MenuOpen)
      {
         key = getch();
         if (key == 'A' || key == 'a' || key == 'D' || key == 'd') //h key
         {
            YesSelect = !YesSelect;
            NoSelect = !NoSelect;
            if (YesSelect)
               Console.PrintFrame(QuitMenuYes.getX(), QuitMenuYes.getY(), QuitMenuYes);
            if (NoSelect)
               Console.PrintFrame(QuitMenuNo.getX(), QuitMenuNo.getY(), QuitMenuNo);
         }
         if (key == 32 || key == 13)
            MenuOpen = false;
      }
      if (YesSelect)
         exit(0);
      if (NoSelect)
         Console.PrintMap(3, 4, aMap);
   }
}

void UpdateDescription(WindowsConsole &Console, Map &aMap)
{
   Console.SetCursor(14, 33);
   Console.txtCC("                                                                                                     ", ColorCode(Black, Purple));
   Console.SetCursor(14, 33);
   Console.txtCC(aMap.getPlayerMapSquare().getDescription(), ColorCode(Black, Purple));
}

void UpdateScenario(WindowsConsole &Console, Map &aMap)
{
   Console.SetCursor(62, 1);
   Console.txtCC("Scenario      ", ColorCode(Black, Purple));
   Console.SetCursor(18, 37);
   Console.txtCC(aMap.getPlayerMapSquare().getScenario().getMyDescription(), ColorCode(Black, Purple));
}

int OptionMenu(WindowsConsole &Console, Map &aMap)
{
   bool Menu = true;
   Option OptionListO[4]{ aMap.getPlayerMapSquare().getScenario().getMyOption1(),
      aMap.getPlayerMapSquare().getScenario().getMyOption2(),
      aMap.getPlayerMapSquare().getScenario().getMyOption3(),
      aMap.getPlayerMapSquare().getScenario().getMyOption4() };
   int currentOption = 0;
   char key = ' ';
   while (Menu)
   {
      for (int olist = 0; olist < 4; olist++)
      {
         Console.SetCursor(6, 41 + (2 * olist));
         if (olist == currentOption)
            Console.txtCC(OptionListO[olist].getMyText(), ColorCode(Yellow, Black));
         else
            Console.txtCC(OptionListO[olist].getMyText(), ColorCode(Black, Purple));
      }
      key = getch();
      if (key == 'W' || key == 'w')
         --currentOption %= 4;
      if (key == 'S' || key == 's')
         ++currentOption %= 4;
      if (key == 32 || key == 13)
         Menu = false;
   }
   ClearOptions(Console);

   MapSquare temp(aMap.getPlayerMapSquare());
   temp.DeActiveScenario();
   aMap.PlaceMapSquare(aMap.getMyPlayerXLocation(), aMap.getMyPlayerYLocation(), temp);

   if (OptionListO[currentOption].getHealthChange() + aMap.getPlayerCurrentHealth() <= aMap.getPlayerMAXHEALTH())
      aMap.modifyPlayerHealth(OptionListO[currentOption].getHealthChange());
   else
      aMap.modifyPlayerHealth(aMap.getPlayerMAXHEALTH() - aMap.getPlayerCurrentHealth());

   if (OptionListO[currentOption].getStaminaChange() + aMap.getPlayerCurrentStamina() <= aMap.getPlayerMAXSTAMINA())
      aMap.modifyPlayerStamina(OptionListO[currentOption].getStaminaChange());
   else
      aMap.modifyPlayerHealth(aMap.getPlayerMAXSTAMINA() - aMap.getPlayerCurrentStamina());

   if (OptionListO[currentOption].getMyItem() == "Winning")
      return 1;
   else if (aMap.getPlayerCurrentHealth() <= 0 || aMap.getPlayerCurrentStamina() <= 0)
      return -1;
   else
      return 0;  
}

void ClearOptions(WindowsConsole &Console)
{
   Console.SetCursor(18, 37);
   Console.txtCC("                                                                                                   ", ColorCode(Black, Purple));
   for (int olist = 0; olist < 4; olist++)
   {
      Console.SetCursor(6, 41 + (2 * olist));
      Console.txtCC("                                                                                                                ", ColorCode(Black, Purple));
   }
}