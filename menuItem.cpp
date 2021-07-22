#include "MenuItem.h"
#include "LcdHandler.h"


MenuItem::MenuItem(const char menuText[], LcdHandler& lcd){
  this->menuText = menuText;
  this->lcd = &lcd;
}

MenuItem::~MenuItem(){
  delete menuText;
}

int MenuItem::getSize(){
  return strlen(menuText);
}

void MenuItem::printAll(){
  for(int i=0; i < getSize(); i++){
    lcd->print(menuText[i]);
    }
  }

void MenuItem::action(ButtonType button){
  if (button == SELECT){
    lcd->print("com");
    }
  
  }

void MenuItem::left(){

}
void MenuItem::right(){
  
}
void MenuItem::select(){
  lcd->print("parent");
  
  }
