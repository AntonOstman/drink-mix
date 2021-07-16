#ifndef MY_MENUSCONTAINER_H // header guards
#define MY_MENUSCONTAINER_H

#include "buttonType.h"
#include "menu.h"
#include <Arduino.h>
#include <LiquidCrystal.h>

class menuTwo: public menu{
  
  public:
  // use super class to construct
    menuTwo(int menuSize, LiquidCrystal& lcd): menu(menuSize, lcd){}
    
  };


#endif