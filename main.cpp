#include <Arduino.h>

// include the library code:
#include <LiquidCrystal.h>
#include "MenuItem.h"
#include "Menu.h"
#include "LcdHandler.h"
#include "MenuItemContainer.h"
#include "MenuFactory.h"
#include "MenuType.h"


int PUMP_ONE = 3;
int PUMP_TWO = 2;

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
//LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
LcdHandler lcd(8, 9, 4, 5, 6, 7);
MenuFactory menuFactory;

//menuItem texts[] = {menu1Pointer, menu1Pointer ,menu1Pointer};



void setup() {
  // put your setup code here, to run once:

    Menu* mainMenu = menuFactory.createMenu(MAIN, lcd);

    lcd.setMenu(*mainMenu);



    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.cursor();
    lcd.updateScreen();
    pinMode(PUMP_ONE, OUTPUT);
    pinMode(PUMP_TWO, OUTPUT);
}


void loop() {

  // put your main code here, to run repeatedly:
  int key = lcd.getKey();
  if (lcd.checkNewKey(key)){
    lcd.doKey(key); 
    lcd.updateScreen();
  } 


  lcd.setCursorPos();
}


