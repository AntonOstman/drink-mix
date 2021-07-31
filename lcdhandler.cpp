
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
  Menu* funMenu = menuFactory.createMenu(FUN_MENU, *this);
  
  menus[MAIN_MENU] = mainMenu;
  menus[DRINK_MENU] = drinkMenu;
  menus[FUN_MENU] = funMenu;
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

// this is horrible but works for now. should be changed later
int LcdHandler::getNewKey(){
  // wait until the current buttonm, if any, is released
  while(getKey() != 0){
    // do nothing
    }
    // wait until a new button is pressed
  int newKey = getKey();

  while(newKey == 0){
    // make sure that the new key found is an actual key press and not a random value from the
    // ad conversion
      newKey = doubleCheckKey();
    }  
  return newKey;
  }

int LcdHandler::doubleCheckKey(){

bool twoDifferentValues = true;
int correctValue;
while(twoDifferentValues){


  int firstKey = getKey();
  delay(100);
  int secondKey = getKey();

  if (firstKey == secondKey){
    twoDifferentValues = false;
    correctValue = secondKey;
    }
  }
  return correctValue;
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
      currentMenu-> left();
      break;
    
    case 3:
      currentMenu-> down();
      break;
    
    case 4:
      currentMenu -> right();
      break;
    
    case 5:
      currentMenu -> up();
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

int LcdHandler::getKey2(int read){
  
  //int analogPin = A0;
  //int val = analogRead(analogPin);
  
  if (read > 300){
    return 0;
    }
  else if(read > 180){
    return 1; // select
    }
  else if(read > 110){
    return 2; // left
    }
  else if (read > 32){
    return 3; // down
    }
  else if (read > 12){
    return 4; // right
    }
  else{
    return 5; // up
     } 
 }
  
int LcdHandler::getKey(){
  
  int analogPin = A0;
  int read = analogRead(analogPin);
  
  if (read > 300){
    return 0;
    }
  else if(read > 180){
    return 1; // select
    }
  else if(read > 110){
    return 2; // left
    }
  else if (read > 32){
    return 3; // down
    }
  else if (read > 12){
    return 4; // right
    }
  else{
    return 5; // up
     } 
 }
  