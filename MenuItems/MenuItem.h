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
    int volumeAmount = 0;
    PumpType selectedPump = SOFTDRINK_PUMP;

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
    void setVolume(int volume);
    int getVolumeAmount();
    void setSelectedPump(PumpType PumpType);
    };
#endif  // headerguard
