#include "RouletteItem.h"
#include "LcdHandler.h"
#include "MenuType.h"

void RouletteItem::select(){
    lcd->changeMenu(ROULETTE_MENU);
    lcd->roulette();
    lcd->changeMenu(FUN_MENU);
}