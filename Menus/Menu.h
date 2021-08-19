
#ifndef MY_MENU_H // header guards
#define MY_MENU_H

#include <Arduino.h>
#include "ButtonType.h"

class MenuItem;
class LcdHandler;

class Menu {
  protected:
    int cursorPos;
    int selectedMenu;
    int menuSize;
    int indexPositon;
    MenuItem** menuItems;
    LcdHandler* lcd;
    
  public:
    Menu(int menuSize, LcdHandler& lcd);
    virtual ~Menu();
    void nextItem();
    void action(ButtonType button);
    void printCurrent();
    void moveMenu(ButtonType buttontype);
    void setCursorPos();
    void addMenuItem(MenuItem* item);
    int getMenuItemAmount();
    void printMenu(int index);
    virtual void printMenus();
    void playRoulette();
    void playGuessGame();
    void printSelectedMenu();
    virtual void select();
    virtual void up();
    virtual void down();
    virtual void left();
    virtual void right();
    MenuItem getMenuItem(int index);
  };
 #endif
