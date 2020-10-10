#pragma once
#include <string>
#include <iostream>
using namespace std;

class Monster
{
public:
	int fireElem;
	int waterElem;
	int windElem;
	string monsterDes;
	int maxHP;
	int hP;

	Monster(int MaxHP, int HP, int FireElem, int WaterElem, int WindElem, string MonsterDes) : 
		maxHP(MaxHP), hP(HP), fireElem(FireElem), waterElem(WaterElem), windElem(WindElem), monsterDes(MonsterDes) {};

	Monster() {};

	friend ostream& operator<<(ostream& aOstream, Monster monster) {
		aOstream << monster.monsterDes << endl;
		return aOstream;
	}

	~Monster() {};
};

