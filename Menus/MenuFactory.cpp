
#include <Arduino.h>

#include "MenuType.h"
#include "Menu.h"
#include "MenuItemContainer.h"
#include "LcdHandler.h"
#include "MenuFactory.h"
#include "GroggItem.h"
#include "MenuChangeItem.h"
#include "VolumeItem.h"
#include "RandomDrinkItem.h"

MenuFactory::MenuFactory(){

}


Menu* MenuFactory::createMenu(int menuType, LcdHandler& lcd){
    
    switch (menuType)
    {
    case 0:
    {
        char const* q1 = "Drink Menu";
        char const* q2 = "Toggle pump 1";
        char const* q3 = "Fun menu";

        MenuPrinter* menu1 = new MenuPrinter(q2, lcd);
        MenuChangeItem* menu4 = new MenuChangeItem(q1,  lcd);
        MenuChangeItem* funMenu = new MenuChangeItem(q3, lcd);

        menu4->changeMenuType(DRINK_MENU);
        funMenu->changeMenuType(FUN_MENU);
        
        int menuSize = 3;

        Menu* menus = new Menu(menuSize, lcd);        

        menus->addMenuItem(0, menu1);
        menus->addMenuItem(1, menu4);
        menus->addMenuItem(2, funMenu);
        
        return menus;
        break;
    }
    case 1:
    {
        char const* q2 = "Grogg: ";
        char const* q3 = "pump 2";
        char const* q4 = "pump 1";
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

        menus->addMenuItem(0, menu2);
        menus->addMenuItem(1, menu3);
        menus->addMenuItem(2, menu4);
        menus->addMenuItem(3, menu5);
        
        return menus;
        break;
    }

    case 2:
        char const* q1 = "Back";
        char const* q3 = "Random Grogg";
        char const* shotText = "Random shot";
                
        MenuChangeItem* menu1 = new MenuChangeItem(q1, lcd);
        RandomDrinkItem* menu3 = new RandomDrinkItem(q3,  lcd);
        RandomDrinkItem* shotItem = new RandomDrinkItem(shotText,  lcd);

        //BackItem* menu5 = new BackItem(q5,  lcd);
        shotItem->changeDrinkType(SHOT);
        menu1->changeMenuType(MAIN_MENU);

        int menuSize = 3;
        Menu* menus = new Menu(menuSize, lcd);        

        menus->addMenuItem(0, menu1);
        menus->addMenuItem(1, menu3);
        menus->addMenuItem(2, shotItem);
        //menus->addMenuItem(4, menu5);
        
        return menus;
        break;

    default:
        break;
    }

    return NULL;
}