#pragma once
#include <string>
#include <iostream>
#include "LinkedList.h"
#include "Item.h"
#include <stdlib.h>     /* srand, rand */

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

	int throwDice() {
		return rand() % 10 + 1;
	}

	friend ostream& operator<<(ostream& aOstream, Slime slime) {
		aOstream << slime.name << " -> " << "HP: " << slime.hP << "/" << slime.maxHP << " Attack: " << slime.attack << endl;
		return aOstream;
	}
};

