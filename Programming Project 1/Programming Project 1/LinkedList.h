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
    LinkedListNode<DataType>* tail = new LinkedListNode<DataType>();

    LinkedList() {}

    // copy constructor
    LinkedList(const LinkedList& src) {
        LinkedListNode<DataType>* node = src.head;
        while (node->next != NULL)
        {            
            node = node->next;    
            append(node->val);
        }
    }

    // assignment operator
    LinkedList& operator=(LinkedList src)
    {
        swap(head, src.head);
        swap(tail, src.tail);
        size = src.size;
        return *this;
    }

    //destructor
    ~LinkedList()
    {
        LinkedListNode<DataType>* curr = head;
        while (curr != NULL) {
            LinkedListNode<DataType>* next = curr->next;
            delete curr;
            curr = next;
        }
        head = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, throw error. */
    DataType& getValue(int index) {
        if (index >= size) throw "Index Invalid";
        LinkedListNode<DataType>* temp = head;
        for (int i = 0; i <= index; i++) temp = temp->next;
        return temp->val;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, throw error. */
    DataType get(int index) {
        if (index >= size) throw "Index Invalid";
        LinkedListNode<DataType>* temp = head;
        for (int i = 0; i <= index; i++) temp = temp->next;
        return temp->val;
    }

    //correct
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void prepend(DataType val) {
        LinkedListNode<DataType>* node = new LinkedListNode<DataType>(val);
        if (head->next == NULL && tail->next == NULL) {
            head->next = node;
            tail->next = node;
        }
        else {
            node->next = head->next;
            head->next = node;
        }
        size++;
    }

    //correct
    /** Append a node of value val to the last element of the linked list. */
    void append(DataType val) {
        LinkedListNode<DataType>* node = new LinkedListNode<DataType>(val);
        if (head->next == NULL && tail->next == NULL) {            
            head->next = node;
            tail->next = node;
        }
        else {
            tail->next->next = node;
            tail->next = node;
        }
        size++;
    }

    void display() {
        LinkedListNode<DataType>* temp = head;
        int counter = 0;
        while (temp->next != NULL) {
            Sleep(100);
            counter++;
            temp = temp->next;
            //will call the overloaded operator of the data type.
            cout << "(" << counter << ")" << temp->val ;
        }
    }

    //should be correct
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, DataType val) {
        if (index > size) return;
        LinkedListNode<DataType>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        LinkedListNode<DataType>* node = new LinkedListNode<DataType>(val);
        if (head->next == NULL && tail->next == NULL) {
            head->next = node;
            tail->next = node;
        }
        else {
            node->next = temp->next;
            temp->next = node;
        }
        size++;
    }

    //some bug if delete at last index
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size) return;
        LinkedListNode< DataType>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        LinkedListNode< DataType>* deletedNode = temp->next;
        if (tail->next == deletedNode) {
            delete deletedNode;
            tail->next = temp;
            temp->next = NULL;
        }
        else {
            temp->next = deletedNode->next;
            delete deletedNode;
        }
        size--;
    }
};

