#pragma once
#include <string>
#include <iostream>
#include "LinkedList.h"
#include "Item.h"

using namespace std;

class Slime
{
public:
	string name;
	int maxHP;
	int hP;
	int attack;
	string type;
	string status;

	Slime(int MaxHP, int HP, int Attack, string Type, string Name) :
		maxHP(MaxHP), hP(HP), attack(Attack), type(Type), name(Name) {
		status = "Normal";
	};
	Slime() {};

	friend ostream& operator<<(ostream& aOstream, Slime slime) {
		aOstream << slime.name << " -> " << "HP: " << slime.hP << "/" << slime.maxHP << " Attack: " << slime.attack << endl;
		return aOstream;
	}
};

