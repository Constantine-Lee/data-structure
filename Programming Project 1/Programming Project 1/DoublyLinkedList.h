#pragma once
#include <iostream>
#include "DoublyLinkedNode.h"

template<class DataType>
class DoublyLinkedList
{

public:
    DoublyLinkedNode<DataType>* head, * tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList()
    {
        DoublyLinkedNode<DataType>* tmp = nullptr;
        while (head)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        head = nullptr;
    }

    void insertFront(DataType val)
    {
        DoublyLinkedNode<DataType>* node = new DoublyLinkedNode<DataType>(val);
        DoublyLinkedNode<DataType>* tmp = head;
        // If empty
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head = node;
            node->next->prev = node;
        }
    }

    void insertBack(DataType val)
    {
        DoublyLinkedNode<DataType>* node = new DoublyLinkedNode<DataType>(val);
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }             
    }

    void deleteVal(DataType val)
    {
        DoublyLinkedNode<DataType>* find = findVal(val);
        DoublyLinkedNode<DataType>* tmp = head;

        if (tmp == find)
        {
            head = tmp->next;
        }
        else
        {
            while (find != nullptr)
            {
                if (tmp->next == find)
                {
                    tmp->next = find->next;
                    find->next->prev = tmp;
                    delete find;
                    return;
                }
                tmp = tmp->next;
            }
        }
    }

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<U>& dll) {
        dll.display(os);
        return os;
    }

private:

    DoublyLinkedNode<DataType>* findVal(DataType n) //returns node of the given number
    {
        DoublyLinkedNode<DataType>* node = head;
        while (node != nullptr)
        {
            if (node->data == n)
                return node;

            node = node->next;
        }
        std::cerr << "No such element in the list \n";
        return nullptr;
    }

    void display(std::ostream& out = std::cout) const
    {
        DoublyLinkedNode<DataType>* node = head;
        while (node != nullptr)
        {
            out << node->data << " ";
            node = node->next;
        }
    }
};

