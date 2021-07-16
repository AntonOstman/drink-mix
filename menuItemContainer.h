#ifndef MY_MENUITEMCONTAINER_H // header guards
#define MY_MENUITEMCONTAINER_H

#include "buttonType.h"
#include "menuItem.h"
#include <Arduino.h>
#include <LiquidCrystal.h>

class menuPrinter: public menuItem{
  
  public:
  // use super class to construct
    menuPrinter(char menuText[], LiquidCrystal& lcd): menuItem(menuText, lcd){}
    void select() override;
  };


#endif
