
#ifndef MY_MENU_H // header guards
#define MY_MENU_H
#include <Arduino.h>
#include "menuItem.h"
#include "buttonType.h"
#include "lcdHandler.h"

class menu {
  private:
    int cursorPos;
    int selectedMenu;
    int menuSize;
    menuItem** menuItems;
    lcdHandler* lcd;
    
  public:
    menu(int menuSize, lcdHandler& lcd);
    virtual ~menu();
    void nextItem();
    void action(buttonType button);
    void printCurrent();
    void printMenus();
    void setCursorPos();
    void addMenuItem(int index, menuItem* item);
    int getMenuItemAmount();
    virtual void select();
    virtual void up();
    virtual void down();
    virtual void left();
    virtual void right();
    menuItem getMenuItem(int index);
  };
 #endif
