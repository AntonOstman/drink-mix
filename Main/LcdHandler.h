
#ifndef MY_LCDHANDLER_H // header guards
#define MY_LCDHANDLER_H
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "MenuType.h"

class Menu;


class LcdHandler  : public LiquidCrystal{
  private:
    Menu* currentMenu;
    Menu** menus;
    MenuType menuType;
    int keyPressed = 0;
    const int MENU_AMOUNT = 3;

  public:
//    menuPrinter(char menuText[], lcdHandler& lcd): menuItem(menuText, lcd){}
    const int PUMP_ONE = 2;
    const int PUMP_TWO = 3;
    const int LIQUID_SCALE = 10; 
    const int MAX_VOLUME = 100;
    //const int MAIN_MENU = 0;
    //const int DRINK_MENU = 1;

    LcdHandler(int rs, int en, int d0, int d1, int d2, int d3) : LiquidCrystal(rs, en, d0, d1, d2, d3){
      this->currentMenu = nullptr;
      // initialize an array of pointers where the menu objects will remain alive
      this->menus = new Menu*[MENU_AMOUNT];
      
      this->menuType = MAIN_MENU;
    }
    void setMenu(Menu* menus);
    int getMenuType();
    void nextItem();
    void changeMenu(MenuType menuType);
    void setupMenus();
    void setMainMenu();
    int doubleCheckKey();
    void togglePin(int pin);
    void printCurrent();
    void resetLcd();
    bool checkNewKey(int key);
    void updateScreen();
    void changeMenu(Menu* newMenu);
    void printAllMenus();
    void doKey(int key);
    void setCursorPos();
    void pumpAmount(int pumpOneAmount, int pumpTwoAmount);
    int getKey2(int key);
    int getKey();
    int getNewKey();
  };

  #endif
