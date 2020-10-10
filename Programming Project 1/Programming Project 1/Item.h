#pragma once
#include <string>
#include <iostream>

using namespace std;

class Item
{
public:
	string name;
	string description;
	int amount;

	Item() {};

	Item(string Name, string Description, int Amount) :
		name(Name), description(Description), amount(Amount) {};

	friend ostream& operator<<(ostream& aOstream, Item item) {
		aOstream << item.name << ": " << item.amount << endl;
		return aOstream;
	}
};

