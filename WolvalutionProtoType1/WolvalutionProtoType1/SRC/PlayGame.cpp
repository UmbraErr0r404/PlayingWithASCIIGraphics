#include <string>	
#include "Screen.hpp"
#include "Frame.hpp"
#include "ColoredCharacter.hpp"
#include "WindowsConsole.hpp"
#include "Option.hpp"
#include "Scenario.hpp"
#include "MapSquare.hpp"
#include "Map.hpp"

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

   while (HomeSelecting)
   {
      key = getch();
      if (key == 'w' || key == 'W') //w key
      {
         if (QuitSelect)
         {
            Console.PrintFrame(PlaySelected.getX(), PlaySelected.getY(), PlaySelected);
            QuitSelect = false;
            PlaySelect = true;
         }
         else if (PlaySelect)
         {
            Console.PrintFrame(QuitSelected.getX(), QuitSelected.getY(), QuitSelected);
            QuitSelect = true;
            PlaySelect = false;
         }
      }
      if (key == 's' || key == 'S') //s key
      {
         if (QuitSelect)
         {
            Console.PrintFrame(PlaySelected.getX(), PlaySelected.getY(), PlaySelected);
            QuitSelect = false;
            PlaySelect = true;
         }
         else if (PlaySelect)
         {
            Console.PrintFrame(QuitSelected.getX(), QuitSelected.getY(), QuitSelected);
            QuitSelect = true;
            PlaySelect = false;
         }
      }
      if (key == 32 || key == 13) //space-bar or enter
      {
         if (QuitSelect)
         {
            return 0;
         }
         else if (PlaySelect)
         {
            HomeSelecting = false;
         }
      }
   }

   Console.ClearScreen();

   Console.PrintFrame(IntroBase.getX(), IntroBase.getY(), IntroBase);
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

   Console.ClearScreen();

   Console.PrintFrame(PlayGameBase.getX(), PlayGameBase.getY(), PlayGameBase);
   Console.PrintMap(3, 4, IAmMap);

   bool PlayGame = true;
   bool walking = true;
   bool wonGame = false;
   bool loseGame = false;
   bool MenuOpen = false;
   bool OptionMenu = false;

   while (PlayGame)
   {
      Console.SetCursor(14, 33);
      Console.txtCC("                                                                                                     ", ColorCode(Black, Purple));
      Console.SetCursor(14, 33);
      Console.txtCC(IAmMap.getPlayerMapSquare().getDescription(), ColorCode(Black, Purple));

      Console.SetCursor(62, 1);
      Console.txtCC("Walking      ", ColorCode(Black, Purple));

      for (int mh = 0; mh < IAmMap.getPlayerMAXHEALTH(); mh++)
      {
         Console.SetCursor(9 + mh, 30);
         Console.CCC(' ', ColorCode(Black, Red));
      }
      for (int h = 0; h < IAmMap.getPlayerCurrentHealth(); h++)
      {
         Console.SetCursor(9 + h, 30);
         Console.CCC(char(219), ColorCode(Black, Red));
      }
      for (int ms = 0; ms < IAmMap.getPlayerMAXSTAMINA(); ms++)
      {
         Console.SetCursor(71 + ms, 30);
         Console.CCC(' ', ColorCode(Black, Green));
      }
      for (int h = 0; h < IAmMap.getPlayerMAXSTAMINA() - IAmMap.getPlayerCurrentStamina(); h++)
      {
         Console.SetCursor(71 + h, 30);
         Console.CCC(char(219), ColorCode(Black, Green));
      }

      while (walking)
      {
         key = getch();
         if (key == 'w' || key == 'W') //w key to move north
         {
            IAmMap.MovePlayerNorth();
            Console.PrintMap(3, 4, IAmMap);
         }
         if (key == 's' || key == 'S') //s key to move south
         {
            IAmMap.MovePlayerSouth();
            Console.PrintMap(3, 4, IAmMap);
         }
         if (key == 'a' || key == 'A') //a key to move west
         {
            IAmMap.MovePlayerWest();
            Console.PrintMap(3, 4, IAmMap);
         }
         if (key == 'd' || key == 'D') //d key to move east
         {
            IAmMap.MovePlayerEast();
            Console.PrintMap(3, 4, IAmMap);
         }
         if (key == 'h' || key == 'H') //h key
         {
            Console.PrintFrame(HelpMenu.getX(), HelpMenu.getY(), HelpMenu);
            MenuOpen = true;
            while (MenuOpen)
            {
               key = getch();
               if (key == 'h' || key == 'H') //h key
                  MenuOpen = false;
            }
            Console.PrintMap(3, 4, IAmMap);
         }
         if (key == 'i' || key == 'I') //i key
         {
            Console.PrintFrame(Inventory.getX(), Inventory.getY(), Inventory);bool MenuOpen = true;
            MenuOpen = true;
            while (MenuOpen)
            {
               key = getch();
               if (key == 'i' || key == 'I') //h key
                  MenuOpen = false;
            }
            Console.PrintMap(3, 4, IAmMap);
         }
         if (key == 'q' || key == 'Q') //q key
         {
            Console.PrintFrame(QuitMenuYes.getX(), QuitMenuYes.getY(), QuitMenuYes);     
            bool YesSelect = true;
            bool NoSelect = false;
            MenuOpen = true;
            while (MenuOpen)
            {
               key = getch();
               if (key == 'A' || key == 'a' || key == 'D' || key == 'd') //h key
               {
                  YesSelect = !YesSelect;
                  NoSelect = !NoSelect;
                  if(YesSelect)
                     Console.PrintFrame(QuitMenuYes.getX(), QuitMenuYes.getY(), QuitMenuYes);
                  if (NoSelect)
                     Console.PrintFrame(QuitMenuNo.getX(), QuitMenuNo.getY(), QuitMenuNo);
               }
               if (key == 32 || key == 13)
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

      } //walking loop end

      Console.SetCursor(62, 1);
      Console.txtCC("Scenario      ", ColorCode(Black, Purple));

      Console.SetCursor(18, 37);
      Console.txtCC(IAmMap.getPlayerMapSquare().getScenario().getMyDescription(), ColorCode(Black, Purple));

      OptionMenu = true;
      bool OptionListB[4]{ true, false, false, false };
      Option OptionListO[4]{ IAmMap.getPlayerMapSquare().getScenario().getMyOption1(),
                             IAmMap.getPlayerMapSquare().getScenario().getMyOption2(),
                             IAmMap.getPlayerMapSquare().getScenario().getMyOption3(),
                             IAmMap.getPlayerMapSquare().getScenario().getMyOption4() };
      int currentOption = 0;

      while(OptionMenu)
      {
         for (int olist = 0; olist < 4; olist++)
         {
            Console.SetCursor(6, 41 + (2 * olist));
            if (OptionListB[olist])
               Console.txtCC(OptionListO[olist].getMyText(), ColorCode(Yellow, Black));
            else
               Console.txtCC(OptionListO[olist].getMyText(), ColorCode(Black, Purple));
         }
         key = getch();
         if (key == 'W' || key == 'w') //Up
         {
            OptionListB[currentOption] = false;
            if (currentOption == 0)
            {
               currentOption = 3;
               OptionListB[currentOption] = true;
            }
            else
            {
               currentOption--;
               OptionListB[currentOption] = true;
            }
         }
         if (key == 'S' || key == 's') //Down
         {
            OptionListB[currentOption] = false;
            if (currentOption == 3)
            {
               currentOption = 0;
               OptionListB[currentOption] = true;
            }
            else
            {
               currentOption++;
               OptionListB[currentOption] = true;
            }
         }
         if (key == 32 || key == 13)
            OptionMenu = false;
      }//end of option menu
      Console.SetCursor(18, 37);
      Console.txtCC("                                                                                                   ", ColorCode(Black, Purple));
      for (int olist = 0; olist < 4; olist++)
      {
         Console.SetCursor(6, 41 + (2 * olist));
         Console.txtCC("                                                                                                             ", ColorCode(Black, Purple));
      }
      MapSquare temp(IAmMap.getPlayerMapSquare());
      temp.DeActiveScenario();
      IAmMap.PlaceMapSquare(IAmMap.getMyPlayerXLocation(), IAmMap.getMyPlayerYLocation(), temp);
      walking = true;

      for (int olist = 0; olist < 4; olist++)
         if (OptionListB[olist])
         {
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

      if(wonGame || loseGame)
         PlayGame = false;     
   } //END OF PLAY GAME WHILE LOOP  

   Console.ClearScreen();

   if (wonGame)
      Console.PrintFrame(WinBase.getX(), WinBase.getY(), WinBase);
   else
      Console.PrintFrame(LossBase.getX(), LossBase.getY(), LossBase);

   //Make a slection to playagain or quit

   return 0; 
}

