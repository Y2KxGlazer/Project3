#include <iostream>
#include "MENUS.h"




void Menus::printMenu() {
	for (int i = 0; i < menuSize; i++) {
		std::cout << i+1 << ". " << menusOptions[i] << std::endl;
	}

}


void Menus::userMenuChoice() {
	try {
		std::cout << "Menu choice: ";
		std::cin >> userMenuInput; // if non int, and if out of range


		if (std::cin.fail()) {
			std::cin.clear();
			std::string invalidInput;
			std::cin >> invalidInput;  // Read the invalid input as a string to consume it
			throw std::invalid_argument(invalidInput);
		}
		

		if (userMenuInput < 1 || userMenuInput > menuSize) {
			throw std::out_of_range("Invalid option!");
		}
		
	}
	catch (const std::invalid_argument& e) {
		system("cls");
		std::cout << "Invalid input: \""<< e.what() << "\". Please input numerical values!" << std::endl;
		// clear screen beforehand -> reprint menu -> reprint recall function
		printMenu();
		userMenuChoice();
	}
	catch (const std::out_of_range& e) {
		system("cls");
		std::cout << "Value Error: " << e.what() << std::endl;
		printMenu();
		userMenuChoice();
		// clear screen beforehand -> reprint menu -> reprint recall function
	}

	
}





