#pragma once
#include <iostream>
#include "DoublyLinkedNode.h"

template<class DataType>
class DoublyLinkedList
{

public:
    int size = 0;
    DoublyLinkedNode<DataType>* head = head = new DoublyLinkedNode<DataType>();
    DoublyLinkedList() {}

    DoublyLinkedList(const DoublyLinkedList& src) {
        DoublyLinkedNode<DataType>* node = src.head;
        while (node->next != NULL)
        {
            node = node->next;
            insertBack(node->data);
        }
    }

    DoublyLinkedList& operator=(DoublyLinkedList src)
    {
        swap(head, src.head);
        return *this;
    }

    ~DoublyLinkedList()
    {
        DoublyLinkedNode<DataType>* curr = head;
        while (curr != NULL) {
            DoublyLinkedNode<DataType>* next = curr->next;
            delete curr;
            curr = next;
        }
        head = NULL;
    }

    void insertFront(DataType val)
    {
        DoublyLinkedNode<DataType>* temp = head->next;        
        head->next = new DoublyLinkedNode<DataType>(val);
        head->next->next = temp;
        head->next->prev = head;
        temp->prev = head->next;
        size++;
    }

    //correct
    void insertBack(DataType val)
    {
        DoublyLinkedNode<DataType>* temp = head;
        while (temp->next != NULL) temp = temp->next;
        DoublyLinkedNode<DataType>* node = new DoublyLinkedNode<DataType>(val);
        temp->next = node;
        node->prev = temp;
        size++;
    }

    /* Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    DataType& get(int index) {
        if (index > size) throw "Index Invalid";
        DoublyLinkedNode<DataType>* temp = head;
        for (int i = 0; i <= index; i++) temp = temp->next;
        return temp->val;
    }

    DoublyLinkedNode<DataType>* getNode(int index) {
        if (index > size) throw "Index Invalid";
        DoublyLinkedNode<DataType>* temp = head;
        for (int i = 0; i <= index; i++) temp = temp->next;
        return temp;
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
            while (find != NULL)
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
        while (node != NULL)
        {
            if (node->data == n)
                return node;

            node = node->next;
        }
        std::cerr << "No such element in the list \n";
        return NULL;
    }

    void display(std::ostream& out = std::cout) const
    {
        DoublyLinkedNode<DataType>* node = head;
        while (node != NULL)
        {
            out << node->data << " ";
            node = node->next;
        }
    }
};

