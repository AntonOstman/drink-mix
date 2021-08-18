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
  volumeAmount -= 1;

}

void MenuItem::right(){
  volumeAmount += 1;
  
}
void MenuItem::select(){
  lcd->togglePump(SOFTDRINK_PUMP);
  }

const char* MenuItem::getText(){
  return menuText;

}

int MenuItem::getVolumeAmount(){
  return volumeAmount;
}

void MenuItem::setVolume(int volume){
  volumeAmount = volume;

}