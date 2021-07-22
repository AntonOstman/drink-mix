#ifndef MY_MENUITEM_H // header guards
#define MY_MENUITEM_H
#include <Arduino.h>
#include "ButtonType.h"

class LcdHandler;

class MenuItem{
  protected:
    const char* menuText;
    LcdHandler* lcd;
    
  public:

    MenuItem(const char menuText[], LcdHandler& lcd);
    virtual ~MenuItem();
    void action(ButtonType button);
    void printAll();
    int getSize();
    virtual void select();
    void up();
    void down();
    virtual void left();
    virtual void right();
    
    };
#endif  // headerguard
