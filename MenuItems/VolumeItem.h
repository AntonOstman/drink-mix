

#ifndef MY_VOLUMEITEM_H // header guards
#define MY_VOLUMEITEM_H

#include "MenuItem.h"
#include <Arduino.h>
#include "PumpType.h"

class VolumeItem: public MenuItem{
  private:
    int max = 100;
    int increase = 5;

  public:
  // use super class to construct
    VolumeItem(const char menuText[], LcdHandler& lcd): MenuItem(menuText, lcd){}
    void select() override;
    void left() override;
    void right() override;
    void printAll() override;
    void setMax(int max);
    void setIncrease(int increase);
  };


#endif
