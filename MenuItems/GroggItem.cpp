

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
  lcd->pumpAmount(volumePumpOne, volumePumpTwo);

}
