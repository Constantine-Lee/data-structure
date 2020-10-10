#pragma once
#include "Slime.h"

template <class DataType>
class Party
{
public:
	LinkedList<DataType> slimes;
	LinkedList<Item> inventory;

	Party() {

	}

	void addMember(DataType newMember) {
		slimes.addAtTail(newMember);
	}

	void listMembers() {
		slimes.display();
	}

	DataType& getMembers(int index) {
		return slimes.get(index);
	}

	int size() {
		return slimes.size;
	}
};

