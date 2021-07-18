#ifndef MY_MENUITEM_H // header guards
#define MY_MENUITEM_H
#include <Arduino.h>
#include "ButtonType.h"

class LcdHandler;

class MenuItem{
  protected:
    char* menuText;
    LcdHandler* lcd;
    
  public:

    MenuItem(char menuText[], LcdHandler& lcd);
    virtual ~MenuItem();
    void action(ButtonType button);
    void printAll();
    int getSize();
    virtual void select();
    void up();
    void down();
    void left();
    void right();
    
    };
#endif  // headerguard
