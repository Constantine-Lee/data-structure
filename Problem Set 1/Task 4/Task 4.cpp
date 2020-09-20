// Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Dragon.h"
#include "Bowman.h"
#include "Thief.h"

int main()
{
    int unitSelection = 0;
    int selection = 0;
    int position[2] = {0, 0};

    Unit u1("Constantine", LAND, 0, position, 100, 100, 100, 100, 100, 100, Active);
    Dragon d1("Constantine", LAND, 0, position, 100, 100, 100, 100, 100, 100, Active);
    Bowman b1("Constantine", LAND, 0, position, 100, 100, 100, 100, 100, 100, Active);
    Thief t1("Constantine", LAND, 0, position, 100, 100, 100, 100, 100, 100, Active);

    std::cout << "Program Start\n";

    while (unitSelection != 5 && selection != 6)
    {
        Unit unit;
        std::cout << "Press 1 for Base Unit, 2 for Dragon, 3 for Bowman, 4 for Thief, 5 to quit: ";
        if (std::cin >> unitSelection)
        {
            if (unitSelection == 1)
            {
                unit = u1;
            }
            else if (unitSelection == 2)
            {
                unit = d1;
            }
            else if (unitSelection == 3)
            {
                unit = b1;
            }
            else if (unitSelection == 4)
            {
                unit = t1;
            }
            else
            {
                break;
            }
        }
        else
        {
            // if input is not valid and is negative then request for a valid input
            std::cout << "Please enter a valid value" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cout << "Press 1 to PingStatus, 2 to Listen, 3 to Tell, 4 to Overloaded Listen, 5 to Overloaded Tell, 6 to Quit: ";
        if (std::cin >> selection)
        {
            if (selection == 1)
            {
                unit.PingStatus();
            }
            else if (selection == 2)
            {
                std::cout << "Listening..." << std::endl;
                string message;
                std::cin >> message;
                unit.Listen(message);
            }
            else if (selection == 3)
            {
                std::cout << "Telling..." << std::endl;
                unit.Tell();
            }
            else if (selection == 4)
            {
                std::cout << "Listening..." << std::endl;
                std::cin >> unit;
            }
            else if (selection == 5)
            {
                std::cout << "Telling..." << std::endl;
                std::cout << unit;
            }
            else 
            {
                break;
            }
        }
        else
        {
            // if input is not valid and is negative then request for a valid input
            std::cout << "Please enter a valid value" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    }
}
