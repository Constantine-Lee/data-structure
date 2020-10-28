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
	bool reincarnate;

	Monster(int MaxHP, int HP, int FireElem, int WaterElem, int WindElem, string MonsterDes, bool Reincarnate) : 
		maxHP(MaxHP), hP(HP), fireElem(FireElem), waterElem(WaterElem), windElem(WindElem), monsterDes(MonsterDes), reincarnate(Reincarnate) {};

	Monster() {};

	friend ostream& operator<<(ostream& aOstream, Monster monster) {
		aOstream << monster.monsterDes << endl;
		return aOstream;
	}

	~Monster() {};
};

