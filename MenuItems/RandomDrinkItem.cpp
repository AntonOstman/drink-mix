

#include "RandomDrinkItem.h"
#include "LcdHandler.h"
#include "MenuType.h"


void RandomDrinkItem::select(){

    int randomVolumeOne = rand() % lcd->MAX_VOLUME;
    int spanPumpTwo = lcd->MAX_VOLUME - randomVolumeOne;  // span pump two makes sure does not pump more than 100
    int randomVolumeTwo = rand() % spanPumpTwo;

    lcd->resetLcd();
    lcd->print("You got: ");
    lcd->print(randomVolumeOne);
    lcd->print("/");
    lcd->print(randomVolumeTwo);
    delay(1500);

    lcd->pumpAmount(randomVolumeOne, randomVolumeTwo);


}
