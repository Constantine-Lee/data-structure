#pragma once
#include <string>
#include <iostream>
using namespace std;

class Monster
{
public:
	string monsterDes;

	Monster(string MonsterDes) :
		monsterDes(MonsterDes) {};

	Monster() {};

	friend ostream& operator<<(ostream& aOstream, Monster monster) {
		aOstream << monster.monsterDes << endl;
		return aOstream;
	}

	~Monster() {};
};

