
#ifndef MY_LCDHANDLER_H // header guards
#define MY_LCDHANDLER_H
#include <Arduino.h>
#include "menu.h"
#include <LiquidCrystal.h>

class lcdHandler {
  private:
    menu* currentMenu;
    LiquidCrystal* lcd;
    int pumpOne = 3;
    int pumpTwo = 2;
    
  public:
    lcdHandler(menu& newMenu, LiquidCrystal& lcd);
    void nextItem();
    void printCurrent();
    void changeMenu(menu& newMenu);
    void printAllMenus();
    void doKey(int key);
    void setCursorPos();
    int getKey();
    int getNewKey();
  };

  #endif
