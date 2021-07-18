#ifndef MY_MENUITEM_H // header guards
#define MY_MENUITEM_H
#include <Arduino.h>
#include "buttonType.h"

class lcdHandler;

class menuItem{
  protected:
    char* menuText;
    lcdHandler* lcd;
    
  public:

    menuItem(char menuText[], lcdHandler& lcd);
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
