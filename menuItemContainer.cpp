#include "MenuItemContainer.h"
#include "LcdHandler.h"
#include "MenuType.h"

void MenuPrinter::select(){
  lcd->clear();
  lcd->setCursor(0,0);
  lcd->print("Pumping pump one");
  lcd->togglePin(lcd->PUMP_ONE);
  delay(1000);
  }  

void MixerItem::select(){

  lcd->changeMenu(DRINK_MENU);

}

void BackItem::select(){

  // think about changing to enums instead...
  // reason it is not enum already is because index is chosen with the integers in lcdHandler 
  // for which menu to choose in method changeMenu
  int currentMenu = lcd->getMenuType();

  switch (currentMenu)
  {
  case MAIN_MENU:
    /* code */
    break;
  case DRINK_MENU:
    lcd->changeMenu(MAIN_MENU);
    break;
  default:
    break;
  }
}