#ifndef MY_MENUITEM_H // header guards
#define MY_MENUITEM_H
#include <Arduino.h>
#include "ButtonType.h"
#include "PumpType.h"


class LcdHandler;

class MenuItem{
  protected:
    const char* menuText;
    LcdHandler* lcd;
    
  public:

    MenuItem(const char menuText[], LcdHandler& lcd);
    virtual ~MenuItem();
    void action(ButtonType button);
    virtual void printAll();
    int getSize();
    const char* getText();
    virtual void select();
    void up();
    void down();
    virtual void left();
    virtual void right();
    
    };
#endif  // headerguard
