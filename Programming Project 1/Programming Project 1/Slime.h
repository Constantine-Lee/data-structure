#pragma once
#include <string>
#include <iostream>
#include "LinkedList.h"
#include "Item.h"
#include <stdlib.h>     /* srand, rand */

using namespace std;

class Slime
{
protected:
	int hP;

public:
	string name;
	int maxHP;
	int attack;
	string type;
	string status;

	Slime(int MaxHP, int HP, int Attack, string Type, string Name) :
		maxHP(MaxHP), hP(HP), attack(Attack), type(Type), name(Name) {
		status = "Normal";
	};
	Slime() {};


	void setHP(int HP) {
		hP = HP;		
		if (hP < 0) {
			hP = 0;
		}
		if (hP > maxHP) {
			hP = maxHP;
		}
		if (hP == 0 && status == "Normal") {
			status = "Dead";
			cout << name << " is dead." << endl;
		}		
	}

	int getHP() {
		return hP;
	}

	int throwDice() {
		return rand() % 10 + 1;
	}

	virtual void specialLuck() {
		return ;
	}

	friend ostream& operator<<(ostream& aOstream, Slime slime) {
		aOstream << slime.name << " -> " << "HP: " << slime.hP << "/" << slime.maxHP << " Attack: " << slime.attack << endl;
		return aOstream;
	}
};

