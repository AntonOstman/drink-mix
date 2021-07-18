//#include <Keyboard.h>

#include "menu.h"
#include "menuItem.h"
#include <LiquidCrystal.h>

menu::menu(int menuSize, LiquidCrystal& lcd) {
  this->menuItems = new menuItem*[menuSize];
  this->lcd = &lcd;
  this->menuSize = menuSize;
  selectedMenu = 0;
  cursorPos = 0;
  
  }

menu::~menu(){
  
  // we need to destroy the menuItem objects inside of the array of pointers
  for(int i = 0; i  < menuSize; i++){
    delete menuItems[i];
  }
  
  delete[] menuItems;

}

int menu::getMenuItemAmount(){
  return menuSize;
  
  }

void menu::printMenus(){
  for(int i=0; i < menuSize; i++ ){
      menuItems[i]->printAll();
    }
    
  }
void menu::printCurrent(){
  menuItems[selectedMenu]->printAll();
  
  }
  
  void menu::nextItem(){
    
    if (sizeof(menuItems) == selectedMenu){
      cursorPos = 0;
      selectedMenu = 0;
      }
    else{
      int textSize = 0;
      textSize = menuItems[selectedMenu]->getSize();
      cursorPos = cursorPos + textSize;
      
      selectedMenu++;
    }
   }

void menu::setCursorPos(){
  lcd->setCursor(cursorPos, 0);
  }

void menu::addMenuItem(int index, menuItem* item){
  menuItems[index] = item;
  
  }

menuItem menu::getMenuItem(int index){
  return *menuItems[index];
  }
    void menu::select(){
      menuItems[selectedMenu]->select();
    
    }
    void menu::up(){
    if(selectedMenu < menuSize - 1){
      selectedMenu++;
      lcd->clear();
      lcd->setCursor(0,0);
      menuItems[selectedMenu]->printAll();
      lcd->setCursor(0,1);
      menuItems[selectedMenu - 1]->printAll();
      } 
    lcd->print(selectedMenu);

    }
    void menu::down(){
    if(selectedMenu > 0){
      selectedMenu--;
      lcd->clear();
      lcd->setCursor(0,0);
      menuItems[selectedMenu]->printAll();
      lcd->setCursor(0,1);
      if(selectedMenu != 0){
        menuItems[selectedMenu - 1]->printAll();
        }
      }
    }
    void menu::left(){

    }
    void menu::right(){


    }
void menu::action(buttonType button){

  switch(button){
    case DOWN:
     if(selectedMenu > 0){
      selectedMenu--;
      lcd->clear();
      lcd->setCursor(0,0);
      menuItems[selectedMenu]->printAll();
      lcd->setCursor(0,1);
      if(selectedMenu != 0){
        menuItems[selectedMenu - 1]->printAll();
        }
      }
      break;

    case UP:
    // menuSize -1 so that selected menu does not reach the maximum.
    if(selectedMenu < menuSize - 1){
      selectedMenu++;
      lcd->clear();
      lcd->setCursor(0,0);
      menuItems[selectedMenu]->printAll();
      lcd->setCursor(0,1);
      menuItems[selectedMenu - 1]->printAll();
      } 
      lcd->print(selectedMenu);
      break;

    case LEFT:
//     lcd->print("3");

      break;
      
    case RIGHT:
//     lcd->print("2");

      break;
    case SELECT:
      menuItems[selectedMenu]->select();
      break;
    default:
      lcd->print("error");
      break;
  
  }
}


   
    
