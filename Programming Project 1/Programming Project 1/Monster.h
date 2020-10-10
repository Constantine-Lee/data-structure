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

	Monster(int FireElem, int WaterElem, int WindElem, string MonsterDes) : 
		fireElem(FireElem), waterElem(WaterElem), windElem(WindElem), monsterDes(MonsterDes) {};

	Monster() {};

	~Monster() {};
};

