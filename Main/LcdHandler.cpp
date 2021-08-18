
#include "LcdHandler.h"
#include "Menu.h"
#include "GuessGameMenu.h"
#include "MenuFactory.h"

void LcdHandler::changeMenu(Menu* newMenu){
  currentMenu = newMenu;

  }

void LcdHandler::resetLcd(){
  clear();
  setCursor(0,0);

}

void LcdHandler::pumpOne(int amount, PumpType pump){

  if (pump == SOFTDRINK_PUMP){
    pumpVolume(amount, 0);
  }
  else{
    pumpVolume(0, amount);
  }

}

void LcdHandler::togglePump(PumpType pump){
  // the pumps need to be in order with the enum delcaration 
  // otherwise this will toggle the wrong pump
  // switch case could probably be better. 
  int pin = pump + 2;

  togglePin(pin);

}


void LcdHandler::roulette(){
  currentMenu->playRoulette();

}

void LcdHandler::setupMenus(){
  MenuFactory menuFactory;
  
  Menu* mainMenu = menuFactory.createMenu(MAIN_MENU, *this);
  Menu* drinkMenu = menuFactory.createMenu(DRINK_MENU, *this);
  Menu* funMenu = menuFactory.createMenu(FUN_MENU, *this);
  Menu* rouletteMenu = menuFactory.createMenu(ROULETTE_MENU, *this);
  Menu* guessGameMenu = menuFactory.createMenu(GUESS_GAME, *this);

  menus[MAIN_MENU] = mainMenu;
  menus[DRINK_MENU] = drinkMenu;
  menus[FUN_MENU] = funMenu;
  menus[ROULETTE_MENU] = rouletteMenu;
  menus[GUESS_GAME] = guessGameMenu;
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


void LcdHandler::pumpVolume(int softDrinkVolume, int alcoholVolume){
  
  // we get three different cases which we need to handle accordingly to pump
  // the correct amount
  // 1. pumpone time is shorter, 2. pump one time is longer, 3. pump times are equal.
  // this ensures they pump at the same time and the time that is shorter stops first.
  togglePin(SOFTDRINK_PIN);
  togglePin(ALCOHOL_PIN);
  resetLcd();
  print("Pumping...");
  if (softDrinkVolume < alcoholVolume){
    delay(softDrinkVolume * LIQUID_SCALE);
    togglePin(SOFTDRINK_PIN);
    delay(alcoholVolume * LIQUID_SCALE);
    togglePin(ALCOHOL_PIN);

  }

  else if (softDrinkVolume > alcoholVolume){
    delay(alcoholVolume * LIQUID_SCALE);
    togglePin(ALCOHOL_PIN);
    delay(softDrinkVolume * LIQUID_SCALE);
    togglePin(SOFTDRINK_PIN);

  }
  else{
    delay(softDrinkVolume * LIQUID_SCALE);
    togglePin(SOFTDRINK_PIN);
    togglePin(ALCOHOL_PIN);


  }


}



/**
 * Loops until a new key is pressed. Then sets oldKey to the key found.
 * 
 * 
 */

// this is horrible but works for now. should be changed later
ButtonType LcdHandler::getNewKey(){
  // wait until the current buttonm, if any, is released
  while(getKey() != 0){
    // do nothing
    }
    // wait until a new button is pressed
  ButtonType newKey = getKey();

  while(newKey == 0){
    // make sure that the new key found is an actual key press and not a random value from the
    // ad conversion
      newKey = doubleCheckKey();
    }  
  return newKey;
  }

ButtonType LcdHandler::doubleCheckKey(){

bool twoDifferentValues = true;
ButtonType correctValue;
while(twoDifferentValues){


  ButtonType firstKey = getKey();
  delay(75);
  ButtonType secondKey = getKey();

  if (firstKey == secondKey){
    twoDifferentValues = false;
    correctValue = secondKey;
    }
  }
  return correctValue;
}

void LcdHandler::doKey(ButtonType key){
    
  switch(key){
    case NONE:
      // do nothing when no key found
      break;
    
    case SELECT:
        currentMenu-> select();
      break;
    
    case LEFT:
      currentMenu-> left();
      break;
    
    case DOWN:
      currentMenu-> down();
      break;
    
    case RIGHT:
      currentMenu -> right();
      break;
    
    case UP:
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

ButtonType LcdHandler::getKey2(int read){
  
  //int analogPin = A0;
  //int val = analogRead(analogPin);
  
  if (read > 300){
    return NONE;
    }
  else if(read > 180){
    return SELECT; // select
    }
  else if(read > 110){
    return LEFT; // left
    }
  else if (read > 32){
    return DOWN; // down
    }
  else if (read > 12){
    return RIGHT; // right
    }
  else{
    return UP; // up
     } 
 }
  
ButtonType LcdHandler::getKey(){
  
  int analogPin = A0;
  int read = analogRead(analogPin);
  
  if (read > 300){
    return NONE;
    }
  else if(read > 180){
    return SELECT; // select
    }
  else if(read > 110){
    return LEFT; // left
    }
  else if (read > 32){
    return DOWN; // down
    }
  else if (read > 12){
    return RIGHT; // right
    }
  else{
    return UP; // up
     } 
 }
  