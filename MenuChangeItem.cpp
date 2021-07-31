#include "MenuChangeItem.h"
#include "LcdHandler.h"
#include "MenuType.h"


void MenuChangeItem::select(){

  lcd->changeMenu(selectedMenu);

}
  void MenuChangeItem::changeMenuType(MenuType menuType){

    this->selectedMenu = menuType;
  }


