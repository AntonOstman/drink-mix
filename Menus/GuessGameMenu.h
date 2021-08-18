#ifndef MY_GUESSGAMEMENU_H // header guards
#define MY_GUESSGAMEMENU_H

#include "ButtonType.h"
#include "Menu.h"
#include <Arduino.h>

class GuessGameMenu: public Menu{

  public:
  // use super class to construct
    GuessGameMenu(int menuSize, LcdHandler& lcd): Menu(menuSize, lcd){
        

    }
    void select() override;

  };


#endif
