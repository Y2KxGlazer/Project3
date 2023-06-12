#include <iostream>
#include "MENUS.h"




void Menus::printMenu() {
	for (int i = 0; i < menuSize; i++) {
		std::cout << i << ". " << menusOptions[i] << std::endl;

	}
	
}




// Ask user for choice -> perform ops based on guidelines
