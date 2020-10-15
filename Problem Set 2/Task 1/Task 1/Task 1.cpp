// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Entity.h"
#include <vector>
#include <sstream>

int main()
{
    string selection = "";

    string intermediate;
    int position[2] = { 0, 0 };
    // Vector of string to save tokens 
    std::vector <string> tokens;
    Entity u1(1, "Mytical Creater", 99999);
    Entity u2(2, "Pikachu", 100);
    std::cout << "Program Start\n";

    while (true) {
        tokens.clear();
        std::cout << "Command Message: <ObjectID> ID GET, <ObjectID> ID SET <VALUE>, <ObjectID> NAME GET, <ObjectID> NAME SET <VALUE>, <ObjectID> HP GET, <ObjectID> HP SET <VALUE>, EXIT" << std::endl;
        //get the line and save into selection
        std::getline(std::cin, selection);

        std::stringstream check(selection);

        //string tokenizer
        while (std::getline(check, intermediate, ' ')) {
            tokens.push_back(intermediate);
        }

        // Check each token to determine what action to be taken
        if (tokens.size() == 3) {
            if (tokens[1] == "ID") {
                if (tokens[2] == "GET") {
                    if (stoi(tokens[0]) == u1.getEntityID()) {
                        std::cout << u1.getEntityID() << std::endl;
                    }
                    else if (stoi(tokens[0]) == u2.getEntityID()) {
                        std::cout << u2.getEntityID() << std::endl;
                    }
                }
            }
            else if (tokens[1] == "NAME") {
                if (tokens[2] == "GET") {
                    if (stoi(tokens[0]) == u1.getEntityID()) {
                        std::cout << u1.getName() << std::endl;
                    }
                    else if (stoi(tokens[0]) == u2.getEntityID()) {
                        std::cout << u2.getName() << std::endl;
                    }
                }
            }
            else if (tokens[1] == "HP") {
                if (tokens[2] == "GET") {
                    if (stoi(tokens[0]) == u1.getEntityID()) {
                        std::cout << u1.getHP() << std::endl;
                    }
                    else if (stoi(tokens[0]) == u2.getEntityID()) {
                        std::cout << u2.getHP() << std::endl;
                    }
                }
            }
        }
        else if (tokens.size() == 4) {
            if (tokens[1] == "ID") {
                if (tokens[2] == "SET") {
                    if (stoi(tokens[0]) == u1.getEntityID()) {
                        u1.setEntityID(std::stoi(tokens[3]));
                    }
                    else if (stoi(tokens[0]) == u2.getEntityID()) {
                        u2.setEntityID(std::stoi(tokens[3]));
                    }
                }
            }
            else if (tokens[1] == "NAME") {
                if (tokens[2] == "SET") {
                    if (stoi(tokens[0]) == u1.getEntityID()) {
                        u1.setName(tokens[3]);
                    }
                    else if (stoi(tokens[0]) == u2.getEntityID()) {
                        u2.setName(tokens[3]);
                    }
                }
            }
            else if (tokens[1] == "HP") {
                if (tokens[2] == "SET") {
                    if (stoi(tokens[0]) == u1.getEntityID()) {
                        u1.setHP(std::stoi(tokens[3]));
                    }
                    else if (stoi(tokens[0]) == u2.getEntityID()) {
                        u2.setHP(std::stoi(tokens[3]));
                    }
                }
            }
        }
        else if (tokens[0] == "EXIT") {
            std::cout << "Exit Program" << std::endl;
            break;
        }
    }
}