//#include <Keyboard.h>

#include "Menu.h"
#include "LcdHandler.h"
#include "ButtonType.h"
#include "MenuItem.h"
Menu::Menu(int menuSize, LcdHandler& lcd) {
  this->menuItems = new MenuItem*[menuSize];
  this->lcd = &lcd;
  this->menuSize = menuSize;
  selectedMenu = menuSize - 1;
  cursorPos = 0;
  
  }

Menu::~Menu(){
  
  // we need to destroy the menuItem objects inside of the array of pointers
  for(int i = 0; i  < menuSize; i++){
    delete menuItems[i];
  }
  
  delete[] menuItems;

}

int Menu::getMenuItemAmount(){
  return menuSize;
  
  }

void Menu::printMenus(){

  lcd->clear();
  lcd->setCursor(0,0);
  byte customCursor = byte(0);
  lcd->write(customCursor);
  printMenu(selectedMenu);
  lcd->setCursor(0,1);
  if (selectedMenu > 0){
    printMenu(selectedMenu - 1);  
    }
  }


void Menu::menuButtonPress(ButtonType buttontype){
  // if selected menu is out of range then do nothing
  // otherwise we print the menus which are selected
  
  if (buttontype == DOWN){
    if (!(selectedMenu > 0)){
      return;
    }
    selectedMenu--;
  }
  else if (buttontype == UP){
    if (!(selectedMenu < menuSize - 1)){

      return;
    }
    selectedMenu++;
  }
}


void Menu::printMenu(int index){
  menuItems[index]->printAll();
  
  }


void Menu::setCursorPos(){
  lcd->setCursor(cursorPos, 0);
  }

void Menu::addMenuItem(int index, MenuItem* item){
  menuItems[index] = item;
  
  }

MenuItem Menu::getMenuItem(int index){
  return *menuItems[index];
  }

  void Menu::select(){
    menuItems[selectedMenu]->select();
  
  }
  void Menu::up(){
    menuButtonPress(UP);

  }

  void Menu::down(){
    menuButtonPress(DOWN);
  
  }
  void Menu::left(){
    menuItems[selectedMenu]->left();
  }
  void Menu::right(){
    menuItems[selectedMenu]->right();
  }


   
    
void Menu::playRoulette(){
  lcd->resetLcd();
  
  lcd->setCursor(0,0);
  int scrollSpeed = 5;
  int scrollDeceleration = 1;
  int randomItemIndex;
  int randomItemAmount = 20;
  String megaText = String("");

  MenuItem* randomMenuItem;
  const char* randomText;
  
  
  for (int i = 0; i < randomItemAmount; i++)
  {
    // when more than half have been scrolled increase the deceleration
    if (i > randomItemAmount - 4 ){
      scrollDeceleration += 1;
    }
    randomItemIndex = rand() % menuSize;
    randomMenuItem = menuItems[randomItemIndex];

    randomText = randomMenuItem->getText();
    
    for (int i = 0; i < randomMenuItem->getSize(); i++){
      if (megaText.length() == 16){
        megaText.remove(0,1);
        megaText += randomText[i];
        scrollSpeed += scrollDeceleration;
        delay(scrollSpeed);

      }
      else{
        megaText.concat(randomText[i]);
      }
      lcd->resetLcd();
      lcd->print(megaText);

    }
    // add two spaces in between each item
    int spaces = 2;
    for (int i = 0; i < spaces; i++)
    {
      megaText.remove(0,1);
      megaText += " ";
      scrollSpeed += scrollDeceleration;
      delay(scrollSpeed);

      lcd->resetLcd();
      lcd->print(megaText);
    }
    

  }
  lcd->resetLcd();
  lcd->print("!!");
  lcd->print(randomText);
  lcd->print("!!");
  delay(2000);
  randomMenuItem->select();
}