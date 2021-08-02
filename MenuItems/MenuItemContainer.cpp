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

