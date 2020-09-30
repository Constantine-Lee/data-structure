#pragma once
// Include the string library
#include <iostream>
#include <string>
using std::string;

class Entity
{
private:
	int fEntityID;
	string fName;
	int fHP;

public:
	Entity() {};
	Entity(int EntityID, string Name, int HP) : fEntityID(EntityID), fName(Name), fHP(HP) {}

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

