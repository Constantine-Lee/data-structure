#pragma once
#include "LinkedList.h"

template<class DataType>
class Queue
{
private:
	LinkedList<DataType> fElements;

public:
	bool isEmpty() {
		return fElements.size == 0;
	}

	int size() {
		return fElements.size();
	} 

	void enqueue(DataType val) {
		fElements.append(val);
	}

	DataType dequeue() {
		if (!isEmpty()) {
			DataType removed = fElements.get(0);
			fElements.deleteAtIndex(0);
			return removed;
		}
		else
			throw std::underflow_error("Queue is empty!");
	}
};

