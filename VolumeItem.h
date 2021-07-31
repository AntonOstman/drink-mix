

#ifndef MY_VOLUMEITEM_H // header guards
#define MY_VOLUMEITEM_H

#include "MenuItem.h"
#include <Arduino.h>


class VolumeItem: public MenuItem{
  private:
    int volumeAmount = 0;
    int selectedPump = 0;


  public:
  // use super class to construct
    VolumeItem(const char menuText[], LcdHandler& lcd): MenuItem(menuText, lcd){}
    void select() override;
    void left() override;
    void right() override;
    void printAll() override;
    void setSelectedPump(int pin);
  };


#endif
