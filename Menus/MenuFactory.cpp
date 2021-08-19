
#include <Arduino.h>

#include "MenuType.h"
#include "Menu.h"
#include "LcdHandler.h"
#include "MenuFactory.h"
#include "GroggItem.h"
#include "MenuChangeItem.h"
#include "VolumeItem.h"
#include "RandomDrinkItem.h"
#include "RouletteItem.h"
#include "GuessGameMenu.h"

MenuFactory::MenuFactory(){

}


Menu* MenuFactory::createMenu(MenuType menuType, LcdHandler& lcd){
    
    switch (menuType)
    {
    case MAIN_MENU:
    {
        char const* q1 = "Drink Menu";
        char const* q2 = "Toggle sodapump";
        char const* alcoPumpText = "Toggle alcopump";
        char const* q3 = "Fun menu";

        MenuItem* menu1 = new MenuItem(q2, lcd);
        MenuItem* alcoPump = new MenuItem(alcoPumpText, lcd);
        MenuChangeItem* menu4 = new MenuChangeItem(q1,  lcd);
        MenuChangeItem* funMenu = new MenuChangeItem(q3, lcd);
        
        alcoPump->setSelectedPump(ALCOHOL_PUMP);
        menu4->changeMenuType(DRINK_MENU);
        funMenu->changeMenuType(FUN_MENU);
        
        int menuSize = 4;

        Menu* menus = new Menu(menuSize, lcd);        
        
        menus->addMenuItem(3, funMenu);
        menus->addMenuItem(2, menu4);
        menus->addMenuItem(1, alcoPump);
        menus->addMenuItem(0, menu1);

        
        return menus;
        break;
    }
    case DRINK_MENU:
    {
        char const* q2 = "Grogg: ";
        char const* q3 = "alcoholpump: ";
        char const* q4 = "Sodapump: ";
        char const* q5 = "Back";
        
        
        GroggItem* menu2 = new GroggItem(q2, lcd);
        VolumeItem* menu3 = new VolumeItem(q3,  lcd);
        VolumeItem* menu4 = new VolumeItem(q4,  lcd);
        MenuChangeItem* menu5 = new MenuChangeItem(q5,  lcd);


        menu5->changeMenuType(MAIN_MENU);
        menu3->setSelectedPump(ALCOHOL_PUMP);
        menu4->setSelectedPump(SOFTDRINK_PUMP);
        

        int menuSize = 4;
        Menu* menus = new Menu(menuSize, lcd);        

        menus->addMenuItem(3, menu2);
        menus->addMenuItem(1, menu3);
        menus->addMenuItem(2, menu4);
        menus->addMenuItem(0, menu5);
        
        return menus;
        break;
    }

    case FUN_MENU:
    {
        char const* q1 = "Back";
        char const* guessGameText = "Guess game";
        char const* q3 = "Random Grogg";
        char const* shotText = "Random shot";
        char const* roulette = "Roulette";

        MenuChangeItem* menu1 = new MenuChangeItem(q1, lcd);
        MenuChangeItem* guessGame = new MenuChangeItem(guessGameText, lcd);
        RandomDrinkItem* menu3 = new RandomDrinkItem(q3,  lcd);
        RandomDrinkItem* shotItem = new RandomDrinkItem(shotText,  lcd);
        RouletteItem* rouletteItem = new RouletteItem(roulette, lcd);
        

        //BackItem* menu5 = new BackItem(q5,  lcd);
        shotItem->changeDrinkType(SHOT);
        menu1->changeMenuType(MAIN_MENU);
        guessGame->changeMenuType(GUESS_GAME);
        int menuSize = 5;
        Menu* menus = new Menu(menuSize, lcd);        

        menus->addMenuItem(4, guessGame);
        menus->addMenuItem(3, rouletteItem);
        menus->addMenuItem(2, shotItem);
        menus->addMenuItem(1, menu3);
        menus->addMenuItem(0, menu1);

        return menus;
        break;
    }
    case ROULETTE_MENU:
{
        char const* harmlessDrink = "cola:)";
        char const* smallShot = "small shot";
        char const* deathDrink = "50/50 grogg";
        char const* deathShot = "big shot";
        char const* q3 = "Rnd Grogg";
        char const* shotText = "Rnd shot";
        char const* roulette = "Roulette";
        char const* guessGameText = "guessing game";


        VolumeItem* sodapopShot = new VolumeItem(smallShot, lcd);
        VolumeItem* sodapopDrink = new VolumeItem(harmlessDrink, lcd);
        VolumeItem* bigShot = new VolumeItem(deathShot, lcd);
        GroggItem* bigDrink = new GroggItem(deathDrink, lcd);
        RandomDrinkItem* menu3 = new RandomDrinkItem(q3,  lcd);
        RandomDrinkItem* shotItem = new RandomDrinkItem(shotText,  lcd);

        MenuChangeItem* guessingGameItem = new MenuChangeItem(guessGameText, lcd);
        RouletteItem* rouletteItem = new RouletteItem(roulette, lcd);


        //BackItem* menu5 = new BackItem(q5,  lcd);

        guessingGameItem->changeMenuType(GUESS_GAME);
        shotItem->changeDrinkType(SHOT);
        sodapopShot->setSelectedPump(SOFTDRINK_PUMP);
        sodapopShot->setVolume(10);
        sodapopDrink->setSelectedPump(SOFTDRINK_PUMP);
        sodapopDrink->setVolume(50);
        bigDrink->setVolume(50); // 50/50 grogg
        bigShot->setSelectedPump(ALCOHOL_PUMP);
        bigShot->setVolume(10);

        int menuSize = 8;
        Menu* menus = new Menu(menuSize, lcd);

        menus->addMenuItem(7, guessingGameItem);
        menus->addMenuItem(6, bigDrink);
        menus->addMenuItem(5, bigShot);
        menus->addMenuItem(4, sodapopDrink);
        menus->addMenuItem(3, sodapopShot);
        menus->addMenuItem(2, shotItem);
        menus->addMenuItem(1, rouletteItem);
        menus->addMenuItem(0, menu3);
        
        return menus;
        break;
}
    case GUESS_GAME:
    {
        char const* knowerText = "Choose number:";
        char const* guesserText = "Guess number:";
        
        VolumeItem* guesserItem = new VolumeItem(knowerText,  lcd);
        VolumeItem* knowerItem = new VolumeItem(guesserText,  lcd);

        guesserItem->setIncrease(1);
        guesserItem->setMax(10);
        knowerItem->setIncrease(1);
        knowerItem->setMax(10);

        int menuSize = 2;
        GuessGameMenu* menus = new GuessGameMenu(menuSize, lcd);        

        menus->addMenuItem(1, guesserItem);
        menus->addMenuItem(0, knowerItem);

        return menus;
        break;
    }
    default:
        return NULL;
        break;
    }

    return NULL;
}