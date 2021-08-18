#include <Arduino.h>

// include the library code:
#include <LiquidCrystal.h>
#include "MenuItem.h"
#include "Menu.h"
#include "LcdHandler.h"

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
  byte cursor[8] = {
    B11000000,
    B00110000,
    B00011100,
    B00000110,
    B00011100,
    B00110000,
    B11000000,
  };

    Serial.begin(9600);
    lcd.setupMenus();
    lcd.createChar(0, cursor);
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0,0);
    // lcd.cursor();
    lcd.updateScreen();
    pinMode(PUMP_ONE, OUTPUT);
    pinMode(PUMP_TWO, OUTPUT);
    
}


// prints the ADC numbers indefinaterly for testing purposes
void testADC(){
  while(true){
    lcd.setCursor(0,0);
    
    int val = analogRead(A0);
    lcd.print(lcd.getKey2(val));
    Serial.println(val);
    delay(100);
    lcd.print(" AD value: ");
    lcd.print(val);
    lcd.print("  ");


  }


}

void loop() {

  // put your main code here, to run repeatedly:
  //testADC();
  ButtonType key = lcd.getNewKey();
  
  // if(key == 1){
  //     while(true){
  //       Serial.println(key);
  //       Serial.println(adRead);
  //       while (true)
  //       {
  //         /* code */
  //       }
        
  //     }
  //   }
  //if (lcd.checkNewKey(key)){
    
  lcd.doKey(key); 
  lcd.updateScreen();
  //} 


  lcd.setCursorPos();
}


