#include "VolumeItem.h"
#include "LcdHandler.h"
#include "MenuType.h"


 // groggitem and volume item has same left and right, some functionality should be lifted up
void VolumeItem::left(){
  if (volumeAmount > 0){
    volumeAmount -= 5;

  }
}
// groggitem and volume item has same left and right, some functionality should be lifted up
void VolumeItem::right(){
  if (volumeAmount < 100){
    volumeAmount += 5;

  }
}

void VolumeItem::select(){
  lcd->togglePin(selectedPump);
  delay(volumeAmount * lcd->LIQUID_SCALE);
  lcd->togglePin(selectedPump);

}

void VolumeItem::printAll(){
  lcd->print(menuText);
  lcd->print(" vol: ");
  lcd->print(volumeAmount);

}
void VolumeItem::setSelectedPump(int pin){
  selectedPump = pin;
}

