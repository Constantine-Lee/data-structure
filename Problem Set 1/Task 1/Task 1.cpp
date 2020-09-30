// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int selection = 0;
    std::cout << "Program Start\n";
    while (selection != 6) {
        std::cout << "Press 1 to PingStatus, 2 to Listen, 3 to Tell, 4 to Overloaded Listen, 5 to Overloaded Tell, 6 to Quit: ";
        if (std::cin >> selection) { }
        else {
            // if input is not a valid integer then request for a valid input
            std::cout << "Please enter a valid value" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        };
    }
}
