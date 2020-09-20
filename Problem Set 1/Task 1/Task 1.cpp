// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int selection = 1;
    std::cout << "Program Start\n";
    while (selection != 6) {
        std::cout << "Press 1 to PingStatus, 2 to Listen, 3 to Tell, 4 to Overloaded Listen, 5 to Overloaded Tell, 6 to Quit: ";
        std::cin >> selection;
    }
}
