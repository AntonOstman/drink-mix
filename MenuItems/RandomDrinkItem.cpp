

#include "RandomDrinkItem.h"
#include "LcdHandler.h"
#include "MenuType.h"


void RandomDrinkItem::select(){
    int randomVolumeOne = 0;
    int randomVolumeTwo = 0;
    lcd->resetLcd();

    if (drinkType == SHOT){
        randomVolumeTwo = rand() % (lcd->MAX_VOLUME / 10);
        lcd->print("You got: ");
        lcd->print(randomVolumeTwo);
    }
    else{
        randomVolumeOne = rand() % lcd->MAX_VOLUME;
        randomVolumeTwo = lcd->MAX_VOLUME - randomVolumeOne;
        lcd->print("You got: ");
        lcd->print(randomVolumeOne);
        lcd->print("/");
        lcd->print(randomVolumeTwo);
    
    }
    // give user time to read volume 
    delay(1500);

    lcd->pumpAmount(randomVolumeOne, randomVolumeTwo);


}

void RandomDrinkItem::changeDrinkType(DrinkType drinkType){

    this->drinkType = drinkType;
}