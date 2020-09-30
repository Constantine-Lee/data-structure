// Task 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Entity.h"
#include "Iterator1D.h"
#include "Iterator2D.h"

int main()
{
    const std::string oneDimArr[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    const std::string set1[4] = { "zero", "one", "two", "three" };
    const std::string set2[4] = { "four", "five", "six", "seven" };
    const std::string set3[4] = { "eight", "nine", "ten", "eleven" };
    const std::string set4[4] = { "twelve", "thirteen", "fourteen", "fifteen" };
    const std::string* twoDimArr[] = { set1, set2, set3, set4 };
        
    Iterator* pIter1D = new Iterator1D(oneDimArr, 10);
    Iterator* pIter2D = new Iterator2D(twoDimArr, 16);

    Entity u1(1, "Mytical Creater", 99999);
    Entity u2(2, "Pikachu", 100);
    u1.grab(pIter1D);
    u2.grab(pIter2D);

    std::cout << "1D Iterator Test" << std::endl;
    std::cout << u1.InventoryGet() << std::endl;
    std::cout << u1.InventoryPrev() << std::endl;
    std::cout << u1.InventoryNext() << std::endl;
    
    std::cout << std::endl << "2D Iterator Test" << std::endl;
    std::cout << u2.InventoryGet() << std::endl;
    std::cout << u1.InventoryPrev() << std::endl;    
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;    
    std::cout << u2.InventoryNext() << std::endl;    
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;
    std::cout << u2.InventoryNext() << std::endl;

}


