#ifndef MY_RANDOMDRINKITEM_H // header guards
#define MY_RANDOMDRINKITEM_H

#include "MenuItem.h"
#include "DrinkType.h"
#include <Arduino.h>

class RandomDrinkItem: public MenuItem{
  private:
    DrinkType drinkType = DRINK;

  public:
  // use super class to construct
    RandomDrinkItem(const char menuText[], LcdHandler& lcd): MenuItem(menuText, lcd){}
    void select() override;
    void changeDrinkType(DrinkType drinkType);
    //void left() override;
    //void right() override;
    //void printAll() override;
  };


#endif