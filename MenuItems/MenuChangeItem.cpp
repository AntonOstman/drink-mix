#include "MenuChangeItem.h"
#include "LcdHandler.h"
#include "MenuType.h"


// changes menu, default if nothing else is set is MAIN_MENU
void MenuChangeItem::select(){

  lcd->changeMenu(selectedMenu);

}

//Changes the menu which will be changed to when pressing select
  void MenuChangeItem::changeMenuType(MenuType menuType){

    this->selectedMenu = menuType;
  }


