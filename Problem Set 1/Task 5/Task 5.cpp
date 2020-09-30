// Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Unit.h"
#include <vector>
#include <sstream>

int main()
{
    string selection ="";
   
    string intermediate;
    int position[2] = { 0, 0 };
    // Vector of string to save tokens 
    std::vector <string> tokens;
    Unit u1("Constantine", LAND, 0, position, 100, 100, 100, 100, 100, 100, Active);
    std::cout << "Program Start\n";

    while (true) {
        tokens.clear();
        u1.PingStatus();
        std::cout << "Command Message: Damage <Value>, Heal <Value>, Move <Value> <Value> " << std::endl;
        //get the line and save into selection
        std::getline(std::cin, selection);
        
        std::stringstream check(selection);

        //string tokenizer
        while (std::getline(check, intermediate, ' ')) {
            tokens.push_back(intermediate);
        }

        // if command size is 2 then check whether to Damage or Heal, if 3 then execute Move command;
        if (tokens.size() == 2) {
            if (tokens[0] == "Damage") {
                u1.setCurrentHP(u1.getCurrentHP() - std::stoi(tokens[1]));
            }
            else if (tokens[0] == "Heal") {
                u1.setCurrentHP(u1.getCurrentHP() + std::stoi(tokens[1]));
            }
        }
        else if (tokens.size() == 3) {
            if (tokens[0] == "Move") {
                int newPos[2] = { std::stoi(tokens[1]), std::stoi(tokens[2]) };
                u1.setPosition(newPos);
            }
        }
        else {
            std::cout << "Invalid input" << std::endl;
        }
    }          
}
