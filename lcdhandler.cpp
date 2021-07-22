
#include "LcdHandler.h"
#include "Menu.h"
#include "MenuFactory.h"

void LcdHandler::changeMenu(Menu* newMenu){
  currentMenu = newMenu;

  }

void LcdHandler::resetLcd(){
  clear();
  setCursor(0,0);

}

void LcdHandler::setupMenus(){
  MenuFactory menuFactory;
  Menu* mainMenu = menuFactory.createMenu(MAIN_MENU, *this);
  Menu* drinkMenu = menuFactory.createMenu(DRINK_MENU, *this);
  menus[MAIN_MENU] = mainMenu;
  menus[DRINK_MENU] = drinkMenu;
  this->currentMenu = menus[MAIN_MENU];

}

void LcdHandler::changeMenu(MenuType menuType){
  this->menuType = menuType;
  currentMenu = menus[menuType];
}

int LcdHandler::getMenuType(){
  return menuType;
}

void LcdHandler::setMenu(Menu* newMenu){
    this->currentMenu = newMenu;
}

 void LcdHandler::printCurrent(){
  currentMenu->printCurrent();
  }

    // toggles a pin on the PORTD row of the arduino
  void LcdHandler::togglePin(int pin){
    int pinStatus = bitRead(PORTD, pin);
    

    if (pinStatus == 0){
      digitalWrite(pin, HIGH);
      }
    else{    
      digitalWrite(pin, LOW);
      }
  
  }

 void LcdHandler::nextItem(){
  currentMenu->nextItem();
  }

void LcdHandler::updateScreen(){
  currentMenu->printMenus();
  
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

bool LcdHandler::checkNewKey(int newKey){
  
  if (newKey != keyPressed){
    keyPressed = newKey;
    return true;

  }
  return false;

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
  
