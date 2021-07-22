#ifndef MY_MENUSCONTAINER_H // header guards
#define MY_MENUSCONTAINER_H

#include "ButtonType.h"
#include "Menu.h"
#include <Arduino.h>

class DrinkMenu: public Menu{
  private:


  public:
  // use super class to construct
    DrinkMenu(int menuSize, LcdHandler& lcd): Menu(menuSize, lcd){

    }
    void up() override;
    void down() override;
    void left() override;
    void right() override;
  };


#endif
