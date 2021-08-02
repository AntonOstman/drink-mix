
#ifndef MY_MIXERITEM_H // header guards
#define MY_MIXERITEM_H

#include "MenuItem.h"
#include "MenuType.h"

#include <Arduino.h>


class MenuChangeItem: public MenuItem{
  
  private:
    MenuType selectedMenu = MAIN_MENU;

  public:
  // use super class to construct
    MenuChangeItem(const char menuText[], LcdHandler& lcd): MenuItem(menuText, lcd){}
    void select() override;
    void changeMenuType(MenuType menuType);
  };


#endif

