
#include <Arduino.h>

#include "MenuType.h"
#include "Menu.h"
#include "MenuItemContainer.h"
#include "LcdHandler.h"
#include "MenuFactory.h"

MenuFactory::MenuFactory(){

}


Menu* MenuFactory::createMenu(MenuType menuType, LcdHandler& lcd){
    
    switch (menuType)
    {
    case MAIN:
    {
        const char q1[] = "asdf";
        const char q2[] = "hejsan2";
        const char q3[] = "hejsan3";
        const char q4[] = "hejsan4";
        
        char* q = new char(); 
        MenuPrinter* menu1 = new MenuPrinter(q1, lcd);
        MenuPrinter* menu2 = new MenuPrinter(q2, lcd);
        MenuItem* menu3 = new MenuItem(q3,  lcd);
        MenuItem* menu4 = new MenuItem(q4,  lcd);

        int menuSize = 4;
        Menu* menus = new Menu(menuSize, lcd);        
        menus->addMenuItem(0, menu1);
        menus->addMenuItem(1, menu2);
        menus->addMenuItem(2, menu3);
        menus->addMenuItem(3, menu4);

        
        return menus;
        break;
    }
    default:
        break;
    }

    
}