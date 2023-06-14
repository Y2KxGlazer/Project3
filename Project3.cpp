// Stephon Banks
// 6/12/23
//

#include <iostream>
#include <fstream>
#include <map>
#include "MENUS.h"


std::map<std::string, int> createMapFromFile();
void writeFile(const std::map<std::string, int>& map);


int main()
{
    std::map<std::string, int> foodItems;



    Menus men1;
    men1.printMenu();
    men1.userMenuChoice();
    
    
    writeFile(createMapFromFile());

    std::cout << "lmao" << std::endl;
    system("pause");
    return 0;
    
}

// Returns the map w/ frequency 
std::map<std::string, int> createMapFromFile() {
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
void writeFile(const std::map<std::string, int>& map) {
    std::ofstream outputFile("output.txt");
    for (const auto& pair : map) {
        outputFile << pair.first << ": " << pair.second << std::endl;
    }

    outputFile.close();

}


