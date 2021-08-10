

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

void GroggItem::setVolume(int volume){
  volumeAmount = volume;

}

void GroggItem::printAll(){
  lcd->print(menuText);
  int volumeSoftDrink = volumeAmount;
  int volumeAlcoholPump = 100 - volumeAmount;
  lcd->print(volumeSoftDrink);
  lcd->print("/");
  lcd->print(volumeAlcoholPump);
}

void GroggItem::select(){
  int volumeSoftDrink = volumeAmount;
  int volumeAlcoholPump = 100 - volumeAmount;
  lcd->pumpVolume(volumeSoftDrink, volumeAlcoholPump);

}
