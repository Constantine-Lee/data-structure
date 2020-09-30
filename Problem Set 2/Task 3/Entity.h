#pragma once
// Include the string library
#include <iostream>
#include <string>
#include "Iterator.h"
using std::string;

class Entity
{
private:
	int fEntityID;
	string fName;
	int fHP;
	Iterator* fIter;

public:
	Entity() {};
	Entity(int EntityID, string Name, int HP) : fEntityID(EntityID), fName(Name), fHP(HP) {}

	void grab(Iterator* iter) {
		fIter = iter;
	}

	const std::string& InventoryNext() {
		(*fIter)++;
		if (*fIter == (*fIter).end()) {
			(*fIter)--;
		}		
		return *(*fIter);
	}

	const std::string& InventoryPrev() {		
		if (*fIter == (*fIter).begin()) {}
		else {
			(*fIter)--;
		}
		return *(*fIter);
	}

	const std::string& InventoryGet() {
		return *(*fIter);
	}

	void setEntityID(int ID) {
		fEntityID = ID;
	}

	void setName(string Name) {
		fName = Name;
	}

	void setHP(int HP) {
		fHP = HP;
	}

	int getEntityID() {
		return fEntityID;
	}

	string getName() {
		return fName;
	}

	int getHP() {
		return fHP;
	}

	~Entity() {}

};

