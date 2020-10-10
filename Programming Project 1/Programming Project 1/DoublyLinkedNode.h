#pragma once

template<class DataType>
class DoublyLinkedNode
{
public:
    DataType data;
    DoublyLinkedNode<DataType>* next;
    DoublyLinkedNode<DataType>* prev;
    DoublyLinkedNode(DataType val) : data(val), next(nullptr), prev(nullptr) {}
};

