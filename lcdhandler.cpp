
#include "LcdHandler.h"
#include "Menu.h"

//lcdHandler::lcdHandler(int rs, int en, int d0, int d1, int d2, int d3) : LiquidCrystal(rs, en, d0, d1, d2, d3){
 // this->currentMenu = nullptr;
  //

void LcdHandler::changeMenu(Menu& newMenu){
  currentMenu = &newMenu;

  }


void LcdHandler::setMenu(Menu& newMenu){
    this->currentMenu = &newMenu;

}

 void LcdHandler::printCurrent(){
  currentMenu->printCurrent();
  }
 void LcdHandler::nextItem(){
  currentMenu->nextItem();
  }


/**
 * Loops until a new key is pressed. Then sets oldKey to the key found.
 * 
 * 
 */
int LcdHandler::getNewKey(){
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



void LcdHandler::doKey(int key){
    
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

void LcdHandler::setCursorPos(){
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

int LcdHandler::getKey(){
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
  
