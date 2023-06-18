#pragma once
#include <vector>
#include <string>
#include "FILE_MANAGER.h"


struct Menus {
	bool runFlag;
	// Options for the menu
	std::vector<std::string> menusOptions{ "What are you looking for?"
, "List all items", "List all items as graph", "Exit" };

	int userMenuInput;

	// The supposed map of the data
	std::map<std::string, int> foodData;
	int menuSize = menusOptions.size();

	
	

	void printMenu();
	void userMenuChoice();

	void initUserMenuChoice(int userMenuInput);



	void optionOne();
	void optionTwo();
	void optionThree();
	void optionFour();

	// If new function/menu option created add to vector below
	std::vector<void (Menus::*)()> functionList{ &Menus::optionOne, &Menus::optionTwo, &Menus::optionThree, &Menus::optionFour }; // List of function pointers
	Menus(FileManager& fm, bool &run);
	


	// userMenuInput -> if statements
	// if 1 userMenuINput return second value., Clear screen.
	// if 2 print map, Clear screen.
	// if 3 get value of key from map, then, return a char for value , Clear screen.
	// if 4 close program, Clear screen.
	
};