#include "GuessGameMenu.h"
#include "LcdHandler.h"
#include "MenuItem.h"


void GuessGameMenu::select(){
        if (gameRound == 0){
            gameRound++;
            moveMenu(DOWN);
        }
        else {
            lcd->resetLcd();
            lcd->print("Vinnaren .... ");
            delay(5000);
            int numberToGuess = menuItems[0]->getVolumeAmount();
            int numberGuessed = menuItems[1]->getVolumeAmount();

            if (numberToGuess == numberGuessed){
                int fullshot = 10;
                
                lcd->resetLcd();
                lcd->print("GISSAREN!!!!!!");
                delay(3000);
                lcd->resetLcd();
                lcd->print("Drick vetaren :)");
                delay(3000);
                lcd->pumpVolume(0, fullshot);

            }
            else if(numberToGuess == numberGuessed - 1 || numberToGuess == numberGuessed + 1){
                int guesserShot = 5;
                int knowerShot = 5;


                lcd->resetLcd();
                lcd->print("One off :(");
                delay(3000);
                lcd->resetLcd();

                lcd->print("Dela :)");
                lcd->setCursor(0,1);
                lcd->print("två rundor :)");
                delay(3000);
                lcd->pumpVolume(0, guesserShot);
                lcd->resetLcd();
                lcd->print("runda två...");
                delay(3000);
                lcd->pumpVolume(0, knowerShot);

            }
            else {
                
                int difference = abs(numberGuessed - numberToGuess);

                lcd->resetLcd();
                lcd->print("VETAREN!!!!!");
                delay(3000);
                lcd->resetLcd();
                lcd->print("skillnaden: ");
                lcd->print(difference);
                lcd->setCursor(0,1);
                lcd->print("Drick upp det :)");
                delay(3000);
                lcd->pumpVolume(0, difference);

            }
            // reset and exit the game

        
            gameRound = 0;
            moveMenu(UP);
            menuItems[0]->setVolume(0);
            menuItems[1]->setVolume(0);

            lcd->changeMenu(FUN_MENU);
        }

}

    // do not do anything since we cannot go up or down in the game
void GuessGameMenu::up(){

}

    // do not do anything since we cannot go up or down in the game
void GuessGameMenu::down(){
    // do not do anything since we cannot go up or down in the game
}

/**
 * Prints the selectedMenu
 * 
 */
void GuessGameMenu::printMenus(){

    printSelectedMenu();   
}
