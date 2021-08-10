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
  lcd->pumpOne(volumeAmount, selectedPump);

}

void VolumeItem::setVolume(int volume){
  volumeAmount = volume;

}

void VolumeItem::printAll(){
  lcd->print(menuText);
  lcd->print(" vol: ");
  lcd->print(volumeAmount);

}
void VolumeItem::setSelectedPump(PumpType pumpType){
  selectedPump = pumpType;
}

