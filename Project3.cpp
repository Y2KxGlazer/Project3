// Stephon Banks
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
    men1.printMenu();
    

    do {
        men1.userMenuChoice();
        

    } while (men1.runFlag);


   
    system("pause");
    return 0;
    
}






