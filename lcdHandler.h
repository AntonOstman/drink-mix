
#ifndef MY_LCDHANDLER_H // header guards
#define MY_LCDHANDLER_H
#include <Arduino.h>
#include <LiquidCrystal.h>

class Menu;

class LcdHandler  : public LiquidCrystal{
  private:
    Menu* currentMenu;
    int pumpOne = 3;
    int pumpTwo = 2;
    
  public:
//    menuPrinter(char menuText[], lcdHandler& lcd): menuItem(menuText, lcd){}

    LcdHandler(int rs, int en, int d0, int d1, int d2, int d3) : LiquidCrystal(rs, en, d0, d1, d2, d3){}
    void setMenu(Menu& menus);
    void nextItem();
    void printCurrent();
    void changeMenu(Menu& newMenu);
    void printAllMenus();
    void doKey(int key);
    void setCursorPos();
    int getKey();
    int getNewKey();
  };

  #endif
