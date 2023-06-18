#include <iostream>
#include "MENUS.h"




// Prints the menu
void Menus::printMenu() {
	for (int i = 0; i < menuSize; i++) {
		std::cout << i+1 << ". " << menusOptions[i] << std::endl;
	}

}

// Prompts user for input
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



// Definitions

// This is the quantity/frequency of item
void Menus::optionOne(){
	
	system("cls");
	const auto mapEnd = foodData.end();

	std::string ingChoice;
	std::cout << "Enter ingredient to find.\n";
	std::cin >> ingChoice;
	ingChoice[0] = std::toupper(ingChoice[0]);
	auto f = foodData.find(ingChoice);

	if (f != mapEnd) {

		std::cout << f->first << " Frequencey: " << f->second << std::endl;
	}
	else {
		std::cout << "Item not found!\n";
	}

	}

// This prints the entire map
void Menus::optionTwo(){
	for (const auto& pair : foodData) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}


	}

// This is the histogram
void Menus::optionThree(){
	auto f = foodData;
	for (auto itMap = f.begin(); itMap != f.end(); ++itMap) {
		std::cout << itMap->first << ": ";
		for (int i = 0; i < itMap->second; i++) {
			std::cout << '*';
		}
		std::cout << "\n";
	}


	}
	
// Exits the program
void Menus::optionFour() {
	runFlag = false;
	

}

void Menus::initUserMenuChoice(int userMenuInput) {
	

}

Menus::Menus(FileManager& fm, bool run) {
	userMenuInput = 0;
	std::vector<void (Menus::*)()> functionList{ &Menus::optionOne, &Menus::optionTwo, &Menus::optionThree, &Menus::optionFour };
	foodData = fm.createMapFromFile();
	runFlag = run;
	
}



