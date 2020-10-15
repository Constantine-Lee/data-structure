#pragma once
#include "LinkedListNode.h"
#include "windows.h"

template <class DataType>
class LinkedList
{
public:
    /** Initialize your data structure here. */
    int size = 0;
    LinkedListNode<DataType>* head = new LinkedListNode<DataType>();
    LinkedList() {
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    DataType& get(int index) {
        if (index > size) throw "Index Invalid";
        LinkedListNode<DataType>* temp = head->next;
        for (int i = 1; i < index; i++) temp = temp->next;
        return temp->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(DataType val) {
        LinkedListNode<DataType>* temp = head->next;
        head->next = new LinkedListNode<DataType>(val);
        head->next->next = temp;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(DataType val) {
        LinkedListNode< DataType>* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = new LinkedListNode< DataType>(val);
        size++;
    }

    void display() {
        LinkedListNode<DataType>* temp = head;
        int counter = 0;
        while (temp->next != NULL) {
            Sleep(100);
            counter++;
            temp = temp->next;
            cout << "(" << counter << ")" << temp->val ;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, DataType val) {
        if (index > size) return;
        LinkedListNode< DataType>* temp = head;
        for (int i = 0; i < index; i++) temp = temp->next;
        LinkedListNode< DataType>* temp1 = temp->next;
        temp->next = new LinkedListNode< DataType>(val);
        temp->next->next = temp1;
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index > size) return;
        LinkedListNode< DataType>* temp = head;
        for (int i = 1; i < index; i++) temp = temp->next;
        LinkedListNode< DataType>* temp1 = temp->next;
        temp->next = temp1->next;
        size--;
        delete temp1;
    }
};

