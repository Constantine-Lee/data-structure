#pragma once
#include <iostream>
#include "DoublyLinkedNode.h"

template<class DataType>
class DoublyLinkedList
{

public:
    int size = 0;
    DoublyLinkedNode<DataType>* head = new DoublyLinkedNode<DataType>();
    DoublyLinkedNode<DataType>* tail = new DoublyLinkedNode<DataType>();

    DoublyLinkedList() {}

    // copy constructor
    DoublyLinkedList(const DoublyLinkedList& src) {
        DoublyLinkedNode<DataType>* node = src.head;
        while (node->next != NULL)
        {
            node = node->next;
            append(node->data);
        }
    }

    // assignment operator
    DoublyLinkedList& operator=(DoublyLinkedList src)
    {
        swap(head, src.head);
        swap(tail, src.tail);
        size = src.size;
        return *this;
    }

    // destructor
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

    // add at the start
    void prepend(DataType val)
    {
        DoublyLinkedNode<DataType>* node = new DoublyLinkedNode<DataType>(val);
        if (head->next == NULL && tail->next == NULL) {
            head->next = node;
            tail->next = node;
            node->prev = head;
        }
        else {
            node->prev = head;
            node->next = head->next;
            head->next = node;
        }
        size++;
    }

   // add at the end
    void append(DataType val)
    {
        DoublyLinkedNode<DataType>* node = new DoublyLinkedNode<DataType>(val);
        if (head->next == NULL && tail->next == NULL) {
            head->next = node;
            tail->next = node;
            node->prev = head;
        }
        else {
            node->prev = tail->next;
            tail->next->next = node;
            tail->next = node;
        }
        size++;
    }

    /* Get the value of the index-th node in the linked list. If the index is invalid, throw error. */
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

    //should be correct
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, DataType val) {
        if (index > size) return;
        DoublyLinkedNode<DataType>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        DoublyLinkedNode<DataType>* node = new DoublyLinkedNode<DataType>(val);
        if (head->next == NULL && tail->next == NULL) {
            head->next = node;
            tail->next = node;
            node->prev = head;
        }
        else {
            node->next = temp->next;
            temp->next = node;
            node->prev = temp;
        }
        size++;
    }

    //should be correct
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size) return;
        DoublyLinkedNode< DataType>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        DoublyLinkedNode< DataType>* deletedNode = temp->next;
        temp->next = deletedNode->next;
        deletedNode->next->prev = temp;
        size--;
        delete deletedNode;
     }
    

    void display() {
        DoublyLinkedNode<DataType>* node = head;
        while (node != NULL)
        {
            cout << node->data << " ";
            node = node->next;
        }
    }
};

