// 6/12/23
//

#include <iostream>
#include "MENUS.h"
#include "FILE_MANAGER.h"





int main()
{
    FileManager data1;

    bool isRunning = true;
    Menus men1(data1, isRunning);
   
    do {
        men1.printMenu();
        men1.userMenuChoice();
        men1.initUserMenuChoice(men1.userMenuInput);
    } while (men1.runFlag);

   
    system("pause");
    return 0;
    
}






