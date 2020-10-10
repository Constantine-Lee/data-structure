#pragma once
#include "StackNode.h"
#include <iostream>
using namespace std;

template <class DataType>
class Stack
{
public:
	StackNode<DataType>* top;

    // Utility function to add an element  
    // data in the stack insert at the beginning  
    void push(DataType data)
    {
        // Create new node temp and allocate memory  
        StackNode<DataType>* temp = new StackNode<DataType>();

        // Check if stack (heap) is full.  
        // Then inserting an element would  
        // lead to stack overflow  
        if (!temp)
        {
            cout << "\nHeap Overflow";
            exit(1);
        }

        // Initialize data into temp data field  
        temp->data = data;

        // Put top pointer reference into temp link  
        temp->next = top;

        // Make temp as top of Stack  
        top = temp;
    }

    // Utility function to check if  
// the stack is empty or not  
    int isEmpty()
    {
        return top == NULL;
    }

    // Utility function to return top element in a stack  
    DataType& peek()
    {
        // Check for empty stack  
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }

    // Utility function to pop top  
    // element from the stack  
    void pop()
    {
        StackNode<DataType>* temp;

        // Check for stack underflow  
        if (top == NULL)
        {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else
        {

            // Top assign into temp  
            temp = top;

            // Assign second node to top  
            top = top->next;

            // Destroy connection between 
            // first and second  
            temp->next = NULL;

            // Release memory of top node  
            free(temp);
        }
    }

    // Function to print all the  
    // elements of the stack  
    void display()
    {
        StackNode<DataType>* temp;

        // Check for stack underflow  
        if (top == NULL)
        {
            cout << "\nStack Underflow";
            exit(1);
        }
        else
        {
            temp = top;
            int counter = 0;
            while (temp != NULL)
            {
                counter++;
                // Print node data  
                cout << "(" << counter << ")" << temp->data << endl;

                // Assign temp link to temp  
                temp = temp->next;
            }
        }
    }
};

