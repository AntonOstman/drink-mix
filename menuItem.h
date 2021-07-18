#ifndef MY_MENUITEM_H // header guards
#define MY_MENUITEM_H

#include "buttonType.h"
#include <Arduino.h>
#include <LiquidCrystal.h>
class menuItem{
  protected:
    char* menuText;
    LiquidCrystal* lcd;
    
  public:

    menuItem(char menuText[], LiquidCrystal& lcd);
    virtual ~menuItem();
    void action(buttonType button);
    void printAll();
    int getSize();
    virtual void select();
    void up();
    void down();
    void left();
    void right();
    
    };
#endif  // headerguard
