

#ifndef MY_ROULETTEITEM_H // header guards
#define MY_ROULETTEITEM_H

#include "MenuItem.h"
#include <Arduino.h>

class RouletteItem: public MenuItem{
  private:


  public:
  // use super class to construct
    RouletteItem(const char menuText[], LcdHandler& lcd): MenuItem(menuText, lcd){}
    void select() override;

  };


#endif
