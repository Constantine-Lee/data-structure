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

        // if command size is 2 then check whether to Damage or Heal, if 3 then execute Move command;
        if (tokens.size() == 3) {
            if (tokens[1] == "ID") {
                if (tokens[2] == "GET") {
                    if (tokens[0] == "1") {
                        std::cout << u1.getEntityID() << std::endl;
                    }
                    else if (tokens[0] == "2") {
                        std::cout << u2.getEntityID() << std::endl;
                    }
                }
            }
            else if (tokens[1] == "NAME") {
                if (tokens[2] == "GET") {
                    if (tokens[0] == "1") {
                        std::cout << u1.getName() << std::endl;
                    }
                    else if (tokens[0] == "2") {
                        std::cout << u2.getName() << std::endl;
                    }
                }
            }
            else if (tokens[1] == "HP") {
                if (tokens[2] == "GET") {
                    if (tokens[0] == "1") {
                        std::cout << u1.getHP() << std::endl;
                    }
                    else if (tokens[0] == "2") {
                        std::cout << u2.getHP() << std::endl;
                    }
                }
            }
        }
        else if (tokens.size() == 4) {
            if (tokens[1] == "ID") {
                if (tokens[2] == "SET") {
                    if (tokens[0] == "1") {
                        u1.setEntityID(std::stoi(tokens[3]));
                    }
                    else if (tokens[0] == "2") {
                        u2.setEntityID(std::stoi(tokens[3]));
                    }
                }
            }
            else if (tokens[1] == "NAME") {
                if (tokens[2] == "GET") {
                    if (tokens[0] == "1") {
                        u1.setName(tokens[3]);
                    }
                    else if (tokens[0] == "2") {
                        u2.setName(tokens[3]);
                    }
                }
            }
            else if (tokens[1] == "HP") {
                if (tokens[2] == "GET") {
                    if (tokens[0] == "1") {
                        u1.setHP(std::stoi(tokens[3]));
                    }
                    else if (tokens[0] == "2") {
                        u2.setHP(std::stoi(tokens[3]));
                    }
                }
            }
        }
        else if (tokens[0] == "EXIT"){
            std::cout << "Exit Program" << std::endl;
            break;
        }
    }
}