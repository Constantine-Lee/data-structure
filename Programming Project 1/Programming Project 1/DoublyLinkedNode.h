#pragma once
#include <iostream>
using namespace std;

template<class DataType>
class DoublyLinkedNode
{
public:
    DataType data;
    DoublyLinkedNode<DataType>* next;
    DoublyLinkedNode<DataType>* prev;
    DoublyLinkedNode(DataType val) {
        this->data = val;
        next = NULL;
        prev = NULL;
    }

    DoublyLinkedNode() {
        next = NULL;
        prev = NULL;
    }
};

