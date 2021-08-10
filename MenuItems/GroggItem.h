

#ifndef MY_GROGGITEM_H // header guards
#define MY_GROGGITEM_H

#include "MenuItem.h"
#include <Arduino.h>


class GroggItem: public MenuItem{
  private:
    int volumeAmount = 0;

  public:
  // use super class to construct
    GroggItem(const char menuText[], LcdHandler& lcd): MenuItem(menuText, lcd){}
    void select() override;
    void left() override;
    void right() override;
    void printAll() override;
    void setVolume(int volume);
  };


#endif