#pragma once
#include "LinkedList.h"
#include <iostream>
using namespace std;

template <class DataType>
class Stack
{
public:
	LinkedList<DataType> fElements;
    Stack() {}
    // add data at the end  
    void push(DataType data)
    {
        fElements.append(data);
    }

    // check is empty or not
    int isEmpty()
    {
        return fElements.size == 0;
    }

    // Utility function to return top element in a stack  
    DataType& peek()
    {
        // Check for empty stack  
        if (!isEmpty())
            return fElements.getValue(fElements.size - 1);
        else
            exit(1);
    }

    // Utility function to pop top element from the stack  
    DataType pop()
    {
        if (!isEmpty()) {
            DataType removed = fElements.get(fElements.size - 1);
            fElements.deleteAtIndex(fElements.size - 1);
            return removed;
        }
        else
            throw std::underflow_error("Queue is empty!");
    }

    // Function to print all the elements of the stack  
    void display()
    {      
        fElements.display();
    }
};

