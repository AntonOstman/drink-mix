#include "VolumeItem.h"
#include "LcdHandler.h"
#include "MenuType.h"


 // groggitem and volume item has same left and right, some functionality should be lifted up
void VolumeItem::left(){
  if (volumeAmount > 0){
    volumeAmount -= increase;

  }
}
// groggitem and volume item has same left and right, some functionality should be lifted up
void VolumeItem::right(){
  if (volumeAmount < max){
    volumeAmount += increase;

  }
}

void VolumeItem::select(){
  lcd->pumpOne(volumeAmount, selectedPump);

}



void VolumeItem::printAll(){
  lcd->print(menuText);
  lcd->print(volumeAmount);

}
void VolumeItem::setSelectedPump(PumpType pumpType){
  selectedPump = pumpType;
}

void VolumeItem::setMax(int max){
 this->max = max;
}

void VolumeItem::setIncrease(int increase){
  this->increase = increase;

}