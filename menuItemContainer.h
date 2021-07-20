#ifndef MY_MENUITEMCONTAINER_H // header guards
#define MY_MENUITEMCONTAINER_H

#include "MenuItem.h"
#include <Arduino.h>

// class LcdHandler;

class MenuPrinter: public MenuItem{
  
  public:
  // use super class to construct
    MenuPrinter(char menuText[], LcdHandler& lcd): MenuItem(menuText, lcd){}
    void select() override;
  };


#endif

#ifndef MY_MIXERITEM_H // header guards
#define MY_MIXERITEM_H

#include "MenuItem.h"
#include <Arduino.h>


class MixerItem: public MenuItem{
  
  public:
  // use super class to construct
    MixerItem(char menuText[], LcdHandler& lcd): MenuItem(menuText, lcd){}
    void select() override;
  };


#endif
