#pragma once
#include <vector>
#include <string>

struct Menus {

	// Options for the menu
	std::vector<std::string> menusOptions{ "What are you looking for?"
, "List all items", "List all items as graph", "Exit" };

	int userMenuChoice;
	int menuSize = menusOptions.size();

	void printMenu();
};