#include "lcdHandler.h"
#include "menu.h"

lcdHandler::lcdHandler(menu& newMenu, LiquidCrystal& lcd){
  this->currentMenu = &newMenu;
  this->lcd = &lcd;
  }

void lcdHandler::changeMenu(menu& newMenu){
  currentMenu = &newMenu;

  }

 void lcdHandler::printAllMenus(){
  currentMenu->printMenus();
  }

 void lcdHandler::printCurrent(){
  currentMenu->printCurrent();
  }
 void lcdHandler::nextItem(){
  currentMenu->nextItem();
  }


/**
 * Loops until a new key is pressed. Then sets oldKey to the key found.
 * 
 * 
 */
int lcdHandler::getNewKey(){
  // wait until the current buttonm, if any, is released
  while(getKey() != 0){
    // do nothing
    }
    
    // wait until a new button is pressed
  int newKey = getKey();
  while(newKey == 0){
    delay(150);
    newKey = getKey();
    }  
  return newKey;
  }



void lcdHandler::doKey(int key){
    
  switch(key){
    case 0:
      // do nothing when no key found
      break;
    case 1:
      currentMenu-> select();
      break;
    case 2:
      currentMenu-> up();
      break;
    case 3:
      currentMenu-> down();
      break;
    case 4:
      currentMenu -> left();
      break;
    case 5:
      currentMenu -> right();
      break;
     }
  }

void lcdHandler::setCursorPos(){
  currentMenu->setCursorPos();
  
  }

/*
 * Return the key which is currently being pressed on analog input 0
 * The resistor stair for the buttons goes as following:
 * 4 has 0 ohm
 * 3 has 220 ohm
 * 2 has 680 ohm
 * 1 has 1k ohm
 * 5 has 1k ohm
 * which means when button 1 is pressed there is a total of circa 2k ohm resistance
 */

int lcdHandler::getKey(){
  int analogPin = A0;
  int val = analogRead(analogPin);
  if (val > 800){
    return 0;
    }
  else if(val > 180){
    return 1;
    }
  else if(val > 130){
    return 2;
    }
  else if (val > 50){
    return 3;
    }
  else if (val > 15){
    return 4;
    }
  else{
    return 5;
     } 
 }
  
