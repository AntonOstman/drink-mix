#include <Arduino.h>

// include the library code:
#include <LiquidCrystal.h>
#include "menuItem.h"
#include "menu.h"
#include "lcdHandler.h"
#include "menuItemContainer.h"


int analogPin = A0;
int cursorPos = 0;
int light = 0;
int pumpPinThree = 3;
int pumpPinTwo = 2;


int menyUp = 0;
int menyLeftRight = 0;

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//menuItem texts[] = {menu1Pointer, menu1Pointer ,menu1Pointer};



void setup() {
  // put your setup code here, to run once:
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.cursor();
    pinMode(pumpPinThree, OUTPUT);
    pinMode(pumpPinTwo, OUTPUT);
}

char q1[] = "hejsan1";
char q2[] = "hejsan2";
char q3[] = "hejsan3";
char q4[] = "hejsan4";
  
menuPrinter menu1(q1,lcd);
menuPrinter menu2(q2,lcd);
menuItem menu3(q3,lcd);
menuItem menu4(q4,lcd);

menuPrinter *menu1Pointer = &menu1;
menuPrinter *menu2Pointer = &menu2;
menuItem *menu3Pointer = &menu3;
menuItem *menu4Pointer = &menu4;
  
int menuSize = 4;
menu menus(menuSize, lcd);
lcdHandler lcdhandler(menus,lcd);

void loop() {

  menus.addMenuItem(0,menu1Pointer);
  menus.addMenuItem(1,menu2Pointer);
  menus.addMenuItem(2,menu3Pointer);
  menus.addMenuItem(3,menu4Pointer);
  // put your main code here, to run repeatedly:

  int newKey = lcdhandler.getNewKey();
  
  lcdhandler.doKey(newKey);
  lcdhandler.setCursorPos();
}

void toggleOutput(int pin){
  if (light == 1){
    digitalWrite(pin, HIGH);
    }
  else{    
    digitalWrite(pin, LOW);
    }
  }