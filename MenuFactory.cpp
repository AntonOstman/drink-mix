
#include <Arduino.h>

#include "MenuType.h"
#include "Menu.h"
#include "MenuItemContainer.h"
#include "LcdHandler.h"
#include "MenuFactory.h"

MenuFactory::MenuFactory(){

}


Menu* MenuFactory::createMenu(int menuType, LcdHandler& lcd){
    
    switch (menuType)
    {
    case 0:
    {
        char const* q1 = "asdf";
        char const* q2 = "hejsan2";
        char const* q3 = "hejsan3";
        char const* q4 = "hejsan4";
        
        MenuPrinter* menu1 = new MenuPrinter(q1, lcd);
        MenuPrinter* menu2 = new MenuPrinter(q2, lcd);
        MenuItem* menu3 = new MenuItem(q3,  lcd);
        MixerItem* menu4 = new MixerItem(q4,  lcd);

        int menuSize = 4;
        Menu* menus = new Menu(menuSize, lcd);        
        menus->addMenuItem(0, menu1);
        menus->addMenuItem(1, menu2);
        menus->addMenuItem(2, menu3);
        menus->addMenuItem(3, menu4);

        
        return menus;
        break;
    }
    case 1:
    {
        char const* q1 = "Drink options";
        char const* q2 = "shots";
        char const* q3 = "50 %";
        char const* q4 = "glhf";
        char const* q5 = "Back";
        
        
        MenuPrinter* menu1 = new MenuPrinter(q1, lcd);
        MenuPrinter* menu2 = new MenuPrinter(q2, lcd);
        MenuItem* menu3 = new MenuItem(q3,  lcd);
        MenuItem* menu4 = new MenuItem(q4,  lcd);
        BackItem* menu5 = new BackItem(q5,  lcd);

        int menuSize = 5;
        Menu* menus = new Menu(menuSize, lcd);        
        menus->addMenuItem(0, menu1);
        menus->addMenuItem(1, menu2);
        menus->addMenuItem(2, menu3);
        menus->addMenuItem(3, menu4);
        menus->addMenuItem(4, menu5);
        
        return menus;
        break;
    }
    default:
        break;
    }

    return NULL;
}