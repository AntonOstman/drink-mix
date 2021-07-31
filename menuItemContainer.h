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
#include "MenuType.h"

#include <Arduino.h>


class MenuChangeItem: public MenuItem{
  
  private:
    MenuType selectedMenu = MAIN_MENU;

  public:
  // use super class to construct
    MenuChangeItem(const char menuText[], LcdHandler& lcd): MenuItem(menuText, lcd){}
    void select() override;
    void changeMenuType(MenuType menuType);
  };


#endif

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
  };


#endif