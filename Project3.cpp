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

    auto foodWithFreq = createMapFromFile();
    
    bool isRunning = true;



    Menus men1;
    men1.printMenu();
    writeFile(createMapFromFile());

    do {
        men1.userMenuChoice();
        std::string ingChoice;

        // This is the quantity/frequency of item
        if (men1.userMenuInput == 1) {
            system("cls");
            const auto mapEnd = foodWithFreq.end();
            
            std::cout << "Enter ingredient to find.\n";
            std::cin >> ingChoice;
            ingChoice[0] = std::toupper(ingChoice[0]);
            auto f = foodWithFreq.find(ingChoice);

            if (f != mapEnd) {

                std::cout << f->first << " Frequencey: " << f->second << std::endl;
            }
            else {
                std::cout << "Item not found!\n";
            }
        }

        // This prints the entire map
        else if (men1.userMenuInput == 2) {
            for (const auto& pair : foodWithFreq) {
                std::cout << pair.first << ": " << pair.second << std::endl;
            }

        }

        // This is the histogram
        else if (men1.userMenuInput == 3) {
            auto f = foodWithFreq;
            for ( auto itMap = f.begin(); itMap != f.end(); ++itMap) {
                std::cout << itMap->first << ": ";
                for (int i = 0; i < itMap->second; i++) {
                    std::cout << '*';
                }
                std::cout << "\n";
            }
        }


        else if (men1.userMenuInput == 4) {
            isRunning = false;
        }
        else { // Not possible to reach 
            isRunning = false;
            
        }

    } while (isRunning);

    
    
    
    

   
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
    std::ofstream outputFile("frequency.dat");
    for (const auto& pair : map) {
        outputFile << pair.first << ": " << pair.second << std::endl;
    }

    outputFile.close();

}


