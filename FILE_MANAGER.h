#pragma once


#include <map>

struct FileManager {
	std::map<std::string, int> createMapFromFile();
	void writeFile(const std::map<std::string, int>& map);




};
