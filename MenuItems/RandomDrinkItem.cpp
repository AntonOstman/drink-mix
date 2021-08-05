

#include "RandomDrinkItem.h"
#include "LcdHandler.h"
#include "MenuType.h"


void RandomDrinkItem::select(){
    int randomSoftDrinkVolume = 0;
    int randomAlcoholVolume = 0;
    lcd->resetLcd();

    if (drinkType == SHOT){
        randomAlcoholVolume = rand() % (lcd->MAX_VOLUME / 10);
        lcd->print("You got: ");
        lcd->print(randomAlcoholVolume);
    }
    else{
        randomSoftDrinkVolume = rand() % lcd->MAX_VOLUME;
        randomAlcoholVolume = lcd->MAX_VOLUME - randomSoftDrinkVolume;
        lcd->print("You got: ");
        lcd->print(randomSoftDrinkVolume);
        lcd->print("/");
        lcd->print(randomAlcoholVolume);
    
    }
    // give user time to read volume 
    delay(1500);

    lcd->pumpVolume(randomSoftDrinkVolume, randomAlcoholVolume);


}

void RandomDrinkItem::changeDrinkType(DrinkType drinkType){

    this->drinkType = drinkType;
}