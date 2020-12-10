#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

template <class DataType>
class LinkedListNode
{
public:
    DataType val;
    LinkedListNode<DataType>* next;
    LinkedListNode(DataType val) {
        this->val = val;
        next = NULL;
    }

    LinkedListNode() {
        next = NULL;
    }
};


