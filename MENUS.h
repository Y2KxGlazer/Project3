#pragma once
#include <vector>
#include <string>

struct Menus {

	// Options for the menu
	std::vector<std::string> menusOptions{ "What are you looking for?"
, "List all items", "List all items as graph", "Exit" };

	int userMenuInput;
	int menuSize = menusOptions.size();

	void printMenu();
	void userMenuChoice();


	// userMenuInput -> if statements
	// if 1 userMenuINput return second value., Clear screen.
	// if 2 print map, Clear screen.
	// if 3 get value of key from map, then, return a char for value , Clear screen.
	// if 4 close program, Clear screen.
	
};