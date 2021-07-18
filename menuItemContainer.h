#ifndef MY_MENUITEMCONTAINER_H // header guards
#define MY_MENUITEMCONTAINER_H

#include "lcdHandler.h"
#include "buttonType.h"
#include "menuItem.h"
#include <Arduino.h>

class menuPrinter: public menuItem{
  
  public:
  // use super class to construct
    menuPrinter(char menuText[], lcdHandler& lcd): menuItem(menuText, lcd){}
    void select() override;
  };


#endif
