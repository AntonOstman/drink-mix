#ifndef MY_MENUITEMCONTAINER_H // header guards
#define MY_MENUITEMCONTAINER_H

#include "MenuItem.h"
#include <Arduino.h>

// class LcdHandler;

class MenuPrinter: public MenuItem{
  
  public:
  // use super class to construct
    MenuPrinter(const char menuText[], LcdHandler& lcd): MenuItem(menuText, lcd){}
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
    MixerItem(const char menuText[], LcdHandler& lcd): MenuItem(menuText, lcd){}
    void select() override;
  };


#endif

#ifndef MY_VOLUMEITEM_H // header guards
#define MY_VOLUMEITEM_H

#include "MenuItem.h"
#include <Arduino.h>


class VolumeItem: public MenuItem{
  private:
    int volumeAmount;

  public:
  // use super class to construct
    VolumeItem(const char menuText[], LcdHandler& lcd): MenuItem(menuText, lcd){}
    void select() override;
    void left() override;
    void right() override;
  };


#endif

#ifndef MY_BACKITEM_H // header guards
#define MY_BACKITEM_H

#include "MenuItem.h"
#include <Arduino.h>


class BackItem: public MenuItem{

  public:
  // use super class to construct
    BackItem(const char menuText[], LcdHandler& lcd): MenuItem(menuText, lcd){}
    void select() override;
  };


#endif
