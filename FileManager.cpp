#include <fstream>
#include <string>
#include "FILE_MANAGER.h"


// Returns the map w/ frequency (K,V)
std::map<std::string, int> FileManager::createMapFromFile() {
    std::map<std::string, int> foodFrequency;
    std::string ingredient;
    std::ifstream foodRead;
    foodRead.open("fooditems.txt");

    while (foodRead.good()) {
        std::getline(foodRead, ingredient);
        const auto ingredientLocation = foodFrequency.find(ingredient);

        if (ingredientLocation == foodFrequency.end()) {
            foodFrequency.insert(std::make_pair(ingredient, 1));
        }
        else {
            ingredientLocation->second++;
        }


    }


    foodRead.close();
    return foodFrequency;
}

// Writes map to the output
void FileManager::writeFile(const std::map<std::string, int>& map) {
    std::ofstream outputFile("frequency.dat");
    for (const auto& pair : map) {
        outputFile << pair.first << ": " << pair.second << std::endl;
    }

    outputFile.close();

}
