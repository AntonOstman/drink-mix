#include "menuItem.h"
#include "lcdHandler.h"


menuItem::menuItem(char menuText[], lcdHandler& lcd){
  this->menuText = menuText;
  this->lcd = &lcd;
}

menuItem::~menuItem(){
  delete menuText;
}

int menuItem::getSize(){
  return strlen(menuText);
}

void menuItem::printAll(){
  for(int i=0; i < getSize(); i++){
    lcd->print(menuText[i]);
    }
  }

void menuItem::action(buttonType button){
  if (button == SELECT){
    lcd->print("com");
    }
  
  }


void menuItem::select(){
  lcd->print("parent");
  
  }
