#ifndef MY_MENUFACTORY_H // header guards
#define MY_MENUFACTORY_H
#include <Arduino.h>
#include "MenuType.h"

class LcdHandler;
class Menu;

class MenuFactory{
  protected:

    LcdHandler* lcd;
    

  public:

    MenuFactory();
    Menu* createMenu(MenuType menuType, LcdHandler& lcd);

    };
#endif  // headerguard
