

#include "GroggItem.h"
#include "LcdHandler.h"
#include "MenuType.h"

 // groggitem and volume item has same left and right, some functionality should be lifted up
void GroggItem::left(){
  if (volumeAmount > 0){
    volumeAmount -= 5;

  }
}
// groggitem and volume item has same left and right, some functionality should be lifted up
void GroggItem::right(){
  if (volumeAmount < 100){
    volumeAmount += 5;

  }
}

void GroggItem::printAll(){
  lcd->print(menuText);
  int volumePumpOne = volumeAmount;
  int volumePumpTwo = 100 - volumeAmount;
  lcd->print(volumePumpOne);
  lcd->print("/");
  lcd->print(volumePumpTwo);
}

void GroggItem::select(){
  int volumePumpOne = volumeAmount;
  int volumePumpTwo = 100 - volumeAmount;
  
  // we get three different cases which we need to handle accordingly to pump
  // the correct amount
  // 1. pumpone time is shorter, 2. pump one time is longer, 3. pump times are equal.
  // this ensures they pump at the same time and the time that is shorter stops first.
  lcd->togglePin(lcd->PUMP_ONE);
  lcd->togglePin(lcd->PUMP_TWO);
  
  if (volumePumpOne < volumePumpTwo){
    delay(volumePumpOne * lcd->LIQUID_SCALE);
    lcd->togglePin(lcd->PUMP_ONE);
    delay(volumePumpTwo * lcd->LIQUID_SCALE);
    lcd->togglePin(lcd->PUMP_TWO);

  }

  else if (volumePumpOne > volumePumpTwo){
    delay(volumePumpTwo * lcd->LIQUID_SCALE);
    lcd->togglePin(lcd->PUMP_TWO);
    delay(volumePumpOne * lcd->LIQUID_SCALE);
    lcd->togglePin(lcd->PUMP_ONE);

  }
  else{
    delay(volumePumpOne * lcd->LIQUID_SCALE);
    lcd->togglePin(lcd->PUMP_ONE);
    lcd->togglePin(lcd->PUMP_TWO);


  }

}
