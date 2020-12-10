#pragma once
#include "Slime.h"

template <class DataType>
class Party
{
public:
	LinkedList<DataType> slimes;
	LinkedList<Item> inventory;

	Party() {}

	void addMember(DataType newMember) {		
		slimes.append(newMember);
	}

	void listMembers() {
		slimes.display();
	}

	DataType& getMembers(int index) {
		return slimes.getValue(index);
	}

	int size() {
		return slimes.size;
	}
};

