
#ifndef MY_MENU_H // header guards
#define MY_MENU_H
#include <Arduino.h>
#include "MenuItem.h"
#include "ButtonType.h"

class LcdHandler;

class Menu {
  private:
    int cursorPos;
    int selectedMenu;
    int menuSize;
    MenuItem** menuItems;
    LcdHandler* lcd;
    
  public:
    Menu(int menuSize, LcdHandler& lcd);
    virtual ~Menu();
    void nextItem();
    void action(ButtonType button);
    void printCurrent();
    void printMenus(ButtonType buttontype);
    void setCursorPos();
    void addMenuItem(int index, MenuItem* item);
    int getMenuItemAmount();
    void printMenu(int index);
    virtual void select();
    virtual void up();
    virtual void down();
    virtual void left();
    virtual void right();
    MenuItem getMenuItem(int index);
  };
 #endif
